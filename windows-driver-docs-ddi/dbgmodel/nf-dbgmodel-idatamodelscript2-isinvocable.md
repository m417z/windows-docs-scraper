## Description

The IsInvocable method returns whether or not the script is invocable -- that is, whether it has a "main function" as defined by its language or provider. Such a "main function" is conceptually something that the script author would want called if an imaginary "Execute Script" button were pressed in a user interface.

This method is only legal to call after a successful call to the Execute method. Calling this method when a script has not yet executed (or has unlinked) is illegal and should produce an error.

## Parameters

### `isInvocable`

An indication of whether the script is invocable is returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

## See also

[IDataModelScript2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscript2)