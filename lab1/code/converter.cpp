#include "converter.h"
#include "QVector"
#include "QString"
#include <math.h>

converter::converter()
{

}

QVector <int> converter::conv(QColor color, QString format)
{
    QVector <int> answer;
    if(format == "RGB")
    {
        answer.push_back(color.red());
        answer.push_back(color.green());
        answer.push_back(color.blue());
        answer.push_back(0);
    }
    else if(format == "CMYK")
    {
        answer.push_back(color.cyan());
        answer.push_back(color.magenta());
        answer.push_back(color.yellow());
        answer.push_back(color.black());
    }
    else if(format == "LAB")
    {
        answer = toxyz(color.red(),color.green(),color.blue());
        answer = tolab(answer[0],answer[1],answer[2]);
    }
    else if(format == "HLS")
    {
        answer.push_back(color.hslHue());
        answer.push_back(color.lightness());
        answer.push_back(color.hslSaturation());
        answer.push_back(0);
    }
    else if(format == "HSV")
    {
        answer.push_back(color.hsvHue());
        answer.push_back(color.hsvSaturation());
        answer.push_back(color.value());
        answer.push_back(0);
    }
    else if(format == "XYZ")
    {
        answer = toxyz(color.red(),color.green(),color.blue());
    }
    else
    {
        answer.push_back(0);
        answer.push_back(0);
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}

QVector<int> converter::toxyz(double r, double g, double b)
{
       float var_R = r / 255;
       float var_G = g / 255;
       float var_B = b / 255;

       if (var_R >= 0.04045) {
           var_R = pow(((var_R + 0.055 ) / 1.055), 2.4);
       }
       else {
           var_R = var_R / 12.92;
       }
       if (var_G >= 0.04045) {
           var_G = pow(((var_G + 0.055) / 1.055), 2.4);
       }
       else {
           var_G = var_G / 12.92;
       }
       if (var_B >= 0.04045) {
           var_B = pow(((var_B + 0.055) / 1.055), 2.4);
       }
       else {
           var_B = var_B / 12.92;
       }

       var_R *= 100;
       var_G *= 100;
       var_B *= 100;

       int X = (var_R * 0.4124) + (var_G * 0.3576) + (var_B * 0.1805);
       int Y = (var_R * 0.2126) + (var_G * 0.7152) + (var_B * 0.0722);
       int Z = (var_R * 0.0193) + (var_G * 0.1192) + (var_B * 0.9505);

       QVector <int> res;
       res.push_back(X);
       res.push_back(Y);
       res.push_back(Z);
       res.push_back(0);
       return res;
}

QVector<int> converter::tolab(int x, int y, int z)
{
    float ref_X =  95.047;
        float ref_Y = 100.000;
        float ref_Z = 108.883;

        float var_X = x / ref_X;
        float var_Y = y / ref_Y;
        float var_Z = z / ref_Z;

        if (var_X >= 0.008856) {
            var_X = pow(var_X, 1.0/3);
        }
        else {
            var_X = (var_X * 7.787) + (16 / 116);
        }
        if (var_Y >= 0.008856) {
            var_Y = pow(var_Y, 1.0/3);
        }
        else {
            var_Y = (var_Y * 7.787) + (16 / 116);
        }
        if (var_Z >= 0.008856) {
            var_Z = pow(var_Z, 1.0/3);
        }
        else {
            var_Z = (var_Z * 7.787) + (16 / 116);
        }
        float number_1 = ((116 * var_Y) - 16);
        float number_2 = (500 * (var_X - var_Y));
        float number_3 = (200 * (var_Y - var_Z));
        QVector <int> res;
        res.push_back(number_1);
        res.push_back(number_2);
        res.push_back(number_3);
        res.push_back(0);
        return res;
}

QColor converter::input(QString format, QString value1, QString value2, QString value3, QString value4)
{
    QColor color = Qt::black;
    if(format == "RGB")
    {
        color.setRgb(value1.toInt(),value2.toInt(),value3.toInt());
    }
    else if(format == "CMYK")
    {
        color.setCmyk(value1.toInt(),value2.toInt(),value3.toInt(),value4.toInt());
    }
    else if(format == "HLS")
    {
        color.setHsl(value1.toInt(),value3.toInt(),value2.toInt());
    }
    else if(format == "HSV")
    {
        color.setHsv(value1.toInt(),value2.toInt(),value3.toInt());
    }
    else if(format == "XYZ")
    {
        color = fromxyz(value1,value2,value3);
    }
    else if(format == "LAB")
    {
        color = fromlab(value1,value2,value3);
    }
    return color;
}

QColor converter::fromxyz(QString value1, QString value2, QString value3)
{
    QColor color;
    //
    double x = value1.toFloat() / 100;
    double y = value2.toFloat() / 100;
    double z = value3.toFloat() / 100;
//
    double r,g,b;
    r = 3.2404542 * x - 0.4985314 * y - 0.4985314 * z;
        g = -0.9692660 * x + 1.8760108 * y + 0.0415560 * z;
        b = 0.0556434 * x - 0.2040259 * y + 1.0572252 * z;
        if(r>=0.0031308){
            r = pow(r, 1/2.4)*1.055 - 0.055;
        }else{
            r *=12.92;
        }
        if(g>=0.0031308){
            g = pow(g, 1/2.4)*1.055 - 0.055;
        }else{
            g *=12.92;
        }
        if(b>=0.0031308){
            b = pow(b, 1/2.4)*1.055 - 0.055;
        }else{
            b *=12.92;
        }
        int fr,fg,fb;
        fr = (int)(r*255);
        fg = (int)(g*255);
        fb = (int)(b*255);

        fr = std::max(fr,0);
        fg = std::max(fg,0);
        fb = std::max(fb,0);
       color.setRgb(std::min(fr, 255),std::min(fg, 255), std::min(fb, 255));
    //
    return color;
}

QColor converter::fromlab(QString value1, QString value2, QString value3)
{
       QColor color;
       float ref_X =  95.047;
       float ref_Y = 100.000;
       float ref_Z = 108.883;

       float var_X = ((value1.toDouble() + 16)/116);
       float var_Y = (value2.toDouble() / 500 + (value1.toDouble() + 16)/116);
       float var_Z = ((value1.toDouble() + 16)/116 - value3.toDouble() / 200);


       if (var_X >= 0.008856) {
           var_X = pow(var_X, 3);
       }
       else {
           var_X = (var_X - 16/116) / 7.787;
       }
       if (var_Y >= 0.008856) {
           var_Y = pow(var_Y, 3);
       }
       else {
           var_Y = (var_Y - 16/116) / 7.787;
       }
       if (var_Z >= 0.008856) {
           var_Z = pow(var_Z, 3);
       }
       else {
           var_Z = (var_Z - 16/116) / 7.787;
       }
       var_X *= ref_X;
       var_Y *= ref_Y;
       var_Z *= ref_Z;


    return fromxyz(QString::number(var_X),QString::number(var_Y),QString::number(var_Z));
}

