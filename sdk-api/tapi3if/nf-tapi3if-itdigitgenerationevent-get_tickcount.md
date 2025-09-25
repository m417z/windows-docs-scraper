# ITDigitGenerationEvent::get_TickCount

## Description

The
**get_TickCount** method gets the "tick count" (number of milliseconds since Windows started) at which the digit generation completed.

## Parameters

### `plTickCount` [out]

Pointer to tick count.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *plTickCount* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## See also

[ITDigitGenerationEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itdigitgenerationevent)