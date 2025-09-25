# CertSrvBackupEnd function

## Description

The **CertSrvBackupEnd** function ends a Certificate Services backup session.

## Parameters

### `hbc` [in]

A handle to a Certificate Services backup context.

## Return value

The return value is an **HRESULT**. A value of S_OK indicates success.

## Remarks

Upon completion of a backup session, the session needs to be terminated by means of **CertSrvBackupEnd**. For every successful call to [CertSrvBackupPrepare](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackuppreparew), there should be a call to **CertSrvBackupEnd**.

#### Examples

```cpp
FNCERTSRVBACKUPEND* pfnBackupEnd;
char * szBackEndFunc = "CertSrvBackupEnd";
HRESULT    hr=0;

// Get the address for the desired function.
// hInst was set by calling LoadLibrary for Certadm.dll.
pfnBackupEnd = (FNCERTSRVBACKUPEND*)GetProcAddress(hInst,
                                       szBackEndFunc);
if (NULL == pfnBackupEnd)
{
    printf("Failed GetProcAddress - %s, error=%d\n",
           szBackEndFunc,
           GetLastError() );
    exit(1);  // Or other appropriate error action.
}

// When done, release the HCSBC.
// hCSBC would have been created by an earlier call
// to CertSrvBackupPrepare.
hr = pfnBackupEnd(hCSBC);
if (FAILED(hr))
{
    printf("Failed pfnBackupEnd call [%x]\n", hr);
    exit(1);  // Or other appropriate error action.
}
```

## See also

[CertSrvBackupPrepare](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackuppreparew)

[Using the Certificate Services Backup and Restore Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/using-the-certificate-services-backup-and-restore-functions)