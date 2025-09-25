typedef struct TF_LANGUAGEPROFILE {
  CLSID  clsid;
  LANGID langid;
  GUID   catid;
  BOOL   fActive;
  GUID   guidProfile;
} TF_LANGUAGEPROFILE;