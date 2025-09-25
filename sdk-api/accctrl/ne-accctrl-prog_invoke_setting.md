# PROG_INVOKE_SETTING enumeration

## Description

The **PROG_INVOKE_SETTING** enumeration indicates the initial setting of the function used to track the progress of a call to the [TreeSetNamedSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-treesetnamedsecurityinfoa) or [TreeResetNamedSecurityInfo](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-treeresetnamedsecurityinfoa) function.

## Constants

### `ProgressInvokeNever`

Never invoke the progress function.

### `ProgressInvokeEveryObject`

Invoke the progress function for every object.

### `ProgressInvokeOnError`

Invoke the progress function only when an error is encountered.

### `ProgressCancelOperation`

Discontinue the tree operation.

**Note** The original state of the tree will not be reset, and the results are unpredictable.

### `ProgressRetryOperation`

Retry the tree operation.

### `ProgressInvokePrePostError`

Invoke the progress function before and after applying security on the object and on the error.