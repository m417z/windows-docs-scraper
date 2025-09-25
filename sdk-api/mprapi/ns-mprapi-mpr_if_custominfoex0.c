typedef struct _MPR_IF_CUSTOMINFOEX0 {
  MPRAPI_OBJECT_HEADER           Header;
  DWORD                          dwFlags;
  ROUTER_IKEv2_IF_CUSTOM_CONFIG0 customIkev2Config;
} MPR_IF_CUSTOMINFOEX0, *PMPR_IF_CUSTOMINFOEX0;