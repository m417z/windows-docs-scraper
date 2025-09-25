# ITCustomTone::get_CadenceOff

## Description

The
**get_CadenceOff** method retrieves the "off" duration of the cadence of the custom tone to generate.

## Parameters

### `plCadenceOff` [out]

Pointer to a value to receive the "off" duration, in milliseconds, of the cadence of the custom tone. Zero means no off time, that is, a constant tone.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *plCadenceOff* parameter is not a valid pointer. |

## See also

[ITCustomTone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcustomtone)

[put_CadenceOff](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcustomtone-put_cadenceoff)