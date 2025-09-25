# MI_DestinationOptions_SetDataLocale function

## Description

Sets the default data locale to use for operations.

## Parameters

### `options` [in, out]

A pointer to a [MI_DestinationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_destinationoptions) object returned from [MI_Application_NewDestinationOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newdestinationoptions).

### `locale`

A null-terminated string that represents the new data locale string (for example, "en-us").

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

Data locale represents the format of date strings, whether a dot or a comma is used in floating-point numbers, and a number of other locale specific data. By default, the data locale set on the impersonation thread will be used for the operation unless overridden via this function.

## See also

[MI_Application_NewDestinationOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newdestinationoptions)

[MI_DestinationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_destinationoptions)

[MI_DestinationOptions_GetDataLocale](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_destinationoptions_getdatalocale)