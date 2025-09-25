# OleDestroyMenuDescriptor function

## Description

Called by the container to free the shared menu descriptor allocated by the [OleCreateMenuDescriptor](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatemenudescriptor) function.

## Parameters

### `holemenu` [in]

Handle to the shared menu descriptor that was returned by the [OleCreateMenuDescriptor](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatemenudescriptor) function.

## Return value

This function does not return a value.

## See also

[OleCreateMenuDescriptor](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatemenudescriptor)