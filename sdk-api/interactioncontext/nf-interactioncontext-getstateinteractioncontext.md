# GetStateInteractionContext function

## Description

Gets current [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/) state.

## Parameters

### `interactionContext` [in]

Pointer to a handle for the [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/).

### `pointerInfo` [in, optional]

A [POINTER_INFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-pointer_info) structure that contains basic pointer information for the specific pointer of interest. This parameter can be **NULL**.

### `state` [out]

One of the constants from [INTERACTION_STATE enumeration](https://learn.microsoft.com/windows/win32/api/interactioncontext/ne-interactioncontext-interaction_state).

## Return value

If this function succeeds, it returns S_OK.

Otherwise, it returns an HRESULT error code.

## Remarks

After interaction ends, the interaction context might still be busy reporting inertia, or expecting second tap in a double tap gesture (in general, if multi-stroke gesture is possible). This function allows the caller to find out when it is safe to treat the Interaction Context object as idle. The main purpose of this function is management of pools of interaction contexts.

## See also