# IEAPProviderConfig::Initialize

## Description

The system calls the **Initialize** method to initialize an EAP configuration session with the specified computer.

## Parameters

### `pszMachineName`

Pointer to a null-terminated string that contains the name of the computer on which to configure EAP. String length is not limited.

### `dwEapTypeId`

Specifies the EAP for which to initialize a configuration session.

### `puConnectionParam`

Pointer to an unsigned integer variable. On successful return, the value of this variable identifies this configuration session.

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

The configuration UI should allow the user to configure the EAP provider on a remote computer. Establish the connection to the remote computer during the call to **Initialize**.

The DLL that implements
[IEAPProviderConfig](https://learn.microsoft.com/previous-versions/windows/desktop/api/rrascfg/nn-rrascfg-ieapproviderconfig) can support more than one authentication protocol. The *dwEapTypeId* parameter specifies the authentication protocol to initialize a configuration session for.

## See also

[EAP Interfaces](https://learn.microsoft.com/windows/win32/eap/eap-interfaces)

[Extensible Authentication Protocol Reference](https://learn.microsoft.com/windows/win32/eap/extensible-authentication-protocol-reference)

[IEAPProviderConfig](https://learn.microsoft.com/previous-versions/windows/desktop/api/rrascfg/nn-rrascfg-ieapproviderconfig)

[IEAPProviderConfig::RouterInvokeConfigUI](https://learn.microsoft.com/previous-versions/windows/desktop/api/rrascfg/nf-rrascfg-ieapproviderconfig-routerinvokeconfigui)

[IEAPProviderConfig::RouterInvokeCredentialsUI](https://learn.microsoft.com/previous-versions/windows/desktop/api/rrascfg/nf-rrascfg-ieapproviderconfig-routerinvokecredentialsui)

[IEAPProviderConfig::ServerInvokeConfigUI](https://learn.microsoft.com/previous-versions/windows/desktop/api/rrascfg/nf-rrascfg-ieapproviderconfig-serverinvokeconfigui)

[IEAPProviderConfig::Uninitialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/rrascfg/nf-rrascfg-ieapproviderconfig-uninitialize)