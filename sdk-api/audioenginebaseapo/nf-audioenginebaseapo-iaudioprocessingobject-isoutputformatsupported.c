HRESULT IsOutputFormatSupported(
  [in, optional]  IAudioMediaType *pOppositeFormat,
  [in, optional]  IAudioMediaType *pRequestedOutputFormat,
  [out, optional] IAudioMediaType **ppSupportedOutputFormat
);