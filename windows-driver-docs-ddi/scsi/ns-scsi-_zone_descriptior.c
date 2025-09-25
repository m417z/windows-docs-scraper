typedef struct _ZONE_DESCRIPTIOR {
  UCHAR ZoneType : 4;
  UCHAR Reserved1 : 4;
  UCHAR Reset : 1;
  UCHAR Non_Seq : 1;
  UCHAR Reserved2 : 2;
  UCHAR ZoneCondition : 4;
  UCHAR Reserved3[6];
  UCHAR ZoneLength[8];
  UCHAR ZoneStartLBA[8];
  UCHAR WritePointerLBA[8];
  UCHAR Reserved4[32];
} ZONE_DESCRIPTIOR, *PZONE_DESCRIPTIOR;