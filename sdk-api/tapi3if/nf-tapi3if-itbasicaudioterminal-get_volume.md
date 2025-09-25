# ITBasicAudioTerminal::get_Volume

## Description

The
**get_Volume** method gets the volume.

## Parameters

### `plVolume` [out]

Pointer to volume. The volume property is a value between 0 and FFFF, representing a set of logarithmic steps. Not all devices support as many distinguishable steps.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *plVolume* parameter is not a valid pointer. |

## See also

[ITBasicAudioTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itbasicaudioterminal)

[Terminal Object](https://learn.microsoft.com/windows/desktop/Tapi/terminal-object)

[put_Volume](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itbasicaudioterminal-put_volume)