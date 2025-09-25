# DrvPopulateFilterServices function

## Description

The **DrvPopulateFilterServices** function is called by the XPSDrv filter pipeline manager to allow the service provider to instantiate filter service objects in the filter pipeline property bag specified by the *pPropertyBag* parameter.

## Parameters

### `pPropertyBag` [in]

Pointer to a print pipeline property bag.

## Return value

This function returns an HRESULT value.

## Remarks

The [XPSDrv printer driver](https://learn.microsoft.com/windows-hardware/drivers/print/xpsdrv-printer-driver) can specify filter service provider module using the <*FilterServiceProvider*> or <*OptionalFilterServiceProvider*> element in the [filter pipeline configuration file](https://learn.microsoft.com/windows-hardware/drivers/print/filter-pipeline-configuration-file). The service provider module must export the **DrvPopulateFilterServices** function.

## See also

[Filter pipeline configuration file](https://learn.microsoft.com/windows-hardware/drivers/print/filter-pipeline-configuration-file)

[IPrintPipelinePropertyBag](https://learn.microsoft.com/windows-hardware/drivers/ddi/filterpipeline/nn-filterpipeline-iprintpipelinepropertybag)

[XPSDrv printer driver](https://learn.microsoft.com/windows-hardware/drivers/print/xpsdrv-printer-driver)