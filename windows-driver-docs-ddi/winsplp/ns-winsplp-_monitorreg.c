typedef struct _MONITORREG {
  DWORD cbSize;
  LONG()(HKEYMONITOR hcKey,LPCTSTR pszSubKey,DWORD dwOptions,REGSAM samDesired,PSECURITY_ATTRIBUTES pSecurityAttributes,HKEYMONITOR *phckResult,PDWORD pdwDisposition,HANDLE hSpooler) * fpCreateKey;
  LONG()(HKEYMONITOR hcKey,LPCTSTR pszSubKey,REGSAM samDesired,HKEYMONITOR *phkResult,HANDLE hSpooler) * fpOpenKey;
  LONG( )(HKEYMONITOR hcKey,HANDLE hSpooler) *fpCloseKey;
  LONG( )(HKEYMONITOR hcKey,LPCTSTR pszSubKey,HANDLE hSpooler) *fpDeleteKey;
  LONG( )(HKEYMONITOR hcKey,DWORD dwIndex,LPTSTR pszName,PDWORD pcchName,PFILETIME pftLastWriteTime,HANDLE hSpooler) *fpEnumKey;
  LONG( )(HKEYMONITOR hcKey,PDWORD pcSubKeys,PDWORD pcbKey,PDWORD pcValues,PDWORD pcbValue,PDWORD pcbData,PDWORD pcbSecurityDescriptor,PFILETIME pftLastWriteTime,HANDLE hSpooler) *fpQueryInfoKey;
  LONG()(HKEYMONITOR hcKey,LPCTSTR pszValue,DWORD dwType, const BYTE *pData,DWORD cbData,HANDLE hSpooler) * fpSetValue;
  LONG( )(HKEYMONITOR hcKey,LPCTSTR pszValue,HANDLE hSpooler) *fpDeleteValue;
  LONG( )(HKEYMONITOR hcKey,DWORD dwIndex,LPTSTR pszValue,PDWORD pcbValue,PDWORD pTyp,PBYTE pData,PDWORD pcbData,HANDLE hSpooler) *fpEnumValue;
  LONG( )(HKEYMONITOR hcKey,LPCTSTR pszValue,PDWORD pType,PBYTE pData,PDWORD pcbData,HANDLE hSpooler) *fpQueryValue;
} MONITORREG, *PMONITORREG;