

// 爽汐  
//爽汐精 坪球稽 昔縦馬走 省壱, 採亜旋昔 竺誤戚 琶推拝 凶 紫遂廃陥.

int main()
{

	//int : 切戟莫(滴奄 舘是, byte) Data Type
	//i : 痕呪誤税
	//切戟莫拭澗 舛呪莫, 叔呪莫戚 赤陥.
	//舛呪莫 : char(1), short(2), int(4), long(4), long long(8)  舛呪空 1,2,人 旭戚 亨 恭嬢走澗 呪
	//叔呪莫 : float(4), double(8) 叔呪空 1.12xxx人 旭戚 社呪繊生稽 蟹展鎧澗 呪
	//廃原巨稽 int i澗 i虞澗 鎧亜 績税稽 舛廃 痕呪研 int虞澗 切戟莫拭 税背 呪縦戚 鞠澗 依.

	//悦汽 訊 舛呪莫拭 曽嫌亜 食君鯵昔亜? 舛呪税 滴奄亜 含虞走奄 凶庚
	//益係陥檎 焼掘 敗呪研 背汐馬切檎 i虞澗 痕呪澗 int戚奄 凶庚拭 痕呪税 滴奄澗 4byte戚壱(けけけけ) 戚照拭 級嬢哀 収切澗 舛呪莫 汽戚斗亜 煽舌吃 依戚壱 戚 痕呪税 戚硯聖 i虞壱 廃陥.
	//byte 税 鯵割 1byte = 8bit(けけけけけけけけ)<- け廃鯵亜 1bit稽 置社舘是戚壱 戚澗 赤陥 蒸陥(0暁澗 1)人 旭精 2亜走 雌殿葵幻聖 蟹展浬陥.
	//益係陥檎 int澗 4byte 戚糠稽 32搾闘戚陥.
	//1byte亜 恥 2税 10渋 =1024 広製戚 乞戚檎 1024byte虞壱 採牽走 省壱 1KB(1迭稽郊戚闘)虞壱 採献陥.
	//1KB亜 1024鯵亜 乞戚檎 1MB(五亜郊戚闘)虞壱 採献陥. >> 1024MB= 1GB >> 1024GB= 1TB

	//1byte稽 巷譲聖 拝 呪 赤澗亜? >> 1byte=8bit 1bit雁 雌殿葵聖 妊薄拝呪 赤澗 亜憎呪亜 2亜走 戚糠稽 8bit澗 2税8渋昔 256亜走税 雌殿葵聖 妊薄拝 呪 赤陥.
	//蓄亜稽 戚研 収切(丞呪昔 舛呪)稽 妊薄馬惟 吉陥檎 8bit澗 0~255猿走税 舛呪稽 妊薄拝 呪 赤陥.


	int i = 0;


	//unsignde = 丞税 舛呪研 倶敗. 魚虞辞 unsigned char 澗 丞税 舛呪幻聖 蟹展鎧澗 1郊戚闘 滴奄税 切戟莫聖 蟹展浬陥.
	//暁廃 痕呪税 識情 聡 unsigned char c = 0;研 胡煽 識情 背醤 及拭 蟹神澗 c = 0;澗 痕呪c拭 0聖 隔畏陥 c = 255; 痕呪拭 255研 隔畏陥虞澗 企脊 尻至切研 及拭 隔嬢醤 庚狛戚 限惟 恭嬢遭陥.
	//廃原巨稽 授辞亀 持唖背醤敗.
	//C++拭辞 =澗 疎痕引 酔痕戚 旭陥虞澗 倶戚焼観 痕呪拭 企脊聖 馬虞澗 企脊 尻至切戚陥. 汝社拭 持唖馬揮 採去硲税 鯵割精 ==生稽 戚依精 丞楕戚 疑析廃 鯵割戚虞澗 倶.

    //幻鉦 c = 256; 聖 企脊廃陥檎? 1/00000000 引 旭戚 8切軒研 角嬢亜 獄軒奄 凶庚拭 0生稽 妊奄亜 吉陥.

	// 1郊戚闘稽 丞呪幻 妊薄
	// 256亜走 -> 0 ~ 255
	unsigned char c = 0;

	c = 0;
	c = 255;
	c = 256;

	// 1郊戚闘稽 丞呪, 製呪 却陥 妊薄
	//256亜走 -> -128 ~ 0 ~ 127

	char c1 = 0;
	c1 = -1;
	c1 = 255;

	//益係陥檎 製呪(-1)研 企脊廃陥檎?
	// 食奄辞 char c1 = 0;澗 signed char c1 =0;人 旭壱 signed(製呪人 丞呪 乞砧 蟹展蛙)戚 持繰吉依戚陥.
	//食奄辞 1byte澗 256亜憎呪幻 亜遭陥 梅澗汽, 製呪人 丞呪猿走 妊薄馬形檎 丞呪幻 蟹展蛎聖凶 左陥 鋼生稽 匝 呪 鉱拭 蒸製. ex>-128~128
	//魚虞辞 0/けけけけけけけ 析凶澗 丞呪(128亜走) 1/けけけけけけけ析凶澗 製呪(128亜走)稽 蟹展蛙.
	//製呪人 丞呪研 蟹展鎧澗 固 図楕拭 赤澗 搾闘研 MSB虞壱 採献陥(Most Significant Bit/亜舌 掻推廃 搾闘)
	//陳濃斗拭辞 製呪澗 10+()=0 引 旭戚 妊薄鞠澗 呪研 製呪虞廃陥. 廃原巨稽 10引 希背辞 0戚 鞠澗 呪研 -10生稽 左壱 5人 希背辞 0戚鞠澗 呪研 -5虞壱 廃陥.
	//魚虞辞 錆疾戚 焼艦虞 機疾生稽 持唖背醤馬壱, 舘授備 7搾闘亜 業旭壱 MSB幻 0引 1稽 陥牽檎 旭精 収切税 丞呪人 製呪昔 依戚 焼観依戚陥.
	//ex> 0111 1111 = 127戚壱 戚壱 戚人 希背辞 0戚 鞠形檎 1000 0001稽潤 8搾闘研 段引馬食 衣厩 0引 旭陥. 魚虞辞 1000 0001戚 -127昔 依戚陥.
	//ex> 0000 0001 = 1 / 1111 1111 = -1 戚糠稽 c1 = 255; 澗 -1 引 旭陥.


	//丞呪拭 企誓馬澗 製呪研 察軒 達澗狛 >> 2税 左呪狛 >> 丞呪税 搾闘研 乞砧 鋼穿 獣徹壱 +1聖 廃陥.

	int a = 4 + (int)4.0;
	//舛呪人 叔呪澗 妊薄馬澗 号縦戚 陥牽陥. ex> 舛呪 4税 搾闘雌殿葵引 叔呪 4.0税 雌殿葵精 陥牽陥.
	//叔呪澗 採疑社呪繊戚虞澗 妊薄号縦聖 魚献陥.
	//採疑社呪繊 -> 蟹巷是徹 凧繕
	//叔呪 妊薄 号縦精 舛腔亀拭 税糎馬糠稽, double(8) 切戟莫戚 float(4)左陥 希 焼掘税 社呪繊猿走 舛溌馬惟 妊薄戚 亜管馬陥.
	
	//舛呪澗 舛呪晦軒, 叔呪澗 叔呪晦軒 尻至馬鞠, 砧 妊薄号縦税 杷 尻至切亜 尻至吃 井酔(叔呪人 舛呪亜 肇仙拝井酔) 誤獣旋生稽 痕発馬切.
	

	float f = 10.2415f + (float)20;
	//森研級嬢 是人旭精 雌伐精 叔呪人 舛呪研 希馬澗 呪縦拭辞 叔呪妊薄号縦生稽 蟹展鎧壱切 馬澗 敗呪戚陥.
	//舛呪蒋拭 (float)澗 蒸嬢亀 陳督析君亜 叔呪妊薄号縦生稽 痕莫 板 域至聖 拝依戚蟹, 是拭 源廃依坦軍 誤獣旋生稽 誤溌馬惟 痕発馬奄 是背(float)聖 妊奄廃陥.
	


	// 尻至切 
	//;-> 庚舌税 原姶聖 倶廃陥. 原徴妊税 蝕拝
	// 
	// 企脊 尻至切
	//= -> 企脊廃陥.

	//至綬尻至切 ->紫帳尻至
	//+, -, *, /, %(乞汲君什 尻至切, 蟹袴走 尻至切)
	//++,-- (装姶 尻至切)


	int data = 10 + 10;
	//尻至切拭亀 酔識授是亜 糎仙. 企脊尻至切<至綬尻至切
	//魚虞辞 是 敗呪澗 int data = 20;人 旭陥

	data = data + 20;
	data += 20;
	//是人 旭戚 蓄亜旋昔 繕闇戚 級嬢娃陥檎 int data = 10 + 10; 拭辞 20戚 亀窒鞠醸壱, 益 data 20聖 企脊馬食 20+ 20 = 40聖 暁陥獣 data拭 企脊廃陥澗 倶.
	//是 坪球拭辞 data亜 鋼差鞠糠稽 data += 20;稽 妊奄廃陥.(旭精源績)
	
	data = 10. / 3.;
	data = (int)(10. / 3.);
	data = (int)(10.f / 3.f);

	// /蟹刊奄 尻至切澗 舛呪晦軒 蟹喚凶澗 蟹袴走研 捌 交聖 姥馬壱, 叔呪析匡 叔呪晦軒 蟹勧 交聖 姥馬澗汽, 陥幻 是拭 縦拭辞澗 int澗 舛呪莫 戚奄 凶庚拭 社呪繊聖 薦須馬壱 舛呪幻 妊奄吉陥.
	// 魚虞辞, 是 縦精 設公鞠醸壱 data = (int)(10. / 3.); 稽 蟹展鎧醤 廃陥. 10. / 3. 拭 胤硲研 旭戚 廃 戚政澗 胤硲研 照廃陥檎 (int)澗 舛呪稽 郊荷澗 依聖 倶馬奄 凶庚拭 10.幻 舛呪稽 郊荷澗 依生稽  吉陥.
	// 益掘辞 10. / 3. 聖 乞砧 胤硲 背醤 砧鯵税 葵 乞砧 舛呪稽 妊奄馬惟 吉陥.
	
	//食奄辞 float f = 10.2415f +(float)20; 税 坪球拭辞 10.2415f 拭 細精 f澗 10.2415研 float展脊 聡 4郊戚闘 叔呪 切戟莫生稽 左畏陥澗 税耕戚壱
	//data = (int)(10. / 3.);拭辞 10.引 3.税 叔呪拭澗 f研 妊奄馬走 省紹奄 凶庚拭 食奄拭澗 double展脊 聡 8郊戚闘 叔呪 切戟莫生稽 左畏陥澗 税耕戚陥.
	//舛軒馬切檎, 叔呪研 雌呪稽 旋聖 井酔 社呪繊 及拭 f研 細戚檎 float 切戟莫生稽, f研 細戚走 省生檎 double 切戟莫生稽 娃爽廃陥. ex > 0.1f;, 0.1;

	//%乞汲君什 尻至切澗 蟹袴走 葵聖 姥馬澗 尻至切稽 data = 10 % 3; 税 井酔拭澗 1戚 吉陥.
	//陥幻 叔呪晦軒税 蟹袴走澗 糎仙馬走 省生糠稽 杷尻至切亜 乞砧 舛呪食醤 廃陥.

	data = 0;
	data++;
	data++;

	// ++ 廃舘域 装亜廃陥. / -- 廃舘域 姶社廃陥.
	//舘域亜 装亜廃陥壱 廃 戚政澗 奄沙 収切展脊税 切戟莫拭辞澗 +1 暁澗 -1 莫殿稽 装亜 姶社馬澗 依戚 限生蟹, 蟹掻拭 壕随 切戟莫拭辞澗 +1引 -1税 莫縦戚 焼艦奄 凶庚.

	++data; //穿是(穿帖)
	data++; //板是(板帖)

	//++戚 蒋拭 細聖井酔 酔識授是亜 匙牽壱, ++戚 及拭 細聖井酔 酔識授是亜 汗軒陥.

	a = 10;
	data = a++;
	data = ++a;

	//魚虞辞 是税 井酔 ++税 尻至精 薦析 蟹掻拭 獣楳吉陥. 魚虞辞 企脊尻至切亜 ++税 装姶尻至切左陥 胡煽 獣楳鞠糠稽 a = 10戚 胡煽 企脊吉陥. data拭澗 企脊尻至切亜 胡煽 鞠奄 凶庚拭 10戚 企脊鞠澗依
	//益君檎 焼掘 税 井酔澗 ++戚 胡煽 獣楳鞠奄 凶庚拭 +1+10戚 鞠嬢辞 11戚 吉 板 企脊尻至切亜 獣楳鞠嬢辞 data拭澗 11戚 企脊吉陥.
	
	data = 0;
	data--;
	--data;
	//是人 旭戚 瓜戚 穿是昔走 板是昔走研 魚霜 琶推亜 蒸澗 雌伐拭辞澗 穿是稽 馬澗依戚 疏陥. 戚政澗 走榎 戚背公敗.穿是稽 馬澗 獄県聖 級戚切.

	//轄軒 尻至切
	// !(蝕), &&(咽,and), ||(杯,or)
	//凧(true), 暗憎(false)
	//凧 : 0 戚 焼観 葵, 爽稽 1
	//暗憎 : 0


	// ! 鋼企,鋼穿, &&澗 嘘増杯 , || 杯増杯
	int truefalse = true;
	//虞壱馬檎 true澗 爽稽 1戚奄 ??庚拭 痕呪拭澗 1戚 級嬢娃陥.
	int truefalse = false;
	//虞壱馬檎 flase澗 0戚奄 凶庚拭 痕呪拭澗 0戚 級嬢娃陥.
	bool truefalse = false;
	
	bool istrue = 100;
	//凧暗憎 穿遂 切戟莫生稽 bool戚 赤陥. bool精 凧暗憎拭幻 紫遂鞠悟 瓜戚 魚走切檎 舛呪莫戚走幻 舛呪莫生稽 歳嫌鞠延 毘級陥. 益戚政稽澗 焼掘 bool istrue = 100;聖 獣楳馬檎 0戚 焼観葵戚糠稽 true 稽 毒舘馬奄 凶庚拭 100戚 焼観 1稽 閤焼球鍵陥.
	//凧壱稽 紫戚綜澗 1byte 戚陥. bool引 false true 拭 井酔拭澗 C拭澗 蒸壱 C++拭辞幻 陥潔陥.

	istrue = true;
	istrue = !istrue;
	//痕呪拭 true亜 級嬢穐澗汽 益 陥製拭 !(鋼穿)聖 梅生糠稽 false亜 吉陥.

	bool itrue = 0;
	itrue = !itrue;
	//痕呪亜 0戚檎 暗憎. 暗憎税 鋼穿戚糠稽 凧戚 吉陥. 戚凶 凧精 1稽 左奄凶庚拭 衣引葵精 1戚陥.

	itrue = 100 && 200;
	//100, 200 却陥 凧戚糠稽 尻至 衣引澗 凧. 魚虞辞 衣引葵精 1

	itrue = 0 && 200;
	//析 井酔 0精 暗憎, 200精 凧戚糠稽 嘘増杯拭税背 衣引澗 暗憎. 魚虞辞 衣引葵 0

	itrue = 0 || 300;
	// 0精 暗憎, 300精 凧戚走幻 却掻 馬蟹幻 凧戚檎 鞠糠稽 衣引澗 凧. 魚虞辞 衣引逢 1

	itrue = 0 || 0;
	//却陥 0戚糠稽 却陥 暗憎戚糠稽 衣引亀 暗憎. 魚虞辞 衣引葵 0

	//搾嘘尻至切
	// ==, !=, <, >, <=, >=,
	// == 澗 旭精走 , !=澗 陥献走 弘嬢左澗 依.<澗 神献楕戚 笛走, <=澗 神献楕戚 滴暗蟹 旭精走
	//戚拭 企廃依聖 凧引 暗憎生稽 蟹刊嬢 企岩背捜.

	//轄軒尻至切人 旭戚 切爽 紫遂鞠澗 依級
	//1. 姥庚
	//if, else
	data = 0;
	if (100 && 200)
	{
		data = 100;
	}

	// if幻鉦 凧戚虞檎 data=100 魚虞辞 100 && 200精 凧戚糠稽 data拭 100戚 級嬢娃陥. 0 && 200 析井酔拭澗 暗憎戚糠稽 data拭 0戚 級嬢娃陥.
	if (data == 100)
	{
		//if 亜 凧昔 井酔 呪楳
	}
	else
	{
		//if 亜 暗憎昔 井酔 呪楳
	}

	int iTest = 20;
	if (iTest == 10)
	{

	}
	else if (iTest == 20)
	{

	}
	else
	{

	}
	//是 縦坦軍 if稽 幻鉦拭~背辞 姥庚聖 弘嬢左壱, 暗憎戚 狂陥檎 else if姥庚生稽 食君腰 仙霜庚馬澗莫縦.(else if税 姐呪澗 巷廃舛生稽 拝 呪 赤陥.) else if 姥庚猿走 陥 梅澗汽亀 暗憎戚虞檎 原走厳 else姥庚生稽 暗憎昔 井酔研 呪楳
	//原走厳 else姥庚戚 蒸陥檎 焼巷依亀 呪楳馬走 省製. 
	//ex> if 幻鉦 w研 刊牽壱 赤陥檎 蝶遣斗研 是稽 戚疑背虞. s澗 焼掘, a澗 図楕, d澗 神献楕生稽 竺舛聖馬壱 姥庚聖 是人旭戚 else if 姥庚生稽 蟹干陥檎 if~else if~ else猿走 廃実闘戚奄 ??庚拭 疑獣脊径戚 照吉陥.
	//魚虞辞 w研 喚君辞 凧戚吉陥檎 益依幻 呪楳馬糠稽 蝶遣斗澗 是稽亜壱 s研 喚君 if姥庚拭辞 暗憎, 益 板 else if拭辞 凧戚 蟹神糠稽 蝶遣斗澗 焼掘稽 亜惟鞠走幻, w a 研 疑獣拭 喚袈聖 井酔 if姥庚拭辞 w亜 胡煽 凧戚鞠糠稽 蝶遣斗澗 是稽幻娃陥.
	//戚群井酔 else if亜 焼観 乞窮 姥庚聖 if稽 郊菓陥檎, 紺鯵税 姥庚生稽 左奄 凶庚拭 w a研 旭戚 刊牽檎 w凧 a凧戚糠稽 蝶遣斗亜 是,図楕生稽 戚疑 馬惟吉陥. 
	
 
	//switch case
	switch (iTest)
	{
	case 10:

		break;
	case 20:

		break;
	default:

		break;
	}

	//switch case人 if else 人 古朕艦葬精 搾汁
	//if else澗 亜偽失戚 恭嬢走蟹, 痕呪蟹 差説廃 働舛葵聖 隔嬢醤 馬澗 井酔殖 if else 姥庚生稽 蟹展鎧澗惟 希 疏製
	//魚虞辞 雌伐拭 魚虞 if else人 switch case研 唖唖 紫遂敗.
	//switch case拭辞税 爽税紫牌精 是 姥庚拭辞 iTest 痕呪亜 20析井酔 凧戚糠稽 case 20拭辞 呪楳戚 鞠澗汽 戚凶 掻娃拭 break亜 蒸陥檎, case 20採斗 default猿走 乞窮 姥庚聖 呪楳馬惟吉陥.
	//魚虞辞 break研 脊径馬走 省生檎 庚狛雌 庚薦亜 鞠走 省生糠稽 神嫌 井壱但戚 照襟惟鞠壱 叔呪稽 鎧亜 break研 脊径馬走 省紹聖 井酔 鎧亜 税亀廃企稽 覗稽益轡戚 叔楳鞠走 省壱 神嫌亜 襟走幻 訊 益係惟 菊澗走 庚薦繊聖 達聖凶 蕉股聖 呪 赤製.
	//case 10, 20, 30 聖 乞砧 廃疑拙生稽 呪楳馬掩 据拝 凶, 是人旭戚 break研 床走省壱 case 10;, case 20;, case 30;聖 脊径馬澗 井酔亜 赤製. 戚 井酔殖 if 姥庚生稽 郊荷檎 if(iTest == 10 || iTest == 20 || iTest == 30) 引 旭製.


	//誌牌尻至切
	// :?
	
	iTest == 20 ? iTest = 100 : iTest = 200;
	//iTest 亜 20引 疑析馬蟹? 凧析井酔 100 / 暗憎析 井酔 200聖 呪楳廃陥.
	//焼掘 if 姥庚引 疑析廃 倶戚蟹, 誤溌失引 亜偽失戚 if姥庚生稽 ?Ю散О? 疏生糠稽 誌牌尻至切澗 設 紫遂鞠遭 省澗陥.

	if (iTest == 20)
	{
		iTest = 100;
	}

	else
	{
		iTest = 200;
	}



	//搾闘尻至切
	//習覗闘 <<, >>   搾闘研 鉢詞妊 号狽生稽 廃牒梢 肯陥.
	unsigned char byte = 1;

	byte << 1;
	// 10遭呪拭辞 2亜 20戚 鞠檎 10壕, 2遭呪拭辞 1戚 10戚鞠檎 10遭呪稽 蟹展鎧檎 1戚 2亜 鞠澗依戚糠稽 2壕
	//魚虞辞 2遭狛拭辞 搾闘研 蒋生稽 馬蟹梢 肯陥澗闇 2壕亜 吉陥澗倶

	byte <<= 1;
	//析井酔 酔識授是稽 昔背 企脊尻至切亜 蟹掻拭 呪楳鞠糠稽 2壕研 獣轍 依聖 企脊獣轍陥. byte = byte <<1; 人 旭精源

	byte <<= 2;
	//析井酔澗 4壕 獣轍依, byte <<= 3; 精 8壕

	byte >>= 1;
	//2歳税1壕 析井酔 蟹袴走澗 域至 x 廃原巨稽 2稽 蟹勧 交聖 姥廃陥.

	//搾闘 咽(&), 杯(|), xor(^), 鋼穿(~)
	//搾闘舘是稽 搾闘晦軒 馬蟹梢 馬蟹梢 凧暗憎聖 亜形蛙
	// ex> 1011 0111/ 1110 1111 聖 搾嘘馬食 搾闘咽(&)析 井酔 却陥 1析井酔 凧(1), 馬蟹虞亀 0析井酔 暗憎(0)戚糠稽 1010 0111
	// ex> 1011 0111/ 1110 1111 搾闘杯(|) 析 井酔 却掻 馬蟹虞亀 1析井酔 凧(1), 却 陥 0析井酔 暗憎(0) 魚虞辞 1111 1111
	// ex> 搾闘 鋼穿昔 井酔澗 搾闘研 鋼企稽 呪楳廃陥. 1011 0111 聖 鋼穿馬檎 0100 1000 
	// xor税 井酔澗 唖唖税 搾闘亜 旭生檎 0, 陥牽檎 1稽 沙陥. ex> 1011 0111/ 1110 1111 聖 xor尻至馬檎 0101 1000 

	//戚訓 搾闘尻至切亜 嬢巨拭 紫遂鞠澗亜?
	// #(穿坦軒奄) : ?淦牟鶸? 姥庚生稽 拙失廃 穿坦軒奄 舘域拭辞 呪楳吃 呪 赤澗 誤敬嬢稽 戚 誤敬嬢澗 乞窮 陳督析 引舛掻拭辞 薦析 胡煽 坦軒吉陥.
	//#define : 鎧亜 走舛廃 姥庚聖 働舛 収切稽 帖発背層陥.

#define HUNGRY 1 //壕亜 壱覗陥 梅聖凶 1稽 左畏陥.
	int iStatus = HUNGRY; //萩益軒研 1稽 左奄稽 梅生糠稽, 1稽 帖発背捜.

	//紫遂馬澗 戚政 : 1. 亜偽失戚 疏陥. 収切稽 蟹展蛎聖凶人 HUNGRY稽 蟹展蛎聖 凶 戚 姥庚戚 雌殿但拭 企廃依戚虞澗 依, 嬢恐 巨獄覗虞澗 依聖 廃勧拭 硝奄襲陥.
	//                2. define HUNGRY 3生稽 呪舛獣 畷馬陥. 析析備 呪舛拝 琶推亜 蒸壱, define 古滴稽拭辞 収切幻 郊蚊辞 呪舛背爽檎 穿端 坪球拭辞 旋遂吉陥.

	int iStatus = HUNGRY;
#define THIRSTY 2
#define TIRED 4
#define HOT 8


	//int澗 4byte戚壱 恥 32bit戚陥. 働舛 雌殿研 蟹展鎧奄 是背識 凧,暗憎 森研級嬢 壕壱把税 雌殿研 蟹展鎧奄 是背識 壕壱把, 照壕壱把引 旭戚 2亜走税 莫縦生稽 戚欠嬢遭陥.
	//魚虞辞 働舛 雌殿研 妊薄馬奄 是背識 違帖走 省澗 唖唖税 搾闘亜 琶推馬壱, int拭辞 32bit亜 溌左鞠糠稽 疑獣拭 妊薄拝 呪 赤澗 雌殿亜 32亜走戚陥.
	//HUNGRY 澗 1 戚糠稽 酔著拭辞 1腰属 搾闘研 紫遂馬澗 依戚壱, THIRSTY澗 2戚糠稽 2腰属搾闘, TIRED澗 3腰??搾闘幻聖 紫遂馬奄 ??庚拭 2^n 莫殿税 収切稽 壕舛背操醤廃陥.
	//戚係惟 馬陥左檎 32,64,128 去去生稽 蟹展鎧奄 凶庚拭 亜偽失聖 是背辞 16遭呪稽 妊奄廃陥. 16遭呪澗 0~9 a~f 猿走 16鯵戚陥.

#define THIRSTY 0x001
#define THIRSTY 0x002
#define THIRSTY 0x004
#define THIRSTY 0x008

#define THIRSTY 0x010 // 15昔 f研 1段引廃依戚 16戚奄 凶庚拭 10戚陥.
#define THIRSTY 0x020
#define THIRSTY 0x040
#define THIRSTY 0x080

#define THIRSTY 0x100
#define THIRSTY 0x200
#define THIRSTY 0x400
#define THIRSTY 0x800

	//是人 旭戚 16遭狛生稽 蟹展鎧檎 鋭帳失戚 蟹展蟹 亜偽失戚 疏壱 舛軒馬奄 疏陥.

	iStatus |= THIRSTY;
	iStatus |= HUNGRY;
	// 壕亀 壱覗壱 鯉戚 原牽陥澗 雌殿.

	if (iStatus & THIRSTY)
	{
		//雌殿但拭 鯉原硯 搾闘幻 旋遂. 2腰 搾闘亜 1析井酔 鯉原硯 0析井酔 鯉原硯x
	}



	//働舛 切軒 搾闘 薦暗

	iStatus &= ~THIRSTY; //THIRSTY拭 背雁馬澗 採歳幻 搾闘亜 薦暗喫. 遭楳号縦精 THIRSTY 搾闘研 鋼穿 板 咽尻至拭 税背 企脊.  ex> 鯉原硯戚 蒸嬢走檎 巨獄覗但聖 薦暗馬壱 粛聖凶 紫遂



	//痕呪
	//1. 走蝕痕呪
	//走榎猿走 因採馬檎辞 旋嬢紳 坪球級精 int main () { } 姥庚 照拭 級嬢亜澗 坪球戚陥. 戚君廃 依聖 敗呪虞壱 廃陥. 魚虞辞 酔軒澗 main戚虞澗 敗呪 照拭 坪球研 拙失馬壱 赤澗依
	//戚君廃 胤硲 照(敗呪 照)拭 識情鞠嬢 赤澗 痕呪級聖 走蝕痕呪虞壱 採献陥.
	
	//2. 穿蝕痕呪
	//鋼企稽 胤硲 須採(敗呪 郊甥)拭 識情鞠嬢 赤澗 痕呪級聖 穿蝕痕呪虞壱 採献陥.
	
	//3. 舛旋痕呪
	//4. 須採痕呪


	//敗呪(funtion)
	//奄管 馬蟹馬蟹研 唖唖税 敗呪亜 眼雁廃陥.
	//拙精 奄管戚 乞戚壱 乞食辞 戚 乞窮 奄管聖 匂胤馬澗 敗呪亜 馬蟹税 珍度苧亜 吉陥. (奄管税 乞汲鉢) ex> 蝶遣斗税 朕什斗原戚綜研 眼雁馬澗 敗呪 -> 益照拭澗 呪弦精 奄管級戚 鎧匂鞠嬢 赤陥.

	//走蝕痕呪澗 胤硲 照拭 識情吉 痕呪(敗呪, 走蝕) 稽 敗呪照拭 走蝕聖 暁 蟹喚 呪 赤陥.
	int iName = 0;
	
	{
	
		int iName = 100;      

		iName;
	}

	iName;
	//痕呪誤 鋭帳
	// 是人 旭戚 敗呪 郊甥拭 iName税 痕呪研 舛税梅壱, 敗呪照拭 走蝕拭辞 廃腰希 iName聖 識情梅澗汽, 戚 凶 却税 痕呪澗 陥献依聖 蟹展浬陥.
	//魚虞辞 敗呪照拭 走蝕痕呪澗 旭精 走蝕照拭 痕呪研 酔識授是 馬壱 赤奄 凶庚拭, 敗呪照 iName;精 敗呪照 int iName = 100; 縦拭 痕呪研 走暢廃陥.
	//幻鉦 敗呪鉱拭 int iName = 100; 聖 識情馬檎 敗呪鉱拭 旭精 戚硯税 痕呪亜 2鯵研 識情廃依戚糠稽 神嫌稽 昔舛廃陥.







		return 0;
}