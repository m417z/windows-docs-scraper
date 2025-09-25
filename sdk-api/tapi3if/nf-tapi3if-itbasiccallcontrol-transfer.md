# ITBasicCallControl::Transfer

## Description

The
**Transfer** method transfers the current call to the destination address.

## Parameters

### `pCall` [in]

Pointer to
[ITBasicCallControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itbasiccallcontrol) interface of consultation call created for the transfer.

### `fSync` [in]

Indicates whether the method should be completed synchronously (VARIANT_TRUE) or asynchronously (VARIANT_FALSE).

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The *pCall* parameter does not point to a valid call. |
| **E_FAIL** | Transfers not supported. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **TAPI_E_TIMEOUT** | The operation failed because the TAPI 3 DLL timed it out. The timeout interval is two minutes. |

## Remarks

Some service providers do not support this operation while streaming is active. The application may need to call
[ITStream::StopStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itstream-stopstream) or
[ITSubStream::StopSubStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itsubstream-stopsubstream) prior to the operation and
[ITStream::StartStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itstream-startstream) or
[ITSubStream::StartSubStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itsubstream-startsubstream) following completion of the operation.

Call transfer involves setting up a consultation call in preparation for the transfer. *pCall* is the
[ITBasicCallControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itbasiccallcontrol) pointer returned by
[ITAddress::CreateCall](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-createcall) following the creation of a consultation call.
[ITBasicCallControl::Finish](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itbasiccallcontrol-finish) (FM_ASTRANSFER) completes the transfer.

If the consultation call is not in the CONNECTED state when
**Transfer** is called, TAPI will use the destination address (as specified when the consultation call was first created via
[ITAddress::CreateCall](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-createcall)) and try to connect at that time. If the original call had a **NULL** destination address,
**Transfer** will fail with E_INVALIDARG.

## See also

[Call Object](https://learn.microsoft.com/windows/desktop/Tapi/call-object)

[Conference](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itbasiccallcontrol-conference)

[Finish](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itbasiccallcontrol-finish)

[ITAddress::CreateCall](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-createcall)

[ITBasicCallControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itbasiccallcontrol)

[Transfer Overview](https://learn.microsoft.com/windows/desktop/Tapi/transfer-ovr)