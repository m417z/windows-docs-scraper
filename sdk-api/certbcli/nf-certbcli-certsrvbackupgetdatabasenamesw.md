# CertSrvBackupGetDatabaseNamesW function

## Description

The **CertSrvBackupGetDatabaseNames** function retrieves the list of Certificate Services database file names that need to be backed up for the given backup context.

## Parameters

### `hbc` [in]

A handle to a Certificate Services backup context.

### `ppwszzAttachmentInformation` [out]

A pointer to a **WCHAR** pointer that will receive the list of null-terminated database file names. There is a null character after every file name and an extra null character at the end of the list. The file name will be in the UNC form "## \\\\*Server*\\*SharePoint*\…*Path*…\\*FileName*.ext". The directory names will have the same form but without the trailing "\\*FileName*.ext". The text "##" denotes a Certificate Services Backup file type (CSBFT_*) and is stored as a single non-null [Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) character prefixed onto each UNC path. The type tag is defined in Certbcli.h and can be the following value for this function.

| Value | Meaning |
| --- | --- |
| **CSBFT_CERTSERVER_DATABASE** | Certificate Services database file name including path. |

You must free this allocated memory when done by calling [CertSrvBackupFree](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackupfree). Before calling this function, setting **ppwszzAttachmentInformation* to **NULL** is optional.

### `pcbSize` [out]

A pointer to the **DWORD** value that specifies the number of bytes in *ppwszzAttachmentInformation*.

## Return value

The return value is an **HRESULT**. A value of S_OK indicates success.

## Remarks

This function's name in the Certadm.dll is **CertSrvBackupGetDatabaseNamesW**. You must use this form of the name when calling [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress). Also, this function is defined as type **FNCERTSRVBACKUPGETDATABASENAMESW** in the Certbcli.h header file.

#### Examples

```cpp
FNCERTSRVBACKUPGETDATABASENAMESW* pfnGetDBNames;
char * szGetDBNamesFunc = "CertSrvBackupGetDatabaseNamesW";
WCHAR *    pwszzDBFiles;
DWORD      nListBytes=0;
HRESULT    hr=0;

// Get the address for the desired function.
// hInst was set by calling LoadLibrary for Certadm.dll.
pfnGetDBNames = (FNCERTSRVBACKUPGETDATABASENAMESW*)
    GetProcAddress(hInst, szGetDBNamesFunc);

if ( NULL == pfnGetDBNames )
{
    printf("Failed GetProcAddress - %s, error=%d\n",
           szGetDBNamesFunc,
           GetLastError() );
    exit(1); // Or other appropriate error action.
}

// Determine the names of the database files.
// hCSBC was set by an earlier call to CertSrvBackupPrepare
hr = pfnGetDBNames(hCSBC, &pwszzDBFiles, &nListBytes);
if (FAILED(hr))
{
    printf("Failed pfnGetDBNames call [%x]\n", hr);
    exit(1); // Or other appropriate error action.
}
else
{
    printf("%d bytes for DB file names\n", nListBytes);
    WCHAR * pwszFile = pwszzDBFiles;
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
    pfnBackupFree(pwszzDBFiles);
}
```

## See also

[CertSrvBackupFree](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackupfree)

[CertSrvBackupOpenFile](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackupopenfilew)

[Using the Certificate Services Backup and Restore Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/using-the-certificate-services-backup-and-restore-functions)