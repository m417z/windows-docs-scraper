# IDataModelScriptTemplate::GetDescription

## Description

The GetDescription method returns a description of the template. Such description would be presented to the user in more descriptive interfaces to help the user understand what the template is designed to do. The template may return E_NOTIMPL from this method if it does not have a description.

## Parameters

### `templateDescription`

The description of the template is returned here as a string allocated via the SysAllocString function. The caller is responsible for freeing this string with SysFreeString.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

## See also

[IDataModelScriptTemplate interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscripttemplate)