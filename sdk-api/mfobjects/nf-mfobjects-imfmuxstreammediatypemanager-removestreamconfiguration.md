# IMFMuxStreamMediaTypeManager::RemoveStreamConfiguration

## Description

Unregisters a stream configuration, which defines a set of substreams that can be included the multiplexed output.

## Parameters

### `ullStreamMask` [in]

A bitmask value where the bits that are on represent the indices of the substreams that are included in the stream configuration.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | The specified configuration is not currently registered. |
| **E_OUTOFMEMORY** | There is insufficient memory to complete the operation. |

## See also

[IMFMuxStreamMediaTypeManager](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmuxstreammediatypemanager)