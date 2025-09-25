# RasEapFreeMemory function

## Description

The RAS connection manager calls
**RasEapFreeMemory** to free memory buffers returned by
[RasEapInvokeConfigUI](https://learn.microsoft.com/previous-versions/windows/desktop/api/raseapif/nf-raseapif-raseapinvokeconfigui),
[RasEapGetIdentity](https://learn.microsoft.com/previous-versions/windows/desktop/api/raseapif/nf-raseapif-raseapgetidentity), and
[RasEapInvokeInteractiveUI](https://learn.microsoft.com/previous-versions/windows/desktop/api/raseapif/nf-raseapif-raseapinvokeinteractiveui).

## Parameters

### `pMemory` [in]

Pointer to the memory to free.

## Return value

If the function succeeds, the return value is **NO_ERROR**.

If the function fails, the return value should be an appropriate error code from Winerror.h, Raserror.h, or Mprerror.h.

## Remarks

An authentication protocol may implement its various user interfaces in different DLLs. In such a case, each DLL must implement the
**RasEapFreeMemory** function.

It is also possible that a single DLL may implement multiple user interfaces. For example, a single DLL may implement both the configuration and identity user interface for an authentication protocol. Another example would be a DLL that implements two configuration user interfaces, each to support a different authentication protocol. In these cases, the DLL must implement a single version of
**RasEapFreeMemory** that can free memory returned from any of the user interfaces implemented in the DLL.

## See also

[EAP Functions](https://learn.microsoft.com/windows/win32/eap/eap-functions)

[Extensible Authentication Protocol Reference](https://learn.microsoft.com/windows/win32/eap/extensible-authentication-protocol-reference)

[RasEapGetIdentity](https://learn.microsoft.com/previous-versions/windows/desktop/api/raseapif/nf-raseapif-raseapgetidentity)

[RasEapInvokeConfigUI](https://learn.microsoft.com/previous-versions/windows/desktop/api/raseapif/nf-raseapif-raseapinvokeconfigui)

[RasEapInvokeInteractiveUI](https://learn.microsoft.com/previous-versions/windows/desktop/api/raseapif/nf-raseapif-raseapinvokeinteractiveui)