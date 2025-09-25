typedef struct _SP_SELECTDEVICE_PARAMS_W {
  SP_CLASSINSTALL_HEADER ClassInstallHeader;
  WCHAR                  Title[MAX_TITLE_LEN];
  WCHAR                  Instructions[MAX_INSTRUCTION_LEN];
  WCHAR                  ListLabel[MAX_LABEL_LEN];
  WCHAR                  SubTitle[MAX_SUBTITLE_LEN];
} SP_SELECTDEVICE_PARAMS_W, *PSP_SELECTDEVICE_PARAMS_W;