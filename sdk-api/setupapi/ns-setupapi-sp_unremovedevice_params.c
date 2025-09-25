typedef struct _SP_UNREMOVEDEVICE_PARAMS {
  SP_CLASSINSTALL_HEADER ClassInstallHeader;
  DWORD                  Scope;
  DWORD                  HwProfile;
} SP_UNREMOVEDEVICE_PARAMS, *PSP_UNREMOVEDEVICE_PARAMS;