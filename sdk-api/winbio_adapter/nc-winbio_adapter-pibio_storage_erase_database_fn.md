# PIBIO_STORAGE_ERASE_DATABASE_FN callback function

## Description

Called by the Windows Biometric Framework to erase the database and mark it for deletion.

## Parameters

### `Pipeline` [in, out]

Pointer to the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `DatabaseId` [in]

A pointer to a GUID that uniquely identifies the database. This is the same GUID used to register the database in the registry.

### `FilePath` [in]

Pointer to a **NULL**-terminated UNICODE string that contains the fully qualified file path for the database.

### `ConnectString` [in]

A pointer to a **NULL**-terminated UNICODE connection string for the database.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_POINTER** | A mandatory pointer argument is **NULL**. |
| **WINBIO_E_DATABASE_CORRUPTED** | The *DatabaseId* parameter is not the same as the one used when creating the database. |
| **WINBIO_E_DATABASE_CANT_FIND** | The specified database cannot be found. |
| **WINBIO_E_INVALID_DEVICE_STATE** | The **StorageContext** member of the pipeline object is **NULL**. |

## See also

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)

[StorageAdapterCloseDatabase](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_close_database_fn)

[StorageAdapterCreateDatabase](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_create_database_fn)

[StorageAdapterOpenDatabase](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_open_database_fn)