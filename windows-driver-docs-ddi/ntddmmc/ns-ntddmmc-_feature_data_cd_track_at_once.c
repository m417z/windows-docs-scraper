typedef struct _FEATURE_DATA_CD_TRACK_AT_ONCE {
  FEATURE_HEADER Header;
  UCHAR          RWSubchannelsRecordable : 1;
  UCHAR          CdRewritable : 1;
  UCHAR          TestWriteOk : 1;
  UCHAR          RWSubchannelPackedOk : 1;
  UCHAR          RWSubchannelRawOk : 1;
  UCHAR          Reserved1 : 1;
  UCHAR          BufferUnderrunFree : 1;
  UCHAR          Reserved3 : 1;
  UCHAR          Reserved2;
  UCHAR          DataTypeSupported[2];
} FEATURE_DATA_CD_TRACK_AT_ONCE, *PFEATURE_DATA_CD_TRACK_AT_ONCE;