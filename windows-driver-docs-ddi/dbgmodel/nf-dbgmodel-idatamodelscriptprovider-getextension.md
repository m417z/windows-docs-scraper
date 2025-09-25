# IDataModelScriptProvider::GetExtension

## Description

The GetExtension method returns the file extension for scripts managed by this provider (without the dot) as a string allocated via the SysAllocString method. The debugger application hosting the data model (with scripting support) will delegate opening of script files with this extension to the script provider. The caller is responsible for freeing the returned string via SysFreeString. Examples of strings which might be returned from this method are "js" or "NatVis".

No two script providers may return the same file extension (case insensitive). A provider which wishes to handle multiple file extensions must implement multiple [IDataModelScriptProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptprovider) interfaces and provide unique names and file extensions to the script manager via the implementation of these methods.

## Parameters

### `extension`

The file extension of script files which managed by this provider is returned here. The string is allocated via SysAllocString and the caller is responsible for freeing it via SysFreeString.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

## See also

[IDataModelScriptProvider interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptprovider)