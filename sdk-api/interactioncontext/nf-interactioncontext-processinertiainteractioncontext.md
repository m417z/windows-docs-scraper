# ProcessInertiaInteractionContext function

## Description

Sends timer input to the [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/) object for inertia processing.

## Parameters

### `interactionContext` [in]

Pointer to a handle for the [Interaction Context](https://learn.microsoft.com/windows/win32/api/_input_intcontext/).

## Return value

If this function succeeds, it returns S_OK.

Otherwise, it returns an HRESULT error code.

## Remarks

The caller is responsible for creating timer when inertia starts, and for driving inertia input with the timer by calling this function from the timer callback. Recommended timer period is 15 ms.

This function has no effect outside inertia.

## See also