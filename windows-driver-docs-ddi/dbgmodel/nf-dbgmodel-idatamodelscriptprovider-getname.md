# IDataModelScriptProvider::GetName

## Description

The GetName method returns the name of the type of (or language of) scripts which the provider manages as a string allocated via the SysAllocString method. The caller is responsible for freeing the returned string via SysFreeString. Examples of strings which might be returned from this method are "JavaScript" or "NatVis". The returned string is likely to appear in the user interface of the debugger application which is hosting the data model.

No two script providers may return the same name (case insensitive).

## Parameters

### `name`

The name of the type of (or language of) scripts managed via the provider. The string is allocated via SysAllocString and the caller is responsible for freeing it via SysFreeString.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

## See also

[IDataModelScriptProvider interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptprovider)