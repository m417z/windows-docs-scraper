# SRIOV_QUERY_LUID_VF callback

## Description

Gets the PCI Express SR-IOV Virtual Function (VF) given a unique identifier.

## Parameters

### `Context` [in]

A pointer to a driver-defined context.

### `Luid` [in]

The local unique
identifier of the VF whose index is being retrieved.

### `VfIndex` [out]

A zero-based index of the VF that is being queried.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Prototype

```cpp
SRIOV_QUERY_LUID_VF SriovQueryLuidVf;

NTSTATUS SriovQueryLuidVf(
  _In_  PVOID  Context,
  _In_  LUID   Luid,
  _Out_ USHORT VfIndex
)
{ ... }

typedef SRIOV_QUERY_LUID_VF *PSRIOV_QUERY_LUID_VF;
```

## Remarks

This callback function is implemented by the physical function (PF) driver. It is invoked when the system wants to get the identifier of a specific virtual function.

The PF driver registers its implementation by setting the **QueryLuidVf** member of the [SRIOV_DEVICE_INTERFACE_STANDARD_2](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ns-pcivirt-_sriov_device_interface_standard_2), configuring a [WDF_QUERY_INTERFACE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/ns-wdfqueryinterface-_wdf_query_interface_config) structure, and calling [WdfDeviceAddQueryInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nf-wdfqueryinterface-wdfdeviceaddqueryinterface).