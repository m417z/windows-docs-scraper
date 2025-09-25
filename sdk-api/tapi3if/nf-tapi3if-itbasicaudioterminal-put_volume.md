# ITBasicAudioTerminal::put_Volume

## Description

The
**put_Volume** method sets the volume.

## Parameters

### `lVolume` [in]

The volume property is a value between 0 and FFFF, representing a set of logarithmic steps. Not all devices support as many distinguishable steps.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **TAPI_E_NOTERMINALSELECTED** | A terminal must be selected before the volume can be adjusted. |

## See also

[ITBasicAudioTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itbasicaudioterminal)

[Terminal Object](https://learn.microsoft.com/windows/desktop/Tapi/terminal-object)

[get_Volume](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itbasicaudioterminal-get_volume)