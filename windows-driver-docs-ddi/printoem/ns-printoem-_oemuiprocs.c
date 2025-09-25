typedef struct _OEMUIPROCS {
  PFN_DrvGetDriverSetting DrvGetDriverSetting;
  PFN_DrvUpdateUISetting  DrvUpdateUISetting;
} OEMUIPROCS, *POEMUIPROCS;