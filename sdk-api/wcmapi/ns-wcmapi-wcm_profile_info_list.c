typedef struct _WCM_PROFILE_INFO_LIST {
  DWORD            dwNumberOfItems;
#if ...
  WCM_PROFILE_INFO *ProfileInfo[];
#else
  WCM_PROFILE_INFO ProfileInfo[1];
#endif
} WCM_PROFILE_INFO_LIST, *PWCM_PROFILE_INFO_LIST;