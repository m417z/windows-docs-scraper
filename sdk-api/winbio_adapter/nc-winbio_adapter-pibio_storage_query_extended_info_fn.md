# PIBIO_STORAGE_QUERY_EXTENDED_INFO_FN callback function

## Description

Called by the Windows Biometric Framework to determine the capabilities and limitations of the biometric storage component.

## Parameters

### `Pipeline` [in, out]

Pointer to the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `StorageInfo` [out]

Pointer to the [WINBIO_EXTENDED_STORAGE_INFO](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-extended-storage-info) structure that contains the storage information returned by this function.

### `StorageInfoSize` [in]

The specified size of the storage information.

## Return value

If the function succeeds, it returns **S_OK**. If the function fails, it must return one of the following **HRESULT** values to indicate the error.

| Return code | Description |
| --- | --- |
| **E_POINTER** | The *Pipeline* and *StorageInfo* parameters cannot be **NULL**. |
| **E_INVALIDARG** | The *StorageInfoSize* value is less than the size needed to return the storage information. |

## Remarks

This method is called once during configuration of the biometric unit.

It will also be called if a client application uses the [WinBioGetProperty](https://learn.microsoft.com/windows/desktop/api/winbio/nf-winbio-winbiogetproperty) function to query the value of the **WINBIO_PROPERTY_EXTENDED_STORAGE_INFO** property.