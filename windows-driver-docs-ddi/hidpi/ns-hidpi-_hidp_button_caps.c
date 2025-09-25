typedef struct _HIDP_BUTTON_CAPS {
  USAGE   UsagePage;
  UCHAR   ReportID;
  BOOLEAN IsAlias;
  USHORT  BitField;
  USHORT  LinkCollection;
  USAGE   LinkUsage;
  USAGE   LinkUsagePage;
  BOOLEAN IsRange;
  BOOLEAN IsStringRange;
  BOOLEAN IsDesignatorRange;
  BOOLEAN IsAbsolute;
  USHORT  ReportCount;
  USHORT  Reserved2;
  ULONG   Reserved[9];
  union {
    struct {
      USAGE  UsageMin;
      USAGE  UsageMax;
      USHORT StringMin;
      USHORT StringMax;
      USHORT DesignatorMin;
      USHORT DesignatorMax;
      USHORT DataIndexMin;
      USHORT DataIndexMax;
    } Range;
    struct {
      USAGE  Usage;
      USAGE  Reserved1;
      USHORT StringIndex;
      USHORT Reserved2;
      USHORT DesignatorIndex;
      USHORT Reserved3;
      USHORT DataIndex;
      USHORT Reserved4;
    } NotRange;
  };
} HIDP_BUTTON_CAPS, *PHIDP_BUTTON_CAPS;