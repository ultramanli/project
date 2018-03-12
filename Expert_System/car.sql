/*
Navicat MySQL Data Transfer

Source Server         : lyh
Source Server Version : 50622
Source Host           : localhost:3306
Source Database       : test

Target Server Type    : MYSQL
Target Server Version : 50622
File Encoding         : 65001

Date: 2018-03-12 18:45:24
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `car`
-- ----------------------------
DROP TABLE IF EXISTS `car`;
CREATE TABLE `car` (
  `id` int(255) NOT NULL DEFAULT '0',
  `car` varchar(50) CHARACTER SET utf8 DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of car
-- ----------------------------
INSERT INTO `car` VALUES ('1', '法拉利Enzo');
INSERT INTO `car` VALUES ('2', '法拉利FF');
INSERT INTO `car` VALUES ('3', '法拉利F12');
INSERT INTO `car` VALUES ('4', '法拉利488');
INSERT INTO `car` VALUES ('5', '兰博基尼Huracan');
INSERT INTO `car` VALUES ('6', '兰博基尼Aventador');
INSERT INTO `car` VALUES ('7', '兰博基尼Gallardo');
INSERT INTO `car` VALUES ('8', '兰博基尼Urus');
INSERT INTO `car` VALUES ('9', '保时捷911');
INSERT INTO `car` VALUES ('10', '保时捷918');
INSERT INTO `car` VALUES ('11', '保时捷Cayenne');
INSERT INTO `car` VALUES ('12', '保时捷Panamera');
INSERT INTO `car` VALUES ('13', '奥迪R8');
INSERT INTO `car` VALUES ('14', '奥迪TT');
INSERT INTO `car` VALUES ('15', '奥迪A8');
INSERT INTO `car` VALUES ('16', '奥迪Q7');
INSERT INTO `car` VALUES ('17', '迈凯伦P1');
INSERT INTO `car` VALUES ('18', '迈凯伦F1');
INSERT INTO `car` VALUES ('19', '迈凯伦MP4');
INSERT INTO `car` VALUES ('20', '迈凯伦12C');
INSERT INTO `car` VALUES ('21', '布加迪Chiron');
INSERT INTO `car` VALUES ('22', '布加迪Veyron');
INSERT INTO `car` VALUES ('23', '柯尼塞格One');
INSERT INTO `car` VALUES ('24', '柯尼塞格Agera');

-- ----------------------------
-- Table structure for `feature`
-- ----------------------------
DROP TABLE IF EXISTS `feature`;
CREATE TABLE `feature` (
  `id` int(255) NOT NULL,
  `feature` varchar(50) CHARACTER SET utf8 DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of feature
-- ----------------------------
INSERT INTO `feature` VALUES ('1', '意大利');
INSERT INTO `feature` VALUES ('2', '英国');
INSERT INTO `feature` VALUES ('3', '德国');
INSERT INTO `feature` VALUES ('4', '瑞典');
INSERT INTO `feature` VALUES ('5', '跑车');
INSERT INTO `feature` VALUES ('6', '越野车');
INSERT INTO `feature` VALUES ('7', '红色特点');
INSERT INTO `feature` VALUES ('8', '黄色特点');
INSERT INTO `feature` VALUES ('9', '蛙眼灯特点');
INSERT INTO `feature` VALUES ('10', '最快的车');
INSERT INTO `feature` VALUES ('11', '超级跑车');
INSERT INTO `feature` VALUES ('12', '2.0T');
INSERT INTO `feature` VALUES ('13', '3.0T');
INSERT INTO `feature` VALUES ('14', '4.0T');
INSERT INTO `feature` VALUES ('15', '5.0T');

-- ----------------------------
-- Table structure for `result`
-- ----------------------------
DROP TABLE IF EXISTS `result`;
CREATE TABLE `result` (
  `id` int(255) NOT NULL,
  `car` varchar(50) CHARACTER SET utf8 NOT NULL,
  `result` varchar(1000) CHARACTER SET utf8 NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of result
-- ----------------------------
INSERT INTO `result` VALUES ('1', '法拉利Enzo', '  法拉利Enzo是历史上的一款传奇车型，以公司创始人的名字Enzo Ferrari（恩佐法拉利）命名,国内则一般称其为法拉利Enzo。作为法拉利F50的替代品，Enzo于2002年制造，采用12缸中置引擎，售价为60万美元');
INSERT INTO `result` VALUES ('2', '法拉利FF', '  在2011年1月，法拉利官方网站公布了新款法拉利FF的首批照片，这是法拉利推出的性能最强、功能最全的四座跑车，也是法拉利历史上第一款四轮驱动跑车。法拉利FF由宾尼法利纳（Pininfarina）设计，在2011年3月1日举行的日内瓦车展上正式首发亮相。FF是英文Ferrari Four（四座和四轮驱动）的缩写，这款新车带来了全新的GT跑车概念，标志着对原有理念的颠覆性突破，它不是一次升级换代，而是一次真正的创新。');
INSERT INTO `result` VALUES ('3', '法拉利F12', '  法拉利F12 Berlinetta是新一代的V12动力车款，原装配备米其林Pilot Super Sport。[1]  车头设计将与FF系出同门，经由在风洞中精雕细琢的车身造型，创造出风阻仅0.299的c/d值，车身尺寸为4618×1942×1273mm，采用以20种复合材质制造的铝合金车体框架，并藉由镭射焊接技术，让车体误差值接近完美，车体大量运用碳纤维材质组件，以完美达到兼顾轻量化与车身强度的要求，也让车重成功压低至仅1525kg的程度，而通过前中置发动机的配置，也达到了前46：后54完美配重。');
INSERT INTO `result` VALUES ('4', '法拉利488', '  法拉利488是法拉利旗下的一款超级跑车，采用了3.9升V8双涡轮发动机，满足高速运动的需要。当488GTB带着这台3.9升V8双涡轮发动机问世，宣告的其实是涡轮增压车型的全面回归——除了多少有些试水成分的CaliforniaT之外，在30年前那台被无数人奉若神明的F40搭载的可也是一台V8双涡轮发动机。');
INSERT INTO `result` VALUES ('5', '兰博基尼Huracan', '  “兰博基尼Huracan”是兰博基尼的一种型号。2013年底，兰博基尼官方正式公布了全新车型Huracan LP610-4车型的官方指导价，其售价为429.088万元人民币。Huracan的名字在西班牙语中直译为“飓风”，外观方面，Huracan的设计与此前发布的Sesto Elemento概念车相同具有很强的相似性，设计上也秉承了兰博基尼一贯的攻击性，特别是其尾部还启用了全LED尾灯。据悉，经过轻量化的设计，这款新车将会采用碳纤维材质来进一步降低车身重量。');
INSERT INTO `result` VALUES ('6', '兰博基尼Aventador', '  Aventador LP700-4是兰博基尼旗下的一款旗舰超级跑车，作为Murcielago的换代车型，在2011年日内瓦车展上正式亮相。低矮的车身、剪刀门、遍布车身四周的巨大进气口以及玻璃下一览无余的V12发动机，依旧是为人熟知的兰博基尼风格。兰博基尼的传统是用斗牛的名字来命名新车，该款旗舰车型的名字Aventador（埃文塔多）同样来源于一头公牛，并且是西班牙斗牛界最勇猛的斗牛之一。该车敞篷版本于2013年2月进入中国，售738.88万元。此后，兰博基尼又陆续发布了Aventador LP720-4的硬顶版及敞篷版车型。这是继兰博基尼雷文顿Reventon以来兰博基尼公司的又一部新一代旗舰车型。');
INSERT INTO `result` VALUES ('7', '兰博基尼Gallardo', '#假装有介绍#');
INSERT INTO `result` VALUES ('8', '兰博基尼Urus', '#假装有介绍#');
INSERT INTO `result` VALUES ('9', '保时捷911', '#假装有介绍#');
INSERT INTO `result` VALUES ('10', '保时捷918', '#假装有介绍#');
INSERT INTO `result` VALUES ('11', '保时捷Cayenne', '#假装有介绍#');
INSERT INTO `result` VALUES ('12', '保时捷Panamera', '#假装有介绍#');
INSERT INTO `result` VALUES ('13', '奥迪R8', '#假装有介绍#');
INSERT INTO `result` VALUES ('14', '奥迪TT', '#假装有介绍#');
INSERT INTO `result` VALUES ('15', '奥迪A8', '#假装有介绍#');
INSERT INTO `result` VALUES ('16', '奥迪Q7', '#假装有介绍#');
INSERT INTO `result` VALUES ('17', '迈凯伦P1', '  迈凯轮P1是一款拥有超过900匹马力，百公里加速仅耗时2.8秒，极速被电脑限定350km/h，未限速极速380km/h以上的超级跑车。该车将搭载3.8L V8发动机，最大功率737马力，通过在F1赛车上已经应用的KERS动能回收系统，还可以获得179马力的额外功率。迈凯轮P1概念跑车已经在2012年9月末的巴黎车展全球首发');
INSERT INTO `result` VALUES ('18', '迈凯伦F1', '  迈凯伦F1是1992年由迈凯伦工程师结合了大量的F1赛车技术打造的一款跑车，所以其F1的名字也由此而来，可以说它是一台地地道道的街道[1]  F1。迈凯伦F1能在3.2秒内从静止加速到100km/h，极速突破380km/h。它曾经是世界上跑的最快的量产跑车，这个纪录从它1994年进入批量生产一直保持到2005年停产。直到2005年，科尼赛克CCR终止了Mclaren F1全球最速量产跑车的纪录');
INSERT INTO `result` VALUES ('19', '迈凯伦MP4', '  迈凯轮MP4-12C是一款迈凯轮F1赛车，继承了一级方程式赛车的血统，不管是直线加速能力还是赛道能力都极为强悍，MP4-12C使用迈凯轮一体式碳纤维座舱这项技术直接移植。迈凯轮MP4-12C可谓是“低调的幽灵”经国外媒体测试，当前同级别超级跑车，以加速能力来说，没有任何一台超级跑车可以超越迈凯轮MP4-12C');
INSERT INTO `result` VALUES ('20', '迈凯伦12C', '  迈凯轮MP4-12C是一款迈凯轮F1赛车，继承了一级方程式赛车的血统，不管是直线加速能力还是赛道能力都极为强悍，MP4-12C使用迈凯轮一体式碳纤维座舱这项技术直接移植。迈凯轮MP4-12C可谓是“低调的幽灵”经国外媒体测试，当前同级别超级跑车，以加速能力来说，没有任何一台超级跑车可以超越迈凯轮MP4-12C');
INSERT INTO `result` VALUES ('21', '布加迪Chiron', '#假装有介绍#');
INSERT INTO `result` VALUES ('22', '布加迪Veyron', '#假装有介绍#');
INSERT INTO `result` VALUES ('23', '柯尼塞格One', '#假装有介绍#');
INSERT INTO `result` VALUES ('24', '柯尼塞格Agera', '#假装有介绍#');

-- ----------------------------
-- Table structure for `rules`
-- ----------------------------
DROP TABLE IF EXISTS `rules`;
CREATE TABLE `rules` (
  `rule` varchar(50) CHARACTER SET utf8 NOT NULL,
  `rear` varchar(50) CHARACTER SET utf8 NOT NULL,
  `id` int(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of rules
-- ----------------------------
INSERT INTO `rules` VALUES ('意大利 跑车 红色特点 2.0T', '法拉利Enzo', '1');
INSERT INTO `rules` VALUES ('意大利 跑车 红色特点 3.0T', '法拉利FF', '2');
INSERT INTO `rules` VALUES ('意大利 跑车 红色特点 4.0T', '法拉利F12', '3');
INSERT INTO `rules` VALUES ('意大利 跑车 红色特点 5.0T', '法拉利488', '4');
INSERT INTO `rules` VALUES ('意大利 跑车 黄色特点 2.0T', '兰博基尼Huracan', '5');
INSERT INTO `rules` VALUES ('意大利 跑车 黄色特点 3.0T', '兰博基尼Aventador', '6');
INSERT INTO `rules` VALUES ('意大利 跑车 黄色特点 4.0T', '兰博基尼Gallardo', '7');
INSERT INTO `rules` VALUES ('意大利 跑车 黄色特点 5.0T', '兰博基尼Urus', '8');
INSERT INTO `rules` VALUES ('意大利 跑车 最快的车 4.0T', '布加迪Chiron', '9');
INSERT INTO `rules` VALUES ('意大利 跑车 最快的车 5.0T', '布加迪Veyron', '10');
INSERT INTO `rules` VALUES ('德国 跑车 蛙眼灯特点 2.0T', '保时捷911', '11');
INSERT INTO `rules` VALUES ('德国 跑车 蛙眼灯特点 3.0T', '保时捷918', '12');
INSERT INTO `rules` VALUES ('德国 跑车 蛙眼灯特点 4.0T', '保时捷Panamera', '13');
INSERT INTO `rules` VALUES ('奥迪 跑车 超级跑车 5.0T', '奥迪R8', '14');
INSERT INTO `rules` VALUES ('德国 越野车 蛙眼灯特点 4.0T', '保时捷Cayenne', '15');
INSERT INTO `rules` VALUES ('瑞典 跑车 最快的车 4.0T', '柯尼塞格Agera', '16');
INSERT INTO `rules` VALUES ('瑞典 跑车 最快的车 5.0T', '柯尼塞格One', '17');
INSERT INTO `rules` VALUES ('奥迪 跑车 2.0T', '奥迪TT', '18');
INSERT INTO `rules` VALUES ('德国 越野车 3.0T', '奥迪Q7', '19');
INSERT INTO `rules` VALUES ('英国 跑车 2.0T', '迈凯伦P1', '20');
INSERT INTO `rules` VALUES ('英国 跑车 3.0T', '迈凯伦F1', '21');
INSERT INTO `rules` VALUES ('英国 跑车 4.0T', '迈凯伦MP4', '22');
INSERT INTO `rules` VALUES ('英国 跑车 5.0T', '迈凯伦12C', '23');
INSERT INTO `rules` VALUES ('意大利 跑车', '法拉利', '24');
INSERT INTO `rules` VALUES ('意大利 跑车', '兰博基尼', '25');
INSERT INTO `rules` VALUES ('意大利 跑车', '布加迪', '26');
INSERT INTO `rules` VALUES ('意大利 越野车', '兰博基尼', '27');
INSERT INTO `rules` VALUES ('法拉利 2.0T', '法拉利Enzo', '28');
INSERT INTO `rules` VALUES ('法拉利 3.0T', '法拉利FF', '29');
INSERT INTO `rules` VALUES ('法拉利 4.0T', '法拉利F12', '30');
INSERT INTO `rules` VALUES ('法拉利 5.0T', '法拉利488', '31');
INSERT INTO `rules` VALUES ('英国 跑车', '迈凯伦', '32');
INSERT INTO `rules` VALUES ('德国 跑车', '保时捷', '33');
INSERT INTO `rules` VALUES ('德国 跑车', '奥迪', '34');
INSERT INTO `rules` VALUES ('德国 越野车', '奥迪', '35');
INSERT INTO `rules` VALUES ('德国 越野车', '保时捷', '36');
INSERT INTO `rules` VALUES ('意大利', '法拉利', '37');
INSERT INTO `rules` VALUES ('意大利', '兰博基尼', '38');
INSERT INTO `rules` VALUES ('意大利', '布加迪', '39');
INSERT INTO `rules` VALUES ('德国', '保时捷', '40');
INSERT INTO `rules` VALUES ('德国', '奥迪', '41');
INSERT INTO `rules` VALUES ('英国', '迈凯伦', '42');
INSERT INTO `rules` VALUES ('瑞典', '柯尼塞格', '43');
INSERT INTO `rules` VALUES ('法拉利', '2.0T', '44');
INSERT INTO `rules` VALUES ('法拉利', '3.0T', '45');
INSERT INTO `rules` VALUES ('法拉利', '4.0T', '46');
INSERT INTO `rules` VALUES ('法拉利', '5.0T', '47');
INSERT INTO `rules` VALUES ('兰博基尼', '2.0T', '48');
INSERT INTO `rules` VALUES ('兰博基尼', '3.0T', '49');
INSERT INTO `rules` VALUES ('兰博基尼', '4.0T', '50');
INSERT INTO `rules` VALUES ('兰博基尼', '5.0T', '51');
INSERT INTO `rules` VALUES ('保时捷', '2.0T', '52');
INSERT INTO `rules` VALUES ('保时捷', '3.0T', '53');
INSERT INTO `rules` VALUES ('保时捷', '4.0T', '54');
INSERT INTO `rules` VALUES ('保时捷', '5.0T', '55');
INSERT INTO `rules` VALUES ('奥迪', '2.0T', '56');
INSERT INTO `rules` VALUES ('奥迪', '3.0T', '57');
INSERT INTO `rules` VALUES ('奥迪', '4.0T', '58');
INSERT INTO `rules` VALUES ('奥迪', '5.0T', '59');
INSERT INTO `rules` VALUES ('迈凯伦', '2.0T', '60');
INSERT INTO `rules` VALUES ('迈凯伦', '3.0T', '61');
INSERT INTO `rules` VALUES ('迈凯伦', '4.0T', '62');
INSERT INTO `rules` VALUES ('迈凯伦', '5.0T', '63');
INSERT INTO `rules` VALUES ('布加迪', '4.0T', '64');
INSERT INTO `rules` VALUES ('布加迪', '5.0T', '65');
INSERT INTO `rules` VALUES ('柯尼塞格', '4.0T', '66');
INSERT INTO `rules` VALUES ('柯尼塞格', '5.0T', '67');
INSERT INTO `rules` VALUES ('2.0T', '法拉利Enzo', '68');
INSERT INTO `rules` VALUES ('3.0T', '法拉利FF', '69');
INSERT INTO `rules` VALUES ('4.0T', '法拉利F12', '70');
INSERT INTO `rules` VALUES ('5.0T', '法拉利488', '71');
INSERT INTO `rules` VALUES ('2.0T', '兰博基尼Huracan', '72');
INSERT INTO `rules` VALUES ('3.0T', '兰博基尼Aventador', '73');
INSERT INTO `rules` VALUES ('4.0T', '兰博基尼Gallardo', '74');
INSERT INTO `rules` VALUES ('5.0T', '兰博基尼Urus', '75');
INSERT INTO `rules` VALUES ('4.0T', '布加迪Chiron', '76');
INSERT INTO `rules` VALUES ('5.0T', '布加迪Veyron', '77');
INSERT INTO `rules` VALUES ('2.0T', '保时捷911', '78');
INSERT INTO `rules` VALUES ('3.0T', '保时捷918', '79');
INSERT INTO `rules` VALUES ('4.0T', '保时捷Panamera', '80');
INSERT INTO `rules` VALUES ('5.0T', '奥迪R8', '81');
INSERT INTO `rules` VALUES ('4.0T', '保时捷Cayenne', '82');
INSERT INTO `rules` VALUES ('4.0T', '柯尼塞格Agera', '83');
INSERT INTO `rules` VALUES ('5.0T', '柯尼塞格One', '84');
INSERT INTO `rules` VALUES ('2.0T', '奥迪TT', '85');
INSERT INTO `rules` VALUES ('3.0T', '奥迪Q7', '86');
INSERT INTO `rules` VALUES ('2.0T', '迈凯伦P1', '87');
INSERT INTO `rules` VALUES ('3.0T', '迈凯伦F1', '88');
INSERT INTO `rules` VALUES ('4.0T', '迈凯伦MP4', '89');
INSERT INTO `rules` VALUES ('5.0T', '迈凯伦12C', '90');
INSERT INTO `rules` VALUES ('红色特点', '法拉利', '91');
INSERT INTO `rules` VALUES ('黄色特点', '兰博基尼', '92');
INSERT INTO `rules` VALUES ('蛙眼灯特点', '保时捷', '93');
INSERT INTO `rules` VALUES ('最快的车', '布加迪', '94');
INSERT INTO `rules` VALUES ('最快的车', '柯尼塞格', '95');
INSERT INTO `rules` VALUES ('跑车', '法拉利', '96');
INSERT INTO `rules` VALUES ('跑车', '兰博基尼', '97');
INSERT INTO `rules` VALUES ('跑车', '保时捷', '98');
INSERT INTO `rules` VALUES ('跑车', '奥迪', '99');
INSERT INTO `rules` VALUES ('跑车', '迈凯伦', '100');
INSERT INTO `rules` VALUES ('跑车', '布加迪', '101');
INSERT INTO `rules` VALUES ('跑车', '柯尼塞格', '102');
INSERT INTO `rules` VALUES ('超级跑车', '奥迪', '103');
INSERT INTO `rules` VALUES ('越野车', '奥迪', '104');
INSERT INTO `rules` VALUES ('越野车', '兰博基尼', '105');
INSERT INTO `rules` VALUES ('越野车', '保时捷', '106');
