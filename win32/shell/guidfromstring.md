# GUIDFromString function

\[**GUIDFromString** is available through Windows XP with Service Pack 2 (SP2) or Windows Vista. It might be altered or unavailable in subsequent versions. Applications should use [**CLSIDFromString**](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-clsidfromstring) or [**IIDFromString**](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-iidfromstring) in place of this function.\]

Converts a string to a GUID.

## Parameters

*psz* \[in\]

Type: **LPCTSTR**

A pointer to the null-terminated string to convert. The string should be in the following form:

{00000000-0000-0000-0000-000000000000}

*pguid* \[out\]

Type: **LPGUID**

Pointer to a buffer to receive the GUID when this method returns.

## Return value

Type: **BOOL**

**TRUE** if the GUID was created successfully; otherwise, **FALSE**.

## Remarks

This function is not declared in a header or exported by name from a .dll file. It must be loaded from Shell32.dll as ordinal 703 for **GUIDFromStringA** and ordinal 704 for **GUIDFromStringW**.

It can also be accessed from Shlwapi.dll as ordinal 269 for **GUIDFromStringA** and ordinal 270 for **GUIDFromStringW**.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| DLL<br> | Shell32.dll |
| Unicode and ANSI names<br> | **GUIDFromStringW** (Unicode) and **GUIDFromStringA** (ANSI)<br> |

