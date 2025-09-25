typedef struct _REPORT_ZONES_DATA {
  UCHAR            ZoneListLength[4];
  UCHAR            Same : 4;
  UCHAR            Reserved1 : 4;
  UCHAR            Reserved2[3];
  UCHAR            MaxLBA[8];
  UCHAR            Reserved3[48];
  ZONE_DESCRIPTIOR ZoneDescriptors[ANYSIZE_ARRAY];
} REPORT_ZONES_DATA, *PREPORT_ZONES_DATA;