# ITLegacyCallMediaControl::GenerateDigits

## Description

The
**GenerateDigits** method causes digits to be output on the current call.

## Parameters

### `pDigits` [in]

Pointer to **BSTR** representation of digits to be sent.

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

## Remarks

The application must use
[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring) to allocate memory for the *pDigits* parameter and use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory when the variable is no longer needed.

## See also

[ITLegacyAddressMediaControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itlegacyaddressmediacontrol)

[ITLegacyCallMediaControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itlegacycallmediacontrol)