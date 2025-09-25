# IDataModelScriptProvider::GetDefaultTemplateContent

## Description

The GetDefaultTemplateContent method returns an interface for the default template content of the provider. This is content that the script provider would like pre-populated in an edit window for a newly created script. If the script provider has no templates (or has no template content which is designated as the default content), the script provider may return E_NOTIMPL from this method.

## Parameters

### `templateContent`

The default template content for the script provider is returned here as a component implementing the [IDataModelScriptTemplate](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscripttemplate) interface.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

## See also

[IDataModelScriptProvider interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptprovider)