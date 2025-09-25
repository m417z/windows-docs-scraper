# MI_DestinationOptions_SetString function

## Description

Sets a custom string option.

## Parameters

### `options` [in, out]

A pointer to a [MI_DestinationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_destinationoptions) object returned from the [MI_Application_NewDestinationOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newdestinationoptions) function.

### `optionName`

A null-terminated string that represents the name of the option to set.

### `optionValue`

A null-terminated string that represents the new value of the option.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## See also

[MI_Application_NewDestinationOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newdestinationoptions)

[MI_DestinationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_destinationoptions)

[MI_DestinationOptions_GetString](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_destinationoptions_getstring)