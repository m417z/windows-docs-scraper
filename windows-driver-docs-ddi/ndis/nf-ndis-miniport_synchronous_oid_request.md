# MINIPORT_SYNCHRONOUS_OID_REQUEST function

## Description

NDIS calls a miniport driver's *MiniportSynchronousOidRequest* callback function to issue a Synchronous OID request.

## Parameters

### `MiniportAdapterContext` [in]

A handle to a context area that the miniport driver allocated in its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.
The miniport driver uses this context area to maintain state information for a miniport adapter.

### `OidRequest` [in]

A pointer to an
[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure that contains
both the buffer and the request packet for the miniport driver to handle. Depending on the request, the
driver returns requested information in the structure that is provided.

## Return value

*MiniportSynchronousOidRequest* can return one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The miniport driver set or obtained the data as requested. |
| **NDIS_STATUS_INVALID_OID** | The request that *OidRequest* specified was invalid or not recognized. |
| **NDIS_STATUS_NOT_SUPPORTED** | The request that *OidRequest* specified was recognized, but the miniport driver does not support it. |
| **NDIS_STATUS_BUFFER_TOO_SHORT** | The buffer that *OidRequest* supplies was too small to hold the requested data. |
| **NDIS_STATUS_INVALID_LENGTH** | The value that was specified in the **InformationBufferLength** member of the NDIS_OID_REQUEST structure at *OidRequest* is incorrect for the specified OID_*Xxx* code. |
| **NDIS_STATUS_INVALID_DATA** | One or more of the parameters that were specified for the request at *OidRequest* were invalid. |
| **NDIS_STATUS_INDICATION_REQUIRED** | The miniport driver will provide an OID completion status with a subsequent status indication. A miniport driver cannot return NDIS_STATUS_INDICATION_REQUIRED unless the particular OID allows it. To determine if this status is allowed, see the OID reference page. For more information about NDIS_STATUS_INDICATION_REQUIRED, see [NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) and [NDIS_STATUS_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_status_indication). |
| **NDIS_STATUS_NOT_ACCEPTED** | After calling the [MiniportDevicePnPEventNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_device_pnp_event_notify) function to indicate a surprise removal, NDIS called the driver's [MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt) function. If the driver received any OID requests before NDIS calls *MiniportHaltEx*, it should immediately complete such requests with a status value of NDIS_STATUS_NOT_ACCEPTED.<br><br>Miniport drivers are not always required to return NDIS_STATUS_NOT_ACCEPTED for all OIDs after a surprise removal, but doing so helps explain why the call failed. |

## Remarks

*MiniportSynchronousOidRequest* is an optional function. A miniport driver registers this function if it handles Synchronous OID requests. The driver specifies the *MiniportSynchronousOidRequest* entry point when it calls the [NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver) function, using the **SynchronousOidRequestHandler** member of the [NDIS_MINIPORT_DRIVER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_driver_characteristics) structure.

Miniport drivers must not return NDIS_STATUS_PENDING or NDIS_STATUS_REQUEST_ABORTED from MiniportSynchronousOidRequest. Synchronous OID requests cannot be pended or cancelled.

Miniport drivers may return NDIS_STATUS_NOT_ACCEPTED after NDIS calls [MiniportDevicePnPEventNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_device_pnp_event_notify) to notify the driver of the device’s surprise removal. However, miniport drivers may still complete the OID request with a different status code, if it is possible to do so. For more info, see each OID’s specific documentation.

Miniport drivers are expected to complete Synchronous OID requests quickly without blocking, waiting, or sleeping. Synchronous OID requests are only used for low-latency operations, and miniport drivers should strive to complete them within several milliseconds. Most OID requests are delivered to [MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/network/handling-oid-requests-in-a-miniport-adapter), which is permitted to pend or wait for longer durations.

NDIS does not serialize Synchronous OID requests against each other, against other OID requests, against [MiniportPause](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pause), against [MiniportResetEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_reset), or against power transitions. It is the responsibility of the miniport driver to implement its own synchronization and to fail requests that are delivered at a time when the request cannot be handled successfully.

NDIS does serialize Synchronous OID requests against [MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt); NDIS guarantees that no Synchronous OID requests will be active once *MiniportHaltEx* is invoked.

Miniport drivers that implement NDIS Selective Suspend are incompatible with Synchronous OIDs and must not register a *MiniportSynchronousOidRequest* handler.

## See also

[MiniportDevicePnPEventNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_device_pnp_event_notify)

[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/network/handling-oid-requests-in-a-miniport-adapter)

[MiniportPause](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pause)

[MiniportResetEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_reset)

[NDIS_MINIPORT_DRIVER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_driver_characteristics)

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[NDIS_STATUS_INDICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_status_indication)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)

[Synchronous OID Request Interface in NDIS 6.80](https://learn.microsoft.com/windows-hardware/drivers/network/synchronous-oid-request-interface-in-ndis-6-80)