# IDataModelScriptProviderEnumerator::GetNext

## Description

The GetNext method will move the enumerator forward one element and return the script provider which is at that element. When the enumerator hits the end of enumeration, E_BOUNDS will be returned. Calling the GetNext method after receiving this error will continue to return E_BOUNDS indefinitely.

## Parameters

### `provider`

The next script provider registered with the script manager will be returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

## See also

[IDataModelScriptProviderEnumerator interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptproviderenumerator)