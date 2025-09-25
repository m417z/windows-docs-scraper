# NdisMSetVirtualFunctionBusData function

## Description

A miniport driver calls the **NdisMSetVirtualFunctionBusData** function to write data to the PCI Express (PCIe) configuration space of a Virtual Function (VF) on the network adapter.

**Note** **NdisMGetVirtualFunctionBusData** must only be called by the miniport driver for the network adapter's PCIe Physical Function (PF).

## Parameters

### `NdisMiniportHandle` [in]

The network adapter handle that NDIS passed to the
*MiniportAdapterHandle* parameter of
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize).

### `VFId` [in]

The identifier of the VF to which data is written to its PCI configuration space.

### `Buffer` [in]

A pointer to a buffer that contains the data to be written to the PCI configuration space.

### `Offset` [in]

The offset, in units of bytes, in the PCI configuration space to which data is written.

### `Length` [in]

The length, in units of bytes, of the data to be written.

## Return value

**NdisMSetVirtualFunctionBusData** returns the number of bytes written to the PCI configuration space. If the write operation fails, **NdisMSetVirtualFunctionBusData** returns zero.

## Remarks

The PF miniport driver typically calls **NdisMSetVirtualFunctionBusData** when it handles an OID method request of [OID_SRIOV_WRITE_VF_CONFIG_SPACE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-sriov-write-vf-config-space).
However, the driver can call this function any time after virtualization has been enabled on the network adapter through a call to [NdisMEnableVirtualization](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismenablevirtualization).

For more information about backchannel communication within the single root I/O virtualization (SR-IOV) interface, see [SR-IOV PF/VF Backchannel Communication](https://learn.microsoft.com/windows-hardware/drivers/network/sr-iov-pf-vf-backchannel-communication).

For more information about the SR-IOV interface, see [Overview of Single Root I/O Virtualization (SR-IOV)](https://learn.microsoft.com/windows-hardware/drivers/network/overview-of-single-root-i-o-virtualization--sr-iov-).

### Interfacing to a Virtual Bus Driver

If an independent hardware vendor (IHV) provides a virtual bus driver (VBD) as part of its SR-IOV [driver package](https://learn.microsoft.com/previous-versions/windows/hardware/difxapi/driverpackagepreinstall), its miniport driver must not call **NdisMSetVirtualFunctionBusData**. Instead, the driver must interface with the VBD through a private communication channel, and request that the VBD call [SetVirtualFunctionData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-set_virtual_device_data). This function is exposed from the [GUID_PCI_VIRTUALIZATION_INTERFACE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/hh406642(v=vs.85)) interface that is supported by the underlying PCI bus driver.

The VBD that runs in the Hyper-V parent partition's management operating system can query the [GUID_PCI_VIRTUALIZATION_INTERFACE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/hh406642(v=vs.85)) interface by issuing an [IRP_MN_QUERY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-interface) request to its physical device object (PDO) on the PCI bus. This request must be made from IRQL = PASSIVE_LEVEL. In this request, the driver must set the *InterfaceType* parameter to GUID_PCI_VIRTUALIZATION_INTERFACE.

## See also

[GUID_PCI_VIRTUALIZATION_INTERFACE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/hh406642(v=vs.85))

[NdisMEnableVirtualization](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismenablevirtualization)

[OID_NIC_SWITCH_ALLOCATE_VF](https://learn.microsoft.com/windows-hardware/drivers/network/oid-nic-switch-allocate-vf)

[OID_SRIOV_WRITE_VF_CONFIG_SPACE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-sriov-write-vf-config-space)

[SetVirtualFunctionData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-set_virtual_device_data)