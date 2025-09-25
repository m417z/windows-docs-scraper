HRESULT GetMaxFrameCountForCategory(
  [in]  AUDIO_STREAM_CATEGORY category,
  [in]  BOOL                  offloadEnabled,
  [in]  const WAVEFORMATEX    *objectFormat,
  [out] UINT32                *frameCountPerBuffer
);