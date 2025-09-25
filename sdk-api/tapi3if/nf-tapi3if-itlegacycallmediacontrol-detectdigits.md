# ITLegacyCallMediaControl::DetectDigits

## Description

The
**DetectDigits** method sets an identifier of the type of digits that will be detected on the current call, such as rotary pulse or DTMF.

## Parameters

### `DigitMode` [in]

Indicates
[digit mode](https://learn.microsoft.com/windows/desktop/Tapi/tapi-digitmode--constants).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **TAPI_E_INVALCALLSTATE** | No call currently exists. |

## See also

[ITLegacyAddressMediaControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itlegacyaddressmediacontrol)

[ITLegacyCallMediaControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itlegacycallmediacontrol)