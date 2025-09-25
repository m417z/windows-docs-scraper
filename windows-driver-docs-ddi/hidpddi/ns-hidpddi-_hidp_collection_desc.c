typedef struct _HIDP_COLLECTION_DESC {
  USAGE                UsagePage;
  USAGE                Usage;
  UCHAR                CollectionNumber;
  UCHAR                Reserved[15];
  USHORT               InputLength;
  USHORT               OutputLength;
  USHORT               FeatureLength;
  USHORT               PreparsedDataLength;
  PHIDP_PREPARSED_DATA PreparsedData;
} HIDP_COLLECTION_DESC, *PHIDP_COLLECTION_DESC;