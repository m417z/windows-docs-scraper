typedef struct _MONITOR {
  BOOL( )(LPWSTR pName,DWORD Level,LPBYTE pPorts,DWORD cbBuf,LPDWORD pcbNeeded,LPDWORD pcReturned)  *pfnEnumPorts;
  BOOL( )(LPWSTR pName,PHANDLE pHandle)  *pfnOpenPort;
  BOOL()(LPWSTR pPortName,LPWSTR pPrinterName,PHANDLE pHandle,_MONITOR *pMonitor)  * pfnOpenPortEx;
  BOOL( )(HANDLE hPort,LPWSTR pPrinterName,DWORD JobId,DWORD Level,LPBYTE pDocInfo)  *pfnStartDocPort;
  BOOL( )(HANDLE hPort,LPBYTE pBuffer,DWORD cbBuf,LPDWORD pcbWritten)  *pfnWritePort;
  BOOL( )(HANDLE hPort,LPBYTE pBuffer,DWORD cbBuffer,LPDWORD pcbRead)  *pfnReadPort;
  BOOL( )(HANDLE hPort)  *pfnEndDocPort;
  BOOL( )(HANDLE hPort)  *pfnClosePort;
  BOOL( )(LPWSTR pName,HWND hWnd,LPWSTR pMonitorName)  *pfnAddPort;
  BOOL( )(LPWSTR pName,DWORD Level,LPBYTE lpBuffer,LPWSTR lpMonitorName)  *pfnAddPortEx;
  BOOL( )(LPWSTR pName,HWND hWnd,LPWSTR pPortName)  *pfnConfigurePort;
  BOOL( )(LPWSTR pName,HWND hWnd,LPWSTR pPortName)  *pfnDeletePort;
  BOOL( )(HANDLE hPort,DWORD ControlID,LPWSTR pValueName,LPWSTR lpInBuffer,DWORD cbInBuffer,LPWSTR lpOutBuffer,DWORD cbOutBuffer,LPDWORD lpcbReturned)  *pfnGetPrinterDataFromPort;
  BOOL( )(HANDLE hPort,LPCOMMTIMEOUTS lpCTO,DWORD reserved)  *pfnSetPortTimeOuts;
  BOOL( )(LPCWSTR pszObject,ACCESS_MASK GrantedAccess,PHANDLE phXcv)  *pfnXcvOpenPort;
  DWORD( )(HANDLE hXcv,LPCWSTR pszDataName,PBYTE pInputData,DWORD cbInputData,PBYTE pOutputData,DWORD cbOutputData,PDWORD pcbOutputNeeded) *pfnXcvDataPort;
  BOOL( )(HANDLE hXcv)  *pfnXcvClosePort;
} MONITOR, *LPMONITOR;