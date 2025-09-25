# OleCreateMenuDescriptor function

## Description

Creates and returns an OLE menu descriptor (that is, an OLE-provided data structure that describes the menus) for OLE to use when dispatching menu messages and commands.

## Parameters

### `hmenuCombined` [in]

Handle to the combined menu created by the object.

### `lpMenuWidths` [in]

Pointer to an array of six **LONG** values giving the number of menus in each group.

## Return value

Returns the handle to the descriptor, or **NULL** if insufficient memory is available.

## Remarks

The **OleCreateMenuDescriptor** function can be called by the object to create a descriptor for the composite menu. OLE then uses this descriptor to dispatch menu messages and commands. To free the shared menu descriptor when it is no longer needed, the container should call the companion helper function, [OleDestroyMenuDescriptor](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oledestroymenudescriptor).

## See also

[OleDestroyMenuDescriptor](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oledestroymenudescriptor)