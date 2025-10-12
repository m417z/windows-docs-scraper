# NdisClGetProtocolVcContextFromTapiCallId function

## Description

**NdisClGetProtocolVcContextFromTapiCallId** retrieves the client context for a virtual connection (VC)
identified by a TAPI Call ID string.

## Parameters

### `TapiCallId` [in]

Unicode string that identifies a particular VC. This string is the Unicode version of a string
identifier that was previously returned by the
[NdisCoGetTapiCallId](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscogettapicallid) function.

### `ProtocolVcContext` [out]

Pointer to a caller-allocated NDIS_HANDLE that receives a handle to the client context for the VC.
The client supplied this context to NDIS on return from its
[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc) handler.

## Return value

Returns one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | NDIS successfully retrieved the handle to the client VC context for the VC identified by the TAPI Call ID string. |
| **NDIS_STATUS_FAILURE** | The attempt to retrieve the handle to the client VC context failed. |

## Remarks

Suppose a call manager calls
[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc) to create a VC for a TAPI
call. NDIS in turn supplies the handle to the VC to a client. The client passes this VC handle in a call
to the
[NdisCoGetTapiCallId](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscogettapicallid) function to
retrieve a string identifier for the VC. The client can then present this identifier as a Unicode string
to
**NdisClGetProtocolVcContextFromTapiCallId** to get back its context for the VC.

The client creates a context for each VC that it manages. The client uses
**NdisCoGetTapiCallId** to retrieve a string identifier for each VC. The client passes each string
identifier to a TAPI application to identify each VC. Later, if a TAPI application passes one of these
string identifiers down to the client in a VC-related operation, the client must pass this string
identifier as a Unicode string in a call to
**NdisClGetProtocolVcContextFromTapiCallId** to get back the correct context for the VC.

See the
[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure for more
information.

## See also

[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc)

[NdisCoGetTapiCallId](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscogettapicallid)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)