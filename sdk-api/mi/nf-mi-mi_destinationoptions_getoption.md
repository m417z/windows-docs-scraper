# MI_DestinationOptions_GetOption function

## Description

Gets a previously added option value based on the option name.

## Parameters

### `options` [in]

[MI_DestinationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_destinationoptions) object returned from [MI_Application_NewDestinationOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newdestinationoptions).

### `optionName`

A null-terminated string that represents the name of the option to get.

### `value` [out]

The returned option value. This value is owned by the destination options object, so there is no need to delete it.

### `type` [out]

Returned option type.

### `index` [out, optional]

Returned zero-based index of the option.

### `flags` [out, optional]

Returned option flags.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.