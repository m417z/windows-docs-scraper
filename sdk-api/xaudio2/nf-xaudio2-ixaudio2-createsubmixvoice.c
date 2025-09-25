HRESULT CreateSubmixVoice(
  [out]          IXAudio2SubmixVoice        **ppSubmixVoice,
  [in]           UINT32                     InputChannels,
  [in]           UINT32                     InputSampleRate,
  [in]           UINT32                     Flags,
  [in]           UINT32                     ProcessingStage,
  [in, optional] const XAUDIO2_VOICE_SENDS  *pSendList,
  [in, optional] const XAUDIO2_EFFECT_CHAIN *pEffectChain
);