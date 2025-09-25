# IEAPProviderConfig::ServerInvokeConfigUI

## Description

The system calls the **ServerInvokeConfigUI** method to invoke the configuration user interface for EAP authentication between a remote access client and server.

## Parameters

### `dwEapTypeId`

Specifies the EAP for which to invoke the configuration user interface.

### `uConnectionParam`

Specifies the configuration session for which to invoke the user interface.

### `hWnd`

Handle to the parent window for the configuration user interface.

### `uReserved1`

This parameter is reserved and should be zero.

### `uReserved2`

This parameter is reserved and should be zero.

## Return value

If the function succeeds, the return value should be **S_OK**.

If the function fails, the return value should be one of the following codes.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Non-specific error. |
| **E_INVALIDARG** | One of the arguments is invalid. |
| **E_OUTOFMEMORY** | The method failed because it was unable to allocate required memory. |
| **E_UNEXPECTED** | An unexpected error occurred. |

## Remarks

The DLL that implements
[IEAPProviderConfig](https://learn.microsoft.com/previous-versions/windows/desktop/api/rrascfg/nn-rrascfg-ieapproviderconfig) may support more than one authentication protocol. The *dwEapTypeId* parameter specifies for which authentication protocol to invoke the configuration user interface.

## See also

[EAP Interfaces](https://learn.microsoft.com/windows/win32/eap/eap-interfaces)

[Extensible Authentication Protocol Reference](https://learn.microsoft.com/windows/win32/eap/extensible-authentication-protocol-reference)

[IEAPProviderConfig](https://learn.microsoft.com/previous-versions/windows/desktop/api/rrascfg/nn-rrascfg-ieapproviderconfig)

[IEAPProviderConfig::Initialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/rrascfg/nf-rrascfg-ieapproviderconfig-initialize)

[IEAPProviderConfig::RouterInvokeConfigUI](https://learn.microsoft.com/previous-versions/windows/desktop/api/rrascfg/nf-rrascfg-ieapproviderconfig-routerinvokeconfigui)

[IEAPProviderConfig::RouterInvokeCredentialsUI](https://learn.microsoft.com/previous-versions/windows/desktop/api/rrascfg/nf-rrascfg-ieapproviderconfig-routerinvokecredentialsui)

[IEAPProviderConfig::Uninitialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/rrascfg/nf-rrascfg-ieapproviderconfig-uninitialize)