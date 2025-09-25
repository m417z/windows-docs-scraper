# IPrintPipelineFilter::ShutdownOperation

## Description

The Pipeline Manager uses the `ShutdownOperation` method to shut down a filter if the print job is canceled or an error occurs.

## Return value

`ShutdownOperation` returns an **HRESULT** value.

## Remarks

The `ShutdownOperation` method is called by the pipeline manager if the job is canceled or an error occurs. Filters do not have to block this call until they completely finish using any resources. You should set up an internal state to indicate when filters need to cancel a job. Filters must call [IPrintPipelineManagerControl::FilterFinished](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nf-filterpipeline-iprintpipelinemanagercontrol-filterfinished) when the filters are finished, which can be later.

## See also

[IPrintPipelineFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nn-filterpipeline-iprintpipelinefilter)

[IPrintPipelineManagerControl::FilterFinished](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nf-filterpipeline-iprintpipelinemanagercontrol-filterfinished)