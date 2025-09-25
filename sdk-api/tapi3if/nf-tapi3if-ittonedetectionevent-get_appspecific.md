# ITToneDetectionEvent::get_AppSpecific

## Description

The
**get_AppSpecific** method gets the application-defined tag that identifies the tone associated with the tone detection event.

## Parameters

### `plAppSpecific` [out]

Pointer to a value to receive the application-specific identifier for the tone, as defined in the
[ITDetectTone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itdetecttone) object or in the
[LINEMONITORTONE](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linemonitortone) structure.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *plAppSpecific* parameter is not a valid pointer. |

## See also

[ITToneDetectionEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ittonedetectionevent)

[LINEMONITORTONE](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linemonitortone)