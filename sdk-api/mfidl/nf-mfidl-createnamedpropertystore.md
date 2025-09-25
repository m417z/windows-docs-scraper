# CreateNamedPropertyStore function

## Description

[This API is not supported and may be altered or unavailable in the future. Instead, applications should use the **PSCreateMemoryPropertyStore** function to create named property stores.]

Creates an empty property store to hold name/value pairs.

## Parameters

### `ppStore` [out]

Receives a pointer to the **INamedPropertyStore** interface. The caller must release the interface.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)