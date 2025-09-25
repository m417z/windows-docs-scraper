typedef struct _SP_REMOVEDEVICE_PARAMS {
  SP_CLASSINSTALL_HEADER ClassInstallHeader;
  DWORD                  Scope;
  DWORD                  HwProfile;
} SP_REMOVEDEVICE_PARAMS, *PSP_REMOVEDEVICE_PARAMS;