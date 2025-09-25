# _NDIS_MINIPORT_INIT_PARAMETERS structure

## Description

The **NDIS_MINIPORT_INIT_PARAMETERS** structure defines the initialization parameters for a miniport
adapter.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
NDIS_MINIPORT_INIT_PARAMETERS structure. NDIS sets the
**Type** member of the structure that
**Header** specified to NDIS_OBJECT_TYPE_MINIPORT_INIT_PARAMETERS, the
**Revision** member to NDIS_MINIPORT_INIT_PARAMETERS_REVISION_1, and the
**Size** member to NDIS_SIZEOF_MINIPORT_INIT_PARAMETER_REVISION_1.

### `Flags`

Reserved for NDIS.

### `AllocatedResources`

A pointer to an NDIS_RESOURCE_LIST-type structure that lists the hardware resources that the Plug
and Play Manager assigned to the miniport adapter. The NDIS_RESOURCE_LIST is type definition that is
equivalent to the
[CM_PARTIAL_RESOURCE_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_list) on Windows
2000 and later platforms.

### `IMDeviceInstanceContext`

A pointer to the context area for a virtual device that an intermediate driver supports. The
driver passed this pointer to the
[NdisIMInitializeDeviceInstanceEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisiminitializedeviceinstanceex) function at the
*DeviceContext* parameter. If the miniport driver is not an intermediate driver,
**IMDeviceInstanceContext** is **NULL**.

### `MiniportAddDeviceContext`

A handle for a driver-allocated context area, or **NULL**. The miniport driver specifies this handle,
if any, in the
[MiniportAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_add_device) function.

### `IfIndex`

The network interface index that is associated with the miniport adapter.

### `NetLuid`

The
[NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh) value that is associated with the
miniport adapter.

### `DefaultPortAuthStates`

A pointer to an
[NDIS_PORT_AUTHENTICATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_port_authentication_parameters) structure that defines the default port authentication
parameters for the miniport adapter. For more information about port authentication parameters, see
[OID_GEN_PORT_AUTHENTICATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-port-authentication-parameters).

### `PciDeviceCustomProperties`

A pointer to an
[NDIS_PCI_DEVICE_CUSTOM_PROPERTIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_pci_device_custom_properties) structure that defines the PCI custom properties for the
miniport adapter.

## Remarks

NDIS passes a pointer to an initialized **NDIS_MINIPORT_INIT_PARAMETERS** structure in the
*MiniportInitParameters* parameter of the
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.

## See also

[CM_PARTIAL_RESOURCE_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_list)

[MiniportAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_add_device)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_PCI_DEVICE_CUSTOM_PROPERTIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_pci_device_custom_properties)

[NDIS_PORT_AUTHENTICATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_port_authentication_parameters)

[NET_LUID](https://learn.microsoft.com/windows/win32/api/ifdef/ns-ifdef-net_luid_lh)

[NdisIMInitializeDeviceInstanceEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisiminitializedeviceinstanceex)

[OID_GEN_PORT_AUTHENTICATION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-port-authentication-parameters)