typedef struct tagEMREXTCREATEPEN {
  EMR         emr;
  DWORD       ihPen;
  DWORD       offBmi;
  DWORD       cbBmi;
  DWORD       offBits;
  DWORD       cbBits;
  EXTLOGPEN32 elp;
} EMREXTCREATEPEN, *PEMREXTCREATEPEN;