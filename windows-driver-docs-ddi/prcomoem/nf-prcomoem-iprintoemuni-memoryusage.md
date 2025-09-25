# IPrintOemUni::MemoryUsage

## Description

The `IPrintOemUni::MemoryUsage` method can be used with Unidrv-supported printers to specify the amount of memory required for use by a rendering plug-in's [IPrintOemUni::ImageProcessing](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-imageprocessing) method.

## Parameters

### `pdevobj`

Caller-supplied pointer to a [DEVOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_devobj) structure.

### `pMemoryUsage`

Caller-supplied pointer to an [OEMMEMORYUSAGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-oemmemoryusage) structure.

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed. |
| **E_NOTIMPL** | The method is not implemented. |

## Remarks

The `IPrintOemUni::MemoryUsage` method's purpose is to help the Unidrv driver determine the optimum size for the GDI drawing surface, based on the memory requirements of the [IPrintOemUni::ImageProcessing](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-imageprocessing) method. Implementation of the `IPrintOemUni::MemoryUsage` method is optional.

The `IPrintOemUni::MemoryUsage` method should return two values, as follows:

* The amount of permanently-allocated, fixed-sized memory that the **IPrintOemUni::ImageProcessing** method needs to allocate.

  This value is returned in the **dwFixedMemoryUsage** member of the [OEMMEMORYUSAGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-oemmemoryusage) structure.
* The amount of memory required to hold a bitmap after the **IPrintOemUni::ImageProcessing** method has finished processing it.

  The rendering plug-in either returns this processed bitmap to Unidrv, or spools it. The amount of memory required to store the processed bitmap is returned in the **dwPercentMemoryUsage** member of the OEMMEMORYUSAGE structure, and is expressed as a percentage of the source bitmap's size.

The value returned in the **dwPercentMemoryUsage** member should include, in addition to the processed bitmap's size, the amount of any additional memory allocations that are dependent on the size of the source bitmap.

The **dwMaxBandSize** member of the OEMMEMORYUSAGE structure is supplied by Unidrv and specifies the default maximum band size.

Before the Unidrv driver creates a drawing surface, it requests GDI to determine the optimum size for image banding bitmaps, based on available system memory. This optimum memory space must be shared, for each banding bitmap, between a source bitmap that is passed to the **IPrintOemUni::ImageProcessing** method and a (typically smaller) processed bitmap that the method either returns or outputs. Unidrv calls the rendering plug-in's `IPrintOemUni::MemoryUsage` method, if it exists, and uses the result to calculate how best to divide the optimum memory space.

For example, suppose GDI reports that the optimum amount of memory to use for drawing is 6 megabytes (contained in the OEMMEMORYUSAGE structure's **dwMaxBandSize** member), while the rendering plug-in's `IPrintOemUni::MemoryUsage` method returns values of zero for **dwFixedMemoryUsage** and 50 for **dwPercentMemoryUsage**. The value of 50 means that the **IPrintOemUni::ImageProcessing** method's output bitmaps will be 50 percent smaller than the source bitmaps. Therefore, Unidrv will allocate a source bitmap size of 4 megabytes, thus causing output bitmaps to be 2 megabytes.

If an `IPrintOemUni::MemoryUsage` method is not provided, Unidrv allocates all the optimum available space to the source bitmap. This is acceptable if the **IPrintOemUni::ImageProcessing** method returns the processed bitmap in the memory space allocated for the source bitmap. However, if a rendering plug-in's **IPrintOemUni::ImageProcessing** method does allocate space for a destination bitmap but does not provide an `IPrintOemUni::MemoryUsage` method, the result is that more memory will be allocated for bitmaps than the optimum available size, potentially causing performance degradation.

The `IPrintOemUni::MemoryUsage` method is optional. If a rendering plug-in implements this method, the plug-in's [IPrintOemUni::GetImplementedMethod](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-getimplementedmethod) method must return S_OK when it receives "MemoryUsage" as input.

## See also

[DEVOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_devobj)

[IPrintOemUni](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintoemuni)

[IPrintOemUni::ImageProcessing](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-imageprocessing)

[OEMMEMORYUSAGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-oemmemoryusage)