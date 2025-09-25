typedef struct _WKSTA_TRANSPORT_INFO_0 {
  DWORD wkti0_quality_of_service;
  DWORD wkti0_number_of_vcs;
  LMSTR wkti0_transport_name;
  LMSTR wkti0_transport_address;
  BOOL  wkti0_wan_ish;
} WKSTA_TRANSPORT_INFO_0, *PWKSTA_TRANSPORT_INFO_0, *LPWKSTA_TRANSPORT_INFO_0;