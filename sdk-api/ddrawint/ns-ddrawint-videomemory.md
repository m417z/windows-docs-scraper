# VIDEOMEMORY structure

## Description

The VIDEOMEMORY structure allows the driver to manage its display memory into heaps.

## Members

### `dwFlags`

Specifies a set of flags that describe this particular section of display memory. This member can be a bitwise OR of any of the following values:

| Flag | Meaning |
| --- | --- |
| VIDMEM_ISLINEAR | The display memory is a contiguous block of memory. |
| VIDMEM_ISRECTANGULAR | The display memory is rectangular. |
| VIDMEM_ISHEAP | This flag is reserved for system use and should be ignored by the driver. |
| VIDMEM_ISNONLOCAL | The heap resides in nonlocal (AGP) memory. |
| VIDMEM_ISWC | The driver has enabled write-combining on the display memory in this heap. Write-combining is a special caching mode in Pentium Pro-class processors that batches writes to the same cache line so they can be transferred in a single bus clock. Write-combining does not preserve ordering of the writes, a tradeoff that is usually acceptable for frame buffers. Refer to Intel documentation for more information about write-combining. This flag cannot be used unless the VIDMEM_ISNONLOCAL flag is also set. |
| VIDMEM_HEAPDISABLED | The Microsoft DirectDraw runtime uses this flag to turn off a heap when the heap's initialization has failed. This most likely occurs with an AGP heap. The driver should not set this bit. |

### `fpStart`

Points to the starting address of a memory range in the heap.

### `fpEnd`

Points to the ending address of a memory range if the heap is linear. This address is inclusive, that is, it specifies the last valid address in the range. Thus, the number of bytes specified by **fpStart** and **fpEnd** is (**fpEnd** - **fpStart** + 1).

### `dwWidth`

Specifies the width in bytes of the section of memory pointed to by **fpStart**. This member should only be used to describe rectangular memory regions.

### `ddsCapsAlt`

Specifies a DDSCAPS structure in which the driver returns the capabilities for which this chunk of memory cannot be used when no other memory is found on the first pass.

### `ddsCaps`

Specifies a [DDSCAPS](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550286(v=vs.85)) structure in which the driver returns the capabilities for which this section of memory cannot be used.

### `lpHeap`

Reserved for system use and should be ignored by the driver.

### `dwHeight`

Specifies the height of the chunk of memory to which **fpStart** points. This member should only be used to describe rectangular memory regions.

## Remarks

On Microsoft Windows 2000 and later the data structure is called VIDEOMEMORY and on Windows 98/Me the data structure is called VIDMEM.

GDI allocates and passes an array of VIDEOMEMORY structures to the second call of the driver's [DrvGetDirectDrawInfo](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvgetdirectdrawinfo) function. The driver should fill in the appropriate members of each structure to describe each particular section of memory. The list provides a complete description of the driver's offscreen memory.

DirectDraw scans through to allocate its surfaces in the order the display memory heaps are listed. Heaps are managed in an array of VIDEOMEMORY structures. The memory allocated first will be the memory that is accessed first. The VIDEOMEMORY structure sets up certain starting points, and determines the amount of memory on the surface and what cannot be done with the surface. DirectDraw manages it by suballocating and deallocating memory, that is, creating and destroying surfaces under each heap's jurisdiction. Physical limits determine how to set up these attributes.

DirectDraw's heap manager makes two passes through the VIDEOMEMORY structures. The **ddsCaps** member indicates to DirectDraw what the memory in the heap cannot be used for on the first pass. For example, if the heap was just big enough for a back buffer, sprites could be excluded from being allocated on the first pass by setting the DSCAPS_OFFSCREENPLAIN flag in the [DDSCAPS](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550286(v=vs.85)) structure. That way, other surfaces would fill up with sprites, while preserving the back buffer for page flipping. The **ddsCapsAlt** member could be set to allow sprites on the second pass (by removing the DSCAPS_OFFSCREENPLAIN flag). This allows heaps to be used preferentially for their highest and best use, without ruling out alternative uses. By choosing the order of allocation carefully (for example, by listing the back buffer last), the need to sort by **ddsCaps** and **ddsCapsAlt** can sometimes be eliminated.

## See also

[DDSCAPS](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550286(v=vs.85))

[DrvGetDirectDrawInfo](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvgetdirectdrawinfo)