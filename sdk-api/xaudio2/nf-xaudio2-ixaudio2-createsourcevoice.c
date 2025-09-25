HRESULT CreateSourceVoice(
  [out]          IXAudio2SourceVoice        **ppSourceVoice,
  [in]           const WAVEFORMATEX         *pSourceFormat,
  [in]           UINT32                     Flags,
  [in]           float                      MaxFrequencyRatio,
  [in, optional] IXAudio2VoiceCallback      *pCallback,
  [in, out]      const XAUDIO2_VOICE_SENDS  *pSendList,
  [in, optional] const XAUDIO2_EFFECT_CHAIN *pEffectChain
);