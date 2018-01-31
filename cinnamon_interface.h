#ifndef CINNAMON_INTERFACE_H
#define CINNAMON_INTERFACE_H

#include <string>
#include <vector>

#include <QImage>

struct DesktopItem{
    std::string name;
    std::pair<int,int> position;
    int area;
};

struct DesktopArea{
    std::string title;
    int area_id;

    int x;
    int y;
    int width;
    int height;

    QRgb color;
};

class Cinnamon_Interface
{
public:
    Cinnamon_Interface();

public slots:
    void addArea(DesktopArea area);
    void setAreaToModify(const int x, const int y);
    void renameArea(const std::string area_name);
    void resizeArea(const int x, const int y, const int width, const int height);
    void changeAreaColor(const QRgb color);
    void deleteArea();

private:
    std::string background_image_dir;
    QImage original_background;
    QImage current_background;

    std::vector<DesktopItem> items;
    std::vector<DesktopArea> areas;
    int area_to_modify = -1;

    bool redrawArea();
    bool applyAndUpdateConfig();

    ////////////////////  SYSTEM SPECIFIC  ///////////////////
    bool getDesktopImage();
    bool getCurrentItems();
    bool setItemPosition(const std::string item_name);
    bool setItemPosition(const DesktopItem& item_name);
    bool updateDesktop();

    //////////////////////////  IO  //////////////////////////
    bool loadConfig(const std::string file_path);
    bool saveConfig(const std::string file_path);

signals:
    void activateAreaMenu(const DesktopArea& area);
};

#endif // CINNAMON_INTERFACE_H
