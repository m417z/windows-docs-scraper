# RtlNtPathNameToDosPathName function

Converts an NT path name to a DOS path name.

> [!NOTE]
> This is a legacy API that is documented for completeness, but it is not recommended for use by app developers.

## Parameters

### Flags [in]

Flags. Must be set to 0.

### Path [in, out]

A pointer to a reference-counted Unicode string structure containing a Win32-style NT path name that is replaced with a DOS path name.

### Disposition [out, optional]

A **ULONG** that indicates how the operation completed. This can be one of the following values.

| Value | Description |
|-------|-------------|
| 0x00000001 | The path name was ambiguous. |
| 0x00000002 | The path name was UNC. |
| 0x00000003 | The path name was a drive. |
| 0x00000004 | The path name was already in DOS format. |

### FilePart [in, out, optional]

If present, supplies a pointer to a variable which, on success, receives a pointer to the base name portion of the output NT path name.

## Return value

An NTSTATUS code. For more information, see [Using NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions. The API is exported from ntdll.dll.

## Requirements

| Requirement | Value |
|-----------------------------------|-------------------------------------------------------------------------------------------------------|
| DLL | ntdll.dll |