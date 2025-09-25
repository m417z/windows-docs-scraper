NTDSAPI DWORD DsServerRegisterSpnW(
  [in]           DS_SPN_WRITE_OP Operation,
  [in]           LPCWSTR         ServiceClass,
  [in, optional] LPCWSTR         UserObjectDN
);