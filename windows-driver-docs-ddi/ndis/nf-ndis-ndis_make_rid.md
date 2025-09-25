# NDIS_MAKE_RID macro

## Description

The **NDIS_MAKE_RID** macro builds an NDIS_VF_RID value from PCI Express (PCIe) segment, bus, device, and function numbers. The miniport driver uses this value as a PCIe Requestor ID (RID) for a network adapter's PCIe Virtual Function (VF).

## Parameters

### `_Segment`

The PCIe segment number for the group of PCIe buses on which the device is attached. A PCIe segment is a set of PCIe buses that share configuration space.

### `_Bus`

The PCIe bus number of the bus on which the network adapter is attached.

### `_Function`

The function number of a logical device on the network adapter.

## Return value

NDIS_MAKE_RID returns an NDIS_VF_RID value that is constructed from the parameters.

## Remarks

When it handles an OID request of [OID_NIC_SWITCH_ALLOCATE_VF](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-allocate-vf), the miniport driver for the PCIe Physical Function (PF) uses the **NDIS_MAKE_RID** macro to create a PCIe Requestor ID (RID) value for the VF. The driver retrieves the PCIe segment, bus, device, and function numbers for the VF by calling [**NdisMGetVirtualFunctionLocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismgetvirtualfunctionlocation).

> [!NOTE]
> If an independent hardware vendor (IHV) provides a virtual bus driver (VBD) as part of its SR-IOV [driver package](https://learn.microsoft.com/windows-hardware/drivers/install/driver-packages), its PF miniport driver must not call [**NdisMGetVirtualFunctionLocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismgetvirtualfunctionlocation). Instead, the driver must interface with the VBD through a private communication channel, and request that the VBD call [*GetLocation*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-get_virtual_device_location). This function is exposed from the [GUID_PCI_VIRTUALIZATION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/pci/) interface supported by the underlying PCI bus driver.

## See also

[**NdisMGetVirtualFunctionLocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismgetvirtualfunctionlocation)

[OID_NIC_SWITCH_ALLOCATE_VF](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-allocate-vf)