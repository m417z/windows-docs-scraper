typedef struct _WLX_PROFILE_V2_0 {
  DWORD dwType;
  PWSTR pszProfile;
  PWSTR pszPolicy;
  PWSTR pszNetworkDefaultUserProfile;
  PWSTR pszServerName;
  PWSTR pszEnvironment;
} WLX_PROFILE_V2_0, *PWLX_PROFILE_V2_0;