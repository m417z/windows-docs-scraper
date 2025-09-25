# CfReferenceProtectedHandle function

## Description

Allows the caller to reference a protected handle to a Win32 handle which can be used with non-CfApi Win32 APIs.

## Parameters

### `ProtectedHandle` [in]

The protected handle of a placeholder file.

## Return value

If this function succeeds, it returns `TRUE`. Otherwise, it returns `FALSE`.

## Remarks

Every **CfReferenceProtectedHandle** call must be matched with a [CfReleaseProtectedHandle](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfreleaseprotectedhandle) call. It is not recommended to reference a protected handle for a long period of time, as doing so will prevent the oplock break notification from being acknowledged.

The caller should instead break up long running tasks into smaller sub-tasks and reference/release the protected handle for each sub-task.

## See also

[CfReleaseProtectedHandle](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfreleaseprotectedhandle)