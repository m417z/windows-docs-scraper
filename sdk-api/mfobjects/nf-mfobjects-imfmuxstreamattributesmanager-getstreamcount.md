# IMFMuxStreamAttributesManager::GetStreamCount

## Description

Gets the count of substreams managed by the multiplexed media source.

## Parameters

### `pdwMuxStreamCount` [out]

The count of substreams managed by the multiplexed media source.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | Invalid argument. |

## See also

[IMFMuxStreamMediaTypeManager](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmuxstreammediatypemanager)