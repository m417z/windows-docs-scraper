# ITDetectTone::get_AppSpecific

## Description

The
**get_AppSpecific** method retrieves the application-defined tag that identifies the tone to detect.

## Parameters

### `plAppSpecific` [out]

Pointer to a value to receive the application-specific identifier for the tone. When the TAPI Server detects the tone, the value of this parameter is passed back to the application in the **TE_TONEEVENT** event.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *plAppSpecific* parameter is not a valid pointer. |

## See also

[ITDetectTone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itdetecttone)

[put_AppSpecific](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itdetecttone-put_appspecific)