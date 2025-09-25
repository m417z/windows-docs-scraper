# WDF_ALIGN_SIZE_DOWN function

## Description

[Applies to KMDF and UMDF]

The **WDF_ALIGN_SIZE_DOWN** function returns the next-lower buffer size that is aligned to a specified alignment offset.

## Parameters

### `Length` [in]

The length, in bytes, of a [memory buffer](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-memory-buffers).

### `AlignTo` [in]

The alignment offset, in bytes. This value must be a power of 2, such as 2, 4, 8, 16, and so on.

## Return value

WDF_ALIGN_SIZE_DOWN returns the aligned buffer size, in bytes.

## Remarks

Drivers can use [WDF_ALIGN_SIZE_UP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcore/nf-wdfcore-wdf_align_size_up) or **WDF_ALIGN_SIZE_DOWN** to calculate a buffer size that is aligned to a specified alignment offset. This calculation is useful if your driver must allocate multiple contiguous buffers, if each buffer must begin at an address alignment boundary.

#### Examples

The following code example receives a buffer size and returns the size (either the current size or the next-lower size) that aligns to a DWORD address boundary.

```cpp
bufferSizeAligned = WDF_ALIGN_SIZE_DOWN(bufferSize,
                                        sizeof(DWORD));
```

## See also

[WDF_ALIGN_SIZE_UP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcore/nf-wdfcore-wdf_align_size_up)