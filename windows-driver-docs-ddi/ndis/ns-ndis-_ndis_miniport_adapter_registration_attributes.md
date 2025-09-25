# _NDIS_MINIPORT_ADAPTER_REGISTRATION_ATTRIBUTES structure

## Description

An NDIS miniport driver sets up an **NDIS_MINIPORT_ADAPTER_REGISTRATION_ATTRIBUTES** structure to define
registration attributes that are associated with a miniport adapter.

## Members

### `Header`

The type, revision, and size of the **NDIS_MINIPORT_ADAPTER_REGISTRATION_ATTRIBUTES** structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the **Type** member of **Header** to NDIS_OBJECT_TYPE_MINIPORT_ADAPTER_REGISTRATION_ATTRIBUTES. To specify the version of the **NDIS_MINIPORT_ADAPTER_REGISTRATION_ATTRIBUTES** structure, the driver must set the **Revision** member of **Header** to one of the following values:

#### NDIS_MINIPORT_ADAPTER_REGISTRATION_ATTRIBUTES_REVISION_2

Added **AttributeFlags** flags for NDIS 6.30.

Set the **Size** member to NDIS_SIZEOF_MINIPORT_ADAPTER_REGISTRATION_ATTRIBUTES_REVISION_2.

#### NDIS_MINIPORT_ADAPTER_REGISTRATION_ATTRIBUTES_REVISION_1

Original version for NDIS 6.0.

Set the **Size** member to NDIS_SIZEOF_MINIPORT_ADAPTER_REGISTRATION_ATTRIBUTES_REVISION_1.

### `MiniportAdapterContext`

A handle to a context area that the miniport driver allocated in its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.
The miniport driver uses this context area to maintain state information for a miniport adapter.

### `AttributeFlags`

A bitmask of flags that are combined with a bitwise OR. NDIS miniport drivers should set one or more of
the following flags:

#### NDIS_MINIPORT_ATTRIBUTES_HARDWARE_DEVICE

Set if the miniport driver directly controls a physical device. The physical device is assigned
hardware resources such as interrupts, I/O ports, memory-mapped I/O, or DMA channels that the miniport
driver should claim from the
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.

#### NDIS_MINIPORT_ATTRIBUTES_NDIS_WDM

Set if the lower-level interface of the miniport adapter is a WDM bus driver such as USB or IEEE
1394. In this case, the miniport driver does not allocate hardware resources such as I/O ports,
interrupts, memory-mapped I/O, or DMA channels. Instead, the driver communicates with the device
through the underlying bus driver's WDM interface.

#### NDIS_MINIPORT_ATTRIBUTES_BUS_MASTER

Set if the caller's NIC is a bus-master DMA device.

#### NDIS_MINIPORT_ATTRIBUTES_NO_HALT_ON_SUSPEND

Set if NDIS should not call a miniport driver's
[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt) function before the
system transitions to a low-power (sleeping) state. Drivers that rely on hardware-maintained state
should not set this flag.

#### NDIS_MINIPORT_ATTRIBUTES_SURPRISE_REMOVE_OK

Set if the miniport driver can handle removal of its NIC without user notification. NDIS drivers receive
surprise removal notifications at the
[MiniportDevicePnPEventNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_device_pnp_event_notify) function.

#### NDIS_MINIPORT_ATTRIBUTES_NOT_CO_NDIS

Set by a miniport driver that can support both connection-oriented and connectionless devices to indicate
that the device is a connectionless device.

#### NDIS_MINIPORT_ATTRIBUTES_DO_NOT_BIND_TO_ALL_CO

Set by a CoNDIS miniport driver that does not provide TAPI services. Setting
NDIS_MINIPORT_ATTRIBUTES_DO_NOT_BIND_TO_ALL_CO prevents NDIS from binding the miniport driver to the
NDIS TAPI proxy driver (NDPROXY). By default, NDIS binds NDPROXY to all CoNDIS miniport
drivers.

#### NDIS_MINIPORT_ATTRIBUTES_CONTROLS_DEFAULT_PORT

Set by a miniport driver that calls the
[NdisMNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismnetpnpevent) function to activate
its default port. If NDIS_MINIPORT_ATTRIBUTES_CONTROLS_DEFAULT_PORT is not set, the default port is
active. NDIS does not bind protocol drivers or attach filter modules to a miniport adapter if its
default port is not active.

#### NDIS_MINIPORT_ATTRIBUTES_NO_PAUSE_ON_SUSPEND

Starting with NDIS 6.30, this flag is set if the miniport driver is able to transition to a low-power state without being paused.

For more information about this flag, see the Remarks section.

#### NDIS_MINIPORT_ATTRIBUTES_NO_OID_INTERCEPT_ON_NONDEFAULT_PORTS

Starting with NDIS 6.30, this flag is set if the miniport driver handles OIDs on non-default ports that are usually intercepted
and handled by NDIS on its behalf. This does not change the behavior of OIDs destined to the default port.

#### NDIS_MINIPORT_ATTRIBUTES_REGISTER_BUGCHECK_CALLBACK

Starting with NDIS 6.30 miniports, NDIS will not invoke the miniport's MiniportShutdownEx handler during a BugCheck unless this flag is set. Most miniports should not set this flag.

### `CheckForHangTimeInSeconds`

The time-out interval, in seconds, at which NDIS should call the
[MiniportCheckForHangEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_check_for_hang) function. If a miniport driver has not responded to an OID request or a send request
within two successive calls to
*MiniportCheckForHangEx*, NDIS can call the miniport driver's
[MiniportResetEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_reset) function.

The interval that NDIS uses when calling
*MiniportCheckForHangEx* is always a multiple of 2 seconds. For example, if you specify 5
seconds, the interval will be approximately 4 seconds.

If this member is 0, the default time-out interval is 2 seconds.

**Note** The time-out interval must be greater than your miniport driver's initialization time. For more information, see [Miniport Adapter Check-for-Hang and Reset Operations](https://learn.microsoft.com/windows-hardware/drivers/network/miniport-adapter-check-for-hang-and-reset-operations).

### `InterfaceType`

The I/O bus interface type of the miniport adapter. This is usually the type of I/O bus on which
the miniport adapter is connected. The following values are supported in NDIS 6.0:

#### NdisInterfaceInternal

Specifies a host-specific internal interface.

#### NdisInterfaceIsa

Specifies the ISA interface.

#### NdisInterfaceEisa

Specifies the extended ISA (EISA) interface. This interface type is not supported in NDIS 6.0
and later versions.

#### NdisInterfaceMca

Refers to the MCA bus, which is no longer supported. This interface type is not supported in
NDIS 6.0 and later versions.

#### NdisInterfaceTurboChannel

Specifies the Turbo Channel interface.

#### NdisInterfacePci

Specifies the Peripheral Component Interconnect (PCI) interface.

#### NdisInterfacePcMcia

Specifies the Personal Computer Memory Card International Association (PC Card)
interface.

#### NdisInterfaceCBus

Specifies the CBus.

#### NdisInterfaceMPIBus

Specifies the MPIBus.

#### NdisInterfaceMPSABus

Specifies the MPSABus.

#### NdisInterfaceProcessorInternal

Specifies the processor internal bus.

#### NdisInterfaceInternalPowerBus

Specifies the internal power bus.

#### NdisInterfacePNPISABus

Specifies the PNPISABus.

#### NdisInterfacePNPBus

Specifies the PNPBus.

This parameter is irrelevant for intermediate drivers, which should specify 0 for this
member.

## Remarks

A miniport driver passes a pointer to an NDIS_MINIPORT_ADAPTER_REGISTRATION_ATTRIBUTES structure in
the
*MiniportAttributes* parameter of the
[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes) function. A miniport driver calls
**NdisMSetMiniportAttributes** from its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function
during initialization.

Miniport drivers should set the attributes in NDIS_MINIPORT_ADAPTER_REGISTRATION_ATTRIBUTES as soon as
possible within
*MiniportInitializeEx*. Setting these attributes is mandatory.

### NDIS_MINIPORT_ATTRIBUTES_NO_PAUSE_ON_SUSPEND Flag

NDIS issues an OID request of [OID_PNP_SET_POWER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pnp-set-power) to the miniport driver before the underlying miniport adapter is transitioned to a low power state of D1, D2, or D3. When the driver handles this OID, it must prepare the miniport adapter for the transition to the lower power state and must not wait for the completion of pending receive packet indications.

In some cases, before NDIS issues the OID request of [OID_PNP_SET_POWER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pnp-set-power) to the miniport driver, NDIS calls the miniport driver's [MiniportPause](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pause) function as described below:

* If the **NDIS_MINIPORT_ATTRIBUTES_NO_PAUSE_ON_SUSPEND** flag is not set, NDIS calls the miniport driver's [MiniportPause](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pause) function before the OID request of [OID_PNP_SET_POWER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pnp-set-power) is issued to the driver. Within the context of the *MiniportPause* call, the driver must wait for the completion of pending receive packet indications.
* If the **NDIS_MINIPORT_ATTRIBUTES_NO_PAUSE_ON_SUSPEND** flag is set, NDIS does not call the miniport driver's [MiniportPause](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pause) function before the OID request of [OID_PNP_SET_POWER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pnp-set-power) is issued to the driver. When the miniport driver handles the OID request, it must not assume that it had been previously paused when preparing the miniport adapter for the transition to a low-power state.

  **Note** The exception to this occurs when a protocol or filter driver that supports NDIS 6.20 or earlier versions of NDIS is bound or attached to the miniport adapter. In this case, NDIS calls the miniport driver's [MiniportPause](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pause) function regardless of whether the miniport driver sets the **NDIS_MINIPORT_ATTRIBUTES_NO_PAUSE_ON_SUSPEND** flag.

## See also

[Miniport Adapter Check-for-Hang and Reset Operations](https://learn.microsoft.com/windows-hardware/drivers/network/miniport-adapter-check-for-hang-and-reset-operations)

[MiniportCheckForHangEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_check_for_hang)

[MiniportDevicePnPEventNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_device_pnp_event_notify)

[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[MiniportPause](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pause)

[MiniportResetEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_reset)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NdisMNetPnPEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismnetpnpevent)

[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes)

[OID_PNP_SET_POWER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pnp-set-power)