HRESULT IsInputFormatSupported(
  [in, optional]  IAudioMediaType *pOppositeFormat,
  [in, optional]  IAudioMediaType *pRequestedInputFormat,
  [out, optional] IAudioMediaType **ppSupportedInputFormat
);