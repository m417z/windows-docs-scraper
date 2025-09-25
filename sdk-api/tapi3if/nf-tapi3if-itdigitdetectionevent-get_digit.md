# ITDigitDetectionEvent::get_Digit

## Description

The
**get_Digit** method retrieves an unsigned char pointer to the digit that was detected.

## Parameters

### `pucDigit` [out]

Pointer to the digit.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pucDigit* parameter is not a valid pointer. |

## See also

[ITDigitDetectionEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itdigitdetectionevent)