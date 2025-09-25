HRESULT CreateCaptureAudioStateMonitorForCategoryAndDeviceId(
  [in]  AUDIO_STREAM_CATEGORY category,
  [in]  PCWSTR                deviceId,
  [out] IAudioStateMonitor    **audioStateMonitor
);