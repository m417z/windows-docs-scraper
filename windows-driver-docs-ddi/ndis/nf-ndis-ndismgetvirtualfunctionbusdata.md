# NdisMGetVirtualFunctionBusData function

## Description

A miniport driver calls the **NdisMGetVirtualFunctionBusData** function to read data from the PCI Express (PCIe) configuration space of a specified Virtual Function (VF) on the network adapter.

**Note** **NdisMGetVirtualFunctionBusData** must only be called by the miniport driver for the network adapter's PCIe Physical Function (PF).

## Parameters

### `NdisMiniportHandle` [in]

The network adapter handle that NDIS passed to the
*MiniportAdapterHandle* parameter of
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize).

### `VFId` [in]

The identifier of the VF from which the data from the PCI configuration space is returned.

### `Buffer` [out]

A pointer to a buffer that receives the data that is read from the VF's PCI configuration space.

### `Offset` [in]

The offset, in units of bytes, in the VF's PCI configuration space from which data is read.

### `Length` [in]

The length, in units of bytes, of the data to be read.

**Note** The size of the buffer referenced by *Buffer* must be at least as large as the value of the *Length* parameter.

## Return value

**NdisMGetVirtualFunctionBusData** returns the number of bytes that are read from the PCI configuration space. If the read operation fails, **NdisMGetVirtualFunctionBusData** returns zero.

## Remarks

The PF miniport driver typically calls **NdisMGetVirtualFunctionBusData** when it handles an OID method request of [OID_SRIOV_READ_VF_CONFIG_SPACE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-sriov-read-vf-config-space).
However, the driver can call this function any time after virtualization has been enabled on the network adapter through a call to [NdisMEnableVirtualization](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismenablevirtualization).

For more information on how to query the VF's PCI configuration space, see [Querying the PCI Configuration Space for a Virtual Function](https://learn.microsoft.com/windows-hardware/drivers/network/querying-the-pci-configuration-space-for-a-virtual-function).

For more information about the SR-IOV interface, see [Overview of Single Root I/O Virtualization (SR-IOV)](https://learn.microsoft.com/windows-hardware/drivers/network/overview-of-single-root-i-o-virtualization--sr-iov-).

### Interfacing to a Virtual Bus Driver

If an independent hardware vendor (IHV) provides a virtual bus driver (VBD) as part of its SR-IOV [driver package](https://learn.microsoft.com/previous-versions/windows/hardware/difxapi/driverpackagepreinstall), its miniport driver must not call **NdisMGetVirtualFunctionBusData**. Instead, the driver must interface with the VBD through a private communication channel, and request that the VBD call [GetVirtualFunctionData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-get_virtual_device_data). This function is exposed from the [GUID_PCI_VIRTUALIZATION_INTERFACE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/hh406642(v=vs.85)) interface that is supported by the underlying PCI bus driver.

The VBD that runs in the Hyper-V parent partition's management operating system can query the [GUID_PCI_VIRTUALIZATION_INTERFACE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/hh406642(v=vs.85)) interface by issuing an [IRP_MN_QUERY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-interface) request to its physical device object (PDO) on the PCI bus. This request must be made from IRQL = PASSIVE_LEVEL. In this request, the driver must set the *InterfaceType* parameter to GUID_PCI_VIRTUALIZATION_INTERFACE.

## See also

[GUID_PCI_VIRTUALIZATION_INTERFACE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/hh406642(v=vs.85))

[GetVirtualFunctionData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-get_virtual_device_data)

[NdisMEnableVirtualization](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismenablevirtualization)

[OID_NIC_SWITCH_ALLOCATE_VF](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-allocate-vf)

[OID_SRIOV_READ_VF_CONFIG_SPACE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-sriov-read-vf-config-space)