# MINIDUMP_CALLBACK_ROUTINE callback function

## Description

An application-defined callback function used with
[MiniDumpWriteDump](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nf-minidumpapiset-minidumpwritedump). It receives extended minidump information.

The **MINIDUMP_CALLBACK_ROUTINE** type defines a pointer to this callback function.
**MiniDumpCallback** is a placeholder for the application-defined function name.

## Parameters

### `CallbackParam` [in]

An application-defined parameter value.

### `CallbackInput` [in]

A pointer to a
[MINIDUMP_CALLBACK_INPUT](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_callback_input) structure that specifies extended minidump information.

### `CallbackOutput` [in, out]

A pointer to a
[MINIDUMP_CALLBACK_OUTPUT](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_callback_output) structure that receives application-defined information from the callback function.

## Return value

If the function succeeds, return **TRUE**; otherwise, return **FALSE**.

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[MINIDUMP_CALLBACK_INFORMATION](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_callback_information)

[MiniDumpWriteDump](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nf-minidumpapiset-minidumpwritedump)