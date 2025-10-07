# EPrintXPSJobOperation enumeration

Specifies whether an XPS print job is in the spooling or the rendering phase.

## Constants

**kJobProduction**

The XPS job is spooling.

**kJobConsumption**

The XPS job is rendering.

## Remarks

This enumeration is primarily used as a parameter for the [**ReportJobProcessingProgress**](https://learn.microsoft.com/windows/win32/printdocs/reportjobprocessingprogress) function.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |

