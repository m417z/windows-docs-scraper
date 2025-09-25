typedef struct _SUB_Q_MEDIA_CATALOG_NUMBER {
  SUB_Q_HEADER Header;
  UCHAR        FormatCode;
  UCHAR        Reserved[3];
  UCHAR        Reserved1 : 7;
  UCHAR        Mcval : 1;
  UCHAR        MediaCatalog[15];
} SUB_Q_MEDIA_CATALOG_NUMBER, *PSUB_Q_MEDIA_CATALOG_NUMBER;