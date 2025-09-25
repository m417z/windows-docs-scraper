# CertSrvBackupGetDynamicFileListW function

## Description

The **CertSrvBackupGetDynamicFileList** function retrieves the list of Certificate Services dynamic file names that need to be backed up for the given backup context. The dynamic files are those that are not included in the Certificate Services database backup.

## Parameters

### `hbc` [in]

A handle to a Certificate Services backup context.

### `ppwszzFileList` [out]

A pointer to a **WCHAR** pointer that will receive the list of null-terminated dynamic file names used by Certificate Services. There is a null character after every file name and an extra null character at the end of the list. The file name will be in the UNC form "\\*Server*\*SharePoint*\…*Path*…\*FileName*.ext". When you have finished using this allocated memory, free it by calling the [CertSrvBackupFree](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackupfree) function.

Before calling this function, setting **ppwszzFileList* to **NULL** is optional.

### `pcbSize` [out]

A pointer to the **DWORD** value that specifies the number of bytes in *ppwszzFileList*.

## Return value

The return value is an **HRESULT**. A value of **S_OK** indicates success.

## Remarks

Use this function to retrieve a list of the Certificate Services dynamic file names. These files are separate from the Certificate Services database and log files, and they are not backed up by the Certificate Services backup APIs. As a result, some other means must be used to back up the dynamic files. An example of a Certificate Services dynamic file is the [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL).

This function's name in the Certadm.dll is **CertSrvBackupGetDynamicFileListW**. You must use this form of the name when calling [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress). Also, this function is defined as type **FNCERTSRVBACKUPGETDYNAMICFILELISTW** in the Certbcli.h header file.

#### Examples

```cpp
FNCERTSRVBACKUPGETDYNAMICFILELISTW* pfnGetDynFiles;
char * szGetDynFilesFunc = "CertSrvBackupGetDynamicFileListW";
WCHAR *    pwszzDynFiles;
DWORD      nListBytes=0;
HRESULT    hr=0;

// Get the address for the desired function.
// hInst was set by calling LoadLibrary for Certadm.dll.
pfnGetDynFiles = (FNCERTSRVBACKUPGETDYNAMICFILELISTW*)
    GetProcAddress(hInst, szGetDynFilesFunc);
if ( NULL == pfnGetDynFiles )
{
    printf("Failed GetProcAddress - %s, error=%d\n",
           szGetDynFilesFunc,
           GetLastError() );
    exit(1); // Or other appropriate error action.
}

// Determine the names of the dynamic files.
// hCSBC was set by an earlier call to CertSrvBackupPrepare.
hr = pfnGetDynFiles(hCSBC, &pwszzDynFiles, &nListBytes);
if (FAILED(hr))
{
    printf("Failed pfnGetDynFiles call [%x]\n", hr);
    exit(1); // Or other appropriate error action.
}
else
{
    printf("%d bytes for dynamic file names\n", nListBytes);
    WCHAR * pwszFile = pwszzDynFiles;
    // Process the list.
    while ( L'\0' != *pwszFile )
    {
        // Use the file name referenced by pwszFile.
        // Here it is merely displayed.
        printf("%ws\n", pwszFile);
        // Move to the next dynamic file name.
        // + 1 moves past the null terminator.
        pwszFile+=(wcslen(pwszFile)) + 1;
    }
    // Free the allocated memory.
    // pfnBackupFree is the address of the
    // CertSrvBackupFree function.
    pfnBackupFree(pwszzDynFiles);
}
```

## See also

[CertSrvBackupFree](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackupfree)

[Using the Certificate Services Backup and Restore Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/using-the-certificate-services-backup-and-restore-functions)