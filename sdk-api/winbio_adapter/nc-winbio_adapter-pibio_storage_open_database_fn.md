# PIBIO_STORAGE_OPEN_DATABASE_FN callback function

## Description

Called by the Windows Biometric Framework to open a database.

## Parameters

### `Pipeline` [in, out]

Pointer to the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `DatabaseId` [in]

Pointer to a GUID that uniquely identifies the database. This is the same GUID used to register the database in the registry.

### `FilePath` [in]

Pointer to a **NULL**-terminated Unicode string that contains the fully qualified file path for the database.

### `ConnectString` [in]

Pointer to a **NULL**-terminated Unicode connection string for the database.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_POINTER** | A mandatory pointer argument is **NULL**. |
| ****WINBIO_E_DATABASE_CANT_CREATE**** | The database cannot be created. |
| ****WINBIO_E_DATABASE_CANT_FIND**** | The specified database cannot be found. |
| ****WINBIO_E_DATABASE_LOCKED**** | The database is currently locked by another application and cannot be opened. |
| ****WINBIO_E_DATABASE_CANT_OPEN**** | An unspecified problem has caused the request to fail. |
| **WINBIO_E_INVALID_DEVICE_STATE** | The **StorageContext** member of the pipeline object is **NULL**. |

## See also

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)

[StorageAdapterCloseDatabase](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_close_database_fn)

[StorageAdapterCreateDatabase](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_create_database_fn)

[StorageAdapterEraseDatabase](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_erase_database_fn)