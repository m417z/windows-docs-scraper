# ITLegacyCallMediaControl2::GenerateDigits2

## Description

The
**GenerateDigits2** method causes digits to be output on the current call. This method extends the
[ITLegacyCallMediaControl::GenerateDigits](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itlegacycallmediacontrol-generatedigits) method by adding a duration parameter.

## Parameters

### `pDigits` [in]

A pointer to a **BSTR** representation of the digits to generate.

### `DigitMode` [in]

Indicates the digit mode. Valid values are those from the TAPI 2.*x*
[LINEDIGITMODE_constants](https://learn.microsoft.com/windows/desktop/Tapi/linedigitmode--constants).

### `lDuration` [in]

Both the duration, in milliseconds, of DTMF digits and pulse, and DTMF interdigit spacing.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pDigits* parameter is not a valid pointer. |
| **TAPI_E_INVALCALLSTATE** | The call must be in the *connected* state. |

## Remarks

This method translates to a call to the TAPI 2.*x*
[lineGenerateDigits](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegeneratedigits) function.

When digit generation finishes, an event of type TE_GENERATEEVENT is generated.

## See also

[ITLegacyCallMediaControl2](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itlegacycallmediacontrol2)