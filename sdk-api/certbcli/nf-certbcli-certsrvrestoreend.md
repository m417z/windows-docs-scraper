# CertSrvRestoreEnd function

## Description

The **CertSrvRestoreEnd** function ends a Certificate Services restore session.

## Parameters

### `hbc` [in]

A handle to a Certificate Services backup context.

## Return value

The return value is an **HRESULT**. A value of S_OK indicates success.

## Remarks

When a restore session is complete, terminate the session by calling **CertSrvRestoreEnd**. For every successful call to [CertSrvRestorePrepare](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvrestorepreparew), there should be a call to **CertSrvRestoreEnd**.

When a restore is complete, it is important that you make a new full backup of the Certificate Services database. This is necessary to truncate the restored log files and to establish a base backup set for future restores. Backups performed after a restore cannot be mixed with backups (full or incremental) taken before the restore; that is, after a certificate services database is restored and has progressed to a subsequent state, you cannot use the pre-restoration backups to restore the database to that subsequent state.

#### Examples

```cpp
FNCERTSRVRESTOREEND*  pfnRestoreEnd;
char * szRestoreEndFunc = "CertSrvRestoreEnd";
HRESULT    hr=0;
	
// Get the address for the desired function.
// hInst was set by calling LoadLibrary for Certadm.dll.
pfnRestoreEnd = (FNCERTSRVRESTOREEND*)GetProcAddress(hInst,
                                  szRestoreEndFunc);
if ( NULL == pfnRestoreEnd )
{
    printf("Failed GetProcAddress - %s, error=%d\n",
           szRestoreEndFunc,
           GetLastError() );
    exit(1); // Or other appropriate error action.
}

// When done, release the HCSBC.
// hCSBC would have been set by an earlier call
// to CertSrvRestorePrepare.
hr = pfnRestoreEnd(hCSBC);
if (FAILED(hr))
{
    printf("Failed pfnRestoreEnd call [%x]\n", hr);
    exit(1); // Or other appropriate error action.
}
```

## See also

[CertSrvRestorePrepare](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvrestorepreparew)

[Using the Certificate Services Backup and Restore Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/using-the-certificate-services-backup-and-restore-functions)