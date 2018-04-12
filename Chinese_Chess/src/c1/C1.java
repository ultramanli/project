//中国象棋
package c1;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class C1 {

    public static void main(String args[]) {
        new ChessPerform();
    }
}

class ChessPerform extends JFrame implements MouseListener {

    JLabel play[] = new JLabel[32];       //32个棋子
    Icon icon = new ImageIcon(getClass().getResource("/image/棋盘.gif"));
    JLabel image = new JLabel(icon);	       	     //棋盘
   
    JButton close=new JButton("关闭");
    JButton start = new JButton("开始");
    JButton end = new JButton("结束");
    button lis = new button();

    JLayeredPane cp;
    ChessRule rule;
    static int now;

    static int which = 1;                          //1表示红棋走，2表示黑棋走
    boolean whether = false;                      //判断是否下棋
    JFrame f = new JFrame();

    ChessPerform() {

        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setLayout(null);
        rule = new ChessRule();
        cp = f.getLayeredPane();
        draw();
        cp.add(start);//开始按钮
        cp.add(end);//结束按钮
        cp.add(close);
        cp.setLayer(close, 1);
        cp.setLayer(start, 1);
        cp.setLayer(end, 1);
        close.addMouseListener(lis);
        close.setBounds(480, 618, 60, 25);
        close.setVisible(true);
        start.addMouseListener(lis);
        start.setBounds(195, 618, 60, 25);
        start.setVisible(true);
        end.addMouseListener(lis);
        end.setBounds(309, 618, 60, 25);
        end.setVisible(false);

        for (int i = 0; i < 32; i++) {
            cp.setLayer(play[i], 2);       //添加棋子标签
            play[i].addMouseListener(this);        //为棋子注册监听器
        }
        image.setBounds(0, 30, 559, 620);
        image.addMouseListener(this);
        cp.add(image);              //添加棋盘标签
        cp.setLayer(image, 0);

        f.pack();
        f.setVisible(true);
        f.setSize(new Dimension(590, 700));
    }

    //棋子初始化布局
    public void draw() {
        Icon in;//图标		
        int i, k;
        //黑色棋子		
        in = new ImageIcon(getClass().getResource("/image/黑車.gif"));     //车
        for (i = 0, k = 24; i < 2; i++, k += 456) {
            play[i] = new JLabel(in);
            play[i].setName("車b");
            play[i].setBounds(k, 56, 55, 55);
        }

        in = new ImageIcon(getClass().getResource("/image/黑馬.gif"));     //马
        for (i = 2, k = 81; i < 4; i++, k += 342) {
            play[i] = new JLabel(in);
            play[i].setName("馬b");
            play[i].setBounds(k, 56, 55, 55);
        }

        in = new ImageIcon(getClass().getResource("/image/黑象.gif"));     //象
        for (i = 4, k = 138; i < 6; i++, k += 228) {
            play[i] = new JLabel(in);
            play[i].setName("象b");
            play[i].setBounds(k, 56, 55, 55);
        }

        in = new ImageIcon(getClass().getResource("/image/黑士.gif"));       //士
        for (i = 6, k = 195; i < 8; i++, k += 114) {
            play[i] = new JLabel(in);
            play[i].setName("士b");
            play[i].setBounds(k, 56, 55, 55);
        }

        in = new ImageIcon(getClass().getResource("/image/黑卒.gif"));     //卒
        for (i = 8, k = 24; i < 13; i++, k += 114) {
            play[i] = new JLabel(in);
            play[i].setName("卒b" + i);
            play[i].setBounds(k, 227, 55, 55);
        }

        in = new ImageIcon(getClass().getResource("/image/黑炮.gif"));	                          //炮		
        for (i = 13, k = 81; i < 15; i++, k += 342) {
            play[i] = new JLabel(in);
            play[i].setName("炮b" + i);
            play[i].setBounds(k, 170, 55, 55);
        }

        in = new ImageIcon(getClass().getResource("/image/黑将.gif"));    //将
        play[15] = new JLabel(in);
        play[15].setName("将b");
        play[15].setBounds(252, 56, 55, 55);

        //红色棋子		
        in = new ImageIcon(getClass().getResource("/image/红車.gif"));  //車
        for (i = 16, k = 24; i < 18; i++, k += 456) {
            play[i] = new JLabel(in);
            play[i].setName("車r");
            play[i].setBounds(k, 569, 55, 55);
        }

        in = new ImageIcon(getClass().getResource("/image/红馬.gif"));  //馬
        for (i = 18, k = 81; i < 20; i++, k += 342) {
            play[i] = new JLabel(in);
            play[i].setName("馬r");
            play[i].setBounds(k, 569, 55, 55);
        }

        in = new ImageIcon(getClass().getResource("/image/红相.gif"));	 //相		
        for (i = 20, k = 138; i < 22; i++, k += 228) {
            play[i] = new JLabel(in);
            play[i].setName("相r");
            play[i].setBounds(k, 569, 55, 55);
        }

        in = new ImageIcon(getClass().getResource("/image/红仕.gif"));   //仕
        for (i = 22, k = 195; i < 24; i++, k += 114) {
            play[i] = new JLabel(in);
            play[i].setName("仕r");
            play[i].setBounds(k, 569, 55, 55);
        }

        in = new ImageIcon(getClass().getResource("/image/红兵.gif"));                           //兵
        for (i = 24, k = 24; i < 29; i++, k += 114) {
            play[i] = new JLabel(in);
            play[i].setName("卒r" + i);
            play[i].setBounds(k, 398, 55, 55);
        }

        in = new ImageIcon(getClass().getResource("/image/红炮.gif"));                          //炮
        for (i = 29, k = 81; i < 31; i++, k += 342) {
            play[i] = new JLabel(in);
            play[i].setName("炮r" + i);
            play[i].setBounds(k, 455, 55, 55);
        }

        in = new ImageIcon(getClass().getResource("/image/红帅.gif"));			//帅
        play[31] = new JLabel(in);
        play[31].setName("帅r");
        play[31].setBounds(252, 569, 55, 55);

    }
 
    public void mouseClicked(MouseEvent e) {
        int x = 0, y = 0;
        if (e.getSource().equals(image)) {
            //红棋走棋
            if (which == 1 && play[now].getName().charAt(1) == 'r') {
                x = play[now].getX();
                y = play[now].getY();

                //移动車
                if ((now >= 0 && now < 2) || (now > 15 && now < 18)) {
                    rule.PaoJuRule(play[now], play, e);
                } //移动馬
                else if ((now > 1 && now < 4) || (now > 17 && now < 20)) {
                    rule.HorseRule(play[now], play, e);
                } //移动相、象
                else if ((now > 3 && now < 6) || (now > 19 && now < 22)) {
                    rule.ElephantRule(now, play[now], play, e);
                } //移动仕、士
                else if ((now > 5 && now < 8) || (now > 21 && now < 24)) {
                    rule.ShiRule(now, play[now], play, e);
                } //移动卒、兵
                else if ((now > 7 && now < 13) || (now > 23 && now < 29)) {
                    rule.ZuRule(now, play[now], e);
                } //移动炮
                else if ((now > 12 && now < 15) || (now > 28 && now < 31)) {
                    rule.PaoJuRule(play[now], play, e);
                }//移动将、帅
                else if (now == 15 || now == 31) {
                    rule.CoreRule(now, play[now], play, e);
                }

                //是否没动
                if (x == play[now].getX() && y == play[now].getY()) {        //此时play[now]的坐标已经改变
                    which = 1;     //红棋继续走棋      

                } else {
                    which = 2;           //改为黑棋走棋

                }

            } //该黑棋走棋的时候
            else if (which == 2 && play[now].getName().charAt(1) == 'b') {
                x = play[now].getX();
                y = play[now].getY();

                //移动車
                if ((now >= 0 && now < 2) || (now > 15 && now < 18)) {
                    rule.PaoJuRule(play[now], play, e);
                } //移动馬
                else if ((now > 1 && now < 4) || (now > 17 && now < 20)) {
                    rule.HorseRule(play[now], play, e);
                } //移动相、象
                else if ((now > 3 && now < 6) || (now > 19 && now < 22)) {
                    rule.ElephantRule(now, play[now], play, e);
                } //移动仕、士
                else if ((now > 5 && now < 8) || (now > 21 && now < 24)) {
                    rule.ShiRule(now, play[now], play, e);
                } //移动卒、兵
                else if ((now > 7 && now < 13) || (now > 23 && now < 29)) {
                    rule.ZuRule(now, play[now], e);
                } //移动炮
                else if ((now > 12 && now < 15) || (now > 28 && now < 31)) {
                    rule.PaoJuRule(play[now], play, e);
                }//移动将、帅
                else if (now == 15 || now == 31) {
                    rule.CoreRule(now, play[now], play, e);
                }

                //是否没动
                if (x == play[now].getX() && y == play[now].getY()) {
                    which = 2;     //黑棋继续走棋

                } else {
                    which = 1;           //改为红棋走棋

                }
            }
            whether = false;              //重新置棋子为未选中状态
        } //第一次单击棋子
        else if (!whether) {         //whether初始为false;
            for (int i = 0; i < 32; i++) {
                //被单击的棋子
                if (e.getSource().equals(play[i])) {

                    now = i;

                    whether = true;       //已选中第一个棋子

                    break;
                }
            }
        } else if (whether) {
            whether = false;            //第一个棋子改为未选
            for (int i = 0; i < 32; i++) {
                if (e.getSource().equals(play[i])) {
                    if (which == 1 && play[now].getName().charAt(1) == 'r' && play[i].getName().charAt(1) == 'b') {
                        x = play[now].getX();
                        y = play[now].getY();
                        //車吃规则
                        if ((now >= 0 && now < 2) || (now > 15 && now < 18)) {
                            rule.PaoJuRule(1, play[now], play[i], play, e);
                        } //马吃规则
                        else if ((now > 1 && now < 4) || (now > 17 && now < 20)) {
                            rule.HorseRule(play[now], play[i], play, e);
                        } //相、象规则
                        else if ((now > 3 && now < 6) || (now > 19 && now < 22)) {
                            rule.ElephantRule(play[now], play[i], play);
                        } //仕、士规则
                        else if ((now > 5 && now < 8) || (now > 21 && now < 24)) {
                            rule.ShiRule(now, play[now], play[i], play);
                        } //卒、兵吃规则
                        else if ((now > 7 && now < 13) || (now > 23 && now < 29)) {
                            rule.ZuRule(play[now], play[i]);
                        } //炮吃规则
                        else if ((now > 12 && now < 15) || (now > 28 && now < 31)) {
                            rule.PaoJuRule(0, play[now], play[i], play, e);
                        }//将、帅吃棋规则
                        else if (now == 15 || now == 31) {
                            rule.CoreRule(now, play[now], play[i], play);

                        }

                        //是否没动
                        if (x == play[now].getX() && y == play[now].getY()) {              //此时play[now]已经改变
                            which = 1;     //红棋继续走棋
                        } else {
                            which = 2;           //改为黑棋走棋
                        }

                    } else if (which == 2 && play[now].getName().charAt(1) == 'b' && play[i].getName().charAt(1) == 'r') {
                        x = play[now].getX();
                        y = play[now].getY();
                        //車吃规则
                        if ((now >= 0 && now < 2) || (now > 15 && now < 18)) {
                            rule.PaoJuRule(1, play[now], play[i], play, e);
                        } //马吃规则
                        else if ((now > 1 && now < 4) || (now > 17 && now < 20)) {
                            rule.HorseRule(play[now], play[i], play, e);
                        } //相、象规则
                        else if ((now > 3 && now < 6) || (now > 19 && now < 22)) {
                            rule.ElephantRule(play[now], play[i], play);
                        } //仕、士规则
                        else if ((now > 5 && now < 8) || (now > 21 && now < 24)) {
                            rule.ShiRule(now, play[now], play[i], play);
                        } //卒、兵吃规则
                        else if ((now > 7 && now < 13) || (now > 23 && now < 29)) {
                            rule.ZuRule(play[now], play[i]);
                        } //炮吃规则
                        else if ((now > 12 && now < 15) || (now > 28 && now < 31)) {
                            rule.PaoJuRule(0, play[now], play[i], play, e);
                        }//将、帅吃棋规则
                        else if (now == 15 || now == 31) {
                            rule.CoreRule(now, play[now], play[i], play);

                        }
                        //是否没动
                        if (x == play[now].getX() && y == play[now].getY()) {
                            which = 2;     //黑棋继续走棋

                        } else {
                            which = 1;           //改为红棋走棋
                        }

                    }
                }
            }
            if (!play[15].isVisible()) {
                JOptionPane.showMessageDialog(f, "红棋胜利", "玩家二胜利", JOptionPane.PLAIN_MESSAGE);
                which = 3;
            } else if (!play[31].isVisible()) {
                JOptionPane.showMessageDialog(f, "黑棋胜利", "玩家一胜利", JOptionPane.PLAIN_MESSAGE);
                which = 3;
            }
        }

    }

    public void mousePressed(MouseEvent e) {
    }

    public void mouseEntered(MouseEvent e) {
    }

    public void mouseExited(MouseEvent e) {
    }

    public void mouseReleased(MouseEvent e) {
    }

    class button extends MouseAdapter {

       
public void repieces() {
            int i = 0, k = 0;

            for (i = 0, k = 24; i < 2; i++, k += 456) //車
            {
                play[i].setBounds(k, 56, 55, 55);
            }

            for (i = 2, k = 81; i < 4; i++, k += 342) //马
            {
                play[i].setBounds(k, 56, 55, 55);
            }

            for (i = 4, k = 138; i < 6; i++, k += 228) //象
            {
                play[i].setBounds(k, 56, 55, 55);
            }

            for (i = 6, k = 195; i < 8; i++, k += 114) //士
            {
                play[i].setBounds(k, 56, 55, 55);
            }

            for (i = 8, k = 24; i < 13; i++, k += 114) //卒
            {
                play[i].setBounds(k, 227, 55, 55);
            }

            for (i = 13, k = 81; i < 15; i++, k += 342)//炮	
            {
                play[i].setBounds(k, 170, 55, 55);
            }

            play[15].setBounds(252, 56, 55, 55);   //将

            //红色棋子	
            for (i = 16, k = 24; i < 18; i++, k += 456) //車
            {
                play[i].setBounds(k, 569, 55, 55);
            }

            for (i = 18, k = 81; i < 20; i++, k += 342) //馬
            {
                play[i].setBounds(k, 569, 55, 55);
            }

            for (i = 20, k = 138; i < 22; i++, k += 228)//相
            {
                play[i].setBounds(k, 569, 55, 55);
            }

            for (i = 22, k = 195; i < 24; i++, k += 114) //仕
            {
                play[i].setBounds(k, 569, 55, 55);
            }

            for (i = 24, k = 24; i < 29; i++, k += 114) //兵
            {
                play[i].setBounds(k, 398, 55, 55);
            }

            for (i = 29, k = 81; i < 31; i++, k += 342)//炮
            {
                play[i].setBounds(k, 455, 55, 55);
            }

            play[31].setBounds(252, 569, 55, 55);//帅
        }
        public void mouseClicked(MouseEvent e) {
            if (e.getSource().equals(start)) {
                now = 0;
                which = 1;
                whether = false;
                repieces();//重新初始化棋子位置

                for (int i = 0; i < 32; i++) {
                    cp.add(play[i]);  //添加棋子
                    play[i].setVisible(true);

                }

                start.setVisible(false);
                end.setVisible(true);
            }
            if (e.getSource().equals(end)) {
                start.setVisible(true);
                end.setVisible(false);
                for (int i = 0; i < 32; i++) {
                    cp.remove(play[i]);  //移除棋子

                }
                cp.repaint();

            }
            if(e.getSource().equals(close)){
            System.exit(0);
            }

        }
    }
   
}

class ChessRule {

    //卒(兵)移动
    public void ZuRule(int now, JLabel play, MouseEvent e) {
        //黑卒向下
        if (now < 13) {
            //向下移动、得到终点的坐标模糊成合法的坐标
            if ((e.getY() - play.getY()) > 27 && (e.getY() - play.getY()) < 86 && (e.getX() - play.getX()) < 55 && (e.getX() - play.getX()) > 0) {

                play.setBounds(play.getX(), play.getY() + 57, 55, 55);

            } //向右移动、得到终点的坐标模糊成合法的坐标、必须过河				
            else if (play.getY() > 284 && (e.getX() - play.getX()) >= 57 && (e.getX() - play.getX()) <= 112) {
                play.setBounds(play.getX() + 57, play.getY(), 55, 55);

            } //向左移动、得到终点的坐标模糊成合法的坐标、必须过河
            else if (play.getY() > 284 && (play.getX() - e.getX()) >= 2 && (play.getX() - e.getX()) <= 58) {
                //模糊坐标
                play.setBounds(play.getX() - 57, play.getY(), 55, 55);

            }
        } //红兵向上
        else //向上移动
        //向上移动、得到终点的坐标模糊成合法的坐标
         if ((e.getX() - play.getX()) >= 0 && (e.getX() - play.getX()) <= 55 && (play.getY() - e.getY()) > 27 && play.getY() - e.getY() < 86) {
                play.setBounds(play.getX(), play.getY() - 57, 55, 55);

            } //向右移动、得到终点的坐标模糊成合法的坐标、必须过河
            else if (play.getY() < 341 && (e.getX() - play.getX()) >= 57 && (e.getX() - play.getX()) <= 112) {
                play.setBounds(play.getX() + 57, play.getY(), 55, 55);

            } //向左移动、得到终点的坐标模糊成合法的坐标、必须过河
            else if (play.getY() < 341 && (play.getX() - e.getX()) >= 3 && (play.getX() - e.getX()) <= 58) {
                play.setBounds(play.getX() - 57, play.getY(), 55, 55);

            }

    }

    //卒(兵)吃规则
    public void ZuRule(JLabel play1, JLabel play2) {       //play1为吃棋，play2为被吃棋
        //向右走
        if ((play2.getX() - play1.getX()) <= 112 && (play2.getX() - play1.getX()) >= 57 && (play1.getY() - play2.getY()) < 22 && (play1.getY() - play2.getY()) > -22 && play2.isVisible() && play1.getName().charAt(1) != play2.getName().charAt(1)) {
            //黑棋要过河才能右吃棋
            if (play1.getName().charAt(1) == 'b' && play1.getY() > 284 && play1.getName().charAt(1) != play2.getName().charAt(1)) {
                play2.setVisible(false);
                play1.setBounds(play2.getX(), play2.getY(), 55, 55);

            } //红棋要过河才左能吃棋
            else if (play1.getName().charAt(1) == 'r' && play1.getY() < 341 && play1.getName().charAt(1) != play2.getName().charAt(1)) {
                play2.setVisible(false);
                //把对方的位置给自己
                play1.setBounds(play2.getX(), play2.getY(), 55, 55);

            }
        } //向左走
        else if ((play1.getX() - play2.getX()) <= 112 && (play1.getX() - play2.getX()) >= 57 && (play1.getY() - play2.getY()) < 22 && (play1.getY() - play2.getY()) > -22 && play2.isVisible() && play1.getName().charAt(1) != play2.getName().charAt(1)) {
            //黑棋要过河才能左吃棋
            if (play1.getName().charAt(1) == 'b' && play1.getY() > 284 && play1.getName().charAt(1) != play2.getName().charAt(1)) {
                play2.setVisible(false);
                play1.setBounds(play2.getX(), play2.getY(), 55, 55);

            } //红棋要过河才能右吃棋
            else if (play1.getName().charAt(1) == 'r' && play1.getY() < 341 && play1.getName().charAt(1) != play2.getName().charAt(1)) {
                play2.setVisible(false);
                play1.setBounds(play2.getX(), play2.getY(), 55, 55);

            }
        } else if (play1.getX() - play2.getX() >= -22 && play1.getX() - play2.getX() <= 22 && play1.getY() - play2.getY() >= -112 && play1.getY() - play2.getY() <= 112) {
            //黑棋不能向上吃棋
            if (play1.getName().charAt(1) == 'b' && play1.getY() < play2.getY() && play1.getName().charAt(1) != play2.getName().charAt(1)) {
                play2.setVisible(false);
                play1.setBounds(play2.getX(), play2.getY(), 55, 55);

            } //红棋不能向下吃棋
            else if (play1.getName().charAt(1) == 'r' && play1.getY() > play2.getY() && play1.getName().charAt(1) != play2.getName().charAt(1)) {
                play2.setVisible(false);
                play1.setBounds(play2.getX(), play2.getY(), 55, 55);

            }
        }

    }

    //炮車移动规则
    public void PaoJuRule(JLabel play, JLabel playNow[], MouseEvent e) {

        int count = 0;       //累加器，判断起点和终点之间是否有棋子
        //上、下移动
        if (e.getX() - play.getX() >= 0 && e.getX() - play.getX() <= 55) {      //横坐标在一个棋子范围内
            for (int i = 56; i <= 571; i += 57) {
                //移动的Y坐标是否有指定坐标相近的
                if (Math.abs(i - e.getY()) <= 27) {              //i为找到的与点击点最近的点
                    for (int j = 0; j < 32; j++) {           //所有的棋子                    
                        if (Math.abs(playNow[j].getX() - play.getX()) <= 27 && playNow[j].getName() != play.getName() && playNow[j].isVisible()) {  //在竖坐标上找出自己外的其他棋子                     
                            for (int k = play.getY() + 57; k < i; k += 57) {          //从起点到终点（从上到下）                               
                                if (playNow[j].getY() < i && playNow[j].getY() > play.getY()) {       //大于起点、小于终点的坐标判断是否有棋子
                                    count++;            //中间有棋子就不可以从这条竖线过去
                                    break;
                                }
                            }
                            //从起点到终点(从下到上)
                            for (int k = i + 57; k < play.getY(); k += 57) {
                                //找起点和终点的棋子
                                if (playNow[j].getY() < play.getY() && playNow[j].getY() > i) {
                                    count++;
                                    break;
                                }
                            }
                        }
                    }

                    //起点和终点没有棋子就可以移动了
                    if (count == 0) {
                        play.setBounds(play.getX(), i, 55, 55);

                        break;
                    }
                }
            }
        } //左、右移动
        else if (Math.abs(play.getY() - e.getY()) <= 27) {
            //指定所有模糊X坐标
            for (int i = 24; i <= 480; i += 57) {
                //移动的X坐标是否有指定坐标相近的
                if (e.getX() - i <= 55 && e.getX() - i >= 0) {
                    //所有的棋子
                    for (int j = 0; j < 32; j++) {
                        //找出在同一条横线的所有棋子、并不包括自己
                        if (Math.abs(playNow[j].getY() - play.getY()) <= 27 && playNow[j].getName() != play.getName() && playNow[j].isVisible()) {
                            //从起点到终点(从左到右)				
                            for (int k = play.getX() + 57; k < i; k += 57) {
                                //大于起点、小于终点的坐标判断是否有棋子
                                if (playNow[j].getX() < i && playNow[j].getX() > play.getX()) {
                                    //中间有棋子就不可以从这条横线过去
                                    count++;
                                    break;
                                }
                            }

                            //从起点到终点(从下到上)
                            for (int k = i + 57; k < play.getX(); k += 57) {
                                //找起点和终点的棋子
                                if (playNow[j].getX() < play.getX() && playNow[j].getX() > i) {
                                    count++;
                                    break;
                                }
                            }
                        }
                    }

                    //起点和终点没有棋子
                    if (count == 0) {
                        play.setBounds(i, play.getY(), 55, 55);

                        break;
                    }

                }
            }
        }
    }

    //炮車吃棋规则
    public void PaoJuRule(int Chess, JLabel play, JLabel playTake, JLabel playNow[], MouseEvent e) {
        //起点和终点之间是否有棋子
        int count = 0;
        //所有的棋子
        for (int j = 0; j < 32; j++) {
            //找出在同一条竖线的所有棋子、并不包括自己
            if (Math.abs(playNow[j].getX() - play.getX()) <= 27 && playNow[j].getName() != play.getName() && playNow[j].isVisible()) {

                //自己是起点被吃的是终点(从上到下)
                for (int k = play.getY() + 57; k < playTake.getY(); k += 57) {
                    //大于起点、小于终点的坐标就可以知道中间是否有棋子
                    if (playNow[j].getY() < playTake.getY() && playNow[j].getY() > play.getY()) {
                        //计算起点和终点的棋子个数
                        count++;
                        break;
                    }
                }

                //自己是起点被吃的是终点(从下到上)
                for (int k = playTake.getY(); k < play.getY(); k += 57) {
                    //找起点和终点的棋子
                    if (playNow[j].getY() < play.getY() && playNow[j].getY() > playTake.getY()) {
                        count++;
                        break;
                    }
                }
            } //找出在同一条竖线的所有棋子、并不包括自己
            else if (Math.abs(playNow[j].getY() - play.getY()) <= 10 && playNow[j].getName() != play.getName() && playNow[j].isVisible()) {
                //自己是起点被吃的是终点(从左到右)
                for (int k = play.getX() + 50; k < playTake.getX(); k += 57) {
                    //大于起点、小于终点的坐标就可以知道中间是否有棋子						
                    if (playNow[j].getX() < playTake.getX() && playNow[j].getX() > play.getX()) {
                        count++;
                        break;
                    }
                }//for

                //自己是起点被吃的是终点(从右到左)
                for (int k = playTake.getX(); k < play.getX(); k += 57) {
                    //找起点和终点的棋子
                    if (playNow[j].getX() < play.getX() && playNow[j].getX() > playTake.getX()) {
                        count++;
                        break;
                    }
                }
            }
        }

        //起点和终点之间要一个棋子是炮的规则（并不能吃自己的棋子）
        if (count == 1 && Chess == 0 && playTake.getName().charAt(1) != play.getName().charAt(1)) {
            playTake.setVisible(false);
            play.setBounds(playTake.getX(), playTake.getY(), 55, 55);

        } //起点和终点之间没有棋子是车的规则（并不能吃自己的棋子）			
        else if (count == 0 && Chess == 1 && playTake.getName().charAt(1) != play.getName().charAt(1)) {
            playTake.setVisible(false);
            play.setBounds(playTake.getX(), playTake.getY(), 55, 55);

        }

    }

    //馬移动规则
    public void HorseRule(JLabel play, JLabel playNow[], MouseEvent e) {
        int x = 0, y = 0, Move = 0;   //横坐标，纵坐标，障碍				
        //上移、左边
        if (play.getX() - e.getX() >= 2 && play.getX() - e.getX() <= 57 && play.getY() - e.getY() >= 87 && play.getY() - e.getY() <= 141) {
            //合法的Y坐标
            for (int i = 56; i <= 571; i += 57) {
                //移动的Y坐标是否有指定坐标相近的
                if (Math.abs(i - e.getY()) <= 27) {
                    y = i;
                    break;
                }
            }

            //合法的X坐标
            for (int i = 24; i <= 480; i += 57) {
                //移动的X坐标是否有指定坐标相近的
                if (i - e.getX() >= -55 && i - e.getX() <= 0) {
                    x = i;
                    break;
                }
            }

            //正前方是否有别的棋子
            for (int i = 0; i < 32; i++) {
                if (playNow[i].isVisible() && play.getX() - playNow[i].getX() == 0 && play.getY() - playNow[i].getY() == 57) {
                    Move = 1;
                    break;
                }
            }

            //可以移动该棋子
            if (Move == 0) {
                play.setBounds(x, y, 55, 55);

            }

        } //左移、上边
        else if (play.getY() - e.getY() >= 27 && play.getY() - e.getY() <= 86 && play.getX() - e.getX() >= 70 && play.getX() - e.getX() <= 130) {
            //合法的y坐标
            for (int i = 56; i <= 571; i += 57) {
                if (Math.abs(i - e.getY()) <= 27) {
                    y = i;
                }
            }

            //合法的坐标
            for (int i = 24; i <= 480; i += 57) {
                if (i - e.getX() >= -55 && i - e.getX() <= 0) {
                    x = i;
                }
            }

            //正左方是否有别的棋子
            for (int i = 0; i < 32; i++) {
                if (playNow[i].isVisible() && play.getY() - playNow[i].getY() == 0 && play.getX() - playNow[i].getX() == 57) {
                    Move = 1;
                    break;
                }
            }

            if (Move == 0) {

                play.setBounds(x, y, 55, 55);

            }
        } //下移、左边
        else if (e.getY() - play.getY() >= 87 && e.getY() - play.getY() <= 141 && play.getX() - e.getX() <= 87 && play.getX() - e.getX() >= 10) {
            //合法的Y坐标
            for (int i = 56; i <= 571; i += 57) {
                if (Math.abs(i - e.getY()) <= 27) {
                    y = i;
                    break;
                }
            }

            //合法的X坐标
            for (int i = 24; i <= 480; i += 57) {
                if (i - e.getX() >= -55 && i - e.getX() <= 0) {
                    x = i;
                    break;
                }
            }

            //正下方是否有别的棋子
            for (int i = 0; i < 32; i++) {
                if (playNow[i].isVisible() && play.getX() - playNow[i].getX() == 0 && play.getY() - playNow[i].getY() == 57) {
                    Move = 1;
                    break;
                }
            }

            //可以移动该棋子
            if (Move == 0) {

                play.setBounds(x, y, 55, 55);

            }
        } //左移、下边
        else if (e.getY() - play.getY() >= 30 && e.getY() - play.getY() <= 87 && play.getX() - e.getX() <= 141 && play.getX() - e.getX() >= 87) {
            //合法的y坐标		
            for (int i = 56; i <= 571; i += 57) {
                if (i - e.getY() >= -27 && i - e.getY() <= 27) {
                    y = i;
                }
            }

            //合法的x坐标
            for (int i = 24; i <= 480; i += 57) {
                if (i - e.getX() >= -55 && i - e.getX() <= 0) {
                    x = i;
                }
            }

            //正左方是否有别的棋子
            for (int i = 0; i < 32; i++) {
                if (playNow[i].isVisible() && play.getY() - playNow[i].getY() == 0 && play.getX() - playNow[i].getX() == 57) {
                    Move = 1;
                    break;
                }
            }

            if (Move == 0) {
                play.setBounds(x, y, 55, 55);

            }

        } //下移、右边
        else if (e.getY() - play.getY() >= 87 && e.getY() - play.getY() <= 141 && e.getX() - play.getX() <= 87 && e.getX() - play.getX() >= 2) {
            //合法的y坐标		
            for (int i = 56; i <= 571; i += 57) {
                if (Math.abs(i - e.getY()) <= 27) {
                    y = i;
                }
            }

            //合法的x坐标
            for (int i = 24; i <= 480; i += 57) {
                if (i - e.getX() >= -55 && i - e.getX() <= 0) {
                    x = i;
                }
            }

            //正下方是否有别的棋子
            for (int i = 0; i < 32; i++) {
                if (playNow[i].isVisible() && play.getX() - playNow[i].getX() == 0 && playNow[i].getY() - play.getY() == 57) {
                    Move = 1;
                    break;
                }
            }
            if (Move == 0) {

                play.setBounds(x, y, 55, 55);

            }
        } //右移、下边
        else if (e.getY() - play.getY() >= 30 && e.getY() - play.getY() <= 87 && e.getX() - play.getX() <= 141 && e.getX() - play.getX() >= 87) {
            //合法的y坐标
            for (int i = 56; i <= 571; i += 57) {
                if (i - e.getY() >= -27 && i - e.getY() <= 27) {
                    y = i;
                }
            }

            //合法的x坐标
            for (int i = 24; i <= 480; i += 57) {
                if (i - e.getX() >= -55 && i - e.getX() <= 0) {
                    x = i;
                }
            }

            //正右方是否有别的棋子
            for (int i = 0; i < 32; i++) {
                if (playNow[i].isVisible() && play.getY() - playNow[i].getY() == 0 && playNow[i].getX() - play.getX() == 57) {
                    Move = 1;
                    break;
                }
            }

            if (Move == 0) {

                play.setBounds(x, y, 55, 55);

            }
        } //上移、右边
        else if (play.getY() - e.getY() >= 87 && play.getY() - e.getY() <= 141 && e.getX() - play.getX() <= 87 && e.getX() - play.getX() >= 30) {
            //合法的Y坐标
            for (int i = 56; i <= 571; i += 57) {
                if (Math.abs(i - e.getY()) <= 27) {
                    y = i;
                    break;
                }
            }

            //合法的X坐标
            for (int i = 24; i <= 480; i += 57) {
                if (i - e.getX() >= -55 && i - e.getX() <= 0) {
                    x = i;
                    break;
                }
            }

            //正前方是否有别的棋子
            for (int i = 0; i < 32; i++) {
                if (playNow[i].isVisible() && play.getX() - playNow[i].getX() == 0 && play.getY() - playNow[i].getY() == 57) {
                    Move = 1;
                    break;
                }
            }

            //可以移动该棋子
            if (Move == 0) {

                play.setBounds(x, y, 55, 55);

            }
        } //右移、上边
        else if (play.getY() - e.getY() >= 30 && play.getY() - e.getY() <= 87 && e.getX() - play.getX() <= 141 && e.getX() - play.getX() >= 87) {
            //合法的y坐标	
            for (int i = 56; i <= 571; i += 57) {
                if (Math.abs(i - e.getY()) <= 27) {
                    y = i;
                }
            }

            //合法的x坐标
            for (int i = 24; i <= 480; i += 57) {
                if (i - e.getX() >= -55 && i - e.getX() <= 0) {
                    x = i;
                }
            }

            //正右方是否有别的棋子
            for (int i = 0; i < 32; i++) {
                if (playNow[i].isVisible() && play.getY() - playNow[i].getY() == 0 && playNow[i].getX() - play.getX() == 57) {
                    Move = 1;
                    break;
                }
            }

            if (Move == 0) {
                play.setBounds(x, y, 55, 55);

            }
        }

    }

    //馬吃棋规则
    public void HorseRule(JLabel play, JLabel playTake, JLabel playNow[], MouseEvent e) {
        //障碍
        int Move = 0;
        boolean Chess = false;
        //上移、左吃
        if (play.getName().charAt(1) != playTake.getName().charAt(1) && play.getX() - playTake.getX() == 57 && play.getY() - playTake.getY() == 114) {
            //正前方是否有别的棋子
            for (int i = 0; i < 32; i++) {
                if (playNow[i].isVisible() && play.getX() - playNow[i].getX() == 0 && play.getY() - playNow[i].getY() == 57) {
                    Move = 1;
                    break;
                }
            }

            Chess = true;

        } //上移、右吃
        else if (play.getY() - playTake.getY() == 114 && playTake.getX() - play.getX() == 57) {
            //正前方是否有别的棋子
            for (int i = 0; i < 32; i++) {
                if (playNow[i].isVisible() && play.getX() - playNow[i].getX() == 0 && play.getY() - playNow[i].getY() == 57) {
                    Move = 1;
                    break;
                }
            }

            Chess = true;

        } //左移、上吃
        else if (play.getY() - playTake.getY() == 57 && play.getX() - playTake.getX() == 114) {
            //正左方是否有别的棋子
            for (int i = 0; i < 32; i++) {
                if (playNow[i].isVisible() && play.getY() - playNow[i].getY() == 0 && play.getX() - playNow[i].getX() == 57) {
                    Move = 1;
                    break;
                }
            }

            Chess = true;

        } //左移、下吃
        else if (playTake.getY() - play.getY() == 57 && play.getX() - playTake.getX() == 114) {
            //正左方是否有别的棋子
            for (int i = 0; i < 32; i++) {
                if (playNow[i].isVisible() && play.getY() - playNow[i].getY() == 0 && play.getX() - playNow[i].getX() == 57) {
                    Move = 1;
                    break;
                }
            }

            Chess = true;

        } //右移、上吃
        else if (play.getY() - playTake.getY() == 57 && playTake.getX() - play.getX() == 114) {
            //正右方是否有别的棋子
            for (int i = 0; i < 32; i++) {
                if (playNow[i].isVisible() && play.getY() - playNow[i].getY() == 0 && playNow[i].getX() - play.getX() == 57) {
                    Move = 1;
                    break;
                }
            }

            Chess = true;

        } //右移、下吃
        else if (playTake.getY() - play.getY() == 57 && playTake.getX() - play.getX() == 114) {
            //正右方是否有别的棋子
            for (int i = 0; i < 32; i++) {
                if (playNow[i].isVisible() && play.getY() - playNow[i].getY() == 0 && playNow[i].getX() - play.getX() == 57) {
                    Move = 1;
                    break;
                }
            }

            Chess = true;

        }//else
        //下移、左吃
        else if (playTake.getY() - play.getY() == 114 && play.getX() - playTake.getX() == 57) {
            //正下方是否有别的棋子
            for (int i = 0; i < 32; i++) {
                if (playNow[i].isVisible() && play.getX() - playNow[i].getX() == 0 && play.getY() - playNow[i].getY() == -57) {
                    Move = 1;
                    break;

                }
            }

            Chess = true;

        } //下移、右吃
        else if (playTake.getY() - play.getY() == 114 && playTake.getX() - play.getX() == 57) {
            //正下方是否有别的棋子
            for (int i = 0; i < 32; i++) {
                if (playNow[i].isVisible() && play.getX() - playNow[i].getX() == 0 && play.getY() - playNow[i].getY() == -57) {
                    Move = 1;
                    break;
                }
            }

            Chess = true;

        }

        //没有障碍、并可以吃棋、不能吃自己颜色
        if (Chess && Move == 0 && playTake.getName().charAt(1) != play.getName().charAt(1)) {
            playTake.setVisible(false);
            play.setBounds(playTake.getX(), playTake.getY(), 55, 55);

        }
    }

    //相，象移动规则		
    public void ElephantRule(int now, JLabel play, JLabel playNow[], MouseEvent e) {
        //坐标和障碍
        int x = 0, y = 0, Move = 0;

        //上左
        if (play.getX() - e.getX() <= 141 && play.getX() - e.getX() >= 87 && play.getY() - e.getY() <= 141 && play.getY() - e.getY() >= 87) {
            //合法的Y坐标
            for (int i = 56; i <= 571; i += 57) {
                if (i - e.getY() >= -27 && i - e.getY() <= 27) {
                    y = i;
                    break;
                }
            }

            //合法的X坐标
            for (int i = 24; i <= 480; i += 57) {
                if (i - e.getX() >= -27 && i - e.getX() <= 27) {
                    x = i;
                    break;
                }
            }

            //左上方是否有棋子
            for (int i = 0; i < 32; i++) {
                if (playNow[i].isVisible() && play.getX() - playNow[i].getX() == 57 && play.getY() - playNow[i].getY() == 57) {
                    Move++;
                    break;
                }
            }

            //红棋不能过楚河
            if (Move == 0 && y >= 341 && now > 19) {
                play.setBounds(x, y, 55, 55);

            } //黑棋不能过汉界
            else if (Move == 0 && y <= 284 && now < 7) {

                play.setBounds(x, y, 55, 55);

            }
        } //上右
        else if (play.getY() - e.getY() <= 141 && play.getY() - e.getY() >= 87 && e.getX() - play.getX() >= 87 && e.getX() - play.getX() <= 141) {
            //合法的Y坐标
            for (int i = 56; i <= 571; i += 57) {
                if (i - e.getY() >= -27 && i - e.getY() <= 27) {
                    y = i;
                    break;
                }
            }

            //合法的X坐标
            for (int i = 24; i <= 480; i += 57) {
                if (i - e.getX() >= -27 && i - e.getX() <= 27) {
                    x = i;
                    break;
                }
            }

            //右上方是否有棋子
            for (int i = 0; i < 32; i++) {
                if (playNow[i].isVisible() && playNow[i].getX() - play.getX() == 57 && play.getY() - playNow[i].getY() == 57) {
                    Move++;
                    break;
                }
            }

            if (Move == 0 && y >= 341 && now > 19) {

                play.setBounds(x, y, 55, 55);

            } else if (Move == 0 && y <= 284 && now < 7) {

                play.setBounds(x, y, 55, 55);

            }

        } //下左
        else if (play.getX() - e.getX() <= 141 && play.getX() - e.getX() >= 87 && e.getY() - play.getY() <= 141 && e.getY() - play.getY() >= 87) {
            //合法的Y坐标
            for (int i = 56; i <= 571; i += 57) {
                if (i - e.getY() >= -27 && i - e.getY() <= 27) {
                    y = i;
                    break;
                }
            }

            //合法的X坐标
            for (int i = 24; i <= 480; i += 57) {
                if (i - e.getX() >= -27 && i - e.getX() <= 27) {
                    x = i;
                    break;
                }
            }

            //下左方是否有棋子
            for (int i = 0; i < 32; i++) {
                if (playNow[i].isVisible() && play.getX() - playNow[i].getX() == 57 && play.getY() - playNow[i].getY() == -57) {
                    Move++;
                    break;
                }
            }

            if (Move == 0 && y >= 341 && now > 19) {

                play.setBounds(x, y, 55, 55);

            } else if (Move == 0 && y <= 284 && now < 7) {

                play.setBounds(x, y, 55, 55);

            }
        } //下右
        else if (e.getX() - play.getX() >= 87 && e.getX() - play.getX() <= 141 && e.getY() - play.getY() >= 87 && e.getY() - play.getY() <= 141) {
            //合法的y坐标		
            for (int i = 56; i <= 571; i += 57) {
                if (i - e.getY() >= -27 && i - e.getY() <= 27) {
                    y = i;
                }
            }

            //合法的x坐标
            for (int i = 24; i <= 480; i += 57) {
                if (i - e.getX() >= -27 && i - e.getX() <= 27) {
                    x = i;
                }
            }

            //下右方是否有棋子
            for (int i = 0; i < 32; i++) {
                if (playNow[i].isVisible() && playNow[i].getX() - play.getX() == 57 && playNow[i].getY() - play.getY() == 57) {
                    Move = 1;
                    break;
                }
            }

            if (Move == 0 && y >= 341 && now > 19) {

                play.setBounds(x, y, 55, 55);

            } else if (Move == 0 && y <= 284 && now < 7) {

                play.setBounds(x, y, 55, 55);

            }

        }

    }

    //相，象吃棋规则
    public void ElephantRule(JLabel play, JLabel playTake, JLabel playNow[]) {
        //障碍
        int move = 0;
        boolean Chess = false;

        //吃左上方的棋子
        if (play.getX() - playTake.getX() >= 87 && play.getX() - playTake.getX() <= 141 && play.getY() - playTake.getY() >= 87 && play.getY() - playTake.getY() <= 141) {
            //左上方是否有棋子
            for (int i = 0; i < 32; i++) {
                if (playNow[i].isVisible() && play.getX() - playNow[i].getX() == 57 && play.getY() - playNow[i].getY() == 57) {
                    move++;
                    break;
                }
            }
            Chess = true;

        } //吃右上方的棋子
        else if (playTake.getX() - play.getX() >= 87 && playTake.getX() - play.getX() <= 141 && play.getY() - playTake.getY() >= 87 && play.getY() - playTake.getY() <= 141) {
            //右上方是否有棋子
            for (int i = 0; i < 32; i++) {
                if (playNow[i].isVisible() && playNow[i].getX() - play.getX() == 57 && play.getY() - playNow[i].getY() == 57) {
                    move++;
                    break;
                }
            }

            Chess = true;
        } //吃下左方的棋子
        else if (play.getX() - playTake.getX() >= 87 && play.getX() - playTake.getX() <= 141 && playTake.getY() - play.getY() >= 87 && playTake.getY() - play.getY() <= 141) {
            //下左方是否有棋子
            for (int i = 0; i < 32; i++) {
                if (playNow[i].isVisible() && play.getX() - playNow[i].getX() == 57 && play.getY() - playNow[i].getY() == -57) {
                    move++;
                    break;
                }
            }

            Chess = true;
        } //吃下右方的棋子
        else if (playTake.getX() - play.getX() >= 87 && playTake.getX() - play.getX() <= 141 && playTake.getY() - play.getY() >= 87 && playTake.getY() - play.getY() <= 141) {
            //下右方是否有棋子
            for (int i = 0; i < 32; i++) {
                if (playNow[i].isVisible() && playNow[i].getX() - play.getX() == 57 && playNow[i].getY() - play.getY() == 57) {
                    move = 1;
                    break;
                }
            }

            Chess = true;

        }//else

        //没有障碍(不能吃自己的棋子)
        if (Chess && move == 0 && playTake.getName().charAt(1) != play.getName().charAt(1)) {
            if ((playTake.getY() >= 341 && play.getName().charAt(1) == 'r') || (playTake.getY() <= 284 && play.getName().charAt(1) == 'b')) {

                playTake.setVisible(false);
                play.setBounds(playTake.getX(), playTake.getY(), 55, 55);

            }
        }

    }

    //仕，士移动规则
    public void ShiRule(int now, JLabel play, JLabel playNow[], MouseEvent e) {
        //上、右
        if (e.getX() - play.getX() >= 29 && e.getX() - play.getX() <= 114 && play.getY() - e.getY() >= 25 && play.getY() - e.getY() <= 90) {
            //士不能超过自己的界限
            if (now < 9 && (play.getX() + 57) >= 195 && (play.getX() + 57) <= 309 && (play.getY() - 57) <= 170) {

                play.setBounds(play.getX() + 57, play.getY() - 57, 55, 55);

            } //仕不能超过自己的界限
            else if (now > 21 && (play.getY() - 57) >= 455 && (play.getX() + 57) >= 195 && (play.getX() + 57) <= 309) {

                play.setBounds(play.getX() + 57, play.getY() - 57, 55, 55);

            }
        } //上、左
        else if (play.getX() - e.getX() <= 114 && play.getX() - e.getX() >= 25 && play.getY() - e.getY() >= 20 && play.getY() - e.getY() <= 95) {
            //士不能超过自己的界限
            if (now < 9 && (play.getX() - 57) >= 195 && (play.getX() - 57) <= 309 && (play.getY() - 57) <= 170) {
                play.setBounds(play.getX() - 57, play.getY() - 57, 55, 55);

            } //仕不能超过自己的界限
            else if (now > 21 && (play.getY() - 57) >= 455 && (play.getX() - 57) >= 195 && (play.getX() - 57) <= 309) {

                play.setBounds(play.getX() - 57, play.getY() - 57, 55, 55);

            }
        } //下、左
        else if (play.getX() - e.getX() <= 114 && play.getX() - e.getX() >= 20 && e.getY() - play.getY() >= 2 && e.getY() - play.getY() <= 87) {
            //士不能超过自己的界限
            if (now < 9 && (play.getX() - 57) >= 195 && (play.getX() - 57) <= 309 && (play.getY() + 57) <= 170) {

                play.setBounds(play.getX() - 57, play.getY() + 57, 55, 55);

            } //仕不能超过自己的界限
            else if (now > 21 && (play.getY() + 57) >= 455 && (play.getX() - 57) >= 195 && (play.getX() - 57) <= 309) {

                play.setBounds(play.getX() - 57, play.getY() + 57, 55, 55);

            }

        } //下、右
        else if (e.getX() - play.getX() >= 27 && e.getX() - play.getX() <= 114 && e.getY() - play.getY() >= 2 && e.getY() - play.getY() <= 87) {
            //士不能超过自己的界限
            if (now < 9 && (play.getX() + 57) >= 195 && (play.getX() + 57) <= 309 && (play.getY() + 57) <= 170) {
                play.setBounds(play.getX() + 57, play.getY() + 57, 55, 55);

            } //仕不能超过自己的界限
            else if (now > 21 && (play.getY() + 57) >= 455 && (play.getX() + 57) >= 195 && (play.getX() + 57) <= 309) {
                play.setBounds(play.getX() + 57, play.getY() + 57, 55, 55);

            }
        }

    }

    //仕,士吃棋规则
    public void ShiRule(int now, JLabel play, JLabel playTake, JLabel playNow[]) {
        //当前状态
        boolean Chap = false;

        //上、右
        if (playTake.getX() - play.getX() >= 20 && playTake.getX() - play.getX() <= 114 && play.getY() - playTake.getY() >= 2 && play.getY() - playTake.getY() <= 87) {
            //被吃的棋子是否和当前士相近
            if (now < 9 && playTake.getX() >= 195 && playTake.getX() <= 309 && playTake.getY() <= 170 && playTake.isVisible()) {
                Chap = true;
            } //被吃的棋子是否和当前仕相近
            else if (now > 21 && playTake.getX() >= 195 && playTake.getX() <= 309 && playTake.getY() >= 455 && playTake.isVisible()) {
                Chap = true;
            }
        } //上、左
        else if (play.getX() - playTake.getX() <= 114 && play.getX() - playTake.getX() >= 25 && play.getY() - playTake.getY() >= 2 && play.getY() - playTake.getY() <= 87) {
            //被吃的棋子是否和当前士相近
            if (now < 9 && playTake.getX() >= 195 && playTake.getX() <= 309 && playTake.getY() <= 170 && playTake.isVisible()) {
                Chap = true;
            } //被吃的棋子是否和当前仕相近
            else if (now > 21 && playTake.getX() >= 195 && playTake.getX() <= 309 && playTake.getY() >= 455 && playTake.isVisible()) {
                Chap = true;
            }
        } //下、左
        else if (play.getX() - playTake.getX() <= 114 && play.getX() - playTake.getX() >= 25 && playTake.getY() - play.getY() >= 2 && playTake.getY() - play.getY() <= 87) {
            //被吃的棋子是否和当前士相近
            if (now < 9 && playTake.getX() >= 195 && playTake.getX() <= 309 && playTake.getY() <= 170 && playTake.isVisible()) {
                Chap = true;
            } //被吃的棋子是否和当前仕相近
            else if (now > 21 && playTake.getX() >= 195 && playTake.getX() <= 309 && playTake.getY() >= 455 && playTake.isVisible()) {
                Chap = true;
            }
        } //下、右
        else if (playTake.getX() - play.getX() >= 25 && playTake.getX() - play.getX() <= 114 && playTake.getY() - play.getY() >= 2 && playTake.getY() - play.getY() <= 87) {
            //被吃的棋子是否和当前士相近
            if (now < 9 && playTake.getX() >= 195 && playTake.getX() <= 309 && playTake.getY() <= 170 && playTake.isVisible()) {
                Chap = true;
            } //被吃的棋子是否和当前仕相近
            else if (now > 21 && playTake.getX() >= 195 && playTake.getX() <= 309 && playTake.getY() >= 455 && playTake.isVisible()) {
                Chap = true;
            }
        }

        //可移动、并不能吃自己的棋子
        if (Chap && playTake.getName().charAt(1) != play.getName().charAt(1)) {
            playTake.setVisible(false);
            play.setBounds(playTake.getX(), playTake.getY(), 55, 55);

        }

    }

    //将，帅移动规则
    public void CoreRule(int now, JLabel play, JLabel playNow[], MouseEvent e) {
        //向上
        if ((e.getX() - play.getX()) >= 0 && (e.getX() - play.getX()) <= 55 && (play.getY() - e.getY()) >= 2 && play.getY() - e.getY() <= 87) {
            //将不能超过自己的界限
            if (now == 15 && e.getX() >= 195 && e.getX() <= 359 && e.getY() <= 170) {

                play.setBounds(play.getX(), play.getY() - 57, 55, 55);

            } //帅不能超过自己的界限
            else if (now == 31 && e.getY() >= 455 && e.getX() >= 195 && e.getX() <= 359) {

                play.setBounds(play.getX(), play.getY() - 57, 55, 55);

            }
        } //向左
        else if (play.getX() - e.getX() >= 2 && play.getX() - e.getX() <= 57 && e.getY() - play.getY() <= 27 && e.getY() - play.getY() >= -27) {
            //将不能够超过自己的界限
            if (now == 15 && e.getX() >= 195 && e.getX() <= 359 && e.getY() <= 170) {
                play.setBounds(play.getX() - 57, play.getY(), 55, 55);

            } //帅不能超过自己的界限
            else if (now == 31 && e.getY() >= 455 && e.getX() >= 195 && e.getX() <= 359) {
                play.setBounds(play.getX() - 57, play.getY(), 55, 55);

            }
        } //向右
        else if (e.getX() - play.getX() >= 57 && e.getX() - play.getX() <= 112 && e.getY() - play.getY() <= 27 && e.getY() - play.getY() >= -27) {

            if (now == 15 && e.getX() >= 195 && e.getX() <= 359 && e.getY() <= 170) {

                play.setBounds(play.getX() + 57, play.getY(), 55, 55);

            } else if (now == 31 && e.getY() >= 455 && e.getX() >= 195 && e.getX() <= 359) {
                play.setBounds(play.getX() + 57, play.getY(), 55, 55);

            }
        } //向下
        else if (e.getX() - play.getX() >= 0 && e.getX() - play.getX() <= 55 && e.getY() - play.getY() <= 87 && e.getY() - play.getY() >= 27) {

            if (now == 15 && e.getX() >= 195 && e.getX() <= 359 && e.getY() <= 170) {

                play.setBounds(play.getX(), play.getY() + 57, 55, 55);

            } else if (now == 31 && e.getY() >= 455 && e.getX() >= 195 && e.getX() <= 359) {

                play.setBounds(play.getX(), play.getY() + 57, 55, 55);

            }

        }

    }

    //将，帅吃棋规则
    public void CoreRule(int now, JLabel play, JLabel playTake, JLabel playNow[]) {
        //当前状态
        boolean will = false;
        int count = 0;      //对将时使用用
        //向上吃
        if (play.getX() - playTake.getX() >= 0 && play.getX() - playTake.getX() <= 55 && play.getY() - playTake.getY() >= 27 && play.getY() - playTake.getY() <= 87 && playTake.isVisible()) {
            //被吃的棋子是否和当前将相近
            if (now == 15 && playTake.getX() >= 195 && playTake.getX() <= 309 && playTake.getY() <= 170) {
                will = true;
            } //被吃的棋子是否和当前帅相近
            else if (now == 31 && playTake.getY() >= 455 && playTake.getX() >= 195 && playTake.getX() <= 309) {
                will = true;
            }
        } //向左吃
        else if (play.getX() - playTake.getX() >= 2 && play.getX() - playTake.getX() <= 57 && playTake.getY() - play.getY() <= 27 && playTake.getY() - play.getY() >= -27 && playTake.isVisible()) {
            //被吃的棋子是否和当前将相近
            if (now == 15 && playTake.getX() >= 195 && playTake.getX() <= 309 && playTake.getY() <= 170) {
                will = true;
            } //被吃的棋子是否和当前帅相近
            else if (now == 31 && playTake.getY() >= 455 && playTake.getX() >= 195 && playTake.getX() <= 309) {
                will = true;
            }
        } //向右吃
        else if (playTake.getX() - play.getX() >= 2 && playTake.getX() - play.getX() <= 57 && playTake.getY() - play.getY() <= 27 && playTake.getY() - play.getY() >= -27 && playTake.isVisible()) {
            //被吃的棋子是否和当前将相近
            if (now == 15 && playTake.getX() >= 195 && playTake.getX() <= 309 && playTake.getY() <= 170) {
                will = true;
            } //被吃的棋子是否和当前帅相近
            else if (now == 31 && playTake.getY() >= 455 && playTake.getX() >= 195 && playTake.getX() <= 309) {
                will = true;
            }
        } //向下吃
        else if (playTake.getX() - play.getX() >= 0 && playTake.getX() - play.getX() <= 87 && playTake.getY() - play.getY() <= 27 && playTake.getY() - play.getY() >= 40 && playTake.isVisible()) {
            //被吃的棋子是否和当前将相近
            if (now == 15 && playTake.getX() >= 195 && playTake.getX() <= 309 && playTake.getY() <= 170) {
                will = true;
            } //被吃的棋子是否和当前帅相近
            else if (now == 31 && playTake.getY() >= 455 && playTake.getX() >= 195 && playTake.getX() <= 309) {
                will = true;
            }
        }
        if (playTake.getX() - play.getX() == 0) {
            for (int j = 0; j < 32; j++) {           //所有的棋子                    
                if (Math.abs(playNow[j].getX() - play.getX()) <= 27 && playNow[j].getName() != play.getName() && playNow[j].isVisible()) {  //在竖坐标上找出自己外的其他棋子                     
                    for (int k = play.getY() + 57; k < playTake.getY(); k += 57) {          //从起点到终点（从上到下）                               
                        if (playNow[j].getY() < playTake.getY() && playNow[j].getY() > play.getY()) {       //大于起点、小于终点的坐标判断是否有棋子
                            count++;            //中间有棋子就不可以从这条竖线过去
                            break;
                        }
                    }
                    //从起点到终点(从下到上)
                    for (int k = playTake.getY() + 57; k < play.getY(); k += 57) {
                        //找起点和终点的棋子
                        if (playNow[j].getY() < play.getY() && playNow[j].getY() > playTake.getY()) {
                            count++;
                            break;
                        }
                    }
                }
            }
            if (count == 0) {
                will = true;
            }

        }
        //不能吃自己的棋子、符合当前要求	
        if (playTake.getName().charAt(1) != play.getName().charAt(1) && will) {
            playTake.setVisible(false);
            play.setBounds(playTake.getX(), playTake.getY(), 55, 55);

        }

    }   //将、帅吃规则结束
}
