# IDCompositionDevice::WaitForCommitCompletion

## Description

Waits for the composition engine to finish processing the previous call to the [IDCompositionDevice::Commit](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiondevice-commit) method.

## Return value

If the function succeeds, it returns S_OK. Otherwise, it returns an [HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types) error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## See also

[IDCompositionDevice](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondevice)