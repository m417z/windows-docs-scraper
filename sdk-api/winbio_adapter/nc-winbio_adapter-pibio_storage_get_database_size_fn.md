# PIBIO_STORAGE_GET_DATABASE_SIZE_FN callback function

## Description

Called by the Windows Biometric Framework to retrieve the database size and available space.

## Parameters

### `Pipeline` [in, out]

Pointer to a [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `AvailableRecordCount` [out]

Pointer to a variable that receives the number of unused record slots in the database.

### `TotalRecordCount` [out]

Pointer to a variable that receives the number of valid records in the database.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_POINTER** | A mandatory pointer argument is **NULL**. |
| **WINBIO_E_INVALID_DEVICE_STATE** | The **StorageContext** member of the pipeline object is **NULL**. |

## See also

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)