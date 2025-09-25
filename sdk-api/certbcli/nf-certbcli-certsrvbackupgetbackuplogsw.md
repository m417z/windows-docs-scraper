# CertSrvBackupGetBackupLogsW function

## Description

The **CertSrvBackupGetBackupLogs** function retrieves the list of Certificate Services log file names that need to be backed up for the given backup context.

## Parameters

### `hbc` [in]

A handle to a Certificate Services backup context.

### `ppwszzBackupLogFiles` [out]

A pointer to **WCHAR** pointer that will receive the list of null-terminated log file names. There is a null character after every file name and an extra null character at the end of the list. The file name will be in the UNC form "## \\*Server*\*SharePoint*\…*Path*…\*FileName*.ext". The directory names will have the same form but without the trailing "\*FileName*.ext". The text "##" denotes a Certificate Services Backup file type (CSBFT_*) and is stored as a single non-null [Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) character prefixed onto each UNC path. This type tag is defined in Certbcli.h and can be one of the following values for this function.

| Value | Meaning |
| --- | --- |
| **CSBFT_LOG** | Certificate Services database log file name including path. |
| **CSBFT_PATCH_FILE** | The name, including path, of the update file for the Certificate Services database.<br><br>**Windows Server 2003:** Database update files are not used. |

When you have finished using this allocated memory, free it by calling the [CertSrvBackupFree](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackupfree) function.

Setting *ppwszzBackupLogFiles* to **NULL** before calling this function is optional.

### `pcbSize` [out]

A pointer to the **DWORD** value that specifies the number of bytes in *ppwszzBackupLogFiles*.

## Return value

The return value is an **HRESULT**. A value of **S_OK** indicates success.

## Remarks

The log files represent database activity (request submissions, certificate revocation, and so on) that has occurred since the last log file truncation. Log file volume increases as database activity occurs. The log files can be decreased in size by performing a backup and then calling
[CertSrvBackupTruncateLogs](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackuptruncatelogs).

This function's name in the Certadm.dll is **CertSrvBackupGetBackupLogsW**. You must use this form of the name when calling [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress). Also, this function is defined as type **FNCERTSRVBACKUPGETBACKUPLOGSW** in the Certbcli.h header file.

#### Examples

```cpp
FNCERTSRVBACKUPGETBACKUPLOGSW* pfnGetBackupLogs;
char * szGetBackupLogsFunc = "CertSrvBackupGetBackupLogsW";

WCHAR *    pwszzLogFiles;

DWORD      nListBytes=0;

HRESULT    hr=0;

// Get the address for the desired function.
// hInst was set by calling LoadLibrary for Certadm.dll.
pfnGetBackupLogs = (FNCERTSRVBACKUPGETBACKUPLOGSW*)GetProcAddress
    (hInst, szGetBackupLogsFunc);
if ( NULL == pfnGetBackupLogs )
{
    printf("Failed GetProcAddress - %s, error=%d\n",
           szGetBackupLogsFunc,
           GetLastError() );
    exit(1); // Or other appropriate error action.
}

// Determine the names of the log files.
// hCSBC was set by an earlier call to CertSrvbackupPrepare.
hr = pfnGetBackupLogs(hCSBC, &pwszzLogFiles, &nListBytes);
if (FAILED(hr))
{
    printf("Failed pfnGetBackupLogs call [%x]\n", hr);
    exit(1); // Or other appropriate error action.
}
else
{
    printf("%d bytes for log file names\n", nListBytes);
    WCHAR * pwszLog = pwszzLogFiles;
    // Process the list.
    while ( L'\0' != *pwszLog )
    {
        // Use the file name referenced by pwszLog.
        // Here it is merely displayed.
        printf("%02x: %ws\n", *pwszLog, &pwszLog[1]);
        // Move to the next logfile name.
        // + 1 moves past the null terminator.
        pwszLog+=(wcslen(pwszLog)) + 1;
    }

    // Free the allocated memory.
    // pfnBackupFree is the address of the CertSrvBackupFree
	   // function.
    pfnBackupFree(pwszzLogFiles);
}
```

## See also

[CertSrvBackupFree](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackupfree)

[CertSrvBackupOpenFile](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackupopenfilew)

[CertSrvBackupTruncateLogs](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackuptruncatelogs)

[Using the Certificate Services Backup and Restore Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/using-the-certificate-services-backup-and-restore-functions)