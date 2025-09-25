typedef struct _WCM_PROFILE_INFO {
  WCHAR          strProfileName[WCM_MAX_PROFILE_NAME];
  GUID           AdapterGUID;
  WCM_MEDIA_TYPE Media;
} WCM_PROFILE_INFO, *PWCM_PROFILE_INFO;