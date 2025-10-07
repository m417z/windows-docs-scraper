# RtlDosPathNameToNtPathName_U_WithStatus function

Converts a DOS path name to an NT path name.

## Parameters

### DosFileName [in]

A pointer to a DOS file name path.

### PUNICODE_STRING [out]

A pointer to a reference-counted Unicode string structure containing a Win32-style NT path name.

### FilePart [out, optional]

If present, supplies a pointer to a variable which, on success, receives a pointer to the base name portion of the output NT path name.

### Reserved

Reserved.

## Return value

An NTSTATUS code. For more information, see [Using NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions. The API is exported from ntdll.dll.

## Requirements

| Requirement | Value |
|-----------------------------------|-------------------------------------------------------------------------------------------------------|
| DLL | ntdll.dll |