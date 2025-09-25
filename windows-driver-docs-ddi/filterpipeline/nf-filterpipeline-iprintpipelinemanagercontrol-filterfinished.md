# IPrintPipelineManagerControl::FilterFinished

## Description

The `FilterFinished` method reports that a filter is finished processing.

## Return value

`FilterFinished` returns an **HRESULT**.

## Remarks

The filter does not need to call the `FilterFinished` method. The filter pipeline assumes the filter has finished when the [IPrintPipelineFilter::StartOperation](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nf-filterpipeline-iprintpipelinefilter-startoperation) method returns. `FilterFinished` is provided for compatibility and, when called, it does nothing but returns.