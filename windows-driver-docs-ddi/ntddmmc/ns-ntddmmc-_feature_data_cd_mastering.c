typedef struct _FEATURE_DATA_CD_MASTERING {
  FEATURE_HEADER Header;
  UCHAR          RWSubchannelsRecordable : 1;
  UCHAR          CdRewritable : 1;
  UCHAR          TestWriteOk : 1;
  UCHAR          RawRecordingOk : 1;
  UCHAR          RawMultiSessionOk : 1;
  UCHAR          SessionAtOnceOk : 1;
  UCHAR          BufferUnderrunFree : 1;
  UCHAR          Reserved1 : 1;
  UCHAR          MaximumCueSheetLength[3];
} FEATURE_DATA_CD_MASTERING, *PFEATURE_DATA_CD_MASTERING;