# IOleInPlaceObject::ReactivateAndUndo

## Description

Reactivates a previously deactivated object, undoing the last state of the object.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_NOTUNDOABLE** | The undo state is not available. |
| **E_OUTOFMEMORY** | There is insufficient memory available for the operation. |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## Remarks

If the user chooses the **Undo** command before the undo state of the object is lost, the object's immediate container calls **IOleInPlaceObject::ReactivateAndUndo** to activate the user interface, carry out the undo operation, and return the object to the active state.

## See also

[IOleInPlaceObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplaceobject)