# RxCeQueryTransportInformation function

## Description

**RxCeQueryTransportInformation** queries transport information for a given transport.

## Parameters

### `pTransport`

A pointer to the transport.

### `pTransportInformation`

A pointer to the caller-supplied buffer for returning information.

## Return value

**RxCeQueryTransportInformation** returns STATUS_SUCCESS on success or the following error code on failure:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | This value can be returned for any of the following conditions:<br><br>The *pTransport* parameter passed to this routine was invalid.<br><br>The *pTransportInformation* parameter did not point to allocated memory large enough to hold an **RXCE_TRANSPORT_INFORMATION** data structure. |

## Remarks

**RxCeQueryTransportInformation** returns information for a given transport. The **RXCE_TRANSPORT_INFORMATION** data structure contains two data elements that are filled in by **RxCeQueryTransportInformation**:

ConnectionCount

QualityOfService

## See also

[RxCeQueryAdapterStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxce/nf-rxce-rxcequeryadapterstatus)

[RxCeQueryInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxce/nf-rxce-rxcequeryinformation)