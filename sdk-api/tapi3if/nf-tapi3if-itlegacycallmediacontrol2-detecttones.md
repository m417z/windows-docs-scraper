# ITLegacyCallMediaControl2::DetectTones

## Description

The
**DetectTones** method enables and disables the detection of inband tones on the call. Each time a specified tone is detected, a message is sent to the application.

This method is intended for C/C++ applications. Visual Basic and scripting applications should use the
[DetectTonesByCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itlegacycallmediacontrol2-detecttonesbycollection) method instead.

## Parameters

### `pToneList` [in]

Pointer to a
[TAPI_DETECTTONE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ns-tapi3if-tapi_detecttone) array that specifies the tones to detect. Each tone in the array has an application-defined tag field that is used to identify the individual tones in the list when a tone detection event of type **TE_TONEEVENT** is reported. For more information, see the following Remarks section.

### `lNumTones` [in]

The number of entries in the array specified by the *pToneList* parameter. This parameter is ignored if *pToneList* is **NULL**.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pToneList* parameter is not a valid pointer. |
| **TAPI_E_INVALCALLSTATE** | The call must be in the *connected* state. |

## Remarks

This method translates to a TAPI 2.*x*
[lineMonitorTones](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemonitortones) call.

To cancel tone monitoring in progress, call the
**DetectTones** method and specify a **NULL***pToneList* parameter. To change the list of tones to monitor, call this method and specify a new tone list.

## See also

[ITLegacyCallMediaControl2](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itlegacycallmediacontrol2)

[TAPI_DETECTTONE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ns-tapi3if-tapi_detecttone)