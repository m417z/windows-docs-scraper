# ITDetectTone::put_AppSpecific

## Description

The
**put_AppSpecific** method sets the application-defined tag that identifies the tone to detect.

## Parameters

### `lAppSpecific` [in]

Specifies an application-specific tag that identifies the tone to detect. When the TAPI Server detects the tone, the value of this parameter is passed back to the application in the **TE_TONEEVENT** event.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |

## See also

[ITDetectTone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itdetecttone)

[get_AppSpecific](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itdetecttone-get_appspecific)