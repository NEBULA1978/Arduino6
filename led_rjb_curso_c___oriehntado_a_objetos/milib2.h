#ifndef ledRGB_h
#define ledGRB_h

class ledRGB
{
  public:
      ledRGB(byte red, byte green, byte blue);//declaracion del constructor
      void showRandomColors();//metodo funcion publico
  private:
      byte _red;
      byte _green;
      byte _blue;
};

#endif
