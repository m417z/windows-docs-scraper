# NdisMQueryProbedBars function

## Description

A miniport driver calls the **NdisMQueryProbedBars** function to obtain the values of a network adapter's PCI Express (PCIe) Base Address Registers (BARs). This function returns the BAR values that were reported by the network adapter following a query performed by the PCI bus driver. This query determines the memory or I/O address space that is required by the network adapter.

**Note** **NdisMQueryProbedBars** must only be called by the miniport driver for the network adapter's PCIe Physical Function (PF).

## Parameters

### `NdisMiniportHandle` [in]

The network adapter handle that NDIS passed to the
*MiniportAdapterHandle* parameter of
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize).

### `BaseRegisterValues` [out]

A pointer to an array of ULONG values. The array contains a ULONG value for each BAR of the PCIe network adapter.

**Note** **NdisMQueryProbedBars** returns a maximum of PCI_TYPE0_ADDRESSES values within this array.

## Return value

**NdisMQueryProbedBars** can return one of the following status values.

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The query operation completed successfully. |
| **NDIS_STATUS_FAILURE** | The query operation failed. |

## Remarks

The PCI bus driver, which runs in the management operating system of the Hyper-V parent partition, queries the memory or I/O address space requirements of each PCI Base Address Register (BAR) of the network adapter. The PCI bus driver performs this query when it first detects the adapter on the bus.

Through this PCI BAR query, the PCI bus driver determines the following:

* Whether a PCI BAR is supported by the network adapter.
* If a BAR is supported, how much memory or I/O
  address space is required for the BAR.

The virtual PCI (VPCI) bus driver runs in the guest operating system of a Hyper-V child partition. When a PCI Express (PCIe) Virtual Function (VF) is attached to the child partition, the VPCI bus driver will expose a virtual network adapter for the VF (*VF network adapter*). Before it does this, the VPCI bus driver must perform a PCI BAR query to determine the required memory or address space that is required by the VF network adapter.

Because access to the PCI configuration space is a privileged operation, it can only be performed by components that run in the management operating system of a Hyper-V parent partition. When the VPCI bus driver queries the PCI BARs, NDIS issues an object identifier (OID) query request of [OID_SRIOV_PROBED_BARS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-sriov-probed-bars) to the PF miniport driver. The results returned by this OID query request are forwarded to the VPCI bus driver so that it can determine how much memory address space would be needed by the VF network adapter.

During the handling of this OID request, the driver can call **NdisMQueryProbedBars** to obtain the values returned from the BAR query performed by the PCI driver.

For more information on how to query PCI BAR registers for a VF, see [Querying the PCI Base Address Registers of a Virtual Function](https://learn.microsoft.com/windows-hardware/drivers/network/querying-the-pci-base-address-registers-of-a-virtual-function).

For more information about the SR-IOV interface, see [Overview of Single Root I/O Virtualization (SR-IOV)](https://learn.microsoft.com/windows-hardware/drivers/network/overview-of-single-root-i-o-virtualization--sr-iov-).

### Interfacing to a Virtual Bus Driver

If an independent hardware vendor (IHV) provides a virtual bus driver (VBD) as part of its SR-IOV [driver package](https://learn.microsoft.com/previous-versions/windows/hardware/difxapi/driverpackagepreinstall), its miniport driver must not call **NdisMQueryProbedBars**. Instead, the driver must interface with the VBD through a private communication channel, and request that the VBD call [GetVirtualFunctionProbedBars](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-get_virtual_function_probed_bars). This function is exposed from the [GUID_PCI_VIRTUALIZATION_INTERFACE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/hh406642(v=vs.85)) interface that is supported by the underlying PCI bus driver.

The VBD that runs in the Hyper-V parent partition's management operating system can query the [GUID_PCI_VIRTUALIZATION_INTERFACE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/hh406642(v=vs.85)) interface by issuing an [IRP_MN_QUERY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-interface) request to its physical device object (PDO) on the PCI bus. This request must be made from IRQL = PASSIVE_LEVEL. In this request, the driver must set the *InterfaceType* parameter to GUID_PCI_VIRTUALIZATION_INTERFACE.

## See also

[GUID_PCI_VIRTUALIZATION_INTERFACE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/hh406642(v=vs.85))

[GetVirtualFunctionProbedBars](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-get_virtual_function_probed_bars)

[OID_SRIOV_PROBED_BARS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-sriov-probed-bars)