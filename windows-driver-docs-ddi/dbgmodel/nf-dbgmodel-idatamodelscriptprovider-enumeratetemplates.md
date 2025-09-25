# IDataModelScriptProvider::EnumerateTemplates

## Description

The EnumerateTemplates method returns an enumerator which is capable of enumerating the variety of templates that are provided by the script provider. Template content is what the script provider wants to be "prefilled" into an edit window when creating a new script. If there are multiple different templates supported, those templates can be named (e.g.: "Imperative Script", "Extension Script") and the debugger application hosting the data model can choose how to present the "templates" to the user.

A script provider which has no template content may return E_NOTIMPL here.

## Parameters

### `enumerator`

An enumerator which enumerates all template content of the script provider must be returned here as a component implementing the [IDataModelScriptTemplateEnumerator](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscripttemplateenumerator) interface.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

## See also

[IDataModelScriptProvider interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptprovider)