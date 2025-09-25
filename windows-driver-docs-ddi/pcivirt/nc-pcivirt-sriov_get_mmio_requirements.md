# SRIOV_GET_MMIO_REQUIREMENTS callback

## Description

This callback function is not supported.

Gets the Memory-Mapped I/O space of the specified PCI Express SR-IOV Virtual Function (VF).

## Parameters

### `Context` [in]

A pointer to a driver-defined context.

### `VfIndex` [in]

A zero-based index of the VF to which this read operation applies.

### `BlockId` [in]

A number identifying the block to be read. This is defined by the provider of the PF driver.

### `Buffer` [out]

A pointer to a buffer that receives the data read from the VF's MMIO space.

### `Length` [in]

The length in bytes of this read operation.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Prototype

```cpp
SRIOV_GET_MMIO_REQUIREMENTS SriovGetMmioRequirements;

NTSTATUS SriovGetMmioRequirements(
  _In_  PVOID  Context,
  _In_  USHORT VfIndex,
  _In_  ULONG  BlockId,
  _Out_ PVOID  Buffer,
  _In_  ULONG  Length
)
{ ... }

typedef SRIOV_GET_MMIO_REQUIREMENTS *PSRIOV_GET_MMIO_REQUIREMENTS;
```

## Remarks

This callback function is implemented by the physical function (PF) driver. It is invoked when the system wants to retrieve MMIO requirement of the specified VF.

`(Question: How is this registered?)`