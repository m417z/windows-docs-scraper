## Description

The **Continue** method tells the caller (the XPS rasterization service) whether to continue rasterizing the current XPS fixed page.

## Return value

**Continue** returns S_OK to enable rasterization to continue. Otherwise, the method returns an error code to abort rasterization. Possible error return values include:

| Return code | Description |
|---|---|
| **HRESULT_FROM_WIN32(ERROR_PRINT_CANCELLED)** | The current print job has been canceled. |

## Remarks

This method is implemented by an XPSDrv filter. During a page rasterization operation, the [XPS rasterization service](https://learn.microsoft.com/windows-hardware/drivers/print/using-the-xps-rasterization-service) periodically calls this method to determine whether to continue the operation.

To begin a page rasterization operation, the XPSDrv filter calls the [IXpsRasterizer::RasterizeRect](https://learn.microsoft.com/windows-hardware/drivers/ddi/xpsrassvc/nf-xpsrassvc-ixpsrasterizer-rasterizerect) method. With this call, the filter can, as an option, supply a pointer to an [IXpsRasterizerNotificationCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/xpsrassvc/nn-xpsrassvc-ixpsrasterizernotificationcallback) interface instance. If supplied, **RasterizeRect** will periodically call the **Continue** method on this interface during the processing of the **RasterizeRect** call. If **Continue** returns a success code, **RasterizeRect** continues with the rasterization operation in progress. If **Continue** returns an error code, **RasterizeRect** aborts the rasterization operation and returns immediately.

If the user cancels a print job or if an error occurs during the processing of a print job, the pipeline manager calls the XPSDrv filter's [IPrintPipelineFilter::ShutdownOperation](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nf-filterpipeline-iprintpipelinefilter-shutdownoperation) method to shut down the filter. Typically, the filter can complete the shutdown in a more timely way if it implements the **Continue** method and supplies an **IXpsRasterizerNotificationCallback** pointer to **RasterizeRect**.

For an example implementation of the **Continue** method, see the XpsRasFilter sample in the WDK. This sample is located in the Src\Print\Xpsrasfilter folder in your WDK installation.

## See also

[IPrintPipelineFilter::ShutdownOperation](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nf-filterpipeline-iprintpipelinefilter-shutdownoperation)

[IXpsRasterizer::RasterizeRect](https://learn.microsoft.com/windows-hardware/drivers/ddi/xpsrassvc/nf-xpsrassvc-ixpsrasterizer-rasterizerect)

[IXpsRasterizerNotificationCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/xpsrassvc/nn-xpsrassvc-ixpsrasterizernotificationcallback)