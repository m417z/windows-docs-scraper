# IDataModelScriptTemplate::GetName

## Description

The GetName method returns a name of the template. This may fail with E_NOTIMPL if the template does not have a name. The single default template (if such exists) is not required to have a name. All other templates are. These names may be presented in a user interface as part of a menu to select which template is to be created.

## Parameters

### `templateName`

The name of the template is returned here as a string allocated via the SysAllocString function. The caller is responsible for freeing this string with SysFreeString.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

## See also

[IDataModelScriptTemplate interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscripttemplate)