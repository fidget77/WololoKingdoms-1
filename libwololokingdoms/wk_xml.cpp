#include "wk_xml.h"
#include <ostream>

void write_wk_xml(std::ostream& output, int dlc_level) {
  auto name = dlc_level >= 3
                  ? "Age of Empires II: Rise of the Rajas"
                  : dlc_level >= 2 ? "Age of Empires II: African Kingdoms"
                                   : "Age of Empires II: The Forgotten";

  auto path = dlc_level >= 3
                  ? "WololoKingdoms"
                  : dlc_level >= 2 ? "WololoKingdoms AK" : "WololoKingdoms FE";

  output
      // BOM is required by UP
      << '\xEF' << '\xBB' << '\xBF'
      << R"(<?xml version="1.0" encoding="utf-8"?>)" << std::endl
      << R"(<configuration game="WK">)" << std::endl
      << R"(  <name>)" << name << R"(</name>)" << std::endl
      << R"(  <path>)" << path << R"(</path>)" << std::endl
      << R"(  <civilizations langId="10270" descId="20150" aiNameOffset="6840" uiBaseId="51100" uiStride="40" uiOffset="0">)"
      << std::endl
      << R"(    <civilization id="0" name="gaia" soundFile="stream\random.mp3" scoutUnit="448" uniqueUnit="0" eliteUniqueUnit="0" uniqueUnitLine="0" uniqueUnitUpgrade="0" uniqueResearch="0" />)"
      << std::endl
      << R"(    <civilization id="2" name="briton" soundFile="stream\british.mp3" scoutUnit="448" uniqueUnit="8" eliteUniqueUnit="530" uniqueUnitLine="-277" uniqueUnitUpgrade="360" uniqueResearch="3" />)"
      << std::endl
      << R"(    <civilization id="6" name="frankish" soundFile="stream\french.mp3" scoutUnit="448" uniqueUnit="281" eliteUniqueUnit="531" uniqueUnitLine="-272" uniqueUnitUpgrade="363" uniqueResearch="83" />)"
      << std::endl
      << R"(    <civilization id="7" name="gothic" soundFile="stream\goth.mp3" scoutUnit="448" uniqueUnit="41" eliteUniqueUnit="555" uniqueUnitLine="-279" uniqueUnitUpgrade="365" uniqueResearch="16" />)"
      << std::endl
      << R"(    <civilization id="16" name="teutonic" soundFile="stream\teuton.mp3" scoutUnit="448" uniqueUnit="25" eliteUniqueUnit="554" uniqueUnitLine="-273" uniqueUnitUpgrade="364" uniqueResearch="11" />)"
      << std::endl
      << R"(    <civilization id="9" name="japanese" soundFile="stream\japanese.mp3" scoutUnit="448" uniqueUnit="291" eliteUniqueUnit="560" uniqueUnitLine="-274" uniqueUnitUpgrade="366" uniqueResearch="59" />)"
      << std::endl
      << R"(    <civilization id="5" name="chinese" soundFile="stream\chinese.mp3" scoutUnit="448" uniqueUnit="73" eliteUniqueUnit="559" uniqueUnitLine="-280" uniqueUnitUpgrade="362" uniqueResearch="52" />)"
      << std::endl
      << R"(    <civilization id="3" name="byzantine" soundFile="stream\byzantin.mp3" scoutUnit="448" uniqueUnit="40" eliteUniqueUnit="553" uniqueUnitLine="-281" uniqueUnitUpgrade="361" uniqueResearch="61" />)"
      << std::endl
      << R"(    <civilization id="13" name="persian" soundFile="stream\persian.mp3" scoutUnit="448" uniqueUnit="239" eliteUniqueUnit="558" uniqueUnitLine="-271" uniqueUnitUpgrade="367" uniqueResearch="7" />)"
      << std::endl
      << R"(    <civilization id="14" name="saracen" soundFile="stream\saracen.mp3" scoutUnit="448" uniqueUnit="282" eliteUniqueUnit="556" uniqueUnitLine="-276" uniqueUnitUpgrade="368" uniqueResearch="9" />)"
      << std::endl
      << R"(    <civilization id="17" name="turkish" soundFile="stream\turk.mp3" scoutUnit="448" uniqueUnit="46" eliteUniqueUnit="557" uniqueUnitLine="-278" uniqueUnitUpgrade="369" uniqueResearch="10" />)"
      << std::endl
      << R"(    <civilization id="18" name="viking" soundFile="stream\viking.mp3" scoutUnit="448" uniqueUnit="692" eliteUniqueUnit="694" uniqueUnitLine="-282" uniqueUnitUpgrade="398" uniqueResearch="49" />)"
      << std::endl
      << R"(    <civilization id="12" name="mongol" soundFile="stream\mongol.mp3" scoutUnit="448" uniqueUnit="11" eliteUniqueUnit="561" uniqueUnitLine="-275" uniqueUnitUpgrade="371" uniqueResearch="6" />)"
      << std::endl
      << R"(    <civilization id="4" name="celtic" soundFile="stream\celt.mp3" scoutUnit="448" uniqueUnit="232" eliteUniqueUnit="534" uniqueUnitLine="-269" uniqueUnitUpgrade="370" uniqueResearch="5" />)"
      << std::endl
      << R"(    <civilization id="15" name="spanish" soundFile="stream\spanish.mp3" scoutUnit="448" uniqueUnit="771" eliteUniqueUnit="773" uniqueUnitLine="-264" uniqueUnitUpgrade="60" uniqueResearch="440" />)"
      << std::endl
      << R"(    <civilization id="1" name="aztec" soundFile="stream\aztecs.mp3" scoutUnit="751" uniqueUnit="725" eliteUniqueUnit="726" uniqueUnitLine="-268" uniqueUnitUpgrade="432" uniqueResearch="24" />)"
      << std::endl
      << R"(    <civilization id="11" name="mayan" soundFile="stream\mayans.mp3" scoutUnit="751" uniqueUnit="763" eliteUniqueUnit="765" uniqueUnitLine="-266" uniqueUnitUpgrade="27" uniqueResearch="4" />)"
      << std::endl
      << R"(    <civilization id="8" name="hun" soundFile="stream\huns.mp3" scoutUnit="448" uniqueUnit="755" eliteUniqueUnit="757" uniqueUnitLine="-265" uniqueUnitUpgrade="2" uniqueResearch="21" />)"
      << std::endl
      << R"(    <civilization id="10" name="korean" soundFile="stream\koreans.mp3" scoutUnit="448" uniqueUnit="827" eliteUniqueUnit="829" uniqueUnitLine="-270" uniqueUnitUpgrade="450" uniqueResearch="445" />)"
      << std::endl;

  // FE civs
  output
      << R"(    <civilization id="19" name="italian" soundFile="stream\italians.mp3" scoutUnit="448" uniqueUnit="866" eliteUniqueUnit="868" uniqueUnitLine="866" uniqueUnitUpgrade="468" uniqueResearch="499" />)"
      << std::endl
      << R"(    <civilization id="20" name="indian" soundFile="stream\indians.mp3" scoutUnit="448" uniqueUnit="873" eliteUniqueUnit="875" uniqueUnitLine="873" uniqueUnitUpgrade="481" uniqueResearch="507" />)"
      << std::endl
      << R"(    <civilization id="21" name="incan" soundFile="stream\incas.mp3" scoutUnit="751" uniqueUnit="879" eliteUniqueUnit="881" uniqueUnitLine="879" uniqueUnitUpgrade="509" uniqueResearch="517" />)"
      << std::endl
      << R"(    <civilization id="22" name="magyar" soundFile="stream\magyars.mp3" scoutUnit="448" uniqueUnit="869" eliteUniqueUnit="871" uniqueUnitLine="869" uniqueUnitUpgrade="472" uniqueResearch="515" />)"
      << std::endl
      << R"(    <civilization id="23" name="slavic" soundFile="stream\slavs.mp3" scoutUnit="448" uniqueUnit="876" eliteUniqueUnit="878" uniqueUnitLine="876" uniqueUnitUpgrade="504" uniqueResearch="513" />)"
      << std::endl
      << R"(    <civilization id="24" name="portuguese" soundFile="stream\portuguese.mp3" scoutUnit="448" uniqueUnit="106" eliteUniqueUnit="114" uniqueUnitLine="106" uniqueUnitUpgrade="563" uniqueResearch="573" />)"
      << std::endl;

  if (dlc_level >= 2) {
    output
        << R"(    <civilization id="25" name="ethiopian" soundFile="stream\ethiopians.mp3" scoutUnit="448" uniqueUnit="453" eliteUniqueUnit="459" uniqueUnitLine="453" uniqueUnitUpgrade="569" uniqueResearch="575" />)"
        << std::endl
        << R"(    <civilization id="26" name="malian" soundFile="stream\malians.mp3" scoutUnit="448" uniqueUnit="260" eliteUniqueUnit="418" uniqueUnitLine="260" uniqueUnitUpgrade="567" uniqueResearch="577" />)"
        << std::endl
        << R"(    <civilization id="27" name="berbers" soundFile="stream\berbers.mp3" scoutUnit="448" uniqueUnit="203" eliteUniqueUnit="208" uniqueUnitLine="203" uniqueUnitUpgrade="565" uniqueResearch="579" />)"
        << std::endl;
  }

  if (dlc_level >= 3) {
    output
        << R"(    <civilization id="28" name="khmer" soundFile="stream\khmer.mp3" scoutUnit="448" uniqueUnit="760" eliteUniqueUnit="891" uniqueUnitLine="760" uniqueUnitUpgrade="615" uniqueResearch="623" />)"
        << std::endl
        << R"(    <civilization id="29" name="malay" soundFile="stream\malay.mp3" scoutUnit="448" uniqueUnit="836" eliteUniqueUnit="830" uniqueUnitLine="836" uniqueUnitUpgrade="617" uniqueResearch="625" />)"
        << std::endl
        << R"(    <civilization id="30" name="burmese" soundFile="stream\burmese.mp3" scoutUnit="448" uniqueUnit="823" eliteUniqueUnit="811" uniqueUnitLine="823" uniqueUnitUpgrade="619" uniqueResearch="627" />)"
        << std::endl
        << R"(    <civilization id="31" name="vietnamese" soundFile="stream\vietnamese.mp3" scoutUnit="448" uniqueUnit="784" eliteUniqueUnit="782" uniqueUnitLine="784" uniqueUnitUpgrade="621" uniqueResearch="629" />)"
        << std::endl;
  }

  output << R"(  </civilizations>)" << std::endl
         << R"(</configuration>)" << std::endl;
}
