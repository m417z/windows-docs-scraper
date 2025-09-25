# PIBIO_STORAGE_GET_DATA_FORMAT_FN callback function

## Description

Called by the Windows Biometric Framework to retrieve format and version information used by the current database associated with the pipeline.

## Parameters

### `Pipeline` [in, out]

Pointer to a [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `Format` [out]

Pointer to a variable that receives a GUID that uniquely identifies the data format used by this storage adapter when it stores templates in the database.

### `Version` [out]

Pointer to a [WINBIO_VERSION](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-version) structure that receives the version number of the storage adapter component.

## Return value

If the function succeeds, it returns S_OK. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_POINTER** | A mandatory pointer argument is **NULL**. |
| **WINBIO_E_INVALID_DEVICE_STATE** | The **StorageContext** member of the pipeline object is **NULL**. |

## See also

[Plug-in Functions](https://learn.microsoft.com/windows/desktop/SecBioMet/plug-in-functions)