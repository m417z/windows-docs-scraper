# NdisMReadConfigBlock function

## Description

A miniport driver for a PCI Express (PCIe) Virtual Function (VF) calls the **NdisMReadConfigBlock** function to read data from a VF configuration block. Read operations for a VF configuration block are handled by the miniport driver of the network adapter's PCIe Physical Function (PF).

**Note** **NdisMReadConfigBlock** must only be called by the VF miniport driver.

## Parameters

### `NdisMiniportHandle` [in]

The network adapter handle that NDIS passed to the
*MiniportAdapterHandle* parameter of
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize).

### `BlockId` [in]

A ULONG value that specifies the identifier of the VF configuration block to be read. This identifier is proprietary to the independent hardware vendor (IHV) and is used only by the PF and VF miniport drivers.

### `Buffer` [out]

A pointer to a caller-allocated buffer that will contain the requested configuration data.

### `Length` [in]

The number of bytes to be read from the VF configuration block.

## Return value

**NdisMReadConfigBlock** can return one of the following status values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The query operation completed successfully. |
| **NDIS_STATUS_FAILURE** | The query operation failed. |

## Remarks

The VF miniport driver calls **NdisMReadConfigBlock** to initiate a backchannel read request of VF configuration data by the PF miniport driver. Once notified of this request, the PF driver returns the data from the specified VF configuration block.

A VF configuration block is used for backchannel communication between the PF and VF miniport drivers. The IHV can define one or more VF configuration blocks for the device. Each VF configuration block has an IHV-defined format, length, and block ID.

**Note** Data from each VF configuration block is used only by the PF and VF miniport drivers.

For more information about backchannel communication within the single root I/O virtualization (SR-IOV) interface, see [SR-IOV PF/VF Backchannel Communication](https://learn.microsoft.com/windows-hardware/drivers/network/sr-iov-pf-vf-backchannel-communication).

For more information about the SR-IOV interface, see [Overview of Single Root I/O Virtualization (SR-IOV)](https://learn.microsoft.com/windows-hardware/drivers/network/overview-of-single-root-i-o-virtualization--sr-iov-).

### Interfacing to a Virtual Bus Driver

If an independent hardware vendor (IHV) provides a virtual bus driver (VBD) as part of its SR-IOV [driver package](https://learn.microsoft.com/previous-versions/windows/hardware/difxapi/driverpackagepreinstall), its miniport driver must not call **NdisMReadConfigBlock**. Instead, the driver must interface with the VBD through a private communication channel, and request that the VBD call [ReadVfConfigBlock](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/hh439637(v=vs.85)). This function is exposed from the [GUID_VPCI_INTERFACE_STANDARD](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/hh451580(v=vs.85)) interface that is supported by the underlying virtual PCI (VPCI) bus driver.

The VBD that runs in a Hyper-V child partition's guest operating system can query the [GUID_VPCI_INTERFACE_STANDARD](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/hh451580(v=vs.85)) interface by issuing an [IRP_MN_QUERY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-interface) request to its physical device object (PDO) on the VPCI bus. This request must be made from IRQL = PASSIVE_LEVEL. In this request, the driver must set the *InterfaceType* parameter to GUID_VPCI_INTERFACE_STANDARD.

## See also

[GUID_VPCI_INTERFACE_STANDARD](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/hh451580(v=vs.85))

[ReadVfConfigBlock](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/hh439637(v=vs.85))