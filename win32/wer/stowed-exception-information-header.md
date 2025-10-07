# STOWED\_EXCEPTION\_INFORMATION\_HEADER structure

Contains info that identifies the parent structure.

## Members

**Size**

Type: **[**ULONG**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size, in bytes, of the parent structure.

**Signature**

Type: **[**ULONG**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A 32-bit value that specifies the signature of the parent structure.

| Value | Meaning |
|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------|
| **STOWED\_EXCEPTION\_INFORMATION\_V1\_SIGNATURE**

'SE01' | This value indicates that the parent is a **STOWED\_EXCEPTION\_INFORMATION\_V1** structure.\ | | **STOWED\_EXCEPTION\_INFORMATION\_V2\_SIGNATURE**

'SE02' | This value indicates that the parent is a [**STOWED\_EXCEPTION\_INFORMATION\_V2**](https://learn.microsoft.com/windows/win32/wer/stowed-exception-information-v2) structure.\ |

## Remarks

[**STOWED\_EXCEPTION\_INFORMATION\_V2**](https://learn.microsoft.com/windows/win32/wer/stowed-exception-information-v2) and **STOWED\_EXCEPTION\_INFORMATION\_HEADER** currently aren't defined in a header that is publicly available so you need to define them in your source code before you use them.

The **STOWED\_EXCEPTION\_INFORMATION\_V1** structure is identical to this structure except it doesn't contain the **NestedExceptionType** and **NestedException** members.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | None |

## See also

[**STOWED\_EXCEPTION\_INFORMATION\_V2**](https://learn.microsoft.com/windows/win32/wer/stowed-exception-information-v2)

