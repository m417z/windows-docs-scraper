# IMFMuxStreamMediaTypeManager::GetStreamConfigurationCount

## Description

Gets the count of registered stream configurations, which define set of substreams that can be included the multiplexed output.

## Parameters

### `pdwCount` [out]

The number of registered stream configurations.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | Invalid argument. |

## See also

[IMFMuxStreamMediaTypeManager](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmuxstreammediatypemanager)