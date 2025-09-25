# ReleaseActCtx function

## Description

The
**ReleaseActCtx** function decrements the reference count of the specified activation context.

## Parameters

### `hActCtx` [in]

Handle to the
[ACTCTX](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-actctxa) structure that contains information on the activation context for which the reference count is to be decremented.

## Return value

This function does not return a value. On successful completion, the activation context reference count is decremented. The recipient of the reference-counted object must decrement the reference count when the object is no longer required.

## Remarks

When the reference count of an activation context becomes zero, the activation context structure is deallocated. Activation contexts have not been implemented as kernel objects, therefore, kernel handler functions cannot be used for activation contexts.

If the value of the *hActCtx* parameter is a null handle, this function does nothing and no error condition occurs.

## See also

[ACTCTX](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-actctxa)

[AddRefActCtx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-addrefactctx)