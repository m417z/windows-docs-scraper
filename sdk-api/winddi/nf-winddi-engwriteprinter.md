# EngWritePrinter function

## Description

The **EngWritePrinter** function allows printer graphics DLLs to send a data stream to printer hardware.

## Parameters

### `hPrinter` [in]

Caller-supplied handle to the printer. This should be the handle received as the [DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev) function's *hDriver* parameter value.

### `pBuf` [in]

Caller-supplied pointer to a buffer containing a byte stream to be sent to the printer.

### `cbBuf` [in]

Specifies the caller-supplied number of bytes contained in the buffer pointed to by *pBuf*.

### `pcWritten` [out]

Caller-supplied pointer to a DWORD location that receives the number of bytes actually written to the printer.

## Return value

If the operation succeeds, the function returns **TRUE**; otherwise it returns **FALSE**.

## Remarks

[Printer graphics DLLs](https://learn.microsoft.com/windows-hardware/drivers/print/printer-graphics-dll) call **EngWritePrinter** to send data streams (either control sequences or image data) to the print spooler, which in turn sends the data to the printer hardware by calling the appropriate [print monitor](https://learn.microsoft.com/windows-hardware/drivers/). The function returns after the spooler receives the data.

The buffer pointed to by *pBuf* cannot be in user memory; that is, *pBuf* cannot point to memory allocated by [EngCreateBitmap](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatebitmap) with the BMF_USERMEM flag set or by [EngAllocUserMem](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engallocusermem).

For additional information about calling **EngWritePrinter**, see [Rendering a Print Job](https://learn.microsoft.com/windows-hardware/drivers/print/rendering-a-print-job).

## See also

[DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev)

[EngAllocUserMem](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engallocusermem)

[EngCreateBitmap](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatebitmap)