# SRIOV_RESET_FUNCTION callback

## Description

Resets the specified PCI Express SR-IOV Virtual Function (VF).

## Parameters

### `Context` [in]

A pointer to a driver-defined context.

### `VfIndex` [in]

A zero-based index of the VF that is to be reset.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Prototype

```cpp
SRIOV_RESET_FUNCTION SriovResetFunction;

NTSTATUS SriovResetFunction(
  _In_ PVOID  Context,
  _In_ USHORT VfIndex
)
{ ... }

typedef SRIOV_RESET_FUNCTION *PSRIOV_RESET_FUNCTION;
```

## Remarks

This callback function is implemented by the physical function (PF) driver. It is invoked when the system wants to reset a specific virtual function.

The PF driver registers its implementation by setting the **ResetVf**  member of the [SRIOV_DEVICE_INTERFACE_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ns-pcivirt-_sriov_device_interface_standard), configuring a [WDF_QUERY_INTERFACE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/ns-wdfqueryinterface-_wdf_query_interface_config) structure, and calling [WdfDeviceAddQueryInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nf-wdfqueryinterface-wdfdeviceaddqueryinterface).