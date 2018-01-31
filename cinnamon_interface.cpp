#include "cinnamon_interface.h"

Cinnamon_Interface::Cinnamon_Interface()
{

}

/////////////////////////////////  SLOTS   /////////////////////////////////

void Cinnamon_Interface::addArea(DesktopArea area){
    //find lowest possible area id in order to prevent the ids to explode
    int area_id = 0;
    bool already_taken = true;
    while(already_taken){
        already_taken = false;
        area_id++;
        for(const DesktopArea& area : areas){
            if(area.area_id == area_id){
                already_taken = true;
                break;
            }
        }
    }
    area.area_id = area_id;
    areas.push_back(area);
    area_to_modify = areas.size()-1;
    redrawArea();
}

void Cinnamon_Interface::setAreaToModify(const int x, const int y){
    area_to_modify = -1;

    for(size_t i = 0; i < areas.size(); i++){
        if(areas[i].title.compare(area_name) == 0){
            area_to_modify = i;
            emit activateAreaMenu(areas[i]);
            break;
        }
    }
}

void Cinnamon_Interface::renameArea(const std::string area_name){
    areas[area_to_modify].title = area_name;
    redrawArea();
}

void Cinnamon_Interface::resizeArea(const int x, const int y, const int width, const int height){
    areas[area_to_modify].x=x;
    areas[area_to_modify].y=y;
    areas[area_to_modify].width=width;
    areas[area_to_modify].height=height;
    redrawArea();
}

void Cinnamon_Interface::changeAreaColor(const QRgb color){
    areas[area_to_modify].color = color;
    redrawArea();
}

void Cinnamon_Interface::deleteArea(){
    int area_id = areas[area_to_modify].area_id;
    areas.erase(areas.begin()+area_to_modify);

    for(DesktopItem& item : items){
        if(item.area == area_id){
            item.area = -1;
        }
    }

    area_to_modify = -1;
    redrawArea();
}


/////////////////////////////////  INTERNAL   /////////////////////////////////

bool Cinnamon_Interface::getDesktopImage(){

}

bool Cinnamon_Interface::redrawArea(){
    if(area_to_modify == -1){//redraw all areas

    }
    else{

    }

    return true;
}

bool Cinnamon_Interface::applyAndUpdateConfig(){

}

/////////////////////////////////  SYSTEM SPECIFIC   /////////////////////////////////

bool Cinnamon_Interface::getCurrentItems(){}

bool Cinnamon_Interface::setItemPosition(const std::string item_name){}

bool Cinnamon_Interface::setItemPosition(const DesktopItem& item_name){}

bool Cinnamon_Interface::updateDesktop(){}


/////////////////////////////////  IO   /////////////////////////////////

bool Cinnamon_Interface::loadConfig(const std::string file_path){}

bool Cinnamon_Interface::saveConfig(const std::string file_path){}
