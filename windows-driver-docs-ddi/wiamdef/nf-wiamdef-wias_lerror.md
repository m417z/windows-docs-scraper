# WIAS_LERROR macro (wiamdef.h)

## Description

The WIAS_LERROR macro is obsolete. It is recommended that the [WIAS_ERROR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wias_error) macro be used instead.

The WIAS_LERROR macro writes a diagnostic WIA_ERROR message to the log file.

## Parameters

### `pILog`

Pointer to an [IWiaLog Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wia_lh/nn-wia_lh-iwialog).

### `ResID`

Specifies the resource ID. This value should be set to WIALOG_NO_RESOURCE_ID.

### `Args`

**format_string, ...** - Specifies a variable argument list, which starts with an ANSI format string that describes the message and any format identifiers. The ellipsis (...) specifies a variable number of arguments that need to be output. The error text should be prefixed with the full name of the method or function and generate the message in the format of "class::method, error-text".

## Remarks

The following is an example of how the macro can be used:

```cpp
WIAS_LERROR(g_pIWiaLog, WIALOG_NO_RESOURCE_ID, ("MyClass::MyMethod, This is my text and my lValue = %d", lValue));
```

The WIAS_LERROR macro is obsolete and not recommended for use because it does not record its output to the *Wiatrace.log* diagnostic log file. It is recommended that the [WIAS_ERROR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wias_error) macro be used instead.

## See also

[WIAS_ERROR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wias_error)

[WIAS_LHRESULT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wias_lhresult)

[WIAS_LTRACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wias_ltrace)

[WIAS_LWARNING](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wias_lwarning)