# IInterFilterCommunicator::RequestWriter

## Description

The **RequestWriter** method retrieves the writer interface for an **IInterFilterCommunicator** object.

## Parameters

### `ppIWriter` [out]

A variable that receives the writer interface object that **RequestWriter** retrieves.

## Return value

**RequestWriter** returns an **HRESULT** value.

## Remarks

The **IInterFilterCommunicator** object is passed to each filter in the [IPrintPipelineFilter::InitializeFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nf-filterpipeline-iprintpipelinefilter-initializefilter) method. The filter uses the **RequestWriter** method to get the writer interface for the object. The universally unique identifier (UUID) for the object is declared in the [filter pipeline configuration file](https://learn.microsoft.com/windows-hardware/drivers/print/filter-pipeline-configuration-file).

## See also

[IInterFilterCommunicator](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nn-filterpipeline-iinterfiltercommunicator)

[IPrintPipelineFilter::InitializeFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nf-filterpipeline-iprintpipelinefilter-initializefilter)