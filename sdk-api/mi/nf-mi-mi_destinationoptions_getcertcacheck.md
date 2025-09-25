# MI_DestinationOptions_GetCertCACheck function

## Description

Gets the server certificate CA check value.

## Parameters

### `options` [in]

[MI_DestinationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_destinationoptions) object returned from [MI_Application_NewDestinationOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newdestinationoptions).

### `check` [out]

Returned Boolean value indicating if the CA value will be checked (**MI_TRUE**) or not (**MI_FALSE**).

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

All getters only return information that was previously added by the client. This is appropriate to all the getters of destination and operation options.