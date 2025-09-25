# ITBasicCallControl::ParkDirect

## Description

The
**ParkDirect** method parks the call at a specified address.

## Parameters

### `pParkAddress` [in]

Pointer to **BSTR** containing the address where the call is to be parked.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pParkAddress* parameter is not a valid pointer. |
| **E_FAIL** | Park is not supported. |
| **E_INVALIDARG** | The *pParkAddress* parameter is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **TAPI_E_TIMEOUT** | The operation failed because the TAPI 3 DLL timed it out. The timeout interval is two minutes. |

## Remarks

Some service providers do not support this operation while streaming is active. The application may need to call
[ITStream::StopStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itstream-stopstream) or
[ITSubStream::StopSubStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itsubstream-stopsubstream) prior to the operation and
[ITStream::StartStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itstream-startstream) or
[ITSubStream::StartSubStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itsubstream-startsubstream) following completion of the operation.

With directed park, the application determines the address at which it wants to park the call. With
[ParkInDirect](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itbasiccallcontrol-parkindirect), the switch determines the address and provides this to the application. In either case, a parked call can be unparked by specifying this address.

The parked call enters the disconnected state after it has been successfully parked.

Some switches can remind the user after a call has been parked for some long amount of time. The application sees an offering call with a call reason set to reminder.

The application must use
[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring) to allocate memory for the *pParkAddress* parameter and use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory when the variable is no longer needed.

## See also

[Call Object](https://learn.microsoft.com/windows/desktop/Tapi/call-object)

[ITBasicCallControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itbasiccallcontrol)

[Park overview](https://learn.microsoft.com/windows/desktop/Tapi/park-ovr)

[linePark](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linepark)