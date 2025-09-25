## Description

Sets the DPI scale for which the cursors being created on this thread are intended. This value is taken into account when scaling the cursor for the specific monitor on which it is being shown.

## Parameters

### `cursorDpi`

The 96-based DPI scale of the cursors that the application will be creating. For example, a 96 DPI value corresponds to 100% monitor scale factor, 144 DPI corresponds to 150%, and so on.

There are two special values:

CURSOR_CREATION_SCALING_DEFAULT – resets cursor scaling to default system behavior (as if SetThreadCursorCreationScaling was never called on this thread).

CURSOR_CREATION_SCALING_NONE – disables all cursor scaling (the cursors created after calling SetThreadCursorCreationScaling with this parameter will never be scaled up or down on any monitor).

## Return value

The previous value set for the thread before calling this API.

## Remarks

## See also