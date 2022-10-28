#ifndef LR2_CHARTCONTROL_H
#define LR2_CHARTCONTROL_H

#include <wx/wx.h>
#include <vector>
#include <string>

class ChartControl : public wxWindow
{
public:
    ChartControl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size);
    ChartControl(int i);

    std::vector<double> values;
    std::string title;

private:
    void OnPaint(wxPaintEvent& evt);
    std::tuple<int, double, double> calculateChartSegmentCountAndRange(double origLow, double origHigh);
};

#endif //LR2_CHARTCONTROL_H
