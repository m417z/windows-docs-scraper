# MI_DestinationOptions_SetTimeout function

## Description

Sets the default options timeout value.

## Parameters

### `options` [in, out]

A pointer to a [MI_DestinationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_destinationoptions) object returned from the [MI_Application_NewDestinationOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newdestinationoptions) function.

### `timeout` [in]

A pointer to the new timeout value.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

If you need to run an operation that takes longer than usual, you can call the [MI_OperationOptions_SetTimeout](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operationoptions_settimeout) function to override the default timeout value.

## See also

[MI_Application_NewDestinationOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newdestinationoptions)

[MI_DestinationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_destinationoptions)

[MI_DestinationOptions_GetTimeout](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_destinationoptions_gettimeout)

[MI_Interval](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_interval)

[MI_OperationOptions_SetTimeout](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operationoptions_settimeout)