# BufferPointerPacketsInteractionContext function

## Description

Adds the history for a single input pointer to the buffer of the [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/) object.

## Parameters

### `interactionContext` [in]

The handle of the interaction context.

### `entriesCount` [in]

The number of entries in the pointer history.

### `pointerInfo` [in]

Basic pointer information common to all pointer types.

## Return value

If this function succeeds, it returns S_OK.
Otherwise, it returns an HRESULT error code.

## See also

[POINTER_INFO structure](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-pointer_info)