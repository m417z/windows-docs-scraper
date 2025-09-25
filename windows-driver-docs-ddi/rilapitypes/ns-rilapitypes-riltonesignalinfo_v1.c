typedef struct RILTONESIGNALINFO_V1 {
  DWORD                cbSize;
  DWORD                dwParams;
  RIL3GPPTONE          dwGPPTone;
  RIL3GPP2TONE         dwGPP2Tone;
  RIL3GPP2ISDNALERTING dwGPP2IsdnAlerting;
} RILTONESIGNALINFO_V1, *LPRILTONESIGNALINFO_V1;