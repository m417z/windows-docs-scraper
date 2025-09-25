# CertSrvBackupTruncateLogs function

## Description

The **CertSrvBackupTruncateLogs** function eliminates redundant records and reduces the disk storage space used by log files. Before truncating the log files, ensure that a backup of all files returned by
[CertSrvBackupGetDatabaseNames](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackupgetdatabasenamesw) and
[CertSrvBackupGetBackupLogs](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackupgetbackuplogsw) have been secured.

## Parameters

### `hbc` [in]

A handle to a Certificate Services backup context.

## Return value

The return value is an **HRESULT**. A value of S_OK indicates success.

## Remarks

After securing a backup of the database and log files, the log files can optionally be truncated. Log file volume increases with database activity, and truncating the log files will reduce the redundant records in the log files (thereby decreasing the disk space used to store the log files).

The log files are provided for database integrity and efficiency. If a less-than-graceful exit occurs with the Certificate Services application, the next time Certificate Services is started, the database replays the log files to prevent data corruption from being introduced into the database.

Depending on the volume of the log files, the log file replay can be a time-consuming process. During this replay, the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) will be unavailable for other activity. Note that if the Certificate Services application is properly halted (such as by stopping the service or by shutting down the operating system properly), the log files are not replayed the next time it is started.

**Note** If you call **CertSrvBackupTruncateLogs** without backing up all files returned from
[CertSrvBackupGetDatabaseNames](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackupgetdatabasenamesw) and
[CertSrvBackupGetBackupLogs](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackupgetbackuplogsw), you will not be able to restore the backup set successfully, resulting in an unusable Certificate Services machine. Therefore, call **CertSrvBackupTruncateLogs** only when the backup set contains all files returned from
**CertSrvBackupGetDatabaseNames** and
**CertSrvBackupGetBackupLogs**.

#### Examples

```cpp
FNCERTSRVBACKUPTRUNCATELOGS* pfnTruncateLogs;
char * szTruncateLogsFunc = "CertSrvBackupTruncateLogs";

HRESULT    hr=0;

// Get the address for the desired function.
// hInst was set by calling LoadLibrary for Certadm.dll.
pfnTruncateLogs = (FNCERTSRVBACKUPTRUNCATELOGS*)GetProcAddress( hInst,
                                           szTruncateLogsFunc );
if ( NULL == pfnTruncateLogs )
{
    printf("Failed GetProcAddress - %s, error=%d\n",
           szTruncateLogsFunc,
           GetLastError() );
    exit(1); // Or other appropriate error action.
}

// After they have been backed up, truncate the logs.
// hCSBC is a previously set HCSBC variable.
hr = pfnTruncateLogs(hCSBC);
if (FAILED(hr))
{
    printf("Failed pfnTruncateLogs call [%x]\n", hr);
    exit(1); // Or other appropriate error action.
}
else
    printf("Logs truncated\n");
```

## See also

[CertSrvBackupGetBackupLogs](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvbackupgetbackuplogsw)

[Using the Certificate Services Backup and Restore Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/using-the-certificate-services-backup-and-restore-functions)