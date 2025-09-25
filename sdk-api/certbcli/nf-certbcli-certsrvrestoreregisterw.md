# CertSrvRestoreRegisterW function

## Description

The **CertSrvRestoreRegister** function registers a Certificate Services restore.

## Parameters

### `hbc` [in]

A handle to the Certificate Services restore context. This handle is obtained by calling
the [CertSrvRestorePrepare](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvrestorepreparew) function.

### `pwszCheckPointFilePath` [in]

A pointer to a null-terminated Unicode string that contains the restore path for the check point file. Pass **NULL** for this parameter if it is not needed.

### `pwszLogPath` [in]

A pointer to a null-terminated Unicode string that contains the current log file directory. Pass **NULL** for this parameter if it is not needed.

### `rgrstmap` [in]

An array of **CSEDB_RSTMAP** structures that contains the restore map. If you are performing a full database restoration, this parameter specifies the name of the backup database, as well as a new name for the database after it is restored. The backup database name is referenced by the **pwszDatabaseName** member, and the new database name is referenced by the **pwszNewDatabaseName** member. If the intent is to maintain the same name for both the backup database and the restored database, set both the **pwszNewDatabaseName** and the **pwszDatabaseName** members to the same name. The backup database name is constructed from the path returned by the backup client's call to
the [CertSrvRestoreGetDatabaseLocations](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvrestoregetdatabaselocationsw) function. **CertSrvRestoreGetDatabaseLocations** would have been called during a full backup, and the backup client would have saved the returned path.

If you are performing an incremental restoration, pass **NULL** for this parameter.

### `crstmap` [in]

The number of elements in the *rgrstmap* array. Pass zero for this parameter if you are performing an incremental restoration.

### `pwszBackupLogPath` [in]

A pointer to a null-terminated Unicode string that contains the path for the backup log directory. Pass **NULL** for this parameter if it is not needed.

### `genLow` [in]

The lowest log number that was restored in this restore session. Log files are in the form of edbXXXXX.log, where XXXXX is a five hexadecimal digit value. For example, edb00001.log is the first log file created by the internal database. For purposes of this function, a value of one in *genLow* corresponds to the log file edb00001.log.

### `genHigh` [in]

The highest log number that was restored in this restore session.

## Return value

The return value is an **HRESULT**. A value of **S_OK** indicates success.

## Remarks

Use this function to register a restore operation. All subsequent restore operations will be interlocked. The restore target will be prevented from starting (or successfully executing another call to **CertSrvRestoreRegister**) until
[CertSrvRestoreRegisterComplete](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvrestoreregistercomplete) is called.

When restoring more than one incremental backup, the order in which the incremental backups are registered does not matter. However, the full database backup must be registered before registering the incremental backups.

This function requires that the calling account be a local administrator. If this is not practical, use the [CertSrvRestoreRegisterThroughFile](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvrestoreregisterthroughfile) function instead. The **CertSrvRestoreRegisterThroughFile** function only requires that the calling account have the restore privilege.

#### Examples

```cpp
// szMyDBName is the returned path from the backup client's
// call to CertSrvRestoreGetDatabaseLocations. This value would
// have been saved during a full backup operation.
CSEDB_RSTMAP rgrstmap[1] =
{
    szMyDBName, // database name
    szMyDBName  // new name same as old
};

HRESULT hr = 0;

// Register a restore operation.
// hsb is an HCSBC created previously by CertSrvRestorePrepare.
hr = CertSrvRestoreRegister(
    hsb,
    NULL,
    szMyRestoreLogPath, // defined elsewhere
    rgrstmap,
    1,
    szMyBackupLogPath, // defined elsewhere
    1,    // edb00001.log
    0x1a  // edb0001a.log
    );

if (S_OK != hr)
{
    printf("Failed CertSrvRestoreRegister - %x\n", hr);
    exit(1); // Or other appropriate error action.
}

// Continue processing.
// When done, call CertSrvRestoreRegisterComplete (not shown).
// ...
```

## See also

[CertSrvRestoreRegisterComplete](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvrestoreregistercomplete)

[CertSrvRestoreRegisterThroughFile](https://learn.microsoft.com/windows/desktop/api/certbcli/nf-certbcli-certsrvrestoreregisterthroughfile)

[Using the Certificate Services Backup and Restore Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/using-the-certificate-services-backup-and-restore-functions)