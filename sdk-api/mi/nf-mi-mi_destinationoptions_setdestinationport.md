# MI_DestinationOptions_SetDestinationPort function

## Description

Set the port to use to communicate to the destination.

## Parameters

### `options` [in, out]

A pointer to a [MI_DestinationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_destinationoptions) object returned from the [MI_Application_NewDestinationOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newdestinationoptions) function.

### `port`

Transport port used to communicate with the server.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

Not all transports and protocols will allow the port to be changed, in which case setting this option will be ignored. The default port used is transport-specific.

## See also

[MI_Application_NewDestinationOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newdestinationoptions)

[MI_DestinationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_destinationoptions)

[MI_DestinationOptions_GetDestinationPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_destinationoptions_getdestinationport)