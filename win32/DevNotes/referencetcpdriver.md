# ReferenceTcpDriver function

Obtains a reference to a TCP v4 driver object.

## Parameters

*ppDriverObject* \[out\]

A pointer to a **DRIVER\_OBJECT** structure. For more information, see the documentation for the WDK.

## Return value

If the function succeeds, it returns **STATUS\_SUCCESS**. If it fails, it will return the appropriate status code.

## Remarks

This function can be called only from kernel mode. The caller must decrement the reference count by calling the **ObDereferenceObject** function when it has finished with the object.

## Requirements

| Requirement | Value |
|--------------------|---------------------------------------------------------------------------------------|
| Library<br> | Drvref.lib |

## See also

[**ReferenceTcpDriverV6**](https://learn.microsoft.com/windows/win32/devnotes/referencetcpdriverv6)

