# ITCustomTone::get_Frequency

## Description

The
**get_Frequency** method retrieves the frequency of the tone component to generate.

## Parameters

### `plFrequency` [out]

Pointer to a value to receive the frequency, in hertz, of the tone component.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *plFrequency* parameter is not a valid pointer. |

## See also

[ITCustomTone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcustomtone)

[put_Frequency](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcustomtone-put_frequency)