HRESULT InitializeSharedAudioStream(
  [in]           DWORD              StreamFlags,
  [in]           UINT32             PeriodInFrames,
  [in]           const WAVEFORMATEX *pFormat,
  [in, optional] LPCGUID            AudioSessionGuid
);