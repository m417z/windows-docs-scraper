typedef struct _FEATURE_DATA_INCREMENTAL_STREAMING_WRITABLE {
  FEATURE_HEADER Header;
  UCHAR          DataTypeSupported[2];
  UCHAR          BufferUnderrunFree : 1;
  UCHAR          AddressModeReservation : 1;
  UCHAR          TrackRessourceInformation : 1;
  UCHAR          Reserved01 : 5;
  UCHAR          NumberOfLinkSizes;
  UCHAR          LinkSize[0];
} FEATURE_DATA_INCREMENTAL_STREAMING_WRITABLE, *PFEATURE_DATA_INCREMENTAL_STREAMING_WRITABLE;