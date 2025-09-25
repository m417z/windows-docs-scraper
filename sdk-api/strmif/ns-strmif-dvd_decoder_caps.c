typedef struct tagDVD_DECODER_CAPS {
  DWORD  dwSize;
  DWORD  dwAudioCaps;
  double dFwdMaxRateVideo;
  double dFwdMaxRateAudio;
  double dFwdMaxRateSP;
  double dBwdMaxRateVideo;
  double dBwdMaxRateAudio;
  double dBwdMaxRateSP;
  DWORD  dwRes1;
  DWORD  dwRes2;
  DWORD  dwRes3;
  DWORD  dwRes4;
} DVD_DECODER_CAPS;