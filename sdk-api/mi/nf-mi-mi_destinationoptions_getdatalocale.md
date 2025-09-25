# MI_DestinationOptions_GetDataLocale function

## Description

Gets the data locale (as opposed to UI locale) set by the user.

## Parameters

### `options` [in]

[MI_DestinationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_destinationoptions) object returned from [MI_Application_NewDestinationOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newdestinationoptions).

### `locale`

A pointer to a null-terminated string containing the returned data locale. The memory is owned by the destination options object, so it does not need to be deleted.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

The data locale determines string formats for entities such as decimal numbers in string format and date/time formats.