typedef struct _WTS_POLICY_DATA {
  BOOLEAN fDisableEncryption;
  BOOLEAN fDisableAutoReconnect;
  ULONG   ColorDepth;
  BYTE    MinEncryptionLevel;
  BOOLEAN fDisableCpm;
  BOOLEAN fDisableCdm;
  BOOLEAN fDisableCcm;
  BOOLEAN fDisableLPT;
  BOOLEAN fDisableClip;
  BOOLEAN fDisablePNPRedir;
} WTS_POLICY_DATA, *PWTS_POLICY_DATA;