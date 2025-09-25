## Description

The **RtlEqualDeviceMemory** routine compares two blocks of device memory to determine whether the specified number of bytes are identical. This function is safe for use on device memory because it uses strict alignment requirements.

## Parameters

### `Source1` [in]

A pointer to a caller-allocated block of device memory to compare.

### `Source2` [in]

A pointer to a caller-allocated block of device memory that is compared to the block of memory to which **Source1** points.

### `Length` [in]

Specifies the number of bytes to be compared.

## Syntax

```cpp
BOOL RtlEqualDeviceMemory(
   [in] const void* Source1,
   [in] const void* Source2,
   [in] size_t      Length
);
```

## Return value

**RtlEqualDeviceMemory** returns TRUE if **Source1** and **Source2** are equivalent; otherwise, it returns FALSE.

## Remarks

**RtlEqualDeviceMemory** begins the comparison with byte zero of each block.

The **RtlEqualDeviceMemory** routine is designed for safe comparison of device memory regions where standard memory comparison functions might not be appropriate due to the special characteristics of device memory.

- The function uses strict alignment requirements to ensure proper handling of device memory that may have side effects or special access requirements.

Callers of **RtlEqualDeviceMemory** can be running at any IRQL if both blocks of memory are resident.

This function works on all versions of Windows, not just the latest. You need to consume the latest WDK to get the function declaration from the wdm.h header. You also need the library (volatileaccessk.lib) from the latest WDK. However, the resulting driver will run fine on older versions of Windows.

### Example

```cpp
UCHAR DeviceBuffer1[256];
UCHAR DeviceBuffer2[256];

// Read data from device memory into buffers
ReadFromDevice(DeviceBuffer1, sizeof(DeviceBuffer1));
ReadFromDevice(DeviceBuffer2, sizeof(DeviceBuffer2));

// Compare the device memory buffers
if (RtlEqualDeviceMemory(DeviceBuffer1, DeviceBuffer2, sizeof(DeviceBuffer1))) {
    DbgPrint("Device buffers are identical\n");
} else {
    DbgPrint("Device buffers are different\n");
}
```

## See also

[**RtlEqualMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlequalmemory)

[**RtlCompareDeviceMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcomparedevicememory)