# NtQueryMultipleValueKey function

## Description

[This function may be changed or removed from Windows without further notice.]

Retrieves values for the specified multiple-value key.

## Parameters

### `KeyHandle` [in]

A handle to the key for which to retrieve values. The handle must be opened with the **KEY_QUERY_VALUE** access right.

### `ValueEntries` [in, out]

A pointer to an array of [**KEY_VALUE_ENTRY**] structures containing the names of values to retrieve.

### `EntryCount` [in]

The number of elements in the *ValueEntries* array.

### `ValueBuffer` [out]

A pointer to a buffer to receive the values.

### `BufferLength` [in, out]

A pointer to a variable that contains the size of the buffer at *ValueBuffer*, in bytes. When the function returns, the *BufferLength* parameter contains the number of bytes written to the buffer at *ValueBuffer*.

### `RequiredBufferLength` [out, optional]

A pointer to a variable to receive the number of bytes required for all of the values to be returned by the function. This parameter can be **NULL**.

## Return value

Returns an **NTSTATUS** or error code.

If the buffer is too small to hold the information to be retrieved, the function returns **STATUS_BUFFER_OVERFLOW** and, if the *RequiredBufferLength* parameter is specified, sets it to the buffer size required.

The forms and significance of **NTSTATUS** error codes are listed in the Ntstatus.h header file available in the WDK, and are described in the WDK documentation.

## Remarks

This function has no associated header file. You can also use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/DevNotes/-loadlibrary) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/DevNotes/-getprocaddress-) functions to dynamically link to Ntdll.dll.

## See also

[Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights)