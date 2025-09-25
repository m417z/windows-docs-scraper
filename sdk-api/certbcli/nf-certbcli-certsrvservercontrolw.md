# CertSrvServerControlW function

## Description

The **CertSrvServerControl** function issues a service control command to programmatically stop Certificate Services.

## Parameters

### `pwszServerName` [in]

A pointer to a name or a configuration string of the server to be issued the control command.

### `dwControlFlags` [in]

Value representing the control command being issued to the Certificate Services server specified by *pwszServerName*. The following value is supported for *dwControlFlags*.

| Value | Meaning |
| --- | --- |
| **CSCONTROL_SHUTDOWN** | Stop Certificate Services. |

### `pcbOut` [out]

For future use, this parameter will be the number of bytes allocated to *ppbOut*. The current implementation does not allocate memory to *ppbOut*. You can set this value to **NULL**.

### `ppbOut` [out]

For future use, this parameter will be the pointer to pointer to bytes representing the output from the issued command. The current implementation does not allocate memory to *ppbOut*. You can set this value to **NULL**.

## Return value

The return value is an **HRESULT**. A value of S_OK indicates success.

## Remarks

The purpose of this function is to allow a backup or restore application to programmatically stop the Certificate Services application (thereby not requiring the use of the service controller APIs). Stopping Certificate Services in this manner will also work when Certificate Services is running in console mode; the service controller APIs cannot control applications running in console mode.

This function's name in Certadm.dll is **CertSrvServerControlW**. You must use this form of the name when calling [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress). Also, this function is defined as type **FNCERTSRVSERVERCONTROLW** in the Certbcli.h header file.

#### Examples

```cpp
FNCERTSRVSERVERCONTROLW* pfnControl;
char * szControlFunc = "CertSrvServerControlW";
HRESULT    hr=0;

// Get the address for the desired function.
// hInst was set by calling LoadLibrary for Certadm.dll.
pfnControl = (FNCERTSRVSERVERCONTROLW*)GetProcAddress(hInst,
                                           szControlFunc);
if ( NULL == pfnControl )
{
    printf("Failed GetProcAddress - %s, error=%d\n",
           szControlFunc,
           GetLastError() );
    exit(1); // Or other appropriate error action.
}

// Issue a command to stop the service.
hr = pfnControl( L"MyCertServMachine",
                 CSCONTROL_SHUTDOWN,
                 NULL,
                 NULL);

if ( FAILED( hr ) )
{
    printf("Failed pfnControl call [%x]\n", hr);
    exit(1); // Or other appropriate error action.
}
```

## See also

[Using the Certificate Services Backup and Restore Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/using-the-certificate-services-backup-and-restore-functions)