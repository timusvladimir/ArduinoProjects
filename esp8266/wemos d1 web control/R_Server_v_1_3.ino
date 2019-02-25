#include <ESP8266WiFi.h>
#include <pgmspace.h>   //PROGMEM

const char WiFiAPPSK[] = "testwifi"; //свой пароль, сеть будет (что-то вроде ThingDev-A37) IP 192.168.4.1

//String reopen;
const static char file0[] PROGMEM =
  "<!DOCTYPE html PUBLIC '-//W3C//DTD XHTML 1.0 Transitional//EN'>\n\r"
  "<meta http-equiv='Content-Type' content='text/html; charset=UTF-8' />\n\r"
  "<html><head><title>DevKit ESP8266 Control</title>\n\r"
  "<style type=\"text/css\">\n\r"
  ".onoffswitch {position: relative;width: 24px;-webkit-user-select:none;-moz-user-select:none;-ms-user-select: none;}\n\r"
  ".onoffswitch-checkbox {display: none;}\n\r"
  ".onoffswitch-label {display: block;overflow: hidden;cursor: pointer;border: 2px solid #8084B0;border-radius: 10px;}\n\r"
  ".onoffswitch-inner {display: block;width: 200%;margin-left: -100%;transition: margin 0.3s ease-in 0s;}\n\r"
  ".onoffswitch-inner:before, .onoffswitch-inner:after {display: block;float: left;width: 50%;height: 6px;padding: 0;line-height: 6px;font-size: 14px;color: white;font-family: Trebuchet, Arial, sans-serif;font-weight: bold;box-sizing: border-box;}\n\r"
  ".onoffswitch-inner:before {content: \"\";padding-left: 10px;background-color: #FF0000;color: #999999;}\n\r"
  ".onoffswitch-inner:after {content: \"\";padding-right: 10px;background-color: #0AFF0A;color: #FFFFFF;text-align: right;}\n\r"
  ".onoffswitch-switch {display: block;width: 10px;margin: -2px;background: #FFFFFF;position: absolute;top: 0;bottom: 0;right: 14px;border: 2px solid #8084B0;border-radius: 10px;transition: all 0.3s ease-in 0s;}\n\r"
  ".onoffswitch-checkbox:checked + .onoffswitch-label .onoffswitch-inner {margin-left: 0;}\n\r"
  ".onoffswitch-checkbox:checked + .onoffswitch-label .onoffswitch-switch {right: 0px;}\n\r";

const static char file1[] PROGMEM =
  ".onoffswitch-inner2 {display: block;width: 200%;margin-left: -100%;transition: margin 0.3s ease-in 0s;}\n\r"
  ".onoffswitch-inner2:before, .onoffswitch-inner2:after {display: block;float: left;width: 50%;height: 6px;padding: 0;line-height: 6px;font-size: 14px;color: white;font-family: Trebuchet, Arial, sans-serif;font-weight: bold;box-sizing: border-box;}\n\r"
  ".onoffswitch-inner2:before {content: \"\";padding-right: 10px;background-color: #0AFF0A;color: #FFFFFF;text-align: right;}\n\r"
  ".onoffswitch-inner2:after {content: \"\";padding-left: 10px;background-color: #FF0000;color: #999999;}\n\r"
  ".onoffswitch-checkbox:checked + .onoffswitch-label .onoffswitch-inner2 {margin-left: 0;}\n\r"
  ".out_val {-webkit-appearance: none;appearance: none;padding: 0;margin-left:40px;border: 2px solid #eee;border-radius: 2px;box-shadow: inset 0 1px #ccc, inset 0 1px #575555, inset 0 -1px #00c;background: #fef linear-gradient(#BCBCBC, #fff0f5);overflow: hidden;}\n\r"
  "div.ex_output{width:258px;text-align:center;background-color: #000080;margin-left:6px;}\n\r"
  "div.ex_output output{font-weight:bold;font-size:16px;color: #CCC;}\n\r"
  "div.output {width:80px;background-color: #EFE3CF;border: 2px solid #006;text-align:center;margin-bottom:4px;margin-right:2px;float:left;}\n\r"
  "div.output div {width:80px;background-color:#C1C5F7;}\n\r"
  "div.output output {font-weight:bold;font-size:16px;color:#009;}\n\r";

const static char file2[] PROGMEM =
  ".rangeP {-webkit-appearance: none;appearance: none;padding: 0;border: 2px solid #eee;border-radius: 2px;background: #fef linear-gradient(#BCBCBC, #fff0f5);overflow: hidden;}\n\r"
  ".rangeP::-moz-range-thumb {border-radius: 2px;box-shadow: -13px 0 #40310a, -26px 0 #40310a, -39px 0 #40310a, -52px 0 #40310a, -65px 0 #40310a, -78px 0 #40310a, -91px 0 #40310a, -104px 0 #40310a, -117px 0 #40310a, -130px 0 #40310a, -143px 0 #40310a, -156px 0 #40310a;}\n\r"
  ".rangeP::-moz-range-track {background: none;border: none;}\n\r"
  ".rangeP::-webkit-slider-thumb { -webkit-appearance: none; width:15px; height:8px; border: 1px solid #000081; border-radius: 2px; background-image:linear-gradient(#dedede, #8282ff); box-shadow: -13px 0 #1c59f4, -26px 0 #1c59f4, -39px 0 #1c55eb, -52px 0 #1c50db, -65px 0 #1b49c9, -78px 0 #1b43b7, -91px 0 #1b3a9e, -104px 0 #1b338d, -117px 0 #1b2d7a, -130px 0 #1b286e, -143px 0 #1b286d, -156px 0 #1b2566;}\n\r"
  ".column_view-off {display: none;text-align: center;color: #000;}\n\r"
  ".column_view-on {background-color: #BBBEFF;}.mode_view-off {display: none;}.mode_view-on {background-color: #D1D2F3;}</style>\n\r";

const static char file3[] PROGMEM =
  "<script type= \"text/javascript\">\n\r"
  "var str_URL = \"\"; var x =\"\"; var y =\"\";\n\r"
  "function cb_check0(id_cb){\n\r"
  "x = id_cb.name;\n\r"
  "if (id_cb.checked){\n\r"
  "str_URL=x+\"=1\";}else{str_URL=x+\"=0\";}\n\r"
  "trans_par(id_cb);}\n\r"
  "function cb_check(id_cb){\n\r"
  "x = id_cb.name;\n\r"
  "y = \"c\" + id_cb.id;\n\r"
  "var rng = document.getElementById(y);\n\r"
  "if (id_cb.checked){\n\r"
  "str_URL=x+\"=1\";\n\r"
  "rng.value = rng.max;sd_index(id_cb);}else{str_URL=x+\"=0\";\n\r"
  "rng.value = rng.min;}\n\r"
  "trans_par(id_cb);}\n\r"
  "function cb_check2(id_cb){\n\r"
  "x = id_cb.name;\n\r"
  "y = \"c\" + id_cb.id;\n\r"
  "var rng = document.getElementById(y);\n\r"
  "if (id_cb.checked){\n\r"
  "str_URL=x+\"=0\";\n\r"
  "rng.value = rng.min;}else{str_URL=x+\"=1\";rng.value = rng.max;}\n\r"
  "trans_par(id_cb);}\n\r"
  "function ce_but(id_cb){x = id_cb.id;str_URL=x+\"=0\";trans_par(id_cb);}\n\r"
  "function sel_test(id_cb){\n\r"
  "var colo = id_cb.options[id_cb.selectedIndex].index;\n\r"
  "switch (colo) {case 0: set_color(id_cb, \"#94fff8\"); break\n\r"
  "case 1: set_color(id_cb, \"#fff894\"); break\n\r"
  "case 2: set_color(id_cb, \"#f294ff\"); break\n\r"
  "default: set_color(id_cb, \"#FFFFFF\"); break}\n\r"
  "x = id_cb.id;str_URL = x+\"=\" + colo;\n\r"
  "trans_par(id_cb);}\n\r"
  "function set_color(el, cl) {el.style.backgroundColor = cl;}\n\r"
  "function trans_par(id_cb){var xmlhttp = getXmlHttp();var str_URL2 = \"\";\n\r";

String file3a = "";

const static char file4[] PROGMEM =
  "xmlhttp.open(\"GET\", str_URL2, true);\n\r"
  "var http = new XMLHttpRequest(), href = this.href;\n\r"
  "http.open(\"GET\", str_URL2);\n\r"
  "http.setRequestHeader(\"Content-Type\", \"application/x-www-form-urlencoded\");\n\r"
  "http.timeout = 2000;\n\r"
  "xmlhttp.onreadystatechange = function()\n\r"
  "{if (xmlhttp.readyState == 4){if(xmlhttp.status == 200){x = xmlhttp.responseText;getParam(x);}}}\n\r"
  "xmlhttp.send(null);}\n\r"
  "function getXmlHttp(){try {return new ActiveXObject(\"Msxml2.XMLHTTP\");}catch (e){try {return new ActiveXObject(\"Microsoft.XMLHTTP\");}catch (ee){}}if (typeof XMLHttpRequest!=\"undefined\"){return new XMLHttpRequest();}}\n\r"
  "function polsun_val(id_cb){\n\r"
  "str_URL = id_cb.id+\"=\" + id_cb.value;\n\r"
  "document.getElementById(\"result1\").value = str_URL;\n\r"
  "sd_index(id_cb);trans_par(id_cb);}\n\r";

const static char file5[] PROGMEM =
  "function test_val1(id_cb){x = id_cb.name;str_io = x + \"=\" + id_cb.value;str_URL = id_cb.value;document.getElementById(\"result1\").value = str_io;}\n\r"
  "function getParam(get){var tmp = new Array();var tmp2 = new Array();var param = new Array();\n\r"
  "if(get != \"\"){\n\r"
  "tmp = (get.substr(1)).split(\"&\");\n\r"
  "for(var i=0; i < tmp.length; i++){tmp2 = tmp[i].split(\"=\");param[tmp2[0]] = tmp2[1];}\n\r"
  "for (var key in param){if(param[key] != \"\"){document.getElementById(key).value = param[key];}}}}\n\r"
  "function toggleView(source, tableId, tag) {\n\r"
  "var elems = document.getElementById(tableId).getElementsByTagName(tag);\n\r"
  "for (i = 0; i < elems.length; ++i) {toggleClasses(elems[i], \"column_view-off\", \"column_view-on\");}\n\r"
  "return false;}\n\r"
  "function toggleView_mode(source, tableId, tag) {\n\r"
  "var elems = document.getElementById(tableId).getElementsByTagName(tag);\n\r"
  "for (i = 0; i < elems.length; ++i) {toggleClasses(elems[i], \"mode_view-off\", \"mode_view-on\");}\n\r"
  "return false;}\n\r"
  "\n\r"
  "function toggleClasses(elem, className1, className2) {var clazz = elem.className.toString();\n\r"
  "if (clazz.indexOf(className1) >= 0) {elem.className = clazz.replace(className1, className2);} else if (clazz.indexOf(className2) >= 0) {elem.className = clazz.replace(className2, className1);}}\n\r"
  "function startTimer() {\n\r"
  "var my_timer = document.getElementById(\"my_timer\");\n\r"
  "var time = my_timer.innerHTML;\n\r"
  "var arr = time.split(\":\");\n\r"
  "var h = arr[0];\n\r"
  "var m = arr[1];\n\r"
  "var s = arr[2];\n\r"
  "if (s == 0) {\n\r"
  "if (document.getElementById(\"tt1\").checked){\n\r"
  "str_URL = \"zz=0\";\n\r"
  "trans_par(document.getElementById(\"ce1\"));}\n\r"
  "s = document.getElementById(\"r_sec\").value;}\n\r"
  "else s--;\n\r"
  "if (s < 10) s = \"0\" + s;\n\r"
  "if (document.getElementById(\"tt1\").checked){\n\r"
  "document.getElementById(\"my_timer\").innerHTML = h+\":\"+m+\":\"+s;}\n\r"
  "setTimeout(startTimer, 1000);}\n\r"
  "function sd_index(id_cb){\n\r"
  "if (id_cb.id[0] == \"c\"){\n\r"
  "var l = id_cb.id.length;\n\r"
  "var sd = \"s\";\n\r"
  "for(var i=1; i < id_cb.id.length; i++)\n\r"
  "sd = sd + id_cb.id[i];\n\r"
  "}else{\n\r"
  "sd = \"s\" + id_cb.id;}\n\r"
  "var indout = document.getElementById(sd);\n\r"
  "if (document.getElementById(\"ce1\").checked){\n\r"
  "indout.selectedIndex  = 1;\n\r"
  "indout.style.backgroundColor = \"#fff894\";};}\n\r"
  "</script></head>\n\r";

const static char file6[] PROGMEM =
  "<body onload=\"startTimer()\">\n\r"
  "<div class= \"ex_output\"><output id=\"ex_out\"><span>DevKit ESP8266 Control v1.03</span></output></div>\n\r"
  "<table border=\"0\">\n\r"
  "<tr><td width=\"86\"><div class=\"output\"><div><span>Can 1</span></div><output id=\"out1\">0</output></div></td>\n\r"
  "<td width=\"86\"><div class=\"output\"><div><span>Can 2</span></div><output id=\"out2\">0</output></div></td>\n\r"
  "<td width=\"86\"><div class=\"output\"><div><span>Can 3</span></div><output id=\"out3\">0</output></div></td>\n\r"
  "</tr><tr><td>&nbsp;&nbsp;<input type=\"number\" min=\"1\" max=\"59\" step=\"1\" id=\"r_sec\" style=\"width:72; text-align:center\" value=\"5\"/></td>\n\r"
  "<td><input type=\"checkbox\" id=\"tt1\" name=\"tt1\" onclick=\"cb_check0(this)\" /> avto</td>\n\r"
  "<td align=\"center\"><span id=\"my_timer\" style=\"color: #f00;  font-weight: bold;\">00:00:10</span></td></tr>\n\r"
  "<tr align=\"center\">\n\r"
  "<td><input type=\"button\" id=\"52\" value=\"PWM\" onclick=\"return toggleView(this, 'data-table', 'td')\" style=\"width:64px\" /></td>\n\r"
  "<td>output\n\r"
  "<input type=\"checkbox\" id=\"ce1\" name=\"ce1\" onclick=\"cb_check0(this)\" checked/></td>\n\r"
  "<td><input type=\"button\" id=\"522\" value=\"mode\" onclick=\"return toggleView_mode(this, 'data-table', 'td')\" style=\"width:64px\" /></td></tr></table>\n\r";

const static char file7[] PROGMEM =
  "<table id=\"data-table\"><tbody>\n\r"
  "<tr bgcolor=\"#CCCCCC\"><td align=\"center\"><strong>on/off</strong></td>\n\r"
  "<td align=\"center\" class=\"column_view-m column_view-off\" style=\"background-color:#00C\">&nbsp;</td>\n\r"
  "<td align=\"center\" class=\"mode_view-m mode_view-off\"><strong>i</strong></td>\n\r"
  "<td align=\"center\" class=\"mode_view-m mode_view-off\"><strong>mode</strong></td>\n\r"
  "<td align=\"center\"><strong>pin</strong></td><td align=\"center\"><strong>instr</strong></td>\n\r"
  "<td align=\"center\" bgcolor=\"#666666\">&nbsp;</td><td align=\"center\"><strong>instr</strong></td>\n\r"
  "<td align=\"center\"><strong>pin</strong></td>\n\r"
  "<td align=\"center\" class=\"mode_view-m mode_view-off\"><strong>mode</strong></td>\n\r"
  "<td align=\"center\" class=\"mode_view-m mode_view-off\"><strong>i</strong></td>\n\r"
  "<td align=\"center\" class=\"column_view-m column_view-off\" style=\"background-color:#00C\"><span class=\"out_val\">\n\r"
  "<output id=\"result1\">0</output></span></td><td align=\"center\"><strong>on/off</strong></td></tr>\n\r";

const static char file8[] PROGMEM =
  "<tr>\n\r"
  "<td width=\"38\">\n\r"
  "<div class=\"onoffswitch\"><input type=\"checkbox\" name=\"cbA0\" class=\"onoffswitch-checkbox\" id=\"A0\" onclick=\"cb_check2(this)\" checked>\n\r"
  "<label class=\"onoffswitch-label\" for=\"A0\"> <span class=\"onoffswitch-inner\"></span> <span class=\"onoffswitch-switch\"></span> </label>\n\r"
  "</div></td>\n\r"
  "<td width=\"148\" class=\"column_view-m column_view-off\">\n\r"
  "<input type=\"range\" onchange=\"polsun_val(this)\" class=\"rangeP\" id=\"cA0\" value=\"0\" max=\"1023\" min=\"0\"/></td>\n\r"
  "<td class=\"mode_view-m mode_view-off\">&nbsp;</td>\n\r"
  "<td class=\"mode_view-m mode_view-off\">\n\r"
  "<select id=\"sdA0\" onchange=\"sel_test(this)\"><option  style=\"background-color: #d9fffe\">Input</option>\n\r"
  "<option style=\"background-color: #fffed9\" selected=\"selected\">Output</option></select></td>\n\r"
  "<td width=\"36\">A0</td>\n\r"
  "<td width=\"53\">ADC0</td>\n\r"
  "<td width=\"1\" bgcolor=\"#666666\">&nbsp;</td>\n\r"
  "<td width=\"53\">GPIO16</td>\n\r"
  "<td width=\"34\">D0</td>\n\r"
  "<td class=\"mode_view-m mode_view-off\"><select id=\"sd16\" onchange=\"sel_test(this)\">\n\r"
  "<option  style=\"background-color: #d9fffe\"  selected=\"selected\">Input</option><option style=\"background-color: #fffed9\" selected=\"selected\">Output</option></select></td>\n\r"
  "<td class=\"mode_view-m mode_view-off\"><input type=\"checkbox\" id=\"ci16\" name=\"ci16\" onclick=\"cb_check0(this)\" disabled=\"disabled\"/></td>\n\r"
  "<td align=\"center\" class=\"column_view-m column_view-off\" width=\"148\">\n\r"
  "<input type=\"range\" onchange=\"polsun_val(this)\" class=\"rangeP\" id=\"cd16\" value=\"0\" max=\"1023\" min=\"0\" /></td>\n\r"
  "<td width=\"34\">\n\r"
  "<div class=\"onoffswitch\"><input type=\"checkbox\" name=\"cb16\" class=\"onoffswitch-checkbox\" id=\"d16\" onclick=\"cb_check(this)\"/>\n\r"
  "<label class=\"onoffswitch-label\" for=\"d16\"> <span class=\"onoffswitch-inner2\"></span> <span class=\"onoffswitch-switch\"></span></label></div></td>\n\r"
  "</tr>\n\r";

const static char file9[] PROGMEM =
  "<tr bgcolor=\"#CCCCCC\"><td>&nbsp;</td>\n\r"
  "<td class=\"column_view-m column_view-off\">&nbsp;</td>\n\r"
  "<td class=\"mode_view-m mode_view-off\">&nbsp;</td>\n\r"
  "<td class=\"mode_view-m mode_view-off\">&nbsp;</td>\n\r"
  "<td>RSV</td><td>reserv</td><td bgcolor=\"#666666\">&nbsp;</td>\n\r"
  "<td>GPIO5</td><td>D1</td>\n\r"
  "<td class=\"mode_view-m mode_view-off\"><select id=\"sd5\" onchange=\"sel_test(this)\">\n\r"
  "<option  style=\"background-color: #d9fffe\">Input</option><option style=\"background-color: #fffed9\" selected=\"selected\">Output</option></select></td>\n\r"
  "<td class=\"mode_view-m mode_view-off\"><input type=\"checkbox\" id=\"ci5\" name=\"ci5\" onclick=\"cb_check0(this)\" /></td>\n\r"
  "<td align=\"center\" class=\"column_view-m column_view-off\">\n\r"
  "<input type=\"range\" onchange=\"polsun_val(this)\" class=\"rangeP\" id=\"cd5\" value=\"0\" max=\"1023\" min=\"0\" /></td>\n\r"
  "<td>\n\r"
  "<div class=\"onoffswitch\"><input type=\"checkbox\" name=\"cb5\" class=\"onoffswitch-checkbox\" id=\"d5\" onclick=\"cb_check(this)\"/>\n\r"
  "<label class=\"onoffswitch-label\" for=\"d5\"><span class=\"onoffswitch-inner2\"></span> <span class=\"onoffswitch-switch\"></span></label>\n\r"
  "</div></td>\n\r"
  "</tr>\n\r";

const static char file10[] PROGMEM =
  "<tr>\n\r"
  "<td>&nbsp;</td>\n\r"
  "<td class=\"column_view-m column_view-off\">&nbsp;</td>\n\r"
  "<td class=\"mode_view-m mode_view-off\">&nbsp;</td>\n\r"
  "<td class=\"mode_view-m mode_view-off\">&nbsp;</td>\n\r"
  "<td>RSV</td>\n\r"
  "<td>reserv</td>\n\r"
  "<td bgcolor=\"#666666\">&nbsp;</td>\n\r"
  "\n\r"
  "<td>GPIO4</td><td>D2</td>\n\r"
  "<td class=\"mode_view-m mode_view-off\">\n\r"
  "<select id=\"sd4\" onchange=\"sel_test(this)\"><option  style=\"background-color: #d9fffe\">Input</option><option style=\"background-color: #fffed9\" selected=\"selected\">Output</option></select></td>\n\r"
  "<td class=\"mode_view-m mode_view-off\">\n\r"
  "<input type=\"checkbox\" id=\"ci4\" name=\"ci4\" onclick=\"cb_check0(this)\" /></td>\n\r"
  "<td align=\"center\" class=\"column_view-m column_view-off\">\n\r"
  "<input type=\"range\" onchange=\"polsun_val(this)\" class=\"rangeP\" id=\"cd4\" value=\"0\" max=\"1023\" min=\"0\" /></td>\n\r"
  "<td><div class=\"onoffswitch\"><input type=\"checkbox\" name=\"cb4\" class=\"onoffswitch-checkbox\" id=\"d4\" onclick=\"cb_check(this)\"/>\n\r"
  "<label class=\"onoffswitch-label\" for=\"d4\" > <span class=\"onoffswitch-inner2\"></span> <span class=\"onoffswitch-switch\"></span></label>\n\r"
  "</div></td>\n\r"
  "</tr>\n\r";

const static char file11[] PROGMEM =
  "<tr bgcolor=\"#CCCCCC\">\n\r"
  "<td><div class=\"onoffswitch\"><input type=\"checkbox\" name=\"cb10\" class=\"onoffswitch-checkbox\" id=\"d10\" onclick=\"cb_check2(this)\" checked=\"checked\" />\n\r"
  "<label class=\"onoffswitch-label\" for=\"d10\"> <span class=\"onoffswitch-inner\"></span> <span class=\"onoffswitch-switch\"></span> </label>\n\r"
  "</div></td>\n\r"
  "<td class=\"column_view-m column_view-off\"><input type=\"range\" onchange=\"polsun_val(this)\" class=\"rangeP\" id=\"cd10\" value=\"0\" max=\"1023\" min=\"0\"/></td>\n\r"
  "<td class=\"mode_view-m mode_view-off\"><input type=\"checkbox\" id=\"ci10\" name=\"ci10\" onclick=\"cb_check0(this)\" /></td>\n\r"
  "<td class=\"mode_view-m mode_view-off\"><select id=\"sd10\" onchange=\"sel_test(this)\">\n\r"
  "<option  style=\"background-color: #d9fffe\">Input</option>\n\r"
  "<option style=\"background-color: #fffed9\" selected=\"selected\">Output</option></select></td>\n\r"
  "<td>SD3</td>\n\r"
  "<td>GPIO10</td>\n\r"
  "<td bgcolor=\"#666666\">&nbsp;</td>\n\r"
  "<td>GPIO0</td>\n\r"
  "<td>D3</td>\n\r"
  "<td class=\"mode_view-m mode_view-off\"><select id=\"sd0\" onchange=\"sel_test(this)\">\n\r"
  "<option  style=\"background-color: #d9fffe\">Input</option>\n\r"
  "<option style=\"background-color: #fffed9\" selected=\"selected\">Output</option></select></td>\n\r"
  "<td class=\"mode_view-m mode_view-off\"><input type=\"checkbox\" id=\"ci0\" name=\"ci0\" onclick=\"cb_check0(this)\" /></td>\n\r"
  "<td align=\"center\" class=\"column_view-m column_view-off\"><input type=\"range\" onchange=\"polsun_val(this)\" class=\"rangeP\" id=\"cd0\" value=\"0\" max=\"1023\" min=\"0\" /></td>\n\r"
  "<td><div class=\"onoffswitch\"><input type=\"checkbox\" name=\"cb0\" class=\"onoffswitch-checkbox\" id=\"d0\" onclick=\"cb_check(this)\" />\n\r"
  "<label class=\"onoffswitch-label\" for=\"d0\"> <span class=\"onoffswitch-inner2\"></span> <span class=\"onoffswitch-switch\"></span></label>\n\r"
  "</div></td></tr>\n\r";

const static char file12[] PROGMEM =
  "<tr>\n\r"
  "<td><div class=\"onoffswitch\"><input type=\"checkbox\" name=\"cb9\" class=\"onoffswitch-checkbox\" id=\"d9\" onclick=\"cb_check2(this)\" checked=\"checked\" />\n\r"
  "<label class=\"onoffswitch-label\" for=\"d9\"> <span class=\"onoffswitch-inner\"></span> <span class=\"onoffswitch-switch\"></span> </label>\n\r"
  "</div></td>\n\r"
  "<td class=\"column_view-m column_view-off\"><input type=\"range\" onchange=\"polsun_val(this)\" class=\"rangeP\" id=\"cd9\" value=\"0\" max=\"1023\" min=\"0\"/></td>\n\r"
  "<td class=\"mode_view-m mode_view-off\"><input type=\"checkbox\" id=\"ci9\" name=\"ci9\" onclick=\"cb_check0(this)\" /></td>\n\r"
  "<td class=\"mode_view-m mode_view-off\"><select id=\"sd9\" name=\"sd9\" onchange=\"sel_test(this)\">\n\r"
  "<option  style=\"background-color: #d9fffe\">Input</option>\n\r"
  "<option style=\"background-color: #fffed9\" selected=\"selected\">Output</option></select></td>\n\r"
  "<td>SD2</td>\n\r"
  "<td>GPIO9</td>\n\r"
  "<td bgcolor=\"#666666\">&nbsp;</td>\n\r"
  "<td>GPIO2</td><td>D4</td><td class=\"mode_view-m mode_view-off\"><select id=\"sd2\" onchange=\"sel_test(this)\">\n\r"
  "<option  style=\"background-color: #d9fffe\">Input</option>\n\r"
  "<option style=\"background-color: #fffed9\" selected=\"selected\">Output</option></select></td>\n\r"
  "<td class=\"mode_view-m mode_view-off\"><input type=\"checkbox\" id=\"ci2\" name=\"ci2\" onclick=\"cb_check0(this)\" /></td>\n\r"
  "<td align=\"center\" class=\"column_view-m column_view-off\"><input type=\"range\" onchange=\"polsun_val(this)\" class=\"rangeP\" id=\"cd2\" value=\"0\" max=\"1023\" min=\"0\" /></td>\n\r"
  "<td><div class=\"onoffswitch\"><input type=\"checkbox\" name=\"cb2\" class=\"onoffswitch-checkbox\" id=\"d2\" onclick=\"cb_check(this)\"/>\n\r"
  "<label class=\"onoffswitch-label\" for=\"d2\"><span class=\"onoffswitch-inner2\"></span> <span class=\"onoffswitch-switch\"></span></label>\n\r"
  "</div></td>\n\r"
  "</tr>\n\r";

const static char file13[] PROGMEM =
  "<tr bgcolor=\"#CCCCCC\"><td>&nbsp;</td>\n\r"
  "<td class=\"column_view-m column_view-off\">&nbsp;</td>\n\r"
  "<td align=\"center\" class=\"mode_view-m mode_view-off\">i</td>\n\r"
  "<td class=\"mode_view-m mode_view-off\">&nbsp;</td>\n\r"
  "<td>SD1</td><td>MOSI</td><td bgcolor=\"#666666\">&nbsp;</td><td>&nbsp;</td><td bgcolor=\"#E10000\">3.3v</td><td class=\"mode_view-m mode_view-off\">&nbsp;</td>\n\r"
  "<td class=\"mode_view-m mode_view-off\">&nbsp;</td>\n\r"
  "<td align=\"center\" class=\"column_view-m column_view-off\">&nbsp;</td><td>&nbsp;</td></tr>\n\r"
  "<tr><td>&nbsp;</td>\n\r"
  "<td class=\"column_view-m column_view-off\">&nbsp;</td>\n\r"
  "<td align=\"center\" class=\"mode_view-m mode_view-off\">n</td>\n\r"
  "<td class=\"mode_view-m mode_view-off\">&nbsp;</td><td>CMD</td><td>CS</td>\n\r"
  "\n\r"
  "<td bgcolor=\"#666666\">&nbsp;</td><td>&nbsp;</td><td>GND</td><td class=\"mode_view-m mode_view-off\">&nbsp;</td>\n\r"
  "<td class=\"mode_view-m mode_view-off\">&nbsp;</td>\n\r"
  "<td align=\"center\" class=\"column_view-m column_view-off\">&nbsp;</td>\n\r"
  "<td>&nbsp;</td>\n\r"
  "</tr>\n\r";

const static char file14[] PROGMEM =
  "<tr bgcolor=\"#CCCCCC\">\n\r"
  "<td>&nbsp;</td>\n\r"
  "<td class=\"column_view-m column_view-off\">&nbsp;</td>\n\r"
  "<td align=\"center\" class=\"mode_view-m mode_view-off\">t</td>\n\r"
  "<td class=\"mode_view-m mode_view-off\">&nbsp;</td>\n\r"
  "<td>SD0</td><td>MISO</td>\n\r"
  "<td bgcolor=\"#666666\">&nbsp;</td>\n\r"
  "<td>GPIO14</td>\n\r"
  "<td>D5</td>\n\r"
  "<td class=\"mode_view-m mode_view-off\"><select id=\"sd14\" onchange=\"sel_test(this)\">\n\r"
  "<option  style=\"background-color: #d9fffe\">Input</option><option style=\"background-color: #fffed9\" selected=\"selected\">Output</option></select></td>\n\r"
  "<td class=\"mode_view-m mode_view-off\" width=\"20\"><input type=\"checkbox\" id=\"ci14\" name=\"ci14\" onclick=\"cb_check0(this)\" /></td>\n\r"
  "<td align=\"center\" class=\"column_view-m column_view-off\"><input type=\"range\" onchange=\"polsun_val(this)\" class=\"rangeP\" id=\"cd14\" value=\"0\" max=\"1023\" min=\"0\" /></td>\n\r"
  "<td width=\"34\"><div class=\"onoffswitch\"><input type=\"checkbox\" name=\"cb14\" class=\"onoffswitch-checkbox\" id=\"d14\" onclick=\"cb_check(this)\"/>\n\r"
  "<label class=\"onoffswitch-label\" for=\"d14\"> <span class=\"onoffswitch-inner2\"></span> <span class=\"onoffswitch-switch\"></span></label>\n\r"
  "</div></td>\n\r"
  "</tr>\n\r";

const static char file15[] PROGMEM =
  "<tr>\n\r"
  "<td>&nbsp;</td>\n\r"
  "<td class=\"column_view-m column_view-off\">&nbsp;</td>\n\r"
  "<td align=\"center\" class=\"mode_view-m mode_view-off\">e</td>\n\r"
  "<td class=\"mode_view-m mode_view-off\">&nbsp;</td>\n\r"
  "<td>CLK</td><td>SCLK</td>\n\r"
  "<td bgcolor=\"#666666\">&nbsp;</td>\n\r"
  "<td>GPIO12</td>\n\r"
  "<td>D6</td>\n\r"
  "<td class=\"mode_view-m mode_view-off\"><select id=\"sd12\" onchange=\"sel_test(this)\">\n\r"
  "<option  style=\"background-color: #d9fffe\">Input</option><option style=\"background-color: #fffed9\" selected=\"selected\">Output</option></select></td>\n\r"
  "<td class=\"mode_view-m mode_view-off\"><input type=\"checkbox\" id=\"ci12\" name=\"ci12\" onclick=\"cb_check0(this)\" /></td>\n\r"
  "<td align=\"center\" class=\"column_view-m column_view-off\"><input type=\"range\" onchange=\"polsun_val(this)\" class=\"rangeP\" id=\"cd12\" value=\"0\" max=\"1023\" min=\"0\" /></td>\n\r"
  "<td><div class=\"onoffswitch\"><input type=\"checkbox\" name=\"cb12\" class=\"onoffswitch-checkbox\" id=\"d12\" onclick=\"cb_check(this)\"/><label class=\"onoffswitch-label\" for=\"d12\">\n\r"
  "<span class=\"onoffswitch-inner2\"></span> <span class=\"onoffswitch-switch\"></span></label>\n\r"
  "</div></td>\n\r"
  "</tr>\n\r";

const static char file16[] PROGMEM =
  "<tr bgcolor=\"#CCCCCC\">\n\r"
  "<td>&nbsp;</td>\n\r"
  "<td class=\"column_view-m column_view-off\">&nbsp;</td>\n\r"
  "<td align=\"center\" class=\"mode_view-m mode_view-off\">r</td>\n\r"
  "<td class=\"mode_view-m mode_view-off\">&nbsp;</td>\n\r"
  "<td>GND</td>\n\r"
  "<td>&nbsp;</td>\n\r"
  "<td bgcolor=\"#666666\">&nbsp;</td>\n\r"
  "<td>GPIO13</td><td>D7</td><td class=\"mode_view-m mode_view-off\"><select id=\"sd13\" onchange=\"sel_test(this)\">\n\r"
  "<option  style=\"background-color: #d9fffe\">Input</option><option style=\"background-color: #fffed9\" selected=\"selected\">Output</option></select></td>\n\r"
  "<td class=\"mode_view-m mode_view-off\"><input type=\"checkbox\" id=\"ci13\" name=\"ci13\" onclick=\"cb_check0(this)\" /></td>\n\r"
  "<td align=\"center\" class=\"column_view-m column_view-off\"><input type=\"range\" onchange=\"polsun_val(this)\" class=\"rangeP\" id=\"cd13\" value=\"0\" max=\"1023\" min=\"0\" /></td>\n\r"
  "<td><div class=\"onoffswitch\"><input type=\"checkbox\" name=\"cb13\" class=\"onoffswitch-checkbox\" id=\"d13\" onclick=\"cb_check(this)\"/>\n\r"
  "<label class=\"onoffswitch-label\" for=\"d13\"> <span class=\"onoffswitch-inner2\"></span> <span class=\"onoffswitch-switch\"></span></label>\n\r"
  "</div></td>\n\r"
  "</tr>\n\r";

const static char file17[] PROGMEM =
  "<tr>\n\r"
  "<td>&nbsp;</td>\n\r"
  "<td class=\"column_view-m column_view-off\">&nbsp;</td>\n\r"
  "<td align=\"center\" class=\"mode_view-m mode_view-off\">r</td>\n\r"
  "<td class=\"mode_view-m mode_view-off\">&nbsp;</td>\n\r"
  "<td bgcolor=\"#E10000\">3.3v</td><td>&nbsp;</td>\n\r"
  "<td bgcolor=\"#666666\">&nbsp;</td>\n\r"
  "<td>GPIO15</td><td>D8</td>\n\r"
  "<td class=\"mode_view-m mode_view-off\"><select id=\"sd15\" onchange=\"sel_test(this)\">\n\r"
  "<option style=\"background-color: #d9fffe\">Input</option><option style=\"background-color: #fffed9\" selected=\"selected\">Output</option></select></td>\n\r"
  "<td class=\"mode_view-m mode_view-off\"><input type=\"checkbox\" id=\"ci15\" name=\"ci15\" onclick=\"cb_check0(this)\" /></td>\n\r"
  "<td align=\"center\" class=\"column_view-m column_view-off\"><input type=\"range\" onchange=\"polsun_val(this)\" class=\"rangeP\" id=\"cd15\" value=\"0\" max=\"1023\" min=\"0\" /></td>\n\r"
  "<td><div class=\"onoffswitch\">\n\r"
  "<input type=\"checkbox\" name=\"cb15\" class=\"onoffswitch-checkbox\" id=\"d15\" onclick=\"cb_check(this)\"/>\n\r"
  "<label class=\"onoffswitch-label\" for=\"d15\">\n\r"
  "<span class=\"onoffswitch-inner2\"></span><span class=\"onoffswitch-switch\"></span></label>\n\r"
  "</div></td>\n\r"
  "</tr>\n\r";

const static char file18[] PROGMEM =
  "<tr bgcolor=\"#CCCCCC\">\n\r"
  "<td>&nbsp;</td>\n\r"
  "<td class=\"column_view-m column_view-off\">system</td>\n\r"
  "<td align=\"center\" class=\"mode_view-m mode_view-off\">u</td>\n\r"
  "<td class=\"mode_view-m mode_view-off\">system</td>\n\r"
  "<td>EN</td>\n\r"
  "<td>EN</td>\n\r"
  "<td bgcolor=\"#666666\">&nbsp;</td>\n\r"
  "<td>GPIO3</td>\n\r"
  "<td>D9</td>\n\r"
  "<td class=\"mode_view-m mode_view-off\">&nbsp;</td>\n\r"
  "<td class=\"mode_view-m mode_view-off\">&nbsp;</td>\n\r"
  "<td align=\"center\" class=\"column_view-m column_view-off\">&nbsp;</td>\n\r"
  "<td><div class=\"onoffswitch\"><input type=\"checkbox\" name=\"cb3\" class=\"onoffswitch-checkbox\" id=\"d3\" onclick=\"cb_check0(this)\"/><label class=\"onoffswitch-label\" for=\"d3\">\n\r"
  "<span class=\"onoffswitch-inner2\"></span> <span class=\"onoffswitch-switch\"></span></label>\n\r"
  "</div></td>\n\r"
  "</tr>\n\r";

const static char file19[] PROGMEM =
  "<tr>\n\r"
  "<td>&nbsp;</td>\n\r"
  "<td class=\"column_view-m column_view-off\">system</td>\n\r"
  "<td align=\"center\" class=\"mode_view-m mode_view-off\">p</td>\n\r"
  "<td class=\"mode_view-m mode_view-off\">system</td>\n\r"
  "<td>RST</td><td>RST</td>\n\r"
  "<td bgcolor=\"#666666\">&nbsp;</td>\n\r"
  "<td>GPIO1</td>\n\r"
  "<td>D10</td>\n\r"
  "<td class=\"mode_view-m mode_view-off\">&nbsp;</td>\n\r"
  "<td class=\"mode_view-m mode_view-off\">&nbsp;</td>\n\r"
  "<td align=\"center\" class=\"column_view-m column_view-off\">&nbsp;</td>\n\r"
  "<td><div class=\"onoffswitch\"><input type=\"checkbox\" name=\"cb1\" class=\"onoffswitch-checkbox\" id=\"d1\" onclick=\"cb_check0(this)\"/>\n\r"
  "<label class=\"onoffswitch-label\" for=\"d1\"> <span class=\"onoffswitch-inner2\"></span> <span class=\"onoffswitch-switch\"></span></label></div></td></tr>\n\r"
  "\n\r"
  "<tr bgcolor=\"#CCCCCC\"><td>&nbsp;</td><td class=\"column_view-m column_view-off\">&nbsp;</td>\n\r"
  "<td align=\"center\" class=\"mode_view-m mode_view-off\">t</td>\n\r"
  "<td class=\"mode_view-m mode_view-off\">&nbsp;</td>\n\r"
  "<td>GND</td><td>&nbsp;</td><td bgcolor=\"#666666\">&nbsp;</td><td>&nbsp;</td><td>GND</td><td class=\"mode_view-m mode_view-off\">&nbsp;</td>\n\r"
  "<td class=\"mode_view-m mode_view-off\">&nbsp;</td>\n\r"
  "<td align=\"center\" class=\"column_view-m column_view-off\">&nbsp;</td><td>&nbsp;</td></tr><tr bgcolor=\"#E10000\"><td>&nbsp;</td><td class=\"column_view-m column_view-off\">&nbsp;</td>\n\r"
  "<td class=\"mode_view-m mode_view-off\">&nbsp;</td>\n\r"
  "<td class=\"mode_view-m mode_view-off\">&nbsp;</td><td  bgcolor=\"#FFFF9D\">Vin</td><td>&nbsp;</td><td bgcolor=\"#666666\">&nbsp;</td><td>&nbsp;</td><td>3.3v</td>\n\r"
  "<td class=\"mode_view-m mode_view-off\">&nbsp;</td>\n\r"
  "<td class=\"mode_view-m mode_view-off\">&nbsp;</td>\n\r"
  "\n\r"
  "<td align=\"center\" class=\"column_view-m column_view-off\">&nbsp;</td><td>&nbsp;</td></tr>\n\r"
  "</tbody></table></body></html>\n\r";

const char* const string_table[] PROGMEM = {file0, file1, file2, file3, file4, file5, file6, file7, file8, file9,
                                            file10, file11, file12, file13, file14, file15, file16, file17, file18,
                                            file19
                                           };


int pin = 2;
int sos = 0;
int Key_avto = 0;     //ключ передачи данных по таймеру
int cikl_avto = 1000; //интервал ~1 сек
int cikl_current = 0; //интервал ~1 сек
int Key_output = 1; //1- автоматически устанавливать mode = OUTPUT
String priem = "";
String mess = "";

WiFiServer server(80);
//WiFiClient client = server.available();  //ruben
WiFiClient client;// = server.available(); //ruben

int temp_count = 0;

void setup()
{
  initHardware();
  setupWiFi();
  server.begin();
  IPAddress ip = WiFi.softAPIP();
  file3a = "str_URL2=\"http://" + String(ip[0]) + '.' + String(ip[1]) + '.' + String(ip[2]) + '.' + String(ip[3]) + "/led?\" + str_URL;";
  Serial.println("");                    //для определения IP через терминал
  //Serial.print("IP address: ");        //для определения IP через терминал
  //Serial.println(WiFi.softAPIP());     //для определения IP через терминал
}

void loop()
{
/* 
  if (Key_avto == 1) {
    cikl_current += 1;
    //char c = client.read();  //провоцирующее чтение
    if (cikl_current >= cikl_avto)
    {
      if (client.available()) {
        client.flush();
        char c = client.read();  //провоцирующее чтение
        //  temp_count += 1;
        mess = "Get result=&out1=13&out2=19&out3=t:";
        mess += cikl_current;
        out_mess(mess);
        client.flush();
        cikl_current = 0;
      }
    }
    //Serial.println(cikl_current);
  }
*/  
  //  WiFiClient client = server.available(); //так было ruben
  client = server.available();
  if (!client) {
    return;
  }
  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.print("From client: ");
  Serial.println(req);
  priem = req;
  mess = "";
  analis();
  delay(1);
  Serial.println("Client disonnected");
}

void setupWiFi()
{
  WiFi.mode(WIFI_AP);
  // Do a little work to get a unique-ish name. Append the
  // last two bytes of the MAC (HEX'd) to "ThingDev-":
  uint8_t mac[WL_MAC_ADDR_LENGTH];
  WiFi.softAPmacAddress(mac);
  String macID = String(mac[WL_MAC_ADDR_LENGTH - 2], HEX) +
                 String(mac[WL_MAC_ADDR_LENGTH - 1], HEX);
  macID.toUpperCase();
  String AP_NameString = "ThingDev-" + macID;

  char AP_NameChar[AP_NameString.length() + 1];
  memset(AP_NameChar, 0, AP_NameString.length() + 1);

  for (int i = 0; i < AP_NameString.length(); i++)
    AP_NameChar[i] = AP_NameString.charAt(i);

  WiFi.softAP(AP_NameChar, WiFiAPPSK);
}

void analis()
{
  int ind1 = priem.indexOf('?');              //граница начала данных
  int ind2 = priem.indexOf('=');              //граница
  String    zapros = priem.substring(ind1 + 1, ind2);    //cb2  (=0) или cbA0
  String vetka = zapros.substring(0, 2);
  Serial.println(zapros);  //test
  zapros.remove(0, 2);                                   //2         или A0
  if (zapros != "A0") {
    pin = zapros.toInt();                     //Аналоговый вход A0 = 20
  } else {
    pin = 20;
  }
  priem.remove(0, ind2 + 1); //все после знака =         0 HTTP/1.1
  ind1 = priem.indexOf(' ');
  zapros = priem.substring(0, ind1); //все до пробела    0
  sos = zapros.toInt();              //преобразовали значение в цифру
  if (vetka == "GE" or vetka == "ne")     //первый запрос- проверка
  {
    client.flush();
    for (int i = 0; i < 4; i++)
    { mess = string_table[i];
      client.print(mess);
      delay( 10 );
    }
    client.print(file3a);
    for (int i = 4; i < 20; i++)
    { mess = string_table[i];
      client.print(mess);
      //mess = "";
      delay( 10 );
    }
  } else {
    if (vetka == "cb")          //on/off
    {
      if (pin != 20) {
        if (Key_output > 0)
        {
          pinMode(pin, OUTPUT);
          analogWrite(pin, 0); //для режима прямого управления
        }
        digitalWrite(pin, sos);
        mess = "digitalWrite(GPIO";
        form_mess(mess, pin, sos);
      } else {
        if (sos == 0) {
          pinMode(A0, OUTPUT);  //??
          mess = "pinMode(";
          form_mess(mess, pin, -2); //-2 OUTPUT
        } else {
          pinMode(A0, INPUT);
          mess = "pinMode(";  //-3 INPUT
          form_mess(mess, pin, -3);
        }
      }
    } else {
      if (vetka == "cd") {    //potenciometr
        if (pin != 20) {
          if (Key_output > 0)
          {
            pinMode(pin, OUTPUT);
          }
          analogWrite(pin, sos);
          mess = "analogWrite(GPIO";
          form_mess(mess, pin, sos);
        } else {
          //analogWrite(A0, sos);
        }
      } else {
        if (vetka == "sd")     //mode
        {
          switch (sos)
          {
            case 0: {
                if (pin == 20) {
                  pinMode(A0, INPUT);
                  mess = "pinMode(";
                  form_mess(mess, pin, -3);
                } else {
                  pinMode(pin, INPUT);
                  mess = " pinMode(GPIO";
                  form_mess(mess, pin, -3);
                }
                break;
              }
            case 1: {
                if (pin == 20) {
                  pinMode(A0, OUTPUT);
                  mess = "pinMode(";
                  form_mess(mess, pin, -2);
                } else {
                  pinMode(pin, OUTPUT);
                  mess = " pinMode(GPIO";
                  form_mess(mess, pin, -2);
                }
                break;
              }
            default: {
                Serial.println("mode ERROR - " + pin);
                break;
              }
          }
        } else {
          if  (vetka == "ci") {   //INTERRUPT
            switch (sos)
            {
              case 0: {
                  detachInterrupt(digitalPinToInterrupt(pin));
                  mess = "Interrupt disabled: GPIO";
                  form_mess(mess, pin, -1);

                  Serial.print("Interrupt disabled: pin ");
                  Serial.println(pin);
                  break;
                }
              case 1: {
                  attachInterrupt(digitalPinToInterrupt(pin), INTERRUPT_ok, CHANGE);
                  mess = "Interrupt enabled: GPIO";
                  form_mess(mess, pin, -1);
                  Serial.print("Interrupt enabled: pin ");
                  Serial.println(pin);
                  break;
                }
              default: {
                  Serial.println("Interrupt ERROR - " + pin);
                  break;
                }
            }
          } else {
            if (vetka == "ce") {
              Key_output = sos;               //_mess("Get result=&out2=34&out1=19&out3=test");
              if (sos == 0) {
                mess = "avtooutput turn-off = "; //знак равно автоматически выбросится из параметров
              }
              else {
                mess = "avtooutput turn-on = "; //знак равно автоматически выбросится из параметров
              }
              form_mess(mess, sos , -1);
            } else {
              if (vetka == "tt") {
                Key_avto = sos;
                if (sos == 0) {
                  mess = "timer off = "; //знак равно автоматически выбросится из параметров
                }
                else {
                  mess = "timer on = ";  //знак равно автоматически выбросится из параметров
                }
                form_mess(mess, sos , -1);
              } else {
                if (vetka == "zz") { //запрос параметров
                  client.flush();
                  // char c = client.read();                       //провоцирующее чтение
                  mess = "Get result=&out1=13&out2=19&out3=t:"; //проверка передачи
                  mess += cikl_current;                         //параметров
                  cikl_current += 1;
                  out_mess(mess);            //передача после любого запроса от клиента

                }
              }
            }
          }
        }
      }
    }      out_mess(mess);
  }
  // Serial.println("vetka - " + vetka + ", pin - " + pin + ", vol - " + sos);
}

void form_mess(String m_str, int spin, int ssos) {
  mess = "Get result=&ex_out=" + m_str;
  if (spin != 20) {
    mess += spin;
  } else {
    mess += "A0";
  }
  if (ssos != -1) {
    mess += ", ";
    if (ssos == -2) {
      mess += "OUTPUT";
    } else {
      if (ssos == -3) {
        mess += "INPUT";
      } else    mess += ssos;
    }
    mess += ");";
  }
  out_mess(mess);
}

void out_mess(String m_str)
{
  //Serial.print(m_str);
    client.flush();
  // отправляем запрос на сервер
  client.print(m_str);
//  delay(1000);
}

void INTERRUPT_ok()
{
  switch (pin) {
    case 0: {
        break;
      }
    case 2: {
        break;
      }
    case 4: {
      digitalWrite(16,  HIGH);
      digitalWrite(2, LOW);
      delay(300);
      digitalWrite(16, LOW);
      digitalWrite(2,  HIGH);
      delay(300);
      digitalWrite(16,  HIGH);
      digitalWrite(2, LOW);
      delay(300);
      digitalWrite(16, LOW);
      digitalWrite(2,  HIGH);
      delay(300);
      digitalWrite(16,  HIGH);
      digitalWrite(2, LOW);
      delay(300);
      digitalWrite(16, LOW);
      digitalWrite(2,  HIGH);
        break;
      }
    case 5: {
        break;
      }
    case 9: {
        break;
      }
    case 10: {
        break;
      }
    case 12: {
        break;
      }
    case 13: {
        break;
      }
    case 14: {
        break;
      }
    case 15: {
        break;
      }
    default:
      // if nothing else matches, do the default
      // default is optional
      break;
  }
  Serial.print("INTERRUPT ok - ");
  Serial.println(pin);
}

void initHardware()
{
  Serial.begin(115200);
}
