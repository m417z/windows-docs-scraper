# MI_DestinationOptions_GetOptionAt function

## Description

Gets a previously added option value based on the specified index.

## Parameters

### `options` [in]

[MI_DestinationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_destinationoptions) object returned from [MI_Application_NewDestinationOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newdestinationoptions).

### `index`

Zero-based index of the option.

### `optionName`

A pointer to a null-terminated string containing the returned option name.

### `value` [out]

Returned option value. This value is owned by the destination options object, so there is no need to delete it.

### `type` [out]

Returned option type.

### `flags` [out, optional]

Returned flags.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.