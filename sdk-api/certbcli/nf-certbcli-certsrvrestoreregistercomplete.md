# CertSrvRestoreRegisterComplete function

## Description

The **CertSrvRestoreRegisterComplete** function completes a registered Certificate Services restore operation.

## Parameters

### `hbc` [in]

A handle to a Certificate Services restore context. You must set this handle by calling
[CertSrvRestoreRegister](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvrestoreregisterw) before using it in **CertSrvRestoreRegisterComplete**.

### `hrRestoreState` [in]

**HRESULT** value indicating the success code for the restore operation. Set this value to S_OK if the restore operation was successful.

## Return value

The return value is an **HRESULT**. A value of S_OK indicates success.

## Remarks

If a registered restore operation is not completed, Certificate Services will not start.

#### Examples

```cpp
FNCERTSRVRESTOREREGISTERCOMPLETE* pfnRestRegComplete;
char * szResRegCompleteFunc = "CertSrvRestoreRegisterComplete";
HRESULT    hr=0;

// Get the address for the desired function.
// hInst was set by calling LoadLibrary for Certadm.dll.
pfnRestRegComplete = (FNCERTSRVRESTOREREGISTERCOMPLETE*)
                     GetProcAddress( hInst, szResRegCompleteFunc );
if ( NULL == pfnRestRegComplete )
{
    printf("Failed GetProcAddress - %s, error=%d\n",
           szResRegCompleteFunc,
           GetLastError() );
    exit(1); // Or other appropriate error action.
}

// Complete a registered restoration operation.
// hCSBC is an HCSBC variable used in a previous
// call to CertSrvRestoreRegister.
hr = pfnRestRegComplete(hCSBC, S_OK);
if (FAILED(hr))
{
    printf("Failed pfnRestRegComplete call [%x]\n", hr);
    exit(1); // Or other appropriate error action.
}
```

## See also

[CertSrvRestoreRegister](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvrestoreregisterw)

[Using the Certificate Services Backup and Restore Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/using-the-certificate-services-backup-and-restore-functions)