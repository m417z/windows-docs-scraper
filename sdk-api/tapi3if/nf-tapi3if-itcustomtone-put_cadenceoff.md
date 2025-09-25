# ITCustomTone::put_CadenceOff

## Description

The
**put_CadenceOff** method sets the "off" duration of the cadence of the custom tone to generate.

## Parameters

### `lCadenceOff` [in]

Specifies the "off" duration, in milliseconds, of the cadence of the custom tone to generate. Zero means no off time, that is, a constant tone.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |

## See also

[ITCustomTone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcustomtone)

[get_CadenceOff](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcustomtone-get_cadenceoff)