# SRIOV_WRITE_CONFIG callback

## Description

Writes configuration data to a PCI Express SR-IOV Virtual Function (VF).

## Parameters

### `Context` [in]

A pointer to a driver-defined context.

### `Data` [in]

A pointer to buffer that contains the data to be written to the configuration space.

### `VfIndex` [in]

A zero-based index of the VF to which this write operation applies.

### `Offset` [in]

An offset in bytes to the start of the VF’s configuration space where the write begins.

### `Length` [in]

The length, in bytes, of the data to write to the configuration space.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Prototype

```cpp
SRIOV_WRITE_CONFIG SriovWriteConfig;

NTSTATUS SriovWriteConfig(
  _In_       PVOID  Context,
  _In_ const VOID   *Data,
  _In_       USHORT VfIndex,
  _In_       ULONG  Offset,
  _In_       ULONG  Length
)
{ ... }

typedef SRIOV_WRITE_CONFIG *PSRIOV_WRITE_CONFIG;
```

## Remarks

This callback function is implemented by the physical function (PF) driver. It is invoked when the system wants to write to the configuration space of a specific virtual function.

The PF driver registers its implementation by setting the **WriteVfConfig** member of the [SRIOV_DEVICE_INTERFACE_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ns-pcivirt-_sriov_device_interface_standard), configuring a [WDF_QUERY_INTERFACE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/ns-wdfqueryinterface-_wdf_query_interface_config) structure, and calling [WdfDeviceAddQueryInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nf-wdfqueryinterface-wdfdeviceaddqueryinterface).