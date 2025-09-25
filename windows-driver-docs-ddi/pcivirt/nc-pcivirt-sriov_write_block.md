# SRIOV_WRITE_BLOCK callback

## Description

Writes data to the specified configuration block of a PCI Express SR-IOV Virtual Function (VF).

## Parameters

### `Context` [in]

A pointer to a driver-defined context.

### `VfIndex` [in]

A zero-based index of the VF to which this write operation applies.

### `BlockId` [in]

A number identifying the block to be written. This is defined by the provider of the PF driver.

### `Buffer` [in]

A pointer to a buffer that contains the data to write to the VF's configuration space.

### `Length`

The length in bytes of this write operation. Must not be greater than VPCI_MAX_READ_WRITE_BLOCK_SIZE defined in Pcivirt.h.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Prototype

```cpp
SRIOV_WRITE_BLOCK SriovWriteBlock;

NTSTATUS SriovWriteBlock(
  _In_ PVOID  Context,
  _In_ USHORT VfIndex,
  _In_ ULONG  BlockId,
  _In_ PVOID  Buffer,
       ULONG  Length
)
{ ... }

typedef SRIOV_WRITE_BLOCK *PSRIOV_WRITE_BLOCK;
```

## Remarks

This callback function is implemented by the physical function (PF) driver. It is invoked when the system wants to read a configuration block for one of its VFs.

The PF driver registers its implementation by setting the **WriteVfConfigBlock** member of the [SRIOV_DEVICE_INTERFACE_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ns-pcivirt-_sriov_device_interface_standard), configuring a [WDF_QUERY_INTERFACE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/ns-wdfqueryinterface-_wdf_query_interface_config) structure, and calling [WdfDeviceAddQueryInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nf-wdfqueryinterface-wdfdeviceaddqueryinterface).