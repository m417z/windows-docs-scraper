## Description

The **OEMMEMORYUSAGE** structure is used as an input parameter to a rendering plug-in's [IPrintOemUni::MemoryUsage](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-memoryusage) method.

## Members

### `dwFixedMemoryUsage`

Specifies the amount, in bytes, of fixed-sized memory required by the **IPrintOemUni::MemoryUsage** method. Supplied by the rendering plug-in.

### `dwPercentMemoryUsage`

Specifies the amount of variably-sized memory required by the **IPrintOemUni::MemoryUsage** method, expressed as a percentage of the size of the source bitmap received by [IPrintOemUni::ImageProcessing](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-imageprocessing). Supplied by the rendering plug-in.

### `dwMaxBandSize`

Specifies the maximum size, in bytes, that can be used for source bitmaps. This is the value that Unidrv uses to subtract from when applying the plug-in supplied values contained in **dwFixedMemoryUsage** and **dwPercentMemoryUsage**. Supplied by Unidrv.

## Remarks

The Unidrv driver uses the values in the **dwFixedMemoryUsage** and **dwPercentMemoryUsage** members of this structure to determine the optimum size for a GDI drawing surface, taking into account any memory requirements of a rendering plug-in's **IPrintOemUni::ImageProcessing** method. For more information about how these members are used, see the Remarks section in [IPrintOemUni::MemoryUsage](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-memoryusage).

## See also

[IPrintOemUni::ImageProcessing](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-imageprocessing)

[IPrintOemUni::MemoryUsage](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-memoryusage)