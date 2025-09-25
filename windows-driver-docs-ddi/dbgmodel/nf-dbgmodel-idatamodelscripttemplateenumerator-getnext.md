# IDataModelScriptTemplateEnumerator::GetNext

## Description

The GetNext method moves the enumerator to the next template and returns it. At the end of enumeration, the enumerator returns E_BOUNDS. Once the E_BOUNDS marker has been hit, the enumerator will continue to produce E_BOUNDS errors indefinitely until a Reset call is made.

## Parameters

### `templateContent`

The next template in enumeration order is returned here as a component implementing the [IDataModelScriptTemplate](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscripttemplate) interface.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

## See also

[IDataModelScriptTemplateEnumerator interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscripttemplateenumerator)