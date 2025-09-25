# ITCustomTone::put_Volume

## Description

The
**put_Volume** method sets the volume level at which to generate the tone.

## Parameters

### `lVolume` [in]

Specifies the volume level for the tone. A value of 0x0000FFFF represents full volume; a value of 0x00000000 represents silence.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |

## See also

[ITCustomTone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcustomtone)

[get_Volume](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcustomtone-get_volume)