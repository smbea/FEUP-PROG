#include "Line.h"


Line::Line(string textLine){

  // INITIALISATION CODE GOES IN HERE

  //RECOLHER O ID
  int firstPos = 0;

  int semicolonPos = textLine.find(";", firstPos);

  string ids = textLine.substr(firstPos, semicolonPos - firstPos);
  int idN = stoi(ids);

  id = idN;

  //RECOLHER A FREQUENCIA
  firstPos = semicolonPos + 2;

  semicolonPos = textLine.find(";", firstPos);

  string frequencyS = textLine.substr(firstPos, semicolonPos - firstPos);
  int freq = stoi(frequencyS);

  frequency = freq;

  // RECOLHER AS PARAGENS

  firstPos = semicolonPos + 2;
  semicolonPos = textLine.find(";", firstPos);
  int commaPos = textLine.find(",", firstPos);
  while (commaPos < semicolonPos)
  {
    string stop = textLine.substr(firstPos, commaPos - firstPos);

    busStopList.push_back(stop);

    firstPos = commaPos + 2;
    commaPos = textLine.find(",", firstPos);
  }
  //Extrai ultima paragem
  string stop = textLine.substr(firstPos, semicolonPos - firstPos);
  busStopList.push_back(stop);

  // RECOLHER AS DURACOES

  firstPos = semicolonPos + 2;
  commaPos = textLine.find(",", firstPos);
  while (commaPos < textLine.length())
  {
    string duration = textLine.substr(firstPos, commaPos - firstPos);

    int dur = stoi(duration);

    timesList.push_back(dur);

    firstPos = commaPos + 2;
    commaPos = textLine.find(",", firstPos);
  }
  //Extrai ultima duracao
  string duration = textLine.substr(firstPos, commaPos - firstPos);

  int dur = stoi(duration);
  timesList.push_back(dur);

}

////////////////
// get methods
////////////////

unsigned int Line::getId() const{
  return id;
}

unsigned int Line::getFrequency() const{
    return frequency;
}

vector<string> Line::getBusStops() const{
  return busStopList;
}

vector<int> Line::getTimings() const{
  return timesList;
}
