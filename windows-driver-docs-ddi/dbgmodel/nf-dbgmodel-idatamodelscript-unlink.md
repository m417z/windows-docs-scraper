# IDataModelScript::Unlink

## Description

The Unlink method undoes the Execute operation. Any object model manipulations or extensibility points established during the execution of the script are undone. After an Unlink operation, the script may be re-executed via a call to Execute or it may be released.

It is expected that this is called, for instance, upon the closing of a script window by a user interface client.

After the Unlink call, the state of the script should be the same as if the following sequence of operations were performed on a new script:

- Create a new script

- Populate the new script with the content of the script which was unlinked

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

## See also

[IDataModelScript interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscript)