# IMFMuxStreamMediaTypeManager::GetStreamConfiguration

## Description

Gets the stream configuration with the specified index, which defines a set of substreams that can be included the multiplexed output.

## Parameters

### `ulIndex` [in]

The index of the configuration to retrieve.

### `pullStreamMask` [out]

The index of the configuration to retrieve.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_INVALIDINDEX** | The specified configuration index is not valid. |

## Remarks

Stream configurations are ordered within the [IMFMuxStreamMediaTypeManager](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmuxstreammediatypemanager) by the numeric value of the bitmask.

## See also

[IMFMuxStreamMediaTypeManager](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmuxstreammediatypemanager)