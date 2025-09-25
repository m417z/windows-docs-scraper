typedef struct _CDROM_TOC_CD_TEXT_DATA_BLOCK {
  UCHAR PackType;
  UCHAR TrackNumber : 7;
  UCHAR ExtensionFlag : 1;
  UCHAR SequenceNumber;
  UCHAR CharacterPosition : 4;
  UCHAR BlockNumber : 3;
  UCHAR Unicode : 1;
  union {
    UCHAR Text[12];
    WCHAR WText[6];
  };
  UCHAR CRC[2];
} CDROM_TOC_CD_TEXT_DATA_BLOCK, *PCDROM_TOC_CD_TEXT_DATA_BLOCK;