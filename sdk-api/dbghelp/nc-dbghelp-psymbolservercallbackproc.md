# PSYMBOLSERVERCALLBACKPROC callback function

## Description

An entry point to the symbol server DLL.

The **PSYMBOLSERVERCALLBACKPROC** type defines a pointer to this callback function.
*SymbolServerCallback* is a placeholder for the library-defined function name.

## Parameters

### `action` [in]

The action code. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SSRVACTION_EVENT**<br><br>3 | Provide debug trace information. The *data* parameter is a pointer to an [IMAGEHLP_CBA_EVENT](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_cba_event) structure.<br><br>**DbgHelp 6.0 and earlier:** This value is not supported. |
| **SSRVACTION_QUERYCANCEL**<br><br>2 | Cancel the file copy. The *data* parameter is a **ULONG64** value. If this value is zero, continue the operation. Otherwise, cancel the operation.<br><br>**DbgHelp 6.0 and earlier:** This value is not supported. |
| **SSRVACTION_SIZE**<br><br>5 | The *data* parameter is the size of the file to be provided by the system. |
| **SSRVACTION_TRACE**<br><br>1 | Provide debug trace information. The *data* parameter is a text string. |

### `data` [in]

The format of this parameter depends on the value of the *action* parameter.

### `context` [in]

The context information provided by calling [SymbolServerSetOptions](https://learn.microsoft.com/previous-versions/ff797954(v=vs.85)) with SSRVOPT_SETCONTEXT.

## Return value

To indicate success, return **TRUE**.

To indicate failure, return **FALSE** and call the
[SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) function to indicate an error condition. If you do not handle a particular action code, you should also return **FALSE**. (Returning **TRUE** in this case may have unintended consequences.)

## See also

[DbgHelp
Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[IMAGEHLP_CBA_EVENT](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-imagehlp_cba_event)