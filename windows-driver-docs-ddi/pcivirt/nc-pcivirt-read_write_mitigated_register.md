# READ_WRITE_MITIGATED_REGISTER callback

## Description

Reads or writes to mitigated address spaces.

## Parameters

### `Context` [in]

A pointer to a driver-defined context.

### `VfIndex` [in]

A zero-based index of the VF to which this read/write operation applies.

### `Read` [in]

A boolean that indicates whether to perform a read or a write operation. TRUE indicates read, FALSE otherwise.

### `BarIndex` [in]

The BAR that maps the address space being mitigated.

### `Offset` [in]

The offset in number of bytes into the BAR at which this access begins.

### `Length` [in]

The length in bytes of this read or write operation.

### `Data` [in, out]

A pointer to a buffer that contains the data to read or write.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Prototype

```cpp
READ_WRITE_MITIGATED_REGISTER ReadWriteMitigatedRegister;

NTSTATUS ReadWriteMitigatedRegister(
  _In_    PVOID     Context,
  _In_    USHORT    VfIndex,
  _In_    BOOLEAN   Read,
  _In_    USHORT    BarIndex,
  _In_    ULONGLONG Offset,
  _In_    ULONG     Length,
  _Inout_ PUCHAR    Data
)
{ ... }

typedef READ_WRITE_MITIGATED_REGISTER *PREAD_WRITE_MITIGATED_REGISTER;
```

## Remarks

This callback function is implemented by the physical function (PF) driver. It is invoked when the system wants to read or write from a mitigable register.

The PF driver registers its implementation by setting the **ReadWriteMitigatedRegister** member of the [MITIGABLE_DEVICE_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ns-pcivirt-_mitigable_device_interface), configuring a [WDF_QUERY_INTERFACE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/ns-wdfqueryinterface-_wdf_query_interface_config) structure, and calling [WdfDeviceAddQueryInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nf-wdfqueryinterface-wdfdeviceaddqueryinterface).