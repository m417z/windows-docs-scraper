# IDataModelScriptManager::UnregisterScriptProvider

## Description

The UnregisterScriptProvider method undoes a call to the RegisterScriptProvider method. The name and file extension given by the inpassed script provider will no longer be associated with it. It is important to note that there may be a significant number of outstanding COM references to the script provider even after unregistration. This method only prevents the loading/creation of scripts of the type that the given script provider manages. If a script loaded by that provider is still loaded or has manipulated the object model of the debugger (or data model), those manipulations may still have references back into the script. There may be data models, methods, or objects which directly reference constructs in the script. A script provider must be prepared to deal with that.

## Parameters

### `provider`

The script provider being unregistered from the script manager. Scripts of the given type and file extension will no longer be able to be loaded/created.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

## See also

[IDataModelScriptManager interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptmanager)