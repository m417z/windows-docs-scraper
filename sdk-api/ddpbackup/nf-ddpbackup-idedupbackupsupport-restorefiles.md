# IDedupBackupSupport::RestoreFiles

## Description

Reconstructs a set of files from a backup store that contains the fully optimized version of the files
(reparse points) and the Data Deduplication store.

Applications that call the
[RestoreFiles](https://learn.microsoft.com/previous-versions/windows/desktop/api/ddpbackup/nf-ddpbackup-idedupbackupsupport-restorefiles) method must also implement
the [IDedupReadFileCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/ddpbackup/nn-ddpbackup-idedupreadfilecallback) interface. Before
calling the **RestoreFiles** method, the
application must have previously restored the Data Deduplication reparse points for the files to the location
specified by the *FileFullPaths* parameter. Metadata located in the reparse points will be
utilized by Data Deduplication to further drive the restore process.

After calling this method, applications can expect to receive two calls to
[IDedupReadFileCallback::OrderContainersRestore](https://learn.microsoft.com/previous-versions/windows/desktop/api/ddpbackup/nf-ddpbackup-idedupreadfilecallback-ordercontainersrestore)
(one for stream map containers and one for data containers) and two or more calls to
[IDedupReadFileCallback::ReadBackupFile](https://learn.microsoft.com/previous-versions/windows/desktop/api/ddpbackup/nf-ddpbackup-idedupreadfilecallback-readbackupfile).
The application will also receive one call to
[IDedupReadFileCallback::PreviewContainerRead](https://learn.microsoft.com/previous-versions/windows/desktop/api/ddpbackup/nf-ddpbackup-idedupreadfilecallback-previewcontainerread)
before each call to
**ReadBackupFile** that is directed
to a container file.

## Parameters

### `NumberOfFiles` [in]

The number of files to restore. If this exceeds 10,000 then the method will fail with
**E_INVALIDARG** (0x80070057).

### `FileFullPaths` [in]

For each file, this parameter contains the full path from the root directory of the volume to the reparse
point previously restored by the application.

### `Store` [in]

[IDedupReadFileCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/ddpbackup/nn-ddpbackup-idedupreadfilecallback) interface pointer
for the backup store. This parameter is required and cannot be **NULL**.

### `Flags` [in]

This parameter must be **DEDUP_RECONSTRUCT_UNOPTIMIZED** on input. For more
information, see the
[DEDUP_BACKUP_SUPPORT_PARAM_TYPE](https://learn.microsoft.com/windows/win32/api/ddpbackup/ne-ddpbackup-dedup_backup_support_param_type)
enumeration.

### `FileResults` [out]

For each file, this parameter contains the results of the restore operation for that file. This parameter
is optional and can be **NULL** if the application doesn't need to know the results for each individual file.

#### S_OK (0x00000000L)

The file was restored successfully.

#### S_FALSE (0x00000001L)

The specified file is not a deduplicated file.

#### DDP_E_FILE_CORRUPT (0x80565355L)

Data deduplication encountered a file corruption error.

#### DDP_E_FILE_SYSTEM_CORRUPT (0x8056530EL)

Data deduplication encountered a file system corruption error.

#### DDP_E_INVALID_DATA (0x8056531DL)

The data is not valid.

#### DDP_E_JOB_COMPLETED_PARTIAL_SUCCESS (0x80565356L)

The operation completed with some errors. Check the event logs for more details.

**Windows Server 2012:** This value is not supported before Windows Server 2012 R2.

#### DDP_E_NOT_FOUND (0x80565301L)

The requested object was not found.

#### DDP_E_PATH_NOT_FOUND (0x80565304L)

A specified container path was not found in the backup store.

#### DDP_E_UNEXPECTED (0x8056530CL)

Data deduplication encountered an unexpected error. Check the Data Deduplication Operational event log
for more information.

#### DDP_E_VOLUME_DEDUP_DISABLED (0x80565323L)

The specified volume is not enabled for deduplication.

#### DDP_E_VOLUME_UNSUPPORTED (0x8056530bL)

The specified volume type is not supported. Deduplication is supported on fixed, write-enabled NTFS data
volumes.

**Windows Server 2012:** This value is not supported before Windows Server 2012 R2.

## Return value

This method can return standard **HRESULT** values, such as
**S_OK**. It can also return converted
[system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the
[HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. You can test for success
or failure **HRESULT** values by using the
[SUCCEEDED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-succeeded) and
[FAILED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-failed) macros defined in Winerror.h. Possible
return values include the following.

If no file was restored successfully, the result is the first file error encountered. This will be one of the
"DDP_E_*XXX*" error codes above.

## Remarks

The *Store* parameter is required because the restore engine (implemented by Data
Deduplication) can read data from the backup media only by calling the
[IDedupReadFileCallback::ReadBackupFile](https://learn.microsoft.com/previous-versions/windows/desktop/api/ddpbackup/nf-ddpbackup-idedupreadfilecallback-readbackupfile)
method.

## See also

[DEDUP_BACKUP_SUPPORT_PARAM_TYPE](https://learn.microsoft.com/windows/win32/api/ddpbackup/ne-ddpbackup-dedup_backup_support_param_type)

[IDedupBackupSupport](https://learn.microsoft.com/previous-versions/windows/desktop/api/ddpbackup/nn-ddpbackup-idedupbackupsupport)

[IDedupReadFileCallback](https://learn.microsoft.com/previous-versions/windows/desktop/api/ddpbackup/nn-ddpbackup-idedupreadfilecallback)