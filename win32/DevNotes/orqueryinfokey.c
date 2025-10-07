DWORD ORQueryInfoKey(
  _In_        ORHKEY    Handle,
  _Out_opt_   PWSTR     lpClass,
  _Inout_opt_ PDWORD    lpcClass,
  _Out_opt_   PDWORD    lpcSubKeys,
  _Out_opt_   PDWORD    lpcMaxSubKeyLen,
  _Out_opt_   PDWORD    lpcMaxClassLen,
  _Out_opt_   PDWORD    lpcValues,
  _Out_opt_   PDWORD    lpcMaxValueNameLen,
  _Out_opt_   PDWORD    lpcMaxValueLen,
  _Out_opt_   PDWORD    lpcbSecurityDescriptor,
  _Out_opt_   PFILETIME lpftLastWriteTime
);