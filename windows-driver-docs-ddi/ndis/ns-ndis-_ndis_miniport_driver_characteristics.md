# _NDIS_MINIPORT_DRIVER_CHARACTERISTICS structure

## Description

An NDIS driver initializes an **NDIS_MINIPORT_DRIVER_CHARACTERISTICS** structure to define its miniport
driver characteristics, including the entry points for its
*MiniportXxx* functions.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
**NDIS_MINIPORT_DRIVER_CHARACTERISTICS** structure. Set the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_MINIPORT_DRIVER_CHARACTERISTICS.

To indicate the version of the **NDIS_MINIPORT_DRIVER_CHARACTERISTICS** structure, set the
**Revision** member to one of the following values:

#### NDIS_MINIPORT_DRIVER_CHARACTERISTICS_REVISION_3

Added the **SynchronousOidRequestHandler** member for NDIS 6.80.

Set the
**Size** member to NDIS_SIZEOF_MINIPORT_DRIVER_CHARACTERISTICS_REVISION_3.

#### NDIS_MINIPORT_DRIVER_CHARACTERISTICS_REVISION_2

Added the **DirectOidRequestHandler**, and **CancelDirectOidRequestHandler** members for NDIS 6.1.

Set the
**Size** member to NDIS_SIZEOF_MINIPORT_DRIVER_CHARACTERISTICS_REVISION_2.

#### NDIS_MINIPORT_DRIVER_CHARACTERISTICS_REVISION_1

Original version for NDIS 6.0.

Set the
**Size** member to NDIS_SIZEOF_MINIPORT_DRIVER_CHARACTERISTICS_REVISION_1.

### `MajorNdisVersion`

The major version of the NDIS library the driver is using. The current value is 0x06.

### `MinorNdisVersion`

The minor NDIS version. The following are the available minor version value settings.

|Value|Meaning|
|--- |--- |
|0|NDIS 6|
|20|NDIS 6.20|
|30|NDIS 6.30|
|40|NDIS 6.40|
|50|NDIS 6.50|
|51|NDIS 6.51|
|60|NDIS 6.60|
|70|NDIS 6.70|
|80|NDIS 6.80|
|81|NDIS 6.81|
|82|NDIS 6.82|
|83|NDIS 6.83|
|84|NDIS 6.84|
|85|NDIS 6.85|
|86|NDIS 6.86|
|87|NDIS 6.87|
|88|NDIS 6.88|
|89|NDIS 6.89|

### `MajorDriverVersion`

Reserved for the major version number of the driver. Miniport drivers can specify any value that
they require.

### `MinorDriverVersion`

Reserved for the minor version number of the driver. Miniport drivers can specify any value that
they require.

### `Flags`

A bitmask that can be set to zero or any of the following flags, combined with bitwise OR:

#### NDIS_INTERMEDIATE_DRIVER

Set if the caller is an NDIS intermediate driver.

#### NDIS_WDM_DRIVER

Set if the caller is an NDIS-WDM miniport driver.

### `SetOptionsHandler`

The entry point for the caller's
[MiniportSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options) function.

Required for Co-NDIS. Suggested for Ethernet miniport drivers that support RSS using MSI-C over PCI.

### `InitializeHandlerEx`

Required. The entry point for the
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.

### `HaltHandlerEx`

Required. The entry point for the
[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt) function.

### `UnloadHandler`

Required. The entry point for the
[MiniportDriverUnload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_unload) function.

### `PauseHandler`

Required. The entry point for the
[MiniportPause](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pause) function.

### `RestartHandler`

Required. The entry point for the
[MiniportRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_restart) function.

### `OidRequestHandler`

The entry point for the
[MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_oid_request) function. Required for all connection-less miniport drivers, including all Ethernet, WLAN, and IM drivers. Optional for some CoNDIS miniport drivers.

### `SendNetBufferListsHandler`

Required. The entry point for the
[MiniportSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_send_net_buffer_lists) function.

### `ReturnNetBufferListsHandler`

Required. The entry point for the
[MiniportReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_return_net_buffer_lists) function.

### `CancelSendHandler`

Required. The entry point for the
[MiniportCancelSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_cancel_send) function.

### `CheckForHangHandlerEx`

Optional. The entry point for the
[MiniportCheckForHangEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_check_for_hang) function.

*MiniportCheckForHangEx* is not required for intermediate drivers or virtual miniports because they are not physical devices that can hang, so they must set this entry
point to **NULL**.

*MiniportCheckForHangEx* is forbidden on any AOAC device due to the impact on battery life, so miniport drivers for these devices must set this entry point to **NULL**.

*MiniportCheckForHangEx* is discouraged for miniport drivers intended to be installed on non-AOAC, battery-powered devices due to the impact on battery life, so they should set this entry point to **NULL**.

*MiniportCheckForHangEx* is permitted but not required for miniport drivers that are intended to be installed in line-powered (mains-powered) devices. For drivers targeting NDIS 6.30 and later, consider using [NdisMResetMiniport](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismresetminiport) instead.

### `ResetHandlerEx`

Optional (required if you provide **CheckForHangHandlerEx**). The entry point for the
[MiniportResetEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_reset) function.
*MiniportResetEx* is not required for intermediate drivers, so they should set this entry point to
**NULL**.

### `DevicePnPEventNotifyHandler`

Required. The entry point for the
[MiniportDevicePnPEventNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_device_pnp_event_notify) function.

### `ShutdownHandlerEx`

Required. The entry point for the
[MiniportShutdownEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_shutdown) function.

### `CancelOidRequestHandler`

Required. The entry point for the
[MiniportCancelOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_cancel_oid_request) function.

### `DirectOidRequestHandler`

The entry point for the
[MiniportDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_direct_oid_request) function. This is an optional entry point. Set this member to **NULL** if
the miniport driver does not handle direct OID requests.

Optional for Ethernet; however, if one is provided, then both must be provided.

Required for WLAN and Ethernet miniports that implement RDMA or IPSec offload.

### `CancelDirectOidRequestHandler`

The entry point for the
[MiniportCancelDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_cancel_direct_oid_request) function. This is an optional entry point. Set this member to **NULL**
if the miniport driver does not handle direct OID requests.

Optional for Ethernet; however, if one is provided, then both must be provided.

Required for WLAN and Ethernet miniports that implement RDMA or IPSec offload.

### `SynchronousOidRequestHandler`

The entry point for the
[MiniportSynchronousOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-miniport_synchronous_oid_request) function. This is an optional entry point. Set this member to **NULL** if
the miniport driver does not handle Synchronous OID requests.

Required for WLAN and Ethernet miniports that implement RSSv2.

## Remarks

An NDIS driver passes a pointer to its **NDIS_MINIPORT_DRIVER_CHARACTERISTICS** structure in the
*MiniportDriverCharacteristics* parameter of the
[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver) function. A miniport driver calls
**NdisMRegisterMiniportDriver** from its
[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine (see also
[DriverEntry of NDIS
Miniport Drivers](https://learn.microsoft.com/windows-hardware/drivers/network/initializing-a-miniport-driver)).

## See also

[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver)

[MiniportCancelDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_cancel_direct_oid_request)

[MiniportCancelOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_cancel_oid_request)

[MiniportCancelSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_cancel_send)

[MiniportCheckForHangEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_check_for_hang)

[MiniportDevicePnPEventNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_device_pnp_event_notify)

[MiniportDirectOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_direct_oid_request)

[MiniportDriverUnload](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_unload)

[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[MiniportOidRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_oid_request)

[MiniportPause](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pause)

[MiniportResetEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_reset)

[MiniportRestart](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_restart)

[MiniportReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_return_net_buffer_lists)

[MiniportSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_send_net_buffer_lists)

[MiniportSetOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-set_options)

[MiniportShutdownEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_shutdown)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)