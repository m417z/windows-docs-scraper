typedef struct _SP_SELECTDEVICE_PARAMS_A {
  SP_CLASSINSTALL_HEADER ClassInstallHeader;
  CHAR                   Title[MAX_TITLE_LEN];
  CHAR                   Instructions[MAX_INSTRUCTION_LEN];
  CHAR                   ListLabel[MAX_LABEL_LEN];
  CHAR                   SubTitle[MAX_SUBTITLE_LEN];
  BYTE                   Reserved[2];
} SP_SELECTDEVICE_PARAMS_A, *PSP_SELECTDEVICE_PARAMS_A;