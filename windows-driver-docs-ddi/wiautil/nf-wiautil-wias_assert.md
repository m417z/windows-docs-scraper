# WIAS_ASSERT macro (wiautil.h)

## Description

The WIAS_ASSERT macro writes a diagnostic message to the *Wiatrace.log* file.

## Parameters

### `x`

### `y`

- **Expression** - Specifies any logical expression.

- **HInst** - Handle to the DLL (driver).

## Remarks

The WIAS_ASSERT macro is used to debug WIA drivers. It is used to test that a certain condition is met. If the *Expression* parameter evaluates to *TRUE*, this macro does nothing. If *Expression* evaluates to *FALSE*, the macro prints an error string to the *Wiatrace.log* diagnostic log file. This error message will contain the name and path to the calling driver and the line number in the driver source code where the WIAS_ASSERT macro failed.

The WIAS_ASSERT macro is available in Windows Vista and later versions of the operating system. This macro is the recommended way to implement WIA assertions on Windows Vista. WIAS_ASSERT allows error messages to be written to the log file (*Wiatrace.log*). The *Wiatrace.log* file is only available in Windows Vista, and later versions of the operating system. The utility used to view the contents of this log file is *WiaTrcVw.exe*.

To enable asserts in free builds, drivers must define the WIA_DEBUG macro by adding `#define WIA_DEBUG` to the driver's source code; this must be done before including any of the WIA headers. Asserts are enabled by default in checked and debug builds of the operating system.

## See also

[WIAS_ERROR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wias_error)

[WIAS_HRESULT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wias_hresult)

[WIAS_TRACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wias_trace)