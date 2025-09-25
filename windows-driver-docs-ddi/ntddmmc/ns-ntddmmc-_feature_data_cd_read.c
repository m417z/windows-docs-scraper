typedef struct _FEATURE_DATA_CD_READ {
  FEATURE_HEADER Header;
  UCHAR          CDText : 1;
  UCHAR          C2ErrorData : 1;
  UCHAR          Reserved01 : 5;
  UCHAR          DigitalAudioPlay : 1;
  UCHAR          Reserved2[3];
} FEATURE_DATA_CD_READ, *PFEATURE_DATA_CD_READ;