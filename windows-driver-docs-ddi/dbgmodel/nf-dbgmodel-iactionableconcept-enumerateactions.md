## Description

Returns an enumerator to all actions on any object implementing the IActionableConcept interface.

## Parameters

### `contextObject`

The pointer to the context object where actions will be enumerated.

### `actionEnumerator`

The pointer to an IActionEnumerator object. This object will point to the first action of the enumeration after the method is called.

## Return value

This method returns a **IActionEnumerator** object that represents the actions on this object.

## Remarks

The returned **IActionEnumerator** object can be used to enumerate all associated actions with the given context object. The enumeration starts on the action which the **actionEnumerator** pointer is set to after the function is called.

## See also

[IActionableConcept interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-iactionableconcept)