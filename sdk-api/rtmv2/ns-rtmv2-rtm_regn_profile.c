typedef struct _RTM_REGN_PROFILE {
  UINT         MaxNextHopsInRoute;
  UINT         MaxHandlesInEnum;
  RTM_VIEW_SET ViewsSupported;
  UINT         NumberOfViews;
} RTM_REGN_PROFILE, *PRTM_REGN_PROFILE;