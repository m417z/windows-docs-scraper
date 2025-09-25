# SRIOV_QUERY_PROBED_BARS_2 callback

## Description

Queries the data read from
the specified PCI Express SR-IOV Virtual Function (VF) base address registers (BARs) if the value -1 were written to them first.

## Parameters

### `Context` [in]

A pointer to a driver-defined context.

### `VfIndex` [in]

A zero-based index of the VF that is being queried.

### `BaseRegisterValues` [out]

A pointer to an array of variables that is bounded by the number of BARs in a PCI device.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Prototype

```cpp
SRIOV_QUERY_PROBED_BARS_2 SriovQueryProbedBars2;

NTSTATUS SriovQueryProbedBars2(
  _In_  PVOID  Context,
  _In_  USHORT VfIndex,
  _Out_ PULONG BaseRegisterValues
)
{ ... }

typedef SRIOV_QUERY_PROBED_BARS_2 *PSRIOV_QUERY_PROBED_BARS_2;
```

## Remarks

This callback function is implemented by the physical function (PF) driver. It is invoked when the system wants to read from
the specified virtual function's (VF) base address registers.

The PF driver registers its implementation by setting the **QueryProbedBars_2** member of the [SRIOV_DEVICE_INTERFACE_STANDARD_2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ns-pcivirt-_sriov_device_interface_standard_2), configuring a [WDF_QUERY_INTERFACE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/ns-wdfqueryinterface-_wdf_query_interface_config) structure, and calling [WdfDeviceAddQueryInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nf-wdfqueryinterface-wdfdeviceaddqueryinterface).

This callback is invoked by the virtualization stack (non-privileged) when it wants to find out the VF’s base address register values after the registers are written with the value (-1). This process is conventional when setting up a PCI device, and the result allows the PCI driver to know the amount of address space that would be decoded by the device after it is enabled. When a non-privileged VM writes to the VF’s BARs, the privileged VM can stop functioning. Therefore, this routine requires the need for writing to the BARs.