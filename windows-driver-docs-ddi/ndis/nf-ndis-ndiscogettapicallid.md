# NdisCoGetTapiCallId function

## Description

**NdisCoGetTapiCallId** retrieves a string that TAPI applications can use to identify a particular NDIS
virtual connection (VC).

## Parameters

### `NdisVcHandle` [in]

Specifies the NDIS handle to the VC. This handle was supplied by NDIS when the VC was originally
created with the
[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc) function.

### `TapiCallId` [in, out]

Pointer to a caller-allocated buffer that receives a data structure of type VAR_STRING. Upon
successful return, this structure describes a string that TAPI applications can use to identify the
VC.

## Return value

Returns one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | NDIS successfully returned a string identifier for the VC. |
| **NDIS_STATUS_BUFFER_TOO_SHORT** | The **ulTotalSize** member of the VAR_STRING structure specifies that the size of the buffer is not large enough to hold the string that identifies the VC. **NdisCoGetTapiCallId** sets the **ulNeededSize** member of the VAR_STRING structure to the required size in bytes. |
| **NDIS_STATUS_INVALID_DATA** | The handle to the VC specified by *NdisVcHandle* is not valid. |

## Remarks

Suppose a call manager calls
[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc) to create a VC for a TAPI
call. NDIS in turn supplies the handle to the VC to a client. The client passes this VC handle in a call
to the
**NdisCoGetTapiCallId** function to retrieve a string that identifies the VC. The client can pass this
string identifier to a TAPI application to identify the VC.

The client creates a context for each VC that it manages. The client uses
**NdisCoGetTapiCallId** to retrieve a string identifier for each VC. The client passes each string
identifier to a TAPI application to identify each VC. Later, if a TAPI application passes one of these
string identifiers down to the client in a VC-related operation, the client must pass this string
identifier as a Unicode string in a call to
[NdisClGetProtocolVcContextFromTapiCallId](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclgetprotocolvccontextfromtapicallid) to get back the correct context for the VC.

For more information about the VAR_STRING structure, see
[TAPI Objects](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff564235(v=vs.85)).

## See also

[NdisClGetProtocolVcContextFromTapiCallId](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclgetprotocolvccontextfromtapicallid)

[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc)