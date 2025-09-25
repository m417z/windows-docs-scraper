typedef struct _SP_TROUBLESHOOTER_PARAMS_W {
  SP_CLASSINSTALL_HEADER ClassInstallHeader;
  WCHAR                  ChmFile[MAX_PATH];
  WCHAR                  HtmlTroubleShooter[MAX_PATH];
} SP_TROUBLESHOOTER_PARAMS_W, *PSP_TROUBLESHOOTER_PARAMS_W;