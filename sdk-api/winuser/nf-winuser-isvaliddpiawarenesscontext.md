# IsValidDpiAwarenessContext function

## Description

Determines if a specified **DPI_AWARENESS_CONTEXT** is valid and supported by the current system.

## Parameters

### `value` [in]

The context that you want to determine if it is supported.

## Return value

**TRUE** if the provided context is supported, otherwise **FALSE**.

## Remarks

**IsValidDpiAwarenessContext** determines the validity of any provided **DPI_AWARENESS_CONTEXT**. You should make sure a context is valid before using [SetThreadDpiAwarenessContext](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setthreaddpiawarenesscontext) to that context.

An input *value* of **NULL** is considered to be an invalid context and will result in a return value of **FALSE.**