# IOleUndoUnit::OnNextAdd

## Description

Notifies the last undo unit in the collection that a new unit has been added.

## Return value

Implementations of this method always return S_OK. The **HRESULT** return type is used only for remotability.

## Remarks

An object can create an undo unit for an action and add it to the undo manager but can continue inserting data into it through private interfaces. When the undo unit receives a call to this method, it communicates back to the creating object that the context has changed. Then, the creating object stops inserting data into the undo unit.

The parent undo unit calls this method on its most recently added child undo unit to notify the child unit that the context has changed and a new undo unit has been added.

For example, this method is used for supporting fuzzy actions, like typing, which do not have a clear point of termination but instead are terminated only when something else happens.

This method may not always be called if the undo manager or an open parent unit chooses to discard the unit by calling [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) instead. Any connection which feeds data to the undo unit behind the scenes through private interfaces should not [IUnknown::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) the undo unit.

### Notes to Implementers

Note that parent units merely delegate this method to their most recently added child unit. A parent unit should terminate communication through any private interfaces when it is closed. A parent unit knows it is being closed when it receives S_FALSE from calling [IOleParentUndoUnit::Close](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleparentundounit-close).

## See also

[IOleParentUndoUnit::Close](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleparentundounit-close)

[IOleUndoUnit](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleundounit)