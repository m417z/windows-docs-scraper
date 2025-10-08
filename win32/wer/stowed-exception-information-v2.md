# STOWED\_EXCEPTION\_INFORMATION\_V2 structure

Contains stowed exception info.

## Members

**Header**

Type: **[**STOWED\_EXCEPTION\_INFORMATION\_HEADER**](https://learn.microsoft.com/windows/win32/wer/stowed-exception-information-header)**

The [**STOWED\_EXCEPTION\_INFORMATION\_HEADER**](https://learn.microsoft.com/windows/win32/wer/stowed-exception-information-header) structure that contains info for this parent structure.

**ResultCode**

Type: **[**HRESULT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The [**HRESULT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types) code for the stowed exception.

**ExceptionForm**

Type: **[**DWORD**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A 2-bit value that identifies the form of the exception.

| Value | Meaning |
|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------|
| **STOWED\_EXCEPTION\_FORM\_BINARY**<br>0x01 | This value indicates that the form of the exception is binary.<br> |
| **STOWED\_EXCEPTION\_FORM\_TEXT**<br>0x02 | This value indicates that the form of the exception is text.<br> |

**ThreadId**

Type: **[**DWORD**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A 30-bit value that identifies the thread that raised the exception. The value is shifted to the right by 2 bits when it's stored. To convert it back to a valid thread ID, shift the value to the left by 2. For example:

``` syntax
DWORD ActualThreadId = (StowedException.ThreadId << 2);
```

(*unnamed struct*)

The members of this nested structure are valid only if the **ExceptionForm** member is set to **STOWED\_EXCEPTION\_FORM\_BINARY**.

**ExceptionAddress**

Type: **[**PVOID**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer that contains the exception address.

**StackTraceWordSize**

Type: **[**ULONG**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size, in bytes, of each word in the stack trace that the **StackTrace** member points to. This value is set to 4 for 32-bit platforms and 8 for 64-bit platforms.

**StackTraceWords**

Type: **[**ULONG**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of words in the stack trace that the **StackTrace** member points to. The number of words is equal to the number of elements in the array.

**StackTrace**

Type: **[**PVOID**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to a memory block that contains the stack trace.

(*unnamed struct*)

The member of this nested structure is valid only if the **ExceptionForm** member is set to **STOWED\_EXCEPTION\_FORM\_TEXT**.

**ErrorText**

Type: **[**PWSTR**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to a null-terminated string that contains the error text of the exception.

**NestedExceptionType**

Type: **[**ULONG**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A 32-bit value that specifies the type of object that the **NestedException** member points to. Define the value with this byte swap type-definition macro that assumes little-endian:

``` syntax
#define STOWED_EXCEPTION_NESTED_TYPE(t) ((((((ULONG)(t)) >> 24) & 0xFF) <<  0) | \
                                         (((((ULONG)(t)) >> 16) & 0xFF) <<  8) | \
                                         (((((ULONG)(t)) >>  8) & 0xFF) << 16) | \
                                         (((((ULONG)(t)) >>  0) & 0xFF) << 24))
```

Here are some common type definitions:

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **STOWED\_EXCEPTION\_NESTED\_TYPE\_NONE**<br>(0x00000000) | This value specifies that there is no nested exception object.<br> |
| **STOWED\_EXCEPTION\_NESTED\_TYPE\_WIN32**<br>STOWED\_EXCEPTION\_NESTED\_TYPE('W32E') | This value specifies that the **NestedException** member points to an [**EXCEPTION\_RECORD**](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-exception_record) object.<br> |
| **STOWED\_EXCEPTION\_NESTED\_TYPE\_STOWED**<br>STOWED\_EXCEPTION\_NESTED\_TYPE('STOW') | This value specifies that the **NestedException** member points to another stowed exception object. The other stowed exception object can be a **STOWED\_EXCEPTION\_INFORMATION\_V2** object or a different version with a valid **Header** member, that is, a **Header** member that contains a valid [**STOWED\_EXCEPTION\_INFORMATION\_HEADER**](https://learn.microsoft.com/windows/win32/wer/stowed-exception-information-header).<br> |
| **STOWED\_EXCEPTION\_NESTED\_TYPE\_CLR**<br>STOWED\_EXCEPTION\_NESTED\_TYPE('CLR1') | This value specifies that the **NestedException** member points to a 'CLR1' exception object.<br> |
| **STOWED\_EXCEPTION\_NESTED\_TYPE\_LEO**<br>STOWED\_EXCEPTION\_NESTED\_TYPE('LEO1') | This value specifies that the **NestedException** member points to a language exception object.<br> |

**NestedException**

Type: **[**PVOID**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to a nested exception type. The type of object is indicated by the **NestedExceptionType** member.

## Remarks

**STOWED\_EXCEPTION\_INFORMATION\_V2** and [**STOWED\_EXCEPTION\_INFORMATION\_HEADER**](https://learn.microsoft.com/windows/win32/wer/stowed-exception-information-header) currently aren't defined in a header that is publicly available so you need to define them in your source code before you use them.

The **STOWED\_EXCEPTION\_INFORMATION\_V1** structure is identical to this structure except it doesn't contain the **NestedExceptionType** and **NestedException** members.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8.1 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 R2 \[desktop apps only\]<br> |
| Header<br> | None |

## See also

[**EXCEPTION\_RECORD**](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-exception_record)

[**STOWED\_EXCEPTION\_INFORMATION\_HEADER**](https://learn.microsoft.com/windows/win32/wer/stowed-exception-information-header)

