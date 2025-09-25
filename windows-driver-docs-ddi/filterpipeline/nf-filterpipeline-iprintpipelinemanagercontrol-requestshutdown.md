# IPrintPipelineManagerControl::RequestShutdown

## Description

The `RequestShutdown` method requests that a pipeline be shut down.

## Parameters

### `hrReason` [in]

An **HRESULT** value that indicates the reason for the lack of memory.

### `pReason` [in]

Not used. Set to **NULL**.

## Return value

`RequestShutdown` returns an **HRESULT** value.

## Remarks

A filter that uses the [IXpsDocumentConsumer](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nn-filterpipeline-ixpsdocumentconsumer) interface must call `IPrintPipelineManagerControl::RequestShutdown` before it calls [IXpsDocumentConsumer::CloseSender](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nf-filterpipeline-ixpsdocumentconsumer-closesender) to shut down the pipeline. Calling **IXpsDocumentConsumer::CloseSender** first can produce an invalid XPS document and cause an error.