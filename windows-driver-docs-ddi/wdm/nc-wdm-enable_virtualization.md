## Description

The **EnableVirtualization** routine enables or disables virtualization for a PCI Express (PCIe) device that supports the single root I/O virtualization (SR-IOV) interface.

## Parameters

### `Context` [in, out]

A pointer to interface-specific context information. The caller passes the value that is passed as the **Context** member of the [PCI_VIRTUALIZATION_INTERFACE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/hh406642(v=vs.85)) structure for the interface.

### `NumVFs` [in]

The number of PCIe virtual functions (VFs) that are to be enabled for the device. The **EnableVirtualization** routine sets the **NumVFs** member of the PCIe SR-IOV Extended Capability structure to the value of the *NumVFs* parameter.

If the *EnableVirtualization* parameter is **FALSE**, the *NumVFs* parameter must be set to zero.

### `EnableVfMigration` [in]

A BOOLEAN value that indicates whether the multi-root I/O virtualization (MR-IOV) base function (BF) can dynamically reprovision the PCIe physical function (PF) of the device as a VF at run time.

This parameter is only applicable to devices that support both the SR-IOV and MR-IOV interfaces. The driver must set this parameter to **FALSE** if the device supports only the SR-IOV interface and not the MR-IOV interface.

### `EnableMigrationInterrupt` [in]

A BOOLEAN value that indicates whether the interrupt associated with the PF should be masked or unmasked during VF migration.

If the *EnableVfMigration* parameters is **FALSE**, the driver must also set this parameter to **FALSE**.

### `EnableVirtualization` [in]

A BOOLEAN value that indicates whether virtualization is enabled on the PCIe configuration space of the device. If the *EnableVirtualization* parameter is **TRUE**, the **EnableVirtualization** routine sets the VF Enable bit of the PCIe SR-IOV Control field. The *EnableVirtualization* routine clears this bit if the *EnableVirtualization* parameter is **FALSE**.

## Return value

The **EnableVirtualization** routine returns one of the following NTSTATUS values:

| Return code | Description |
|---|---|
| **STATUS_SUCCESS** | The operation completed successfully. |
| **STATUS_INVALID_PARAMETER** | The *NumVFs* parameter is either zero or is larger than the value of the **TotalVFs** member of the SR-IOV Extended Capability structure for the device. |
| **STATUS_INVALID_DEVICE_STATE** | Virtualization is already enabled on the device and the *EnableVirtualization* parameter is **TRUE**, or virtualization is already disabled on the device and the *EnableVirtualization* parameter is **FALSE**. |

## Remarks

Drivers call the **EnableVirtualization** routine to configure the SR-IOV Extended Capability fields in the PCIe configuration space. This call enables or disables virtualization in the configuration space, and specifies the number of VFs that should be exposed to the PCIe fabric by the device.

The **EnableVirtualization** routine is provided by the **GUID_PCI_VIRTUALIZATION_INTERFACE** interface.

## See also

[PCI_VIRTUALIZATION_INTERFACE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/hh406642(v=vs.85))