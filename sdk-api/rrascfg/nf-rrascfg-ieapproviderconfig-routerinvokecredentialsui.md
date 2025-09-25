# IEAPProviderConfig::RouterInvokeCredentialsUI

## Description

The system calls the **RouterInvokeCredentialsUI** method to invoke the credentials user interface for EAP authentication between two routers.

## Parameters

### `dwEapTypeId`

Specifies the EAP for which to invoke the configuration user interface.

### `uConnectionParam`

Specifies the configuration session for which to invoke the user interface.

### `hwndParent`

Handle to the parent window for the configuration user interface.

### `dwFlags`

Specifies the RAS_EAP_FLAG_ROUTER flag. This is the only valid flag for this parameter. It indicates that authentication is between two routers. This parameter always includes this flag.

### `pConnectionDataIn`

Pointer to the current configuration data for the interface.

### `dwSizeOfConnectionDataIn`

Specifies the size of the current configuration data pointed to by the *pConnectionDataIn* parameter.

### `pUserDataIn`

Pointer to the current credential data for the interface.

### `dwSizeOfUserDataIn`

Specifies the size of the current credentials data.

### `ppUserDataOut`

Pointer to a pointer to a buffer to receive the new credentials data for the interface.

### `pdwSizeOfUserDataOut`

Pointer to a **DWORD** variable to receive the size of the new credentials data.

## Return value

If the function succeeds, the return value should be **S_OK**.

If the function fails, the return value should be one of the following codes.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Non-specific error. |
| **E_INVALIDARG** | One of the arguments is invalid. |
| **E_OUTOFMEMORY** | The method failed because it was unable to allocate the required memory. |
| **E_UNEXPECTED** | An unexpected error occurred. |

## See also

[EAP Interfaces](https://learn.microsoft.com/windows/win32/eap/eap-interfaces)

[Extensible Authentication Protocol Reference](https://learn.microsoft.com/windows/win32/eap/extensible-authentication-protocol-reference)

[IEAPProviderConfig](https://learn.microsoft.com/previous-versions/windows/desktop/api/rrascfg/nn-rrascfg-ieapproviderconfig)

[IEAPProviderConfig::Initialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/rrascfg/nf-rrascfg-ieapproviderconfig-initialize)

[IEAPProviderConfig::RouterInvokeConfigUI](https://learn.microsoft.com/previous-versions/windows/desktop/api/rrascfg/nf-rrascfg-ieapproviderconfig-routerinvokeconfigui)

[IEAPProviderConfig::ServerInvokeConfigUI](https://learn.microsoft.com/previous-versions/windows/desktop/api/rrascfg/nf-rrascfg-ieapproviderconfig-serverinvokeconfigui)

[IEAPProviderConfig::Uninitialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/rrascfg/nf-rrascfg-ieapproviderconfig-uninitialize)