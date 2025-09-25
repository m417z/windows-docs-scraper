# AddRefActCtx function

## Description

The
**AddRefActCtx** function increments the reference count of the specified activation context.

## Parameters

### `hActCtx` [in]

Handle to an
[ACTCTX](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-actctxa) structure that contains information on the activation context for which the reference count is to be incremented.

## Remarks

This function is provided so that multiple clients can access a single activation context.

## See also

[ACTCTX](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-actctxa)