# PFIND_EXE_FILE_CALLBACK callback function

## Description

An application-defined callback function used with the
[FindExecutableImageEx](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-findexecutableimageex) function. It verifies whether the executable file found by
**FindExecutableImageEx** is the correct executable file.

The **PFIND_EXE_FILE_CALLBACK** and **PFIND_EXE_FILE_CALLBACKW** types define a pointer to this callback function.
**FindExecutableImageProc** is a placeholder for the application-defined function name.

## Parameters

### `FileHandle` [in]

A handle to the executable file.

### `FileName` [in]

The name of the executable file.

### `CallerData` [in]

Optional user-defined data. This parameter can be **NULL**.

## Return value

If the executable file is valid, return **TRUE**. Otherwise, return **FALSE**.

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[FindExecutableImageEx](https://learn.microsoft.com/windows/desktop/api/dbghelp/nf-dbghelp-findexecutableimageex)