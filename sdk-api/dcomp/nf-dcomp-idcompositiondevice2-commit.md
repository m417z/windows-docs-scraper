# IDCompositionDevice2::Commit

## Description

Commits all DirectComposition commands that are pending on this device.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT**
error code. See
[DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a
list of error codes.

## Remarks

Calls to DirectComposition methods are always batched and executed atomically as
a single transaction. Calls take effect only when
**IDCompositionDevice2::Commit** is
called, at which time all pending method calls for a device are executed at once.

An application that uses multiple devices must call
**Commit** for each device separately.
However, because the composition engine processes the calls individually, the batch of commands might not take
effect at the same time.

## See also

[IDCompositionDevice2](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondevice2)