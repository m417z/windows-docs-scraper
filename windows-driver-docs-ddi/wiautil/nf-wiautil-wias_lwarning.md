# WIAS_LWARNING macro (wiautil.h)

## Description

The WIAS_LWARNING macro is obsolete.

The WIAS_LWARNING macro writes a diagnostic WIA_WARNING message to the log file.

## Parameters

### `x`

### `y`

### `params`

- **pIWiaLog** - Pointer to an [IWiaLog Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wia_lh/nn-wia_lh-iwialog).

- **lResId** - Specifies the resource ID. This value should be set to WIALOG_NO_RESOURCE_ID.

- **format_string, ...** - Specifies a variable argument list, which starts with an ANSI format string that describes the message and any format identifiers. The ellipsis (...) specifies a variable number of arguments that need to be output. The error text should be prefixed with the full name of the method or function and generate the message in the format of "class::method, error-text".

## Remarks

The following is an example of how the macro can be used:

```cpp
WIAS_LWARNING(g_pIWiaLog, WIALOG_NO_RESOURCE_ID, ("MyClass::MyMethod, This is my text and my lValue = %d", lValue));
```
Please note that the WIAS_LWARNING macro is obsolete and does not write to the log file used in modern Windows operation systems.

## See also

[WIAS_LERROR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wias_lerror)

[WIAS_LHRESULT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wias_lhresult)

[WIAS_LTRACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wias_ltrace)