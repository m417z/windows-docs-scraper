## Description

The **GetVirtualFunctionProbedBars** routine returns the values of the PCI Express (PCIe) Base Address Registers (BARs) of a device that supports the single root I/O virtualization (SR-IOV) interface.

**GetVirtualFunctionProbedBars** returns the BAR values that were reported by the device after a query that was performed by the PCI bus driver. This query determines the memory or I/O address space that is required by the device.

## Parameters

### `Context` [in, out]

A pointer to interface-specific context information. The caller passes the value that is passed as the **Context** member of the [**PCI_VIRTUALIZATION_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-pci_virtualization_interface) structure for the interface.

### `BaseRegisterValues` [out]

A pointer to an array of ULONG values. The **GetVirtualFunctionProbedBars** routine returns a value for each BAR of the device.

**GetVirtualFunctionProbedBars** returns a maximum of **PCI_TYPE0_ADDRESSES** values within this array.

## Return value

The **GetVirtualFunctionProbedBars** routine returns one of the following NTSTATUS values:

| Return code | Description |
|---|---|
| **STATUS_SUCCESS** | The operation completed successfully. |
| **STATUS_INVALID_DEVICE_STATE** | The device does not support the SR-IOV interface. |

## Remarks

The PCI bus driver. which runs in the management operating system of the Hyper-V parent partition, queries the memory or I/O address space requirements of each BAR of the device. The PCI bus driver performs this query when the it first detects the adapter on the bus.

Through this BAR query, the PCI bus driver determines the following:

- Whether a BAR is supported by the device.

- If a BAR is supported, how much memory or I/O address space is required for the BAR.

The PCI driver performs this BAR query as follows:

1. The PCI bus driver writes 0xFFFFFFFF to a BAR.

1. The PCI bus driver reads the BAR to determine the memory or address space that the device requires. A value of zero indicates that the device does not support the BAR.

The **GetVirtualFunctionProbedBars** routine is provided by the **GUID_PCI_VIRTUALIZATION_INTERFACE** interface.

The following notes apply to the **GetVirtualFunctionProbedBars** routine:

- The SR-IOV interface does not require that the BARs of a PCIe VF comply with the protocol for determining the size of the memory block or I/O address space of a BAR. Therefore, the virtual PCI (VPCI) driver, which runs in the guest operating system, determines the size by using the equivalent size from the BARs on the physical device. The VPCI driver obtains this information by calling the **GetVirtualFunctionProbedBars** routine.

- The VPCI driver requires the size of the memory or I/O
address space for each BAR after the physical device has started. At that point, the PCI driver cannot perform a BAR query on the device without altering the current value of the BAR. Therefore, when the **GetVirtualFunctionProbedBars** routine is called by the VPCI driver, the PCI driver returns the BAR information that it obtained during the BAR query. The PCI driver performed this query when the device was first detected on the bus.

## See also

[**PCI_VIRTUALIZATION_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-pci_virtualization_interface)