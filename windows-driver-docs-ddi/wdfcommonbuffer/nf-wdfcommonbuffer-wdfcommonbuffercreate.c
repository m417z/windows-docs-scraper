NTSTATUS WdfCommonBufferCreate(
  [in]           WDFDMAENABLER          DmaEnabler,
  [in]           size_t                 Length,
  [in, optional] PWDF_OBJECT_ATTRIBUTES Attributes,
  [out]          WDFCOMMONBUFFER        *CommonBuffer
);