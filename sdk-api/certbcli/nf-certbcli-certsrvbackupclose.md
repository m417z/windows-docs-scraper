# CertSrvBackupClose function

## Description

The **CertSrvBackupClose** function closes the file opened by the
[CertSrvBackupOpenFile](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackupopenfilew) function.

## Parameters

### `hbc` [in]

A handle to a Certificate Services backup context.

## Return value

The return value is an **HRESULT**. A value of S_OK indicates success.

## Remarks

For every successful call to [CertSrvBackupOpenFile](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackupopenfilew), there should be a subsequent call to **CertSrvBackupClose**. Upon completion of backing up a file, the file needs to be closed.

#### Examples

```cpp
FNCERTSRVBACKUPCLOSE* pfnClose;
char * szBackupCloseFunc = "CertSrvBackupClose";
HRESULT    hr=0;

// Get the address for the desired function.
// hInst was set by calling LoadLibrary for Certadm.dll.
pfnClose = (FNCERTSRVBACKUPCLOSE*)GetProcAddress(hInst,
                                   szBackupCloseFunc);
if ( NULL == pfnClose )
{
    printf("Failed GetProcAddress - %s, error=%d\n",
            szBackupCloseFunc,
            GetLastError() );
    exit(1);  // Or other appropriate error action.
}
// Close the file.
// hCSBC represents an HCSBC used in
// an earlier call to CertSrvBackupOpenFile.
hr = pfnClose(hCSBC);
if (FAILED(hr))
{
    printf("Failed pfnClose call [%x]\n", hr);
    exit(1);  // Or other appropriate error action.
}
```

## See also

[CertSrvBackupOpenFile](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackupopenfilew)

[CertSrvBackupRead](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackupread)

[Using the Certificate Services Backup and Restore Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/using-the-certificate-services-backup-and-restore-functions)