# SRIOV_READ_CONFIG callback

## Description

Reads data from the configuration space of the specified PCI Express SR-IOV Virtual Function (VF).

## Parameters

### `Context` [in]

A pointer to a driver-defined context.

### `Data` [out]

A pointer to buffer that contains the configuration information to be read from the VF's configuration space.

### `VfIndex` [in]

A zero-based index of the VF to which this read operation applies.

### `Offset` [in]

An offset in bytes to the start of the VF’s configuration space where the read begins.

### `Length` [in]

The length, in bytes, of the data to read from the configuration space.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Prototype

```cpp
NTSTATUS  SRIOV_READ_CONFIG(
  _In_        PVOID  Context,
  _Out_ const VOID   *Data,
  _In_        USHORT VfIndex,
  _In_        ULONG  Offset,
  _In_        ULONG  Length
);

typedef SRIOV_READ_CONFIG *PSRIOV_READ_CONFIG;
```

## Remarks

This callback function is implemented by the physical function (PF) driver. It is invoked when the system wants to read from the configuration space of a specific virtual function.

The PF driver registers its implementation by setting the **ReadVfConfig** member of the [SRIOV_DEVICE_INTERFACE_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ns-pcivirt-_sriov_device_interface_standard), configuring a [WDF_QUERY_INTERFACE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/ns-wdfqueryinterface-_wdf_query_interface_config) structure, and calling [WdfDeviceAddQueryInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nf-wdfqueryinterface-wdfdeviceaddqueryinterface).