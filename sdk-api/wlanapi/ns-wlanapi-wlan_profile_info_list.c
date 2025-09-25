typedef struct _WLAN_PROFILE_INFO_LIST {
  DWORD             dwNumberOfItems;
  DWORD             dwIndex;
#if ...
  WLAN_PROFILE_INFO *ProfileInfo[];
#else
  WLAN_PROFILE_INFO ProfileInfo[1];
#endif
} WLAN_PROFILE_INFO_LIST, *PWLAN_PROFILE_INFO_LIST;