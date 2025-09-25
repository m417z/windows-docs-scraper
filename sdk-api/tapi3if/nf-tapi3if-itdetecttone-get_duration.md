# ITDetectTone::get_Duration

## Description

The
**get_Duration** method retrieves the length of time during which a tone should be present before the TAPI Server generates a tone event.

## Parameters

### `plDuration` [out]

Pointer to a value that receives the tone duration, in milliseconds, during which the specified tone should be present.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *plDuration* parameter is not a valid pointer. |

## See also

[ITDetectTone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itdetecttone)

[put_Duration](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itdetecttone-put_duration)