## Description

The Rename method assigns a new name to the script. It is the responsibility of the script implementation to save this name and return it upon any call to the GetName method. This is often called when a user interface chooses to Save As the script to a new name. Note that renaming the script may affect where the hosting application chooses to project the contents of the script.

## Parameters

### `scriptName`

The name being assigned to the script is passed here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

## See also

[IDataModelScript2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscript2)