# IOfflineFilesErrorInfo::GetRawData

## Description

Retrieves a block of bytes containing internal data associated with the error. The content of this block is intended for use by the Windows development and support teams and is subject to change in any version of Windows. No definition of the data block is provided.

## Parameters

### `ppBlob` [out]

Receives the address of a BYTE_BLOB structure describing the raw data. The caller must free this memory block by using the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## Remarks

The BYTE_BLOB structure is defined in Wtypes.h.

## See also

[IOfflineFilesErrorInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefileserrorinfo)