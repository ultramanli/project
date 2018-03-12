import input_data

import tensorflow as tf

import model




mnist = input_data.read_data_sets('MNIST_data', one_hot=True)#读取数据

  #输入变量，mnist图片大小为28*28
x = tf.placeholder(tf.float32, [None, 784])

#输出变量，数字是1-10
y_ = tf.placeholder(tf.float32, [None, 10])

  # 构建网络，输入—>第一层卷积—>第一层池化—>第二层卷积—>第二层池化—>第一层全连接—>第二层全连接
y_conv, keep_prob = model.deepnn(x)

  #第一步对网络最后一层的输出做一个softmax，第二步将softmax输出和实际样本做一个交叉熵
  #cross_entropy返回的是向量
with tf.name_scope('loss'):
  cross_entropy = tf.nn.softmax_cross_entropy_with_logits(labels=y_,
                                                            logits=y_conv)

  #求cross_entropy向量的平均值得到交叉熵
cross_entropy = tf.reduce_mean(cross_entropy)

  #AdamOptimizer是Adam优化算法：一个寻找全局最优点的优化算法，引入二次方梯度校验
with tf.name_scope('adam_optimizer'):
    train_step = tf.train.AdamOptimizer(1e-4).minimize(cross_entropy)

  #在测试集上的精确度
with tf.name_scope('accuracy'):
    correct_prediction = tf.equal(tf.argmax(y_conv, 1), tf.argmax(y_, 1))
    correct_prediction = tf.cast(correct_prediction, tf.float32)
accuracy = tf.reduce_mean(correct_prediction)

  #将训练的网络保存下来
saver = tf.train.Saver()
with tf.Session() as sess:
    sess.run(tf.global_variables_initializer())
    for i in range(200):
      batch = mnist.train.next_batch(50)
      if i % 100 == 0:
        train_accuracy = accuracy.eval(feed_dict={
            x: batch[0], y_: batch[1], keep_prob: 1.0})#输入是字典，表示tensorflow被feed的值
        print('step %d, training accuracy %g' % (i, train_accuracy))
      train_step.run(feed_dict={x: batch[0], y_: batch[1], keep_prob: 0.5})
    #print ("test accuracy %g"%accuracy.eval(feed_dict={x: mnist.test.images, y_: mnist.test.labels, keep_prob: 1.0}))
    #save_path = saver.save(sess,"E:/Project/Python/mnist/MNIST_my/mnist_cnn_model.ckpt")

    test_accuracy = 0
    for i in range(200):
      batch = mnist.test.next_batch(50)
      test_accuracy += accuracy.eval(feed_dict={x: batch[0], y_: batch[1], keep_prob: 1.0}) / 200;

    print('test accuracy %g' % test_accuracy)

    save_path = saver.save(sess,"./mnist_cnn_model.ckpt")

