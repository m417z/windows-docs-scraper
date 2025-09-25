typedef struct _SP_DETECTDEVICE_PARAMS {
  SP_CLASSINSTALL_HEADER  ClassInstallHeader;
  PDETECT_PROGRESS_NOTIFY DetectProgressNotify;
  PVOID                   ProgressNotifyParam;
} SP_DETECTDEVICE_PARAMS, *PSP_DETECTDEVICE_PARAMS;