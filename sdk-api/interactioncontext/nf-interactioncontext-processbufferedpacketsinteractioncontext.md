# ProcessBufferedPacketsInteractionContext function

## Description

Process buffered packets at the end of a pointer input frame.

## Parameters

### `interactionContext` [in]

Pointer to a handle for the [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/).

## Return value

If this function succeeds, it returns S_OK.

Otherwise, it returns an HRESULT error code.

## Remarks

**ProcessBufferedPacketsInteractionContext** is called at the end of the frame, when the buffer contains all the pointer histories from the frame.

## See also