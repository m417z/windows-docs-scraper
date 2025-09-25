typedef struct _SP_PROPCHANGE_PARAMS {
  SP_CLASSINSTALL_HEADER ClassInstallHeader;
  DWORD                  StateChange;
  DWORD                  Scope;
  DWORD                  HwProfile;
} SP_PROPCHANGE_PARAMS, *PSP_PROPCHANGE_PARAMS;