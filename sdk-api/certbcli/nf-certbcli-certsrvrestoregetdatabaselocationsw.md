# CertSrvRestoreGetDatabaseLocationsW function

## Description

The **CertSrvRestoreGetDatabaseLocations** function is used both in backup and restore scenarios and retrieves the list of Certificate Services database location names for all the files being backed up or restored.

## Parameters

### `hbc` [in]

A handle to a Certificate Services backup or restore context.

### `ppwszzDatabaseLocationList` [out]

A pointer to a **WCHAR** pointer to receive the list of null-terminated database location names, log directory name, and system (or checkpoint) directory name. There is a null character after every name and an extra null character at the end of the list. The location name will be in the UNC form "## \\*Server*\*SharePoint*\…*Path*…\*FileName*.ext". The directory names will have the same form but without the trailing "\*FileName*.ext". The text "##" denotes a Certificate Services Backup file type (CSBFT_*) and is stored as a single non-null [Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) character prefixed onto each UNC path. The type tag is defined in Certbcli.h and can be one of the following values for this function.

| Value | Meaning |
| --- | --- |
| **CSBFT_CERTSERVER_DATABASE** | Certificate Services database file name including path. |
| **CSBFT_CHECKPOINT_DIR** | Certificate Services database system (or checkpoint) directory. |
| **CSBFT_LOG_DIR** | Certificate Services database log directory. |

You must free this allocated memory when done by calling [CertSrvBackupFree](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackupfree).

Setting **ppwszzDatabaseLocationList* to **NULL** before calling this function is optional.

### `pcbSize` [out]

A pointer to the **DWORD** value that specifies the number of bytes in *ppwszzDatabaseLocationList*.

## Return value

The return value is an **HRESULT**. A value of S_OK indicates success.

## Remarks

Certificate Services must be running for this method to succeed.

This function's name in Certadm.dll is **CertSrvRestoreGetDatabaseLocationsW**. You must use this form of the name when calling [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress). Also, this function is defined as type **FNCERTSRVRESTOREGETDATABASELOCATIONSW** in the Certbcli.h header file.

#### Examples

```cpp
FNCERTSRVRESTOREGETDATABASELOCATIONSW* pfnGetDBLocs;
char *  szGetDBLocsFunc = "CertSrvRestoreGetDatabaseLocationsW";
WCHAR * pwszzDBLocs;
DWORD   nListBytes=0;
HRESULT hr=0;

// Get the address for the desired function.
// hInst was set by calling LoadLibrary for Certadm.dll.
pfnGetDBLocs = (FNCERTSRVRESTOREGETDATABASELOCATIONSW*)
    GetProcAddress(hInst, szGetDBLocsFunc);
if ( NULL == pfnGetDBLocs )
{
    printf("Failed GetProcAddress - %s, error=%d\n",
           szGetDBLocsFunc,
           GetLastError() );
    exit(1); // Or other appropriate error action.
}

// Determine the names of the database locations.
// hCSBC was set by an earlier call to CertSrvRestorePrepare.
hr = pfnGetDBLocs(hCSBC, &pwszzDBLocs, &nListBytes);
if (FAILED(hr))
{
    printf("Failed pfnGetDBLocs call [%x]\n", hr);
    exit(1); // Or other appropriate error action.
}
else
{
    printf("%d bytes for DB locations\n", nListBytes);
    WCHAR * pwszFile = pwszzDBLocs;
    // Process the list.
    while ( L'\0' != *pwszFile )
    {
        // Use the file name referenced by pwszFile.
        // Here it is merely displayed.
        printf("%02x: %ws\n", *pwszFile, &pwszFile[1]);
        // Move to the next database file name.
        // + 1 moves past the null terminator.
        pwszFile+=(wcslen(pwszFile)) + 1;
    }
    // Free the allocated memory.
    // pfnBackupFree is the address of the
    // CertSrvBackupFree function.
    pfnBackupFree(pwszzDBLocs);
}
```

## See also

[CertSrvBackupFree](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackupfree)

[Using the Certificate Services Backup and Restore Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/using-the-certificate-services-backup-and-restore-functions)