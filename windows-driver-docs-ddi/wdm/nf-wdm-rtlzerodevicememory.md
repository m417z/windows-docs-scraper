## Description

The **RtlZeroDeviceMemory** function is a convenience wrapper around [**RtlFillDeviceMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfilldevicememory).

## Parameters

### `Destination` [out]

A pointer to the starting address of the block of memory to fill with zeros.

### `Length` [in]

The size of the block of memory to fill with zeros, in bytes.

## Return value

Returns the value of *Destination*.

## Remarks

The **RtlZeroDeviceMemory** function is a convenience wrapper around **RtlFillDeviceMemory**.

For more information, see the remarks section of [**RtlFillDeviceMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfilldevicememory).

> [!NOTE]
> This function works on all versions of Windows, not just the latest. You need to consume the latest WDK to get the function declaration from the wdm.h header. You also need the library (volatileaccessk.lib) from the latest WDK. However, the resulting driver will run fine on older versions of Windows.

### Example

```cpp
// In this scenario we are setting data on memory mapped
// as "device memory" (for example, memory not backed by RAM) to the value zero. On
// some platforms like ARM64, device memory cannot tolerate
// memory accesses that are not naturally aligned (for example, a 4-byte
// load must be 4-byte aligned). Functions like memset, RtlFillMemory,
// and even RtlFillVolatileMemory may perform unaligned memory accesses
// because it is typically faster to do this.
// To ensure only naturally aligned accesses happen, use RtlFillDeviceMemory.
//
// RtlZeroDeviceMemory is an wrapper around RtlFillDeviceMemory that sets the memory
// to zero.

RtlZeroDeviceMemory(DeviceMemoryBuffer, 100);
```

## See also

[**RtlFillDeviceMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlfilldevicememory)