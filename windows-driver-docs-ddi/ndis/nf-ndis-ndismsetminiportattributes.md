# NdisMSetMiniportAttributes function

## Description

A miniport driver must call the
**NdisMSetMiniportAttributes** function from its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function to
identify a context area for miniport adapter to NDIS, and to provide NDIS with information about the
miniport adapter.

## Parameters

### `NdisMiniportHandle`

The miniport adapter handle that NDIS passed to the
*MiniportAdapterHandle* parameter of
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize).

### `MiniportAttributes` [in]

A pointer to an
[NDIS_MINIPORT_ADAPTER_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_attributes) union which contains a driver-allocated attributes structure. The
structure defines the attributes of the miniport adapter instance that
*MiniportAdapterHandle* specifies.

## Return value

**NdisMSetMiniportAttributes** returns one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | [NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes) registered the miniport adapter attributes successfully. |
| **NDIS_STATUS_BAD_VERSION** | Indicates that NDIS does not support the version that is specified in the **Revision** member of the structure specified in the **Header** member at *MiniportAttributes* . |

## Remarks

A miniport driver must call
**NdisMSetMiniportAttributes** from its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function
before the driver calls any other
**Ndis*Xxx*** function that depends on the information supplied to
**NdisMSetMiniportAttributes**.

The
[NDIS_MINIPORT_ADAPTER_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_attributes) union is a placeholder for various attributes structures. A
miniport driver calls
**NdisMSetMiniportAttributes** multiple times with different attributes structures. A miniport driver
must provide an initialized
[NDIS_MINIPORT_ADAPTER_REGISTRATION_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_registration_attributes) structure from
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize). The miniport driver must provide these registration attributes before it
calls any other
**Ndis*Xxx*** function that depends on these attributes or that claims hardware resources.

The driver provides a
**MiniportAdapterContext** member to NDIS in the [NDIS_MINIPORT_ADAPTER_REGISTRATION_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_registration_attributes)
structure. The
**MiniportAdapterContext** member identifies a caller-supplied context area that NDIS passes as an
input parameter to the driver's
*MiniportXxx* functions. This context area contains miniport-adapter-specific state information.

Miniport drivers must set the attributes in the
[NDIS_MINIPORT_ADAPTER_GENERAL_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniportgeneralattributes/ns-miniportgeneralattributes-ndis_miniport_adapter_general_attributes) structure after they set the registration attributes in
the [NDIS_MINIPORT_ADAPTER_REGISTRATION_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_registration_attributes) structure and before they set any additional
attributes.

A miniport driver can also call **NdisMSetMiniportAttributes** from its [MiniportAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_add_device) function. In this case, the [NDIS_MINIPORT_ADD_DEVICE_REGISTRATION_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_add_device_registration_attributes) structure is used to specify the context area.

## See also

[Initializing a Miniport Adapter](https://learn.microsoft.com/windows-hardware/drivers/network/initializing-a-miniport-adapter)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NDIS_MINIPORT_ADAPTER_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_attributes)

[NDIS_MINIPORT_ADAPTER_GENERAL_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniportgeneralattributes/ns-miniportgeneralattributes-ndis_miniport_adapter_general_attributes)

[NDIS_MINIPORT_ADAPTER_HARDWARE_ASSIST_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_hardware_assist_attributes)

[NDIS_MINIPORT_ADAPTER_NATIVE_802_11_ATTRIBUTES](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff565926(v=vs.85))

[NDIS_MINIPORT_ADAPTER_NDK_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_ndk_attributes)

[NDIS_MINIPORT_ADAPTER_OFFLOAD_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_offload_attributes)

[NDIS_MINIPORT_ADAPTER_REGISTRATION_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_adapter_registration_attributes)

[NDIS_MINIPORT_ADD_DEVICE_REGISTRATION_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_add_device_registration_attributes)

[Setting the NDIS 6.0 Miniport Adapter Attributes](https://learn.microsoft.com/windows-hardware/drivers/network/setting-the-ndis-6-0-miniport-adapter-attributes)