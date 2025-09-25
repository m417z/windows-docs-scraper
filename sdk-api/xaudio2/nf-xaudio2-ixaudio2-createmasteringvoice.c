HRESULT CreateMasteringVoice(
  [out]          IXAudio2MasteringVoice     **ppMasteringVoice,
  [in]           UINT32                     InputChannels,
  [in]           UINT32                     InputSampleRate,
  [in]           UINT32                     Flags,
  [in]           LPCWSTR                    szDeviceId,
  [in, optional] const XAUDIO2_EFFECT_CHAIN *pEffectChain,
  [in, optional] AUDIO_STREAM_CATEGORY      StreamCategory
);