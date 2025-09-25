# IDataModelScriptHostContext::NotifyScriptChange

## Description

It is required that a script provider notify the debug host upon certain operations occurring with a method call to the NotifyScriptChange method on the associated context. Such operations are defined as members of the ScriptChangeKind enumeration which is defined as follows:

Enumerant | Description
|-------|--------|
ScriptRename | Indicates that the name of the script has changed. This notification should be made during a Rename call on the [IDataModelScript](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscript). The host may then query back the name of the script via a GetName method. The placement of the context namespace (as returned by GetNamespaceObject) may completely change as a result of this notification.

## Parameters

### `script`

The script for which the notification is occurring.

### `changeKind`

The nature of the notification.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

## See also

[IDataModelScriptHostContext interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscripthostcontext)