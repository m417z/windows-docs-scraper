# ITLegacyCallMediaControl2::GenerateTone

## Description

The
**GenerateTone** method generates the specified tone.

To generate custom tones, call the
[GenerateCustomTones](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itlegacycallmediacontrol2-generatecustomtones) (C/C++) or the
[GenerateCustomTonesByCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itlegacycallmediacontrol2-generatecustomtonesbycollection) method (Visual Basic and scripting applications).

## Parameters

### `ToneMode` [in]

Indicates the tone mode. The values used are those from the
[TAPI_TONEMODE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-tapi_tonemode) enumeration.

### `lDuration` [in]

Both the duration, in milliseconds, of DTMF digits and pulse, and DTMF interdigit spacing.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | One of the parameters is invalid. |
| **TAPI_E_INVALCALLSTATE** | The call must be in the *connected* state. |

## Remarks

This method translates to a call to the TAPI 2.*x*
[lineGenerateTone](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegeneratetone) function.

When tone generation finishes, an event of type TE_GENERATEEVENT is generated.

## See also

[ITLegacyCallMediaControl2](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itlegacycallmediacontrol2)