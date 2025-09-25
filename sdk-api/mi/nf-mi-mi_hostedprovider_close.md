# MI_HostedProvider_Close function

## Description

Close a hosted provider handle that was returned from [MI_Application_NewHostedProvider](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newhostedprovider).

## Parameters

### `hostedProvider` [in, out]

A pointer to a provider handle returned from the [MI_Application_NewHostedProvider](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newhostedprovider) function.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

When this function returns, no new calls will enter the provider.

## See also

[MI_Application_NewHostedProvider](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newhostedprovider)

[MI_HostedProvider_GetApplication](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_hostedprovider_getapplication)