## Description

The **GetLocation** routine returns the device location of a PCI Express (PCIe) virtual function (VF) on a PCI bus. A device that supports the single root I/O virtualization (SR-IOV) interface can expose one or more VFs on the PCI bus.

## Parameters

### `Context` [in, out]

A pointer to interface-specific context information. The caller passes the value that is passed as the **Context** member of the [**PCI_VIRTUALIZATION_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-pci_virtualization_interface) structure for the interface.

### `VirtualFunction` [in]

A zero-based value that specifies the VF on the device for which the device location is returned

### `SegmentNumber` [out]

A pointer to a caller-supplied variable in which this routine returns a UINT16 value for the current PCI segment number. This value specifies the group of PCI buses on which the device is attached.

### `BusNumber` [out]

A pointer to a caller-supplied variable in which this routine returns a UINT8 value. This value specifies the current PCI bus number on which the device is attached.

### `FunctionNumber` [out]

A pointer to a caller-supplied variable in which this routine returns a UINT8 value. This value contains the function number for the specified VF on the PCI bus.

## Return value

The **GetLocation** routine returns one of the following NTSTATUS values:

| Return code | Description |
|---|---|
| **STATUS_SUCCESS** | The operation completed successfully. |
| **STATUS_INVALID_PARAMETER** | The *VirtualFunction* parameter is larger than the value of the **TotalVFs** member of the SR-IOV Extended Capability structure for the device. |

## Remarks

The **GetLocation** routine returns the current device location of a VF in the PCIe hierarchy. This information is necessary for a virtualization system that is using an I/O memory management unit (IOMMU) to route traffic to or from the device.

Upon a successful return from a call to the **GetLocation** routine, the *FunctionNumber* parameter contains a value that represents the function number for the specified VF on the PCI bus. This value is based on the Alternative Routing Interpretation (ARI) option of the PCI Express 3.0 specification. ARI treats a PCIe bus as a single device with an 8-bit function space, which allows for 256 functions on the bus.

The **GetLocation** routine is provided by the **GUID_PCI_VIRTUALIZATION_INTERFACE** interface.

The PCI bus number on which the VF is located can change. We do not recommend that drivers store the device location for a VF in nonvolatile storage such as the registry.

## See also

[**PCI_VIRTUALIZATION_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-pci_virtualization_interface)