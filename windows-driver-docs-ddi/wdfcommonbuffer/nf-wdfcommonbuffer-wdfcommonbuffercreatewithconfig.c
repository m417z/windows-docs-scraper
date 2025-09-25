NTSTATUS WdfCommonBufferCreateWithConfig(
  [in]           WDFDMAENABLER             DmaEnabler,
  [in]           size_t                    Length,
  [in]           PWDF_COMMON_BUFFER_CONFIG Config,
  [in, optional] PWDF_OBJECT_ATTRIBUTES    Attributes,
  [out]          WDFCOMMONBUFFER           *CommonBuffer
);