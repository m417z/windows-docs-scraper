# RoUninitialize function

## Description

Closes the Windows Runtime on the current thread.

## Remarks

Call the **RoUninitialize** function to close the Windows Runtime on the current thread. This unloads all DLLs loaded by the thread, frees any other resources that the thread maintains, and forces all RPC connections on the thread to close.

Use the [RoInitialize](https://learn.microsoft.com/windows/desktop/api/roapi/nf-roapi-roinitialize) function to initialize a thread in the Windows Runtime.

## See also

[CoUninitialize](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-couninitialize)

[RoInitialize](https://learn.microsoft.com/windows/desktop/api/roapi/nf-roapi-roinitialize)