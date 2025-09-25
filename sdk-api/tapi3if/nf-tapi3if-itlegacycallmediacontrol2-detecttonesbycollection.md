# ITLegacyCallMediaControl2::DetectTonesByCollection

## Description

The
**DetectTonesByCollection** method enables and disables the detection of inband tones on the call. Each time a specified tone is detected, a message is sent to the application.

This method is intended for Visual Basic and scripting applications. C/C++ applications should use the
[DetectTones](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itlegacycallmediacontrol2-detecttones) method instead.

## Parameters

### `pDetectToneCollection` [in]

Pointer to an
[ITCollection2](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection2) interface containing a collection of
[ITDetectTone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itdetecttone) interface pointers that represent the tones to monitor. Each tone in the list has an application-defined tag field that is used to identify the individual tones when tone detection is reported by a **TE_TONEEVENT** event. For more information, see the following Remarks section.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pDetectToneCollection* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | There is not enough memory to allocate the tones buffer. |
| **TAPI_E_INVALCALLSTATE** | The call must be in the *connected* state. |

## Remarks

This method translates to a TAPI 2.*x*
[lineMonitorTones](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemonitortones) call.

To cancel tone monitoring in progress, call the
**DetectTonesByCollection** method and specify an empty collection. To change the list of tones to monitor, call this method and specify a new tone collection.

## See also

[ITCollection2](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection2)

[ITDetectTone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itdetecttone)

[ITLegacyCallMediaControl2](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itlegacycallmediacontrol2)