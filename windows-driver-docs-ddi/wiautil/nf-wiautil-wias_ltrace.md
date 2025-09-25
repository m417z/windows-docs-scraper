# WIAS_LTRACE macro (wiautil.h)

## Description

The WIAS_LTRACE macro is obsolete. It is recommended that the [WIAS_TRACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wias_trace) macro be used instead.

The WIAS_LTRACE macro writes a diagnostic WIA_TRACE message to the log file.

## Parameters

### `x`

### `y`

### `z`

### `params`

- **DetailLevel** - Specifies the diagnostic detail level of the message. This parameter can be one of the following values.

 | Value | Description |
| --- | --- |
| WIALOG_LEVEL1 | Logs entry and exit points for all WIA methods and functions. |
| WIALOG_LEVEL2 | Logs additional details for WIALOG_LEVEL1. |
| WIALOG_LEVEL3 | Logs entry and exit points for all WIA methods and functions and additional vendor-supplied functions. |
| WIALOG_LEVEL4 | Logs additional details for WIALOG_LEVEL3. |
| WIALOG_LEVELXXX | User-defined log levels. |

- **ResourceID** - Specifies the resource ID. This value should be set to WIALOG_NO_RESOURCE_ID.

- **format_string** - Specifies a variable argument list, which starts with an ANSI format string describing the message and any format identifiers. The ellipsis (...) specifies a variable number of arguments that need to be output. The error text should be prefixed with the full name of the method or function and generate the message in the format of "class::method, error-text".

- **pIWiaLog** - Pointer to an [IWiaLog Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wia_lh/nn-wia_lh-iwialog).

## Remarks

The following is an example of how the macro can be used:

```cpp
WIAS_LTRACE(g_pIWiaLog, WIALOG_NO_RESOURCE_ID, WIALOG_LEVEL2,
  ("MyClass::MyMethod, This is my text and my lValue = %d", lValue));
```

Use of the WIAS_LTRACE macro is not recommended because it does not record its output to the *Wiatrace.log* diagnostic log file. It is recommended that the [WIAS_TRACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wias_trace) macro be used instead.

## See also

[WIAS_LERROR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wias_lerror)

[WIAS_LHRESULT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wias_lhresult)

[WIAS_LWARNING](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wias_lwarning)

[WIAS_TRACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wias_trace)