# VideoPortAllocatePool function

## Description

The **VideoPortAllocatePool** function allocates a block of pool memory, inserting a caller-supplied tag at the beginning of the memory.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `PoolType` [in]

Specifies the type of memory pool to allocate. This parameter can be set to one of the following:

|Value|Meaning|
|--- |--- |
|VpNonPagedPool|The pool is from nonpaged memory.|
|VpPagedPool|The pool is from paged memory.|
|VpNonPagedPoolCacheAligned|The pool is from cache-aligned, nonpaged memory.|
|VpPagedPoolCacheAligned|The pool is from cache-aligned, paged memory.|

### `NumberOfBytes` [in]

Specifies the number of bytes of memory to allocate.

### `Tag` [in]

Specifies a four-byte allocation tag, consisting of up to four ASCII characters, that uniquely identifies the driver that is allocating the memory. The tag string is delimited with single quotes.

## Return value

On successful allocation of the memory pool, **VideoPortAllocatePool** returns the address of the allocated memory pool. Otherwise, this function returns **NULL**.

## Remarks

**VideoPortAllocatePool** is intended to replace **VideoPortAllocateBuffer**, which is obsolete.

The *Tag* string should be specified in byte-reversed order. It is recommended that the first letter in the string (before it is reversed) be 'D' to denote a display driver; the other three bytes should be indicative of the driver name. For example, the *Tag* string 'zyxD' appears as 'Dxyz' if pool is dumped. The tag appears in any crash dump of the system that occurs.

Callers of **VideoPortAllocatePool** can be running at IRQL = DISPATCH_LEVEL only if the requested *PoolType* is one of the **VpNonPaged***Xxx* types. Otherwise, callers must be running at IRQL < DISPATCH_LEVEL.

## See also

[VideoPortFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportfreepool)