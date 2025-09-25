## Description

Retrieves the next action available for the object that implements the IActionEnumerator interface.

## Parameters

### `keyName`

Pointer which is set to the BSTR of the key name for the next action.

### `actionName`

Pointer which is set to the BSTR of the action's name.

### `actionDescription`

Pointer which is set to the BSTR describing the action.

### `actionIsDefault`

Pointer to boolean value indicating if the retrieved action is the default action.

### `actionMethod`

Pointer to a pointer to IModelObject interface method for the action, optional parameter, may be null if it's not provided.

### `metadta`

Pointer to a pointer to IKeyStore interface for the action's metadata, optional parameter, may be null if it's not provided.

## Return value

If the method succeeds, it returns S_OK. If there are no more actions to enumerate, it returns S_FALSE. Otherwise, it returns an HRESULT error code.

## Remarks

After resolving a single action, the action enumerator is incremented to the next available action. If there are no more actions to enumerate, the method will return S_FALSE.

## See also

[IActionEnumerator interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-iactionenumerator)