# WIAS_TRACE macro (wiautil.h)

## Description

The WIAS_TRACE macro writes a diagnostic message to the*Wiatrace.log* file.

## Parameters

### `x`

- **HInst** - Handle to the DLL (driver).

- **format_string, ...** - Specifies a variable argument list, which starts with an ANSI format string that describes the message and any format identifiers. The ellipsis (...) specifies a variable number of arguments that need to be output. The error text should be prefixed with the full name of the method or function and generate the message in the format of "class::method, error-text".

## Remarks

To enable tracing in free builds, drivers must define the WIA_DEBUG macro by adding `#define WIA_DEBUG` before including any of the WIA headers. Tracing is enabled by default in checked and debug builds of the operating system.

The following is an example of how the macro would be used:

```cpp
WIAS_TRACE((g_hInst,"WIA storage path = %ws",m_wszStoragePath));
```

This code snippet was taken from*Wiadriver.cpp*, which is included with the WDK.

## See also

[WIAS_ASSERT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wias_assert)

[WIAS_ERROR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wias_error)

[WIAS_HRESULT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wias_hresult)