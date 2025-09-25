## Description

The GetName method returns the name of the script as an allocated string via the SysAllocString function. If the script does not yet have a name, the method should return a null BSTR. It should not fail in this circumstance. If the script is explicitly renamed via a call to the Rename method, the GetName method should return the newly assigned name.

## Parameters

### `scriptName`

The name of the script should be returned here as a string allocated via SysAllocString. The caller is responsible for freeing this string via the SysFreeString method. Note that if the script is unnamed, the method should return a null BSTR as the output. It should still succeed in this case.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

## See also

[IDataModelScript2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscript2)