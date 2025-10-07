# ApplyDeltaW function

Uses the delta and source (provided as buffers) to create a new copy of the target data. The output data is returned in an MSDelta-allocated buffer.

> [!NOTE]
> You must call [DeltaFree](https://learn.microsoft.com/windows/win32/devnotes/msdelta-deltafree) to free the output buffer after this function has completed.

> [!NOTE]
> If the specified delta was created using [PatchAPI](https://learn.microsoft.com/windows/win32/devnotes/patchapi), and the [DELTA_APPLY_FLAG_ALLOW_PA19](https://learn.microsoft.com/previous-versions/bb417345(v=msdn.10)#delta_flag_type-flags) flag is set, MSDelta will call PatchAPI to apply the delta.

## Parameters

*ApplyFlags*

[in] Either [DELTA_FLAG_NONE](https://learn.microsoft.com/previous-versions/bb417345(v=msdn.10)#delta_flag_type-flags) or [DELTA_APPLY_FLAG_ALLOW_PA19](https://learn.microsoft.com/previous-versions/bb417345(v=msdn.10)#delta_flag_type-flags).

*Source*

[in] A [DELTA_INPUT](https://learn.microsoft.com/previous-versions/bb417345(v=msdn.10)#delta-input-structure) structure containing a pointer to the file path containing the source data.

*Delta*

[in] A [DELTA_INPUT](https://learn.microsoft.com/previous-versions/bb417345(v=msdn.10)#delta-input-structure) structure containing a pointer to the file path containing the delta data.

*lpTarget*

[out] Pointer to the [DELTA_OUTPUT](https://learn.microsoft.com/previous-versions/bb417345(v=msdn.10)#delta-output-structure) structure where the target is to be written.

## Return value

This function returns **TRUE** if it succeeds; otherwise, it returns **FALSE**. When the function returns **FALSE**, you can call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) to get the corresponding Win32 system error code.

## Requirements

| Requirement | Value |
|----------------|---------------------------------------------------------------------------------------|
| Header | msdelta.h |
| DLL | msdelta.dll |
| Unicode | Not applicable |

## See also

[MSDelta](https://learn.microsoft.com/windows/win32/devnotes/msdelta)

[DeltaFree](https://learn.microsoft.com/windows/win32/devnotes/msdelta-deltafree)