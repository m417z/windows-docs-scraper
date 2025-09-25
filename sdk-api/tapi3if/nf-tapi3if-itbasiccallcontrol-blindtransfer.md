# ITBasicCallControl::BlindTransfer

## Description

The
**BlindTransfer** method performs a blind or single-step transfer of the specified call to the specified destination address. The application must be the owner of the call. After a successful transfer, the
[call state](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-call_state) transitions to CS_DISCONNECTED.

## Parameters

### `pDestAddress` [in]

Pointer to **BSTR** containing destination address for the transfer.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pDestAddress* is not a valid pointer. |
| **E_FAIL** | Blind transfer is not supported. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **TAPI_E_TIMEOUT** | The operation failed because the TAPI 3 DLL timed it out. The timeout interval is two minutes. |

## Remarks

Some service providers do not support this operation while streaming is active. The application may need to call
[ITStream::StopStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itstream-stopstream) or
[ITSubStream::StopSubStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itsubstream-stopsubstream) prior to the operation and
[ITStream::StartStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itstream-startstream) or
[ITSubStream::StartSubStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itsubstream-startsubstream) following completion of the operation.

The application must use
[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring) to allocate memory for the *pDestAddress* parameter and use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory when the variable is no longer needed.

In some cases, the application may need to use the address translation interfaces (
[ITAddressTranslation](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddresstranslation) and
[ITAddressTranslationInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddresstranslationinfo)) to obtain a *pDestAddress* string in the proper format.

## See also

[Call Object](https://learn.microsoft.com/windows/desktop/Tapi/call-object)

[ITAddressTranslation](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddresstranslation)

[ITAddressTranslationInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddresstranslationinfo)

[ITBasicCallControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itbasiccallcontrol)

[Transfer Overview](https://learn.microsoft.com/windows/desktop/Tapi/transfer-ovr)

[lineBlindTransfer](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineblindtransfer)