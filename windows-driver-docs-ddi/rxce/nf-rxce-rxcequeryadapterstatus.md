# RxCeQueryAdapterStatus function

## Description

**RxCeQueryAdapterStatus** returns the ADAPTER_STATUS structure for a given transport in a caller-allocated buffer.

## Parameters

### `pTransport`

A pointer to the RDBSS transport that is associated with an adapter.

### `pAdapterStatus`

On input, this parameter contains a pointer to caller-allocated buffer to hold the adapter status. On output when this call is successful, the buffer contains the adapter status associated with the specified RDBSS transport.

## Return value

**RxCeQueryAdapterStatus** returns STATUS_SUCCESS on success or one of the following error codes on failure:

| Return code | Description |
| --- | --- |
| **STATUS_ADDRESS_NOT_ASSOCIATED** | An adapter address is not associated with the RDBSS transport. |
| **STATUS_INSUFFICIENT_RESOURCES** | The allocation of nonpaged pool memory needed by this routine failed. |
| **STATUS_INVALID_PARAMETER** | The *pTransport* parameter passed to this routine was invalid. |

## Remarks

**RxCeQueryAdapterStatus** returns an ADAPTER_STATUS structure for a given transport. This routine is most commonly used to get the NetBIOS name of the adapter.

**RxCeQueryAdapterStatus** calls **TdiBuildQueryInformation** with a TDI_QUERY_ADAPTER_STATUS query.

## See also

[ADAPTER_STATUS](https://learn.microsoft.com/windows/win32/api/nb30/ns-nb30-adapter_status)

[RxCeQueryInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxce/nf-rxce-rxcequeryinformation)

[RxCeQueryTransportInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxce/nf-rxce-rxcequerytransportinformation)