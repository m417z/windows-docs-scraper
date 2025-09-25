typedef struct MfCard_Des_s {
  DWORD PMF_Count;
  DWORD PMF_Type;
  DWORD PMF_Flags;
  BYTE  PMF_ConfigOptions;
  BYTE  PMF_IoResourceIndex;
  BYTE  PMF_Reserved[2];
  DWORD PMF_ConfigRegisterBase;
} MFCARD_DES, *PMFCARD_DES;