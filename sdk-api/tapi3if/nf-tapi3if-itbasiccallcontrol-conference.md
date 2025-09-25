# ITBasicCallControl::Conference

## Description

The
Conference method adds a consultation call to the conference in which the current call is a participant. If an associated
[ITCallHub](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallhub) object does not exist, it is created.

## Parameters

### `pCall` [in]

Pointer to the
[ITBasicCallControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itbasiccallcontrol) interface for the consultation call.

### `fSync` [in]

Indicates whether the call should be conferenced synchronously (VARIANT_TRUE) or asynchronously (VARIANT_FALSE). See
[Connect](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itbasiccallcontrol-connect) for additional explanation.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pCall* parameter is not a valid pointer. |
| **E_INVALIDARG** | The *pCall* parameter does not point to a valid interface. |
| **TAPI_E_TIMEOUT** | The operation failed because the TAPI 3 DLL timed it out. The timeout interval is two minutes. |

## Remarks

Some service providers do not support this operation while streaming is active. The application may need to call
[ITStream::StopStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itstream-stopstream) or
[ITSubStream::StopSubStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itsubstream-stopsubstream) prior to the operation and
[ITStream::StartStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itstream-startstream) or
[ITSubStream::StartSubStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itsubstream-startsubstream) following completion of the operation.

The consultation call (*pCall*) is created by
[ITAddress::CreateCall](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-createcall). The connection is completed by calling the
[Finish](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itbasiccallcontrol-finish) method. Please see
[Create a Simple Conference](https://learn.microsoft.com/windows/desktop/Tapi/create-a-simple-conference) for an example of using this method.

If the consultation call is not in the CONNECTED state when
Conference is called, TAPI will use the destination address (as specified when the consultation call was first created via
[ITAddress::CreateCall](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-createcall)) and try to connect at that time. If the original call had a **NULL** destination address,
Conference will fail with E_INVALIDARG.

## See also

[Call Object](https://learn.microsoft.com/windows/desktop/Tapi/call-object)

[Conference overview](https://learn.microsoft.com/windows/desktop/Tapi/conference-ovr)

[Create a Simple Conference](https://learn.microsoft.com/windows/desktop/Tapi/create-a-simple-conference)

[Finish](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itbasiccallcontrol-finish)

[ITAddress::CreateCall](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itaddress-createcall)

[ITBasicCallControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itbasiccallcontrol)

[ITCallInfo::get_CallHub](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallinfo-get_callhub)

[Transfer](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itbasiccallcontrol-transfer)