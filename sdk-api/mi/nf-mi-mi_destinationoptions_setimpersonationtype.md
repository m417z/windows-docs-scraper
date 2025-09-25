# MI_DestinationOptions_SetImpersonationType function

## Description

Sets the impersonation type.

## Parameters

### `options` [in, out]

A pointer to a [MI_DestinationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_destinationoptions) object returned from the [MI_Application_NewDestinationOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newdestinationoptions) function.

### `impersonationType` [in]

[MI_DestinationOptions_ImpersonationType](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_destinationoptions_impersonationtype) enumeration.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.