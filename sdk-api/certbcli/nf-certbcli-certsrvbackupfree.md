# CertSrvBackupFree function

## Description

The **CertSrvBackupFree** function is used to free memory allocated from certain Certificate Services Backup APIs.

## Parameters

### `pv` [in]

A pointer to the memory to be freed.

## Return value

This function does not return a value.

## Remarks

Call this function when finished with memory allocated by using the following functions:

* [CertSrvBackupGetBackupLogs](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackupgetbackuplogsw)
* [CertSrvBackupGetDatabaseNames](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackupgetdatabasenamesw)
* [CertSrvBackupGetDynamicFileList](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackupgetdynamicfilelistw)
* [CertSrvServerControl](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvservercontrolw)
* [CertSrvRestoreGetDatabaseLocations](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvrestoregetdatabaselocationsw)

#### Examples

```cpp
FNCERTSRVBACKUPFREE* pfnBackupFree;

char * szBackupFreeFunc = "CertSrvBackupFree";

// Get the address for the desired function.
// hInst was set by calling LoadLibrary for Certadm.dll.
pfnBackupFree = (FNCERTSRVBACKUPFREE*)GetProcAddress(hInst,
                      szBackupFreeFunc);
if ( NULL == pfnBackupFree )
{
    printf("Failed GetProcAddress - %s, error=%d\n",
           szBackupFreeFunc,
           GetLastError() );
    exit(1);
}

// Use the backup APIs.
// ...

// Free allocated memory.
// pBuff was allocated by another certsrv backup function.
pfnBackupFree(pBuff);
```

## See also

[CertSrvBackupGetBackupLogs](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackupgetbackuplogsw)

[CertSrvBackupGetDatabaseNames](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackupgetdatabasenamesw)

[CertSrvBackupGetDynamicFileList](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackupgetdynamicfilelistw)

[CertSrvRestoreGetDatabaseLocations](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvrestoregetdatabaselocationsw)

[CertSrvServerControl](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvservercontrolw)

[Using the Certificate Services Backup and Restore Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/using-the-certificate-services-backup-and-restore-functions)