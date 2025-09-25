# FormatMessage function

## Description

Formats a message string. The function requires a message definition as input. The message
definition can come from a buffer passed into the function. It can come from a message table resource in an
already-loaded module. Or the caller can ask the function to search the system's message table resource(s) for the
message definition. The function finds the message definition in a message table resource based on a message
identifier and a language identifier. The function copies the formatted message text to an output buffer,
processing any embedded insert sequences if requested.

## Parameters

### `dwFlags` [in]

The formatting options, and how to interpret the *lpSource* parameter. The
low-order byte of *dwFlags* specifies how the function handles line breaks in the output
buffer. The low-order byte can also specify the maximum width of a formatted output line.

This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **FORMAT_MESSAGE_ALLOCATE_BUFFER**<br><br>0x00000100 | The function allocates a buffer large enough to hold the formatted message, and places a pointer to the allocated buffer at the address specified by *lpBuffer*. The *lpBuffer* parameter is a pointer to an **LPTSTR**; you must cast the pointer to an **LPTSTR** (for example, `(LPTSTR)&lpBuffer`). The *nSize* parameter specifies the minimum number of **TCHARs** to allocate for an output message buffer. The caller should use the [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree) function to free the buffer when it is no longer needed.<br><br>If the length of the formatted message exceeds 128K bytes, then **FormatMessage** will fail and a subsequent call to [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) will return **ERROR_MORE_DATA**.<br><br>In previous versions of Windows, this value was not available for use when compiling Windows Store apps. As of Windows 10 this value can be used. <br><br>**Windows Server 2003 and Windows XP:** <br><br>If the length of the formatted message exceeds 128K bytes, then **FormatMessage** will not automatically fail with an error of **ERROR_MORE_DATA**. |
| **FORMAT_MESSAGE_ARGUMENT_ARRAY**<br><br>0x00002000 | The *Arguments* parameter is not a **va_list** structure, but is a pointer to an array of values that represent the arguments.<br><br>This flag cannot be used with 64-bit integer values. If you are using a 64-bit integer, you must use the **va_list** structure. |
| **FORMAT_MESSAGE_FROM_HMODULE**<br><br>0x00000800 | The *lpSource* parameter is a module handle containing the message-table resource(s) to search. If this *lpSource* handle is **NULL**, the current process's application image file will be searched. This flag cannot be used with **FORMAT_MESSAGE_FROM_STRING**.<br><br>If the module has no message table resource, the function fails with **ERROR_RESOURCE_TYPE_NOT_FOUND**. |
| **FORMAT_MESSAGE_FROM_STRING**<br><br>0x00000400 | The *lpSource* parameter is a pointer to a null-terminated string that contains a message definition. The message definition may contain insert sequences, just as the message text in a message table resource may. This flag cannot be used with **FORMAT_MESSAGE_FROM_HMODULE** or **FORMAT_MESSAGE_FROM_SYSTEM**. |
| **FORMAT_MESSAGE_FROM_SYSTEM**<br><br>0x00001000 | The function should search the system message-table resource(s) for the requested message. If this flag is specified with **FORMAT_MESSAGE_FROM_HMODULE**, the function searches the system message table if the message is not found in the module specified by *lpSource*. This flag cannot be used with **FORMAT_MESSAGE_FROM_STRING**.<br><br>If this flag is specified, an application can pass the result of the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function to retrieve the message text for a system-defined error. |
| **FORMAT_MESSAGE_IGNORE_INSERTS**<br><br>0x00000200 | Insert sequences in the message definition such as %1 are to be ignored and passed through to the output buffer unchanged. This flag is useful for fetching a message for later formatting. If this flag is set, the *Arguments* parameter is ignored. |

The low-order byte of *dwFlags* can specify the maximum width of a formatted output
line. The following are possible values of the low-order byte.

| Value | Meaning |
| --- | --- |
| 0 | There are no output line width restrictions. The function stores line breaks that are in the message definition text into the output buffer. |
| **FORMAT_MESSAGE_MAX_WIDTH_MASK**<br><br>0x000000FF | The function ignores regular line breaks in the message definition text. The function stores hard-coded line breaks in the message definition text into the output buffer. The function generates no new line breaks. |

If the low-order byte is a nonzero value other than
**FORMAT_MESSAGE_MAX_WIDTH_MASK**, it specifies the maximum number of characters in an
output line. The function ignores regular line breaks in the message definition text. The function never splits
a string delimited by white space across a line break. The function stores hard-coded line breaks in the message
definition text into the output buffer. Hard-coded line breaks are coded with the %n escape sequence.

### `lpSource` [in, optional]

The location of the message definition. The type of this parameter depends upon the settings in the
*dwFlags* parameter.

| *dwFlags* Setting | Meaning |
| --- | --- |
| **FORMAT_MESSAGE_FROM_HMODULE**<br><br>0x00000800 | A handle to the module that contains the message table to search. |
| **FORMAT_MESSAGE_FROM_STRING**<br><br>0x00000400 | Pointer to a string that consists of unformatted message text. It will be scanned for inserts and formatted accordingly. |

If neither of these flags is set in *dwFlags*, then
*lpSource* is ignored.

### `dwMessageId` [in]

The message identifier for the requested message. This parameter is ignored if
*dwFlags* includes **FORMAT_MESSAGE_FROM_STRING**.

### `dwLanguageId` [in]

The [language identifier](https://learn.microsoft.com/windows/desktop/Intl/language-identifiers) for the requested
message. This parameter is ignored if *dwFlags* includes
**FORMAT_MESSAGE_FROM_STRING**.

If you pass a specific **LANGID** in this parameter,
**FormatMessage** will return a message for that
**LANGID** only. If the function cannot find a message for that
**LANGID**, it sets Last-Error to
**ERROR_RESOURCE_LANG_NOT_FOUND**. If you pass in zero,
**FormatMessage** looks for a message for
**LANGIDs** in the following order:

1. Language neutral
2. Thread **LANGID**, based on the thread's locale value
3. User default **LANGID**, based on the user's default locale value
4. System default **LANGID**, based on the system default locale value
5. US English

If **FormatMessage** does not locate a message for any
of the preceding **LANGIDs**, it returns any language message string that is present.
If that fails, it returns **ERROR_RESOURCE_LANG_NOT_FOUND**.

### `lpBuffer` [out]

A pointer to a buffer that receives the null-terminated string that specifies the formatted message. If
*dwFlags* includes **FORMAT_MESSAGE_ALLOCATE_BUFFER**, the
function allocates a buffer using the [LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc)
function, and places the pointer to the buffer at the address specified in
*lpBuffer*.

This buffer cannot be larger than 64K bytes.

### `nSize` [in]

If the **FORMAT_MESSAGE_ALLOCATE_BUFFER** flag is not set, this parameter specifies
the size of the output buffer, in **TCHARs**. If
**FORMAT_MESSAGE_ALLOCATE_BUFFER** is set, this parameter specifies the minimum number of
**TCHARs** to allocate for an output buffer.

The output buffer cannot be larger than 64K bytes.

### `Arguments` [in, optional]

An array of values that are used as insert values in the formatted message. A %1 in the format string
indicates the first value in the *Arguments* array; a %2 indicates the second argument;
and so on.

The interpretation of each value depends on the formatting information associated with the insert in the
message definition. The default is to treat each value as a pointer to a null-terminated string.

By default, the *Arguments* parameter is of type
**va_list***, which is a language- and implementation-specific data type for
describing a variable number of arguments. The state of the **va_list** argument is
undefined upon return from the function. To use the **va_list** again, destroy the
variable argument list pointer using **va_end** and reinitialize it with
**va_start**.

If you do not have a pointer of type
**va_list***, then specify the **FORMAT_MESSAGE_ARGUMENT_ARRAY**
flag and pass a pointer to an array of **DWORD_PTR** values; those values are input to
the message formatted as the insert values. Each insert must have a corresponding element in the array.

## Return value

If the function succeeds, the return value is the number of **TCHARs** stored in the
output buffer, excluding the terminating null character.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Within the message text, several escape sequences are supported for dynamically formatting the message. These
escape sequences and their meanings are shown in the following tables. All escape sequences start with the percent
character (%).

| Escape sequence | Meaning |
| --- | --- |
| %0 | Terminates a message text line without a trailing new line character. This escape sequence can be used to build up long lines or to terminate the message itself without a trailing new line character. It is useful for prompt messages. |
| %*n*!*format string*! | Identifies an insert sequence. The value of *n* can be in the range from 1 through 99. The format string (which must be surrounded by exclamation marks) is optional and defaults to !s! if not specified. For more information, see [Format Specification Fields](https://learn.microsoft.com/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions).<br><br>The format string can include a width and precision specifier for strings and a width specifier for integers. Use an asterisk (*) to specify the width and precision. For example, %1!*.*s! or %1!*u!.<br><br>If you do not use the width and precision specifiers, the insert numbers correspond directly to the input arguments. For example, if the source string is "%1 %2 %1" and the input arguments are "Bill" and "Bob", the formatted output string is "Bill Bob Bill".<br><br>However, if you use a width and precision specifier, the insert numbers do not correspond directly to the input arguments. For example, the insert numbers for the previous example could change to "%1!*.*s! %4 %5!*s!".<br><br>The insert numbers depend on whether you use an arguments array (**FORMAT_MESSAGE_ARGUMENT_ARRAY**) or a **va_list**. For an arguments array, the next insert number is *n+2* if the previous format string contained one asterisk and is *n+3* if two asterisks were specified. For a **va_list**, the next insert number is *n+1* if the previous format string contained one asterisk and is *n+2* if two asterisks were specified.<br><br>If you want to repeat "Bill", as in the previous example, the arguments must include "Bill" twice. For example, if the source string is "%1!*.*s! %4 %5!*s!", the arguments could be, 4, 2, Bill, Bob, 6, Bill (if using the **FORMAT_MESSAGE_ARGUMENT_ARRAY** flag). The formatted string would then be " Bi Bob Bill".<br><br>Repeating insert numbers when the source string contains width and precision specifiers may not yield the intended results. If you replaced %5 with %1, the function would try to print a string at address 6 (likely resulting in an access violation).<br><br>Floating-point format specifiers—e, E, f, and g—are not supported. The workaround is to use the [StringCchPrintf](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchprintfa) function to format the floating-point number into a temporary buffer, then use that buffer as the insert string.<br><br>Inserts that use the I64 prefix are treated as two 32-bit arguments. They must be used before subsequent arguments are used. Note that it may be easier for you to use [StringCchPrintf](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchprintfa) instead of this prefix. |

Any other nondigit character following a percent character is formatted in the output message without the
percent character. Following are some examples.

| Format string | Resulting output |
| --- | --- |
| %% | A single percent sign. |
| %*b* | A single space. This format string can be used to ensure the appropriate number of trailing spaces in a message text line. |
| %. | A single period. This format string can be used to include a single period at the beginning of a line without terminating the message text definition. |
| %! | A single exclamation point. This format string can be used to include an exclamation point immediately after an insert without its being mistaken for the beginning of a format string. |
| %n | A hard line break when the format string occurs at the end of a line. This format string is useful when **FormatMessage** is supplying regular line breaks so the message fits in a certain width. |
| %r | A hard carriage return without a trailing newline character. |
| %t | A single tab. |

### Security Remarks

If this function is called without **FORMAT_MESSAGE_IGNORE_INSERTS**, the
*Arguments* parameter must contain enough parameters to satisfy all insertion sequences
in the message string, and they must be of the correct type. Therefore, do not use untrusted or unknown message
strings with inserts enabled because they can contain more insertion sequences than
*Arguments* provides, or those that may be of the wrong type. In particular, it is
unsafe to take an arbitrary system error code returned from an API and use
**FORMAT_MESSAGE_FROM_SYSTEM** without
**FORMAT_MESSAGE_IGNORE_INSERTS**.

#### Examples

The **FormatMessage** function can be used to obtain
error message strings for the system error codes returned by
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). For an example, see
[Retrieving the Last-Error Code](https://learn.microsoft.com/windows/desktop/Debug/retrieving-the-last-error-code).

The following example shows how to use an argument array and the width and precision specifiers.

```cpp
#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>
#include <stdio.h>

void main(void)
{
    LPWSTR pMessage = L"%1!*.*s! %4 %5!*s!";
    DWORD_PTR pArgs[] = { (DWORD_PTR)4, (DWORD_PTR)2, (DWORD_PTR)L"Bill",  // %1!*.*s! refers back to the first insertion string in pMessage
         (DWORD_PTR)L"Bob",                                                // %4 refers back to the second insertion string in pMessage
         (DWORD_PTR)6, (DWORD_PTR)L"Bill" };                               // %5!*s! refers back to the third insertion string in pMessage
    const DWORD size = 100+1;
    WCHAR buffer[size];

    if (!FormatMessage(FORMAT_MESSAGE_FROM_STRING | FORMAT_MESSAGE_ARGUMENT_ARRAY,
                       pMessage,
                       0,
                       0,
                       buffer,
                       size,
                       (va_list*)pArgs))
    {
        wprintf(L"Format message failed with 0x%x\n", GetLastError());
        return;
    }

    // Buffer contains "  Bi Bob   Bill".
    wprintf(L"Formatted message: %s\n", buffer);
}

```

The following example shows how to implement the previous example using
**va_list**.

```cpp
#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>
#include <stdio.h>

LPWSTR GetFormattedMessage(LPWSTR pMessage, ...);

void main(void)
{
    LPWSTR pBuffer = NULL;
    LPWSTR pMessage = L"%1!*.*s! %3 %4!*s!";

    // The variable length arguments correspond directly to the format
    // strings in pMessage.
    pBuffer = GetFormattedMessage(pMessage, 4, 2, L"Bill", L"Bob", 6, L"Bill");
    if (pBuffer)
    {
        // Buffer contains "  Bi Bob   Bill".
        wprintf(L"Formatted message: %s\n", pBuffer);
        LocalFree(pBuffer);
    }
    else
    {
        wprintf(L"Format message failed with 0x%x\n", GetLastError());
    }
}

// Formats a message string using the specified message and variable
// list of arguments.
LPWSTR GetFormattedMessage(LPWSTR pMessage, ...)
{
    LPWSTR pBuffer = NULL;

    va_list args = NULL;
    va_start(args, pMessage);

    FormatMessage(FORMAT_MESSAGE_FROM_STRING |
                  FORMAT_MESSAGE_ALLOCATE_BUFFER,
                  pMessage,
                  0,
                  0,
                  (LPWSTR)&pBuffer,
                  0,
                  &args);

    va_end(args);

    return pBuffer;
}

```

## See also

[Error Handling Functions](https://learn.microsoft.com/windows/desktop/Debug/error-handling-functions)

[Message Compiler](https://learn.microsoft.com/windows/desktop/WES/message-compiler--mc-exe-)

Message Tables