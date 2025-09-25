typedef enum WICMetadataCreationOptions {
  WICMetadataCreationDefault = 0,
  WICMetadataCreationAllowUnknown,
  WICMetadataCreationFailUnknown = 0x10000,
  WICMetadataCreationMask = 0xffff0000
} ;