## Description

The **InitializeFilter** method initializes a filter.

## Parameters

### `pINegotiation` [in]

A pointer to the [IInterFilterCommunicator](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nn-filterpipeline-iinterfiltercommunicator) interface.

### `pIPropertyBag` [in]

A pointer to the [IPrintPipelinePropertyBag](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nn-filterpipeline-iprintpipelinepropertybag) interface.

### `pIPipelineControl` [in]

A pointer to the [IPrintPipelineManagerControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nn-filterpipeline-iprintpipelinemanagercontrol) interface.

## Return value

**InitializeFilter** returns an **HRESULT** value. The method should return a value other than **S_OK** or **S_FALSE** if the necessary operations are not performed inside **InitializeFilter**.

## Remarks

When the **InitializeFilter** method is called, the filters should:

- Get, add, or delete properties from the property bag.

- Get the read and write interfaces.

## See also

[IInterFilterCommunicator](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nn-filterpipeline-iinterfiltercommunicator)

[IPrintPipelineFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nn-filterpipeline-iprintpipelinefilter)

[IPrintPipelineManagerControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nn-filterpipeline-iprintpipelinemanagercontrol)

[IPrintPipelinePropertyBag](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nn-filterpipeline-iprintpipelinepropertybag)