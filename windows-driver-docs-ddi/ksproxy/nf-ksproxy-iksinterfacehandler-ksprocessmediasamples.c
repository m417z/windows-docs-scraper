HRESULT KsProcessMediaSamples(
  [in]      IKsDataTypeHandler *KsDataTypeHandler,
  [in]      IMediaSample       **SampleList,
  [in, out] PLONG              SampleCount,
  [in]      KSIOOPERATION      IoOperation,
  [out]     PKSSTREAM_SEGMENT  *StreamSegment
);