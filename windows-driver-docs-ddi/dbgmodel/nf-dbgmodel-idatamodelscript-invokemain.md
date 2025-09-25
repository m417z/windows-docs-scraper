# IDataModelScript::InvokeMain

## Description

If the script has a "main function" which is intended to execute from a UI invocation, it indicates such via a true return from the IsInvocable method. The user interface can then call the InvokeMain method to actually "invoke" the script. Note that this is distinct from *Execute* which runs all root code and bridges the script to the namespace of the underlying host.

This method may fail with E_NOTIMPL if the script does not contain a "main function" or the provider does not define such.

Note that an application which hosts the data model may load and execute a script once but call the InvokeMain method an arbitrary number of times without an intervening Execute call. It is expected that this would preserve the "script context", keep the script loaded, and just call a method within the script multiple times.

If there are errors or other events which occur during execution of the script, such (and their location within the script) can be passed across the communication channel between the [IDataModelScript](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscript) and the inpassed [IDataModelScriptClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptclient).

## Parameters

### `client`

An interface to the client which is requesting the main function be called. If there are errors or other events which occur during execution of the main function, the script can pass this information and its location within the script back to the client via method calls on this interface.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

## See also

[IDataModelScript interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscript)