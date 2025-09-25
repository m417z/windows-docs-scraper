# ITCustomTone::get_Volume

## Description

The
**get_Volume** method retrieves the volume level at which to generate the tone.

## Parameters

### `plVolume` [out]

Pointer to a value to receive the volume level. A value of 0x0000FFFF represents full volume; a value of 0x00000000 represents silence.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *plVolume* parameter is not a valid pointer. |

## See also

[ITCustomTone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcustomtone)

[put_Volume](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcustomtone-put_volume)