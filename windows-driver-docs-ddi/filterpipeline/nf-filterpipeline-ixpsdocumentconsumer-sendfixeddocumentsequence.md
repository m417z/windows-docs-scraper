# IXpsDocumentConsumer::SendFixedDocumentSequence

## Description

The **SendFixedDocumentSequence** method sends a fixed document sequence to the pipeline.

## Parameters

### `pIFixedDocumentSequence` [in]

A pointer to an XPS fixed document sequence object.

## Return value

`SendFixedDocumentSequence` returns an **HRESULT** value.

## Remarks

Only one [IFixedDocumentSequence](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nn-filterpipeline-ifixeddocumentsequence) interface can be sent. The `SendFixedDocumentSequence` method will fail if a filter submits more than one such interface for the same print job.