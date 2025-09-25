typedef struct _STREAM_PROPERTY_DESCRIPTOR {
  PKSPROPERTY Property;
  ULONG       PropertySetID;
  PVOID       PropertyInfo;
  ULONG       PropertyInputSize;
  ULONG       PropertyOutputSize;
} STREAM_PROPERTY_DESCRIPTOR, *PSTREAM_PROPERTY_DESCRIPTOR;