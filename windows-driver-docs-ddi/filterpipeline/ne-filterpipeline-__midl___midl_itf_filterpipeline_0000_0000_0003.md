# __MIDL___MIDL_itf_filterpipeline_0000_0000_0003 enumeration

## Description

The EXpsJobConsumption enumeration describes job consumption updates.

## Constants

### `XpsJob_DocumentSequenceAdded`

A document sequence is added to the job.

### `XpsJob_FixedDocumentAdded`

A fixed document is added to the job.

### `XpsJob_FixedPageAdded`

A fixed page is added to the job.

## Remarks

A rendering filter uses the [IPrintPipelineProgressReport](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nn-filterpipeline-iprintpipelineprogressreport) interface to send updates to the pipeline.

Rendering filters convert XPS to the page description language (PDL).

A pipeline does not necessarily need one of the EXpsJobConsumption enumeration values.