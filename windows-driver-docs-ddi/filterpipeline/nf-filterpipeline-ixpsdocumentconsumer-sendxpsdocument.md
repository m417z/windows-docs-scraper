# IXpsDocumentConsumer::SendXpsDocument

## Description

The `SendXpsDocument` method sends an XPS document to the pipeline.

## Parameters

### `pIXpsDocument` [in]

A pointer to the XPS document object to send.

## Return value

`SendXpsDocument` returns an **HRESULT** value.

## Remarks

The [IXpsDocument](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nn-filterpipeline-ixpsdocument) interface is the root for a tree view of an XPS document. The tree also contains one fixed document sequence and any number of fixed documents and fixed pages.

Only one XpsDocument interface can be sent. The `SendXpsDocument` method will fail if a filter submits more than one XpsDocument interface for the same print job.

## See also

[IXpsDocument](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nn-filterpipeline-ixpsdocument)

[IXpsDocumentConsumer](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nn-filterpipeline-ixpsdocumentconsumer)