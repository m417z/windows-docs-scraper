# WIAS_HRESULT macro (wiautil.h)

## Description

The WIAS_HRESULT macro writes a diagnostic message to the *Wiatrace.log* file.

## Parameters

### `x`

- **hInstance** - Handle to the calling driver.

- **hr** - Specifies the HRESULT value to be printed.

## Remarks

This macro is the recommended way to output HRESULTS on Windows Vista.

## See also

[WIAS_ASSERT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wias_assert)

[WIAS_ERROR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wias_error)

[WIAS_TRACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamdef/nf-wiamdef-wias_trace)