## Description

Resets an async context so it can be reused.

## Parameters

### `Handle`

The async context handle.

## Return value

If the context is invalid or currently in use, an error will be returned.

## Remarks

Only the context state is altered. Client notification info, such as callback, is left alone.

## See also