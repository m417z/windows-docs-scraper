# GetExceptionInformation macro

Retrieves a computer-independent description of an exception, and information about the computer state that exists for the thread when the exception occurs. This function can be called only from within the filter expression of an exception handler.

> [!Note]
> The Microsoft C/C++ Optimizing Compiler interprets this function as a keyword, and its use outside the appropriate exception-handling syntax generates a compiler error.

## Parameters

This macro has no parameters.

## Return value

A pointer to an [**EXCEPTION\_POINTERS**](https://learn.microsoft.com/windows/desktop/api/WinNT/ns-winnt-exception_pointers) structure that contains pointers to the following two structures:

- [**EXCEPTION\_RECORD**](https://learn.microsoft.com/windows/desktop/api/WinNT/ns-winnt-exception_record) structure that contains a description of the exception.
- [**CONTEXT**](https://learn.microsoft.com/windows/desktop/api/WinNT/ns-winnt-arm64_nt_context) structure that contains the computer state information.

## Remarks

The filter expression (from which the function is called) is evaluated if an exception occurs during execution of the **\_\_try** block, and it determines whether or not the **\_\_except** block is executed.

The filter expression can invoke a filter function. The filter function cannot call **GetExceptionInformation**. However, the return value of **GetExceptionInformation** can be passed as a parameter to a filter function.

To pass the [**EXCEPTION\_POINTERS**](https://learn.microsoft.com/windows/desktop/api/WinNT/ns-winnt-exception_pointers) information to the exception-handler block, the filter expression or filter function must copy the pointer or the data to safe storage that the handler can later access.

In the case of nested handlers, each filter expression is evaluated until one is evaluated as **EXCEPTION\_EXECUTE\_HANDLER** or **EXCEPTION\_CONTINUE\_EXECUTION**. Each filter expression can invoke **GetExceptionInformation** to get exception information.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |

## See also

[**CONTEXT**](https://learn.microsoft.com/windows/desktop/api/WinNT/ns-winnt-arm64_nt_context)

[**EXCEPTION\_POINTERS**](https://learn.microsoft.com/windows/desktop/api/WinNT/ns-winnt-exception_pointers)

[**EXCEPTION\_RECORD**](https://learn.microsoft.com/windows/desktop/api/WinNT/ns-winnt-exception_record)

[**GetExceptionCode**](https://learn.microsoft.com/windows/win32/debug/getexceptioncode)

[**GetXStateFeaturesMask**](https://learn.microsoft.com/windows/desktop/api/WinBase/nf-winbase-getxstatefeaturesmask)

[Structured Exception Handling Functions](https://learn.microsoft.com/windows/win32/debug/structured-exception-handling-functions)

[Structured Exception Handling Overview](https://learn.microsoft.com/windows/win32/debug/structured-exception-handling)

[Enable Windows Support for Intel AVX](https://learn.microsoft.com/windows/win32/win7appqual/enable-windows-7-support-for-intel-avx)

