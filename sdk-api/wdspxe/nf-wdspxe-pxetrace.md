# PxeTrace function

## Description

Adds a trace entry to the PXE log.

## Parameters

### `hProvider` [in]

**HANDLE** passed to the
[PxeProviderInitialize](https://learn.microsoft.com/windows/desktop/Wds/pxeproviderinitialize) function.

### `Severity` [in]

Severity of trace entry.

| Value | Meaning |
| --- | --- |
| **PXE_TRACE_VERBOSE**<br><br>0x00010000 | The trace entry is verbose and would primarily be useful when debugging. |
| **PXE_TRACE_INFO**<br><br>0x00020000 | The trace entry is informational, but does not indicate a warning condition. |
| **PXE_TRACE_WARNING**<br><br>0x00040000 | The trace message indicates a warning. |
| **PXE_TRACE_ERROR**<br><br>0x00080000 | The trace message indicates an error condition. |
| **PXE_TRACE_FATAL**<br><br>0x00100000 | The trace message indicates a fatal error condition. |

### `pszFormat` [in]

Address of a buffer that contains a printf-style format string.

### `...`

Optional arguments. The number and type of argument parameters depend on the format control string pointed
to by the *pszFormat* parameter.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

## See also

[PxeProviderInitialize](https://learn.microsoft.com/windows/desktop/Wds/pxeproviderinitialize)

[Windows Deployment Services Server Functions](https://learn.microsoft.com/windows/desktop/Wds/windows-deployment-services-server-functions)