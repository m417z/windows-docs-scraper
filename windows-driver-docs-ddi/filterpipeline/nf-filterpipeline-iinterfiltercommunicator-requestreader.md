# IInterFilterCommunicator::RequestReader

## Description

The **RequestReader** method retrieves the reader interface for an **IInterFilterCommunicator** object.

## Parameters

### `ppIReader` [out]

A variable that receives the reader interface object when **RequestReader** retrieves.

## Return value

**RequestReader** returns an **HRESULT** value.

## Remarks

The **IInterFilterCommunicator** object is passed to each filter in the [IPrintPipelineFilter::InitializeFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nf-filterpipeline-iprintpipelinefilter-initializefilter) method. The filter uses the **RequestReader** method to get the reader interface for the object. The universally unique identifier (UUID) for the object is declared in the [filter pipeline configuration file](https://learn.microsoft.com/windows-hardware/drivers/print/filter-pipeline-configuration-file). The filter uses the **IInterFilterCommunicator** interface to receive input data.

## See also

[IInterFilterCommunicator](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nn-filterpipeline-iinterfiltercommunicator)

[IPrintPipelineFilter::InitializeFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nf-filterpipeline-iprintpipelinefilter-initializefilter)