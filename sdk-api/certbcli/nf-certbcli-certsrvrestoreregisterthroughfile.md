# CertSrvRestoreRegisterThroughFile function

## Description

The **CertSrvRestoreRegisterThroughFile** function registers a Certificate Services restore.

## Parameters

### `hbc` [in]

A handle to the Certificate Services restore context. This handle is obtained by calling
the [CertSrvRestorePrepare](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvrestorepreparew) function.

### `pwszCheckPointFilePath` [in, optional]

A pointer to a null-terminated Unicode string that contains the restore path for the check point file. Pass **NULL** for this parameter if it is not needed.

### `pwszLogPath` [in, optional]

A pointer to a null-terminated Unicode string that contains the current log file directory. Pass **NULL** for this parameter if it is not needed.

### `rgrstmap` [in, optional]

An array of **CSEDB_RSTMAP** structures that contains the restore map. If you are performing a full database restoration, this parameter specifies the name of the backup database, as well as a new name for the database after it is restored. The backup database name is referenced by the **pwszDatabaseName** member, and the new database name is referenced by the **pwszNewDatabaseName** member. If the intent is to maintain the same name for both the backup database and the restored database, set both the **pwszNewDatabaseName** and the **pwszDatabaseName** members to the same name. The backup database name is constructed from the path returned by the backup client's call to
the [CertSrvRestoreGetDatabaseLocations](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvrestoregetdatabaselocationsw) function. **CertSrvRestoreGetDatabaseLocations** would have been called during a full backup, and the backup client would have saved the returned path.

If you are performing an incremental restoration, set this parameter to **NULL**.

### `crstmap` [in]

The number of elements in the *rgrstmap* array. Set this value to one if a you are performing a full restoration, or zero if you are performing an incremental restoration.

### `pwszBackupLogPath` [in, optional]

A pointer to a null-terminated Unicode string that contains the path for the backup log directory. Pass **NULL** for this parameter if it is not needed.

### `genLow` [in]

The lowest log number that was restored in this restore session. Log files are in the form of edbXXXXX.log, where XXXXX is a five hexadecimal digit value. For example, edb00001.log is the first log file created by the internal database. For purposes of this function, a value of one in *genLow* corresponds to the log file edb00001.log.

### `genHigh` [in]

The highest log number that was restored in this restore session.

## Return value

The return value is an **HRESULT**. A value of **S_OK** indicates success.

## Remarks

This function is identical to the [CertSrvRestoreRegister](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvrestoreregisterw) function except that **CertSrvRestoreRegister** requires the calling account to be a local administrator. The **CertSrvRestoreRegisterThroughFile** function only requires that the calling account have the restore privilege.

## See also

[CertSrvRestoreRegister](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvrestoreregisterw)

[CertSrvRestoreRegisterComplete](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvrestoreregistercomplete)

[Using the Certificate Services Backup and Restore Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/using-the-certificate-services-backup-and-restore-functions)