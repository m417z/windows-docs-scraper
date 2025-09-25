# MFCreateTopoLoader function

## Description

Creates a new instance of the topology loader.

## Parameters

### `ppObj`

Receives a pointer to the [IMFTopoLoader](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopoloader) interface of the topology loader. The caller must release the interface.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)