# IWMVideoDecoderHurryup::GetHurryup

## Description

Retrieves the current speed mode of the video decoder.

## Parameters

### `plHurryup` [out]

Address of a variable that receives the decoder speed mode.

| Value | Meaning |
| --- | --- |
| -1 (default) | The decoder will determine the decoding speed. |
| 0 | The decoder will decode in real time. |
| 1 to 4 | The decoder will decode faster than real time. |

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IWMVideoDecoderHurryUp::SetHurryup](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nf-wmcodecdsp-iwmvideodecoderhurryup-sethurryup)

[IWMVideoDecoderHurryup Interface](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-iwmvideodecoderhurryup)