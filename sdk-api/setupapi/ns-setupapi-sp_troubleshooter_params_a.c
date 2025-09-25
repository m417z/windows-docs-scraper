typedef struct _SP_TROUBLESHOOTER_PARAMS_A {
  SP_CLASSINSTALL_HEADER ClassInstallHeader;
  CHAR                   ChmFile[MAX_PATH];
  CHAR                   HtmlTroubleShooter[MAX_PATH];
} SP_TROUBLESHOOTER_PARAMS_A, *PSP_TROUBLESHOOTER_PARAMS_A;