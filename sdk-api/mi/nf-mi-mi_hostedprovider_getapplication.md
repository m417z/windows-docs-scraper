# MI_HostedProvider_GetApplication function

## Description

Gets the top-level application handle from which the hosted provider handle was created.

## Parameters

### `hostedProvider` [in]

Provider handle returned from [MI_Application_NewHostedProvider](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newhostedprovider).

### `application` [out]

Returned application handle. This handle does not need to be deleted as it is a copy.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.