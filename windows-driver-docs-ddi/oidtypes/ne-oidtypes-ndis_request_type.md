# _NDIS_REQUEST_TYPE enumeration

## Description

The NDIS_REQUEST_TYPE enumeration identifies the request type in an OID request.

## Constants

### `NdisRequestQueryInformation`

A query-information request. For certain requests, NDIS satisfies the request. Otherwise,
NDIS forwards such requests to the underlying driver's
*MiniportOidRequest* function. This type of request can originate in a user-mode application, filter module, or protocol driver.

**Note** Drivers should treat **NdisRequestQueryInformation** and **NdisRequestQueryStatistics** queries identically.

### `NdisRequestSetInformation`

A set-information request. NDIS forwards such a request to the underlying driver's
*MiniportOidRequest* function.

### `NdisRequestQueryStatistics`

A query-statistics request. For certain requests, NDIS satisfies the request. Otherwise,
NDIS forwards such requests to the underlying driver's
*MiniportOidRequest* function. This type of request can originate in a user-mode application, filter module, or protocol driver.

**Note** Drivers should treat **NdisRequestQueryInformation** and **NdisRequestQueryStatistics** queries identically.

### `NdisRequestOpen`

This type is obsolete.

### `NdisRequestClose`

This type is obsolete.

### `NdisRequestSend`

This type is obsolete.

### `NdisRequestTransferData`

This type is obsolete.

### `NdisRequestReset`

This type is obsolete.

### `NdisRequestGeneric1`

A request that is specific to the type of the miniport driver.

### `NdisRequestGeneric2`

A request that is specific to the type of the miniport driver.

### `NdisRequestGeneric3`

A request that is specific to the type of the miniport driver.

### `NdisRequestGeneric4`

A request that is specific to the type of the miniport driver.

### `NdisRequestMethod`

A method request. NDIS forwards such a request to the underlying driver's
[MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_oid_request) function.

## Remarks

The NDIS_REQUEST_TYPE enumeration is used in the
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure.

**Note** For any NDIS_REQUEST_TYPE value, the OID_*Xxx* that is specified in the
**Oid** member of the NDIS_OID_REQUEST structure must be compatible with the type of operation
requested.

## See also

[MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_oid_request)

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)