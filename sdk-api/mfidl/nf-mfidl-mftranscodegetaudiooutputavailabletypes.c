HRESULT MFTranscodeGetAudioOutputAvailableTypes(
  [in]  REFGUID       guidSubType,
  [in]  DWORD         dwMFTFlags,
  [in]  IMFAttributes *pCodecConfig,
  [out] IMFCollection **ppAvailableTypes
);