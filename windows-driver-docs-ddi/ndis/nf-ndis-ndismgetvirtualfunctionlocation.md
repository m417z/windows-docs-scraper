# NdisMGetVirtualFunctionLocation function

## Description

A miniport driver calls the **NdisMGetVirtualFunctionLocation** function to query the device location of a PCI Express (PCIe) Virtual Function (VF) on a PCI bus. The driver uses the device location to construct the PCIe Requestor ID (RID) for the VF.

**Note** **NdisMGetVirtualFunctionLocation** must only be called by the miniport driver for the network adapter's PCIe Physical Function (PF).

## Parameters

### `NdisMiniportHandle` [in]

The network adapter handle that NDIS passed to the
*MiniportAdapterHandle* parameter of
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize).

### `VFId` [in]

The identifier of the VF for which the device location is returned.

### `SegmentNumber` [out]

A pointer to a caller-supplied variable in which this function returns a USHORT value for the current PCI segment number. This value specifies the group of PCI buses on which the device is attached.

### `BusNumber` [out]

A pointer to a caller-supplied variable in which this function returns a UCHAR value. This value specifies the current PCI bus number on which the device is attached.

### `FunctionNumber` [out]

A pointer to a caller-supplied variable in which this function returns a UCHAR value. This value specifies the function number of a logical device on the device.

## Remarks

 When it handles a method request of [OID_NIC_SWITCH_ALLOCATE_VF](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-allocate-vf), the PF miniport driver must return the RID for the VF that the driver has successfully allocated on the network adapter. The driver generates the RID in the following way:

1. The driver first calls the **NdisMGetVirtualFunctionLocation** function to obtain the bus-related location information for the VF.
2. The driver then calls the [NDIS_MAKE_RID](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-make-rid) macro with the bus-related location information to generate the RID.

For more information on how to allocate VF resources, see [Virtual Function Initialization Sequence](https://learn.microsoft.com/windows-hardware/drivers/network/virtual-function-initialization-sequence).

For more information about the SR-IOV interface, see [Overview of Single Root I/O Virtualization (SR-IOV)](https://learn.microsoft.com/windows-hardware/drivers/network/overview-of-single-root-i-o-virtualization--sr-iov-).

### Interfacing to a Virtual Bus Driver

If an independent hardware vendor (IHV) provides a virtual bus driver (VBD) as part of its SR-IOV [driver package](https://learn.microsoft.com/previous-versions/windows/hardware/difxapi/driverpackagepreinstall), its miniport driver must not call **NdisMGetVirtualFunctionLocation**. Instead, the driver must interface with the VBD through a private communication channel, and request that the VBD call [GetLocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-get_virtual_device_location). This function is exposed from the [GUID_PCI_VIRTUALIZATION_INTERFACE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/hh406642(v=vs.85)) interface supported by the underlying PCI bus driver.

The VBD that runs in the Hyper-V parent partition's management operating system can query the [GUID_PCI_VIRTUALIZATION_INTERFACE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/hh406642(v=vs.85)) interface by issuing an [IRP_MN_QUERY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-interface) request to its physical device object (PDO) on the PCI bus. This request must be made from IRQL = PASSIVE_LEVEL. In this request, the driver must set the *InterfaceType* parameter to GUID_PCI_VIRTUALIZATION_INTERFACE.

## See also

[GUID_PCI_VIRTUALIZATION_INTERFACE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/hh406642(v=vs.85))

[GetLocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-get_virtual_device_location)

[NDIS_MAKE_RID](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-make-rid)

[OID_NIC_SWITCH_ALLOCATE_VF](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-allocate-vf)