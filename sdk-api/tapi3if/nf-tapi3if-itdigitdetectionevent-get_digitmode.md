# ITDigitDetectionEvent::get_DigitMode

## Description

The
**get_DigitMode** method gets the indicator of the
[line digit mode](https://learn.microsoft.com/windows/desktop/Tapi/linedigitmode--constants), such as LINEDIGITMODE_DTMF.

## Parameters

### `pDigitMode` [out]

Pointer to indicator of digit mode.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pDigitMode* parameter is not a valid pointer. |

## See also

[ITDigitDetectionEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itdigitdetectionevent)