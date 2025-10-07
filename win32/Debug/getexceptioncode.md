# GetExceptionCode macro

Retrieves a code that identifies the type of exception that occurs. The function can be called only from within the filter expression or exception-handler block of an exception handler.

> [!Note]
> The Microsoft C/C++ Optimizing Compiler interprets this function as a keyword, and its use outside the appropriate exception-handling syntax generates a compiler error.

## Parameters

This macro has no parameters.

## Return value

The return value identifies the type of exception. The following table identifies the exception codes that can occur due to common programming errors. These values are defined in WinBase.h and WinNT.h.

| Return code | Description |
|---------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **EXCEPTION\_ACCESS\_VIOLATION** | The thread attempts to read from or write to a virtual address for which it does not have access.<br> This value is defined as STATUS\_ACCESS\_VIOLATION.<br> |
| **EXCEPTION\_ARRAY\_BOUNDS\_EXCEEDED** | The thread attempts to access an array element that is out of bounds, and the underlying hardware supports bounds checking.<br> This value is defined as STATUS\_ARRAY\_BOUNDS\_EXCEEDED.<br> |
| **EXCEPTION\_BREAKPOINT** | A breakpoint is encountered.<br> This value is defined as STATUS\_BREAKPOINT.<br> |
| **EXCEPTION\_DATATYPE\_MISALIGNMENT** | The thread attempts to read or write data that is misaligned on hardware that does not provide alignment. For example, 16-bit values must be aligned on 2-byte boundaries, 32-bit values on 4-byte boundaries, and so on.<br> This value is defined as STATUS\_DATATYPE\_MISALIGNMENT.<br> |
| **EXCEPTION\_FLT\_DENORMAL\_OPERAND** | One of the operands in a floating point operation is denormal. A denormal value is one that is too small to represent as a standard floating point value.<br> This value is defined as STATUS\_FLOAT\_DENORMAL\_OPERAND.<br> |
| **EXCEPTION\_FLT\_DIVIDE\_BY\_ZERO** | The thread attempts to divide a floating point value by a floating point divisor of 0 (zero).<br> This value is defined as STATUS\_FLOAT\_DIVIDE\_BY\_ZERO.<br> |
| **EXCEPTION\_FLT\_INEXACT\_RESULT** | The result of a floating point operation cannot be represented exactly as a decimal fraction.<br> This value is defined as STATUS\_FLOAT\_INEXACT\_RESULT.<br> |
| **EXCEPTION\_FLT\_INVALID\_OPERATION** | A floating point exception that is not included in this list.<br> This value is defined as STATUS\_FLOAT\_INVALID\_OPERATION.<br> |
| **EXCEPTION\_FLT\_OVERFLOW** | The exponent of a floating point operation is greater than the magnitude allowed by the corresponding type.<br> This value is defined as STATUS\_FLOAT\_OVERFLOW.<br> |
| **EXCEPTION\_FLT\_STACK\_CHECK** | The stack has overflowed or underflowed, because of a floating point operation.<br> This value is defined as STATUS\_FLOAT\_STACK\_CHECK.<br> |
| **EXCEPTION\_FLT\_UNDERFLOW** | The exponent of a floating point operation is less than the magnitude allowed by the corresponding type.<br> This value is defined as STATUS\_FLOAT\_UNDERFLOW.<br> |
| **EXCEPTION\_GUARD\_PAGE** | The thread accessed memory allocated with the PAGE\_GUARD modifier.<br> This value is defined as STATUS\_GUARD\_PAGE\_VIOLATION.<br> |
| **EXCEPTION\_ILLEGAL\_INSTRUCTION** | The thread tries to execute an invalid instruction.<br> This value is defined as STATUS\_ILLEGAL\_INSTRUCTION.<br> |
| **EXCEPTION\_IN\_PAGE\_ERROR** | The thread tries to access a page that is not present, and the system is unable to load the page. For example, this exception might occur if a network connection is lost while running a program over a network.<br> This value is defined as STATUS\_IN\_PAGE\_ERROR.<br> |
| **EXCEPTION\_INT\_DIVIDE\_BY\_ZERO** | The thread attempts to divide an integer value by an integer divisor of 0 (zero).<br> This value is defined as STATUS\_INTEGER\_DIVIDE\_BY\_ZERO.<br> |
| **EXCEPTION\_INT\_OVERFLOW** | The result of an integer operation creates a value that is too large to be held by the destination register. In some cases, this will result in a carry out of the most significant bit of the result. Some operations do not set the carry flag.<br> This value is defined as STATUS\_INTEGER\_OVERFLOW.<br> |
| **EXCEPTION\_INVALID\_DISPOSITION** | An exception handler returns an invalid disposition to the exception dispatcher. Programmers using a high-level language such as C should never encounter this exception.<br> This value is defined as STATUS\_INVALID\_DISPOSITION.<br> |
| **EXCEPTION\_INVALID\_HANDLE** | The thread used a handle to a kernel object that was invalid (probably because it had been closed.)<br> This value is defined as STATUS\_INVALID\_HANDLE.<br> |
| **EXCEPTION\_NONCONTINUABLE\_EXCEPTION** | The thread attempts to continue execution after a non-continuable exception occurs.<br> This value is defined as STATUS\_NONCONTINUABLE\_EXCEPTION.<br> |
| **EXCEPTION\_PRIV\_INSTRUCTION** | The thread attempts to execute an instruction with an operation that is not allowed in the current computer mode.<br> This value is defined as STATUS\_PRIVILEGED\_INSTRUCTION.<br> |
| **EXCEPTION\_SINGLE\_STEP** | A trace trap or other single instruction mechanism signals that one instruction is executed.<br> This value is defined as STATUS\_SINGLE\_STEP.<br> |
| **EXCEPTION\_STACK\_OVERFLOW** | The thread uses up its stack.<br> This value is defined as STATUS\_STACK\_OVERFLOW.<br> |
| **STATUS\_UNWIND\_CONSOLIDATE** | A frame consolidation has been executed.<br> |

## Remarks

The **GetExceptionCode** function can be called only from within the filter expression or exception-handler block of an exception handler. The filter expression is evaluated if an exception occurs during execution of the **\_\_try** block, and it determines whether or not the **\_\_except** block is executed.

The filter expression can invoke a filter function. The filter function cannot call **GetExceptionCode**. However, the return value of **GetExceptionCode** can be passed as a parameter to a filter function. The return value of the [**GetExceptionInformation**](https://learn.microsoft.com/windows/win32/debug/getexceptioninformation) function can also be passed as a parameter to a filter function. **GetExceptionInformation** returns a pointer to a structure that includes the exception code information.

When nested handlers exist, each filter expression is evaluated until one is evaluated as EXCEPTION\_EXECUTE\_HANDLER or EXCEPTION\_CONTINUE\_EXECUTION. Each filter expression can invoke **GetExceptionCode** to get the exception code.

The exception code returned is the code generated by a hardware exception, or the code specified in the [**RaiseException**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-raiseexception) function for a software generated exception.

When handling the breakpoint exception, it is important to increment the instruction pointer in the context record to continue from this exception.

## Examples

For an example, see [Using an Exception Handler](https://learn.microsoft.com/windows/win32/debug/using-an-exception-handler).

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |

## See also

[**GetExceptionInformation**](https://learn.microsoft.com/windows/win32/debug/getexceptioninformation)

[**RaiseException**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-raiseexception)

[Structured Exception Handling Functions](https://learn.microsoft.com/windows/win32/debug/structured-exception-handling-functions)

[Structured Exception Handling Overview](https://learn.microsoft.com/windows/win32/debug/structured-exception-handling)

