# ITLegacyCallMediaControl2::GenerateCustomTonesByCollection

## Description

The
**GenerateCustomTonesByCollection** method generates the specified custom tone.

This method is intended for Visual Basic and scripting applications. C/C++ applications should use the
[GenerateCustomTones](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itlegacycallmediacontrol2-generatecustomtones) method instead.

## Parameters

### `pCustomToneCollection` [in]

Pointer to an
[ITCollection2](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection2) interface containing a collection of
[ITCustomTone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcustomtone) interface pointers representing the tone's components. If the collection is a multifrequency tone, the various tones are played simultaneously.

### `lDuration` [in]

The duration, in milliseconds, during which the tone should be sustained. A value of zero uses a default duration.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pCustomToneCollection* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | There is not enough memory to allocate the tones buffer. |
| **TAPI_E_INVALCALLSTATE** | The call must be in the *connected* state. |

## Remarks

This method translates to a call to the TAPI 2.*x*
[lineGenerateTone](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegeneratetone) function.

When tone generation finishes, an event of type TE_GENERATEEVENT is generated.

## See also

[ITCollection2](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection2)

[ITCustomTone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcustomtone)

[ITLegacyCallMediaControl2](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itlegacycallmediacontrol2)