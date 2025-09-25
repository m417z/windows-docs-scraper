# WscGetSecurityProviderHealth function

## Description

Gets the aggregate health state of the security provider categories represented by the specified [WSC_SECURITY_PROVIDER](https://learn.microsoft.com/windows/desktop/api/wscapi/ne-wscapi-wsc_security_provider) enumeration values.

## Parameters

### `Providers` [in]

One or more of the values in the [WSC_SECURITY_PROVIDER](https://learn.microsoft.com/windows/desktop/api/wscapi/ne-wscapi-wsc_security_provider) enumeration. To specify more than one value, combine the individual values by performing a bitwise OR operation.

### `pHealth` [out]

A pointer to a variable that takes the value of one of the members of the [WSC_SECURITY_PROVIDER_HEALTH](https://learn.microsoft.com/windows/desktop/api/wscapi/ne-wscapi-wsc_security_provider_health) enumeration. If more than one provider is specified in the *Providers* parameter, the value of this parameter is the health of the least healthy of the specified provider categories.

## Return value

Returns **S_OK** if the function succeeds, otherwise returns an error code. If the WSC service is not running, the return value is always **S_FALSE** and the *pHealth* out parameter is always set to **WSC_SECURITY_PROVIDER_HEALTH_POOR**.

## Remarks

> [!NOTE]
> [WSC_SECURITY_PROVIDER::WSC_SECURITY_PROVIDER_ANTISPYWARE](https://learn.microsoft.com/windows/desktop/api/wscapi/ne-wscapi-wsc_security_provider) should be used only in operating systems prior to Windows 10, version 1607. As of Windows 10, version 1607, WSC continues to track the status for antivirus, but not for anti-spyware.

## See also

[WSC_SECURITY_PROVIDER_HEALTH](https://learn.microsoft.com/windows/desktop/api/wscapi/ne-wscapi-wsc_security_provider_health)