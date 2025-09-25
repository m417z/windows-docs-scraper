# WIAS_ERROR macro (wiamdef.h)

## Description

The WIAS_ERROR macro writes a diagnostic message to the *Wiatrace.log* file.

## Parameters

### `x`

- **HInst** - Handle to the DLL (driver).

- **format_string, ...** - Specifies a variable argument list, which starts with an ANSI format string that describes the message and any format identifiers. The ellipsis (...) specifies a variable number of arguments that need to be output. The error text should be prefixed with the full name of the method or function and generate the message in the format of "class::method, error-text".

## Remarks

This macro is the recommended way to implement error logging, because unlike [WIAS_LERROR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wias_lerror), WIA_ERROR allows error messages to be written to the log file (*Wiatrace.log*). The utility used to view the contents of this log file is WiaTrcVw.exe.

To enable tracing in free builds, drivers must define the WIA_DEBUG macro by adding `#define WIA_DEBUG` before including any of the WIA headers. Tracing is enabled by default in checked and debug builds of the operating system.

The following is an example of how the macro can be used:

```cpp
WIAS_ERROR((g_hInst, "Failed to read (%ws) entry under %ws section of device registry",REG_ENTRY_STORAGEPATH,REG_ENTRY_DEVICEDATA));
```

This code snippet was taken from [Wiadriver.cpp](https://github.com/Microsoft/Windows-driver-samples/blob/master/wia/wiadriverex/usd/wiadriver.cpp), which is included with the Windows Image Acquisition (WIA) driver samples on GitHub.

## See also

[WIAS_ASSERT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wias_assert)

[WIAS_HRESULT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wias_hresult)

[WIAS_TRACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wias_trace)