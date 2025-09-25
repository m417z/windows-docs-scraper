typedef struct TF_INPUTPROCESSORPROFILE {
  DWORD  dwProfileType;
  LANGID langid;
  CLSID  clsid;
  GUID   guidProfile;
  GUID   catid;
  HKL    hklSubstitute;
  DWORD  dwCaps;
  HKL    hkl;
  DWORD  dwFlags;
} TF_INPUTPROCESSORPROFILE;