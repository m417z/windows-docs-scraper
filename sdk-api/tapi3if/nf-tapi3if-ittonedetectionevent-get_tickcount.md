# ITToneDetectionEvent::get_TickCount

## Description

The
**get_TickCount** method gets the "tick count" (the number of milliseconds since Windows started) at which the tone was detected.

## Parameters

### `plTickCount` [out]

Pointer to a value to receive the tick count.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *plTickCount* parameter is not a valid pointer. |

## See also

[ITToneDetectionEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ittonedetectionevent)