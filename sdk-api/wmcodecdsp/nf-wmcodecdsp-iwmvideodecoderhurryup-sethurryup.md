# IWMVideoDecoderHurryup::SetHurryup

## Description

Sets the speed mode of the video decoder.

## Parameters

### `lHurryup` [in]

The speed mode of the video decoder.

| Value | Meaning |
| --- | --- |
| -1 (default) | The decoder will determine the decoding speed. |
| 0 | The decoder will decode in real time. |
| 1 to 4 | The decoder will decode faster than real time. The higher the value, the faster the decoding. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IWMVideoDecoderHurryUp::GetHurryup](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nf-wmcodecdsp-iwmvideodecoderhurryup-gethurryup)

[IWMVideoDecoderHurryup Interface](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-iwmvideodecoderhurryup)