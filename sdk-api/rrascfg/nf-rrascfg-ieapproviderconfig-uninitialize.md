# IEAPProviderConfig::Uninitialize

## Description

The system calls the **Uninitialize** method to shut down the specified EAP configuration session.

## Parameters

### `dwEapTypeId`

Specifies the EAP for which to shut down the configuration session.

### `uConnectionParam`

Specifies the configuration session to shut down.

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

The configuration UI should allow the user to configure the EAP provider on a remote computer. Delete the connection to the remote computer during the call to **Uninitialize**.

The DLL that implements
[IEAPProviderConfig](https://learn.microsoft.com/previous-versions/windows/desktop/api/rrascfg/nn-rrascfg-ieapproviderconfig) may support more than one authentication protocol. The *dwEapTypeId* parameter specifies the authentication protocol to shut down the configuration session for.

## See also

[EAP Interfaces](https://learn.microsoft.com/windows/win32/eap/eap-interfaces)

[Extensible Authentication Protocol Reference](https://learn.microsoft.com/windows/win32/eap/extensible-authentication-protocol-reference)

[IEAPProviderConfig](https://learn.microsoft.com/previous-versions/windows/desktop/api/rrascfg/nn-rrascfg-ieapproviderconfig)

[IEAPProviderConfig::Initialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/rrascfg/nf-rrascfg-ieapproviderconfig-initialize)

[IEAPProviderConfig::RouterInvokeConfigUI](https://learn.microsoft.com/previous-versions/windows/desktop/api/rrascfg/nf-rrascfg-ieapproviderconfig-routerinvokeconfigui)

[IEAPProviderConfig::RouterInvokeCredentialsUI](https://learn.microsoft.com/previous-versions/windows/desktop/api/rrascfg/nf-rrascfg-ieapproviderconfig-routerinvokecredentialsui)

[IEAPProviderConfig::ServerInvokeConfigUI](https://learn.microsoft.com/previous-versions/windows/desktop/api/rrascfg/nf-rrascfg-ieapproviderconfig-serverinvokeconfigui)