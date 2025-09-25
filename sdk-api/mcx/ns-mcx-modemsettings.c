typedef struct _MODEMSETTINGS {
  DWORD dwActualSize;
  DWORD dwRequiredSize;
  DWORD dwDevSpecificOffset;
  DWORD dwDevSpecificSize;
  DWORD dwCallSetupFailTimer;
  DWORD dwInactivityTimeout;
  DWORD dwSpeakerVolume;
  DWORD dwSpeakerMode;
  DWORD dwPreferredModemOptions;
  DWORD dwNegotiatedModemOptions;
  DWORD dwNegotiatedDCERate;
  BYTE  abVariablePortion[1];
} MODEMSETTINGS, *PMODEMSETTINGS, *LPMODEMSETTINGS;