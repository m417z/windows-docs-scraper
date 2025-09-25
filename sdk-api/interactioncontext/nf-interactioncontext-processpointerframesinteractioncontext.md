# ProcessPointerFramesInteractionContext function

## Description

Processes a set of pointer input frames.

## Parameters

### `interactionContext` [in]

Pointer to a handle for the [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/).

### `entriesCount` [in]

Number of frames to process.

### `pointerCount` [in]

Number of pointers in each frame.

### `pointerInfo` [in]

Pointer to the array of frames (of size *entriesCount*).

## Return value

If this function succeeds, it returns S_OK.

Otherwise, it returns an HRESULT error code.

## Remarks

Output notifications are sent as required.

Frames must be processed in reverse chronological order (most recent data first).

Each frame must have the same set of input pointers.

Each pointer must originate from a different contact.

If pointer filtering is set, a sub-frame that includes the specified pointers is extracted from each frame. Pointers are specified through the [AddPointerInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-addpointerinteractioncontext) and pointer filtering turned on by setting INTERACTION_CONTEXT_PROPERTY_FILTER_POINTERS in the [SetPropertyInteractionContext function](https://learn.microsoft.com/windows/win32/api/interactioncontext/nf-interactioncontext-setpropertyinteractioncontext).

## See also