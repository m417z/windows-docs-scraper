# IPrintOemUni::Compression

## Description

The `IPrintOemUni::Compression` method can be used with Unidrv-supported printers to provide a customized bitmap compression method.

## Parameters

### `pdevobj`

Caller-supplied pointer to a [DEVOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_devobj) structure.

### `pInBuf`

Caller-supplied pointer to input scan line data.

### `pOutBuf`

Caller-supplied pointer to an output buffer to receive compressed scan line data.

### `dwInLen`

Caller-supplied length of the input data.

### `dwOutLen`

Caller-supplied length of the output buffer.

### `piResult` [out]

Receives a method-supplied result value. If the operation succeeds, this value should be the number of compressed bytes, which must not be larger than the value received for *dwOutLen*. If an error occurs, or if the method cannot compress, the result value should be -1.

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed |
| **E_NOTIMPL** | The method is not implemented. |

## Remarks

The `IPrintOemUni::Compression` method is used by rendering plug-ins to compress scan line data before it is sent to the print spooler. The method's purpose is to provide support for printer-specific compression methods that are not supported by Unidrv.

If the `IPrintOemUni::Compression` method is defined, and if the printer's [GPD](https://learn.microsoft.com/windows-hardware/drivers/) file contains a CmdEnableOEMComp command entry, Unidrv calls the method each time a scan line is ready to be sent to the print spooler. (For information about the CmdEnableOEMComp command, see [Raster Data Compression Commands](https://learn.microsoft.com/windows-hardware/drivers/print/raster-data-compression-commands).)

The *pInBuf* and *dwInLen* parameter values describe a buffer containing a scan line of image data to be compressed. The *pOutBuf* and *dwOutLen* parameter values describe the buffer into which the `IPrintOemUni::Compression` method should place the compressed data.

Before Unidrv sends a scan line to the print spooler, it tries every enabled compression method to determine which one creates the smallest data stream. After it determines the best compression algorithm (by compressing the data using each method), it spools the printer command that enables the printer to accept the best compressed format, then sends the compressed data to the printer.

Therefore, the `IPrintOemUni::Compression` method is called for every scan line, whether the compressed data returned by the method is actually used or not. When the method is called, *dwOutLen* contains the length returned by the best compression method Unidrv has tried up to then. (If no other methods have been tried, *dwOutLen* contains the uncompressed length.) If the algorithm cannot produce a compressed scan line that is equal to or shorter than *dwOutLen* bytes, it should return -1 in the location specified by *piResult*.

If, after Unidrv tries all enabled compression methods, the compressed data returned by `IPrintOemUni::Compression` has the smallest length, Unidrv sends the buffer to the print spooler, preceded by the command specified by the CmdEnableOEMComp command entry.

If possible, the method's compression algorithm should use the received *dwOutLen* value to determine whether it can stop the algorithm before completion, to save time if another compression method has already created a better result.

The `IPrintOemUni::Compression` method is optional. If a rendering plug-in implements this method, the plug-in's [IPrintOemUni::GetImplementedMethod](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemuni-getimplementedmethod) method must return S_OK when it receives "Compression" as input.