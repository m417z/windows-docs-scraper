typedef union tagCOLOR {
  struct GRAYCOLOR       gray;
  struct RGBCOLOR        rgb;
  struct CMYKCOLOR       cmyk;
  struct XYZCOLOR        XYZ;
  struct YxyCOLOR        Yxy;
  struct LabCOLOR        Lab;
  struct GENERIC3CHANNEL gen3ch;
  struct NAMEDCOLOR      named;
  struct HiFiCOLOR       hifi;
  struct {
    DWORD reserved1;
    VOID  *reserved2;
  };
} COLOR;