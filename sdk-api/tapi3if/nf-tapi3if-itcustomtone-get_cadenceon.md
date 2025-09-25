# ITCustomTone::get_CadenceOn

## Description

The
**get_CadenceOn** method retrieves the "on" duration of the cadence of the custom tone to generate.

## Parameters

### `plCadenceOn` [out]

Pointer to a value to receive the "on" duration, in milliseconds, of the cadence of the custom tone. Zero means no tone is generated.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *plCadenceOn* parameter is not a valid pointer. |

## See also

[ITCustomTone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcustomtone)

[put_CadenceOn](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcustomtone-put_cadenceon)