typedef struct RILUICCAPPPERSOCHECKSTATUS {
  DWORD                           cbSize;
  DWORD                           dwParams;
  HUICCAPP                        hUiccApp;
  DWORD                           dwPersoFeature;
  RILUICCAPPPERSOCHECKSTATUSSTATE dwPersoCheckState;
} RILUICCAPPPERSOCHECKSTATUS, *LPRILUICCAPPPERSOCHECKSTATUS;