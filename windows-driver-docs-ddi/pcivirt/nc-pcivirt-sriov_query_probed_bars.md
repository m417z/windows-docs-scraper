# SRIOV_QUERY_PROBED_BARS callback

## Description

Queries the data read from
the physical function's (PF) base address registers (BARs) if the value -1 were written to them first.

## Parameters

### `Context` [in]

A pointer to a driver-defined context.

### `BaseRegisterValues` [out]

A pointer to an array of variables that is bounded by the number of BARs in a PCI device.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Prototype

```cpp
SRIOV_QUERY_PROBED_BARS SriovQueryProbedBars;

NTSTATUS SriovQueryProbedBars(
  _In_  PVOID  Context,
  _Out_ PULONG BaseRegisterValues
)
{ ... }

typedef SRIOV_QUERY_PROBED_BARS *PSRIOV_QUERY_PROBED_BARS;
```

## Remarks

This callback function is implemented by the physical function (PF) driver. It is invoked when the system wants to get base address register values.

The PF driver registers its implementation by setting the **QueryProbedBars** member of the [SRIOV_DEVICE_INTERFACE_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ns-pcivirt-_sriov_device_interface_standard), configuring a [WDF_QUERY_INTERFACE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/ns-wdfqueryinterface-_wdf_query_interface_config) structure, and calling [WdfDeviceAddQueryInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nf-wdfqueryinterface-wdfdeviceaddqueryinterface).