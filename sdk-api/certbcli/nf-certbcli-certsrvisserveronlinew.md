# CertSrvIsServerOnlineW function

## Description

The **CertSrvIsServerOnline** function determines if a Certificate Services server is online; if the Certificate Services server is not online, backup operations will not be successful.

## Parameters

### `pwszServerName` [in]

A pointer to the NetBIOS or DNS machine name of the server to check for online status.

### `pfServerOnline` [out]

A pointer to Boolean value which will be **TRUE** if the Certificate Services server is online and **FALSE** if it is not online.

## Return value

The return value is an **HRESULT**. This function will fail if Certificate Services is not running. If Certificate Services is running and ready to accept requests, this function will return S_OK, and **pfServerOnline* will point to a value of **TRUE**. If Certificate Services is running in suspended (or paused) mode, this function will return S_OK, and **pfServerOnline* will point to a value of **FALSE**.

## Remarks

Call this function to determine whether a Certificate Services server is online and available for backup operations.

This function's name in Certadm.dll is **CertSrvIsServerOnlineW**. You must use this form of the name when calling [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress). Also, this function is defined as type **FNCERTSRVISSERVERONLINEW** in the Certbcli.h header file.

#### Examples

```cpp
FNCERTSRVISSERVERONLINEW* pfnOnline = NULL;
char * szOnlineFunc = "CertSrvIsServerOnlineW";
BOOL       bOnline = 0;
HRESULT    hr = 0;

// Get the address of the function.
// hInst was set by calling LoadLibrary for Certadm.dll.
pfnOnline = (FNCERTSRVISSERVERONLINEW*) GetProcAddress(hInst,
                                        szOnlineFunc );
if ( NULL == pfnOnline )
{
    printf("Failed GetProcAddress - %s, error=%d\n",
           szOnlineFunc,
           GetLastError() );
    exit(1);  // Or other appropriate error action.
}

// Call the function; wszServer was set earlier to the server name.
hr = pfnOnline(wszServer, &bOnline);
if (FAILED(hr))
{
    printf("Failed pfnOnline, hr=%x, err=%d\n",
           hr,
           GetLastError());
    exit(1);  // Or other appropriate error action.
}

// Display the online status.
printf("Server is %s\n",
       (bOnline ? "Online" : "Suspended" ));
```

## See also

[CertSrvBackupPrepare](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackuppreparew)

[Using the Certificate Services Backup and Restore Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/using-the-certificate-services-backup-and-restore-functions)