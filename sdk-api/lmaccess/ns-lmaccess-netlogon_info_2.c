typedef struct _NETLOGON_INFO_2 {
  DWORD          netlog2_flags;
  NET_API_STATUS netlog2_pdc_connection_status;
#if ...
  wchar_t        *netlog2_trusted_dc_name;
#else
  LPWSTR         netlog2_trusted_dc_name;
#endif
  NET_API_STATUS netlog2_tc_connection_status;
} NETLOGON_INFO_2, *PNETLOGON_INFO_2;