# MI_DestinationOptions_GetNumber function

## Description

Gets a previously added custom number option.

## Parameters

### `options` [in]

[MI_DestinationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_destinationoptions) object returned from [MI_Application_NewDestinationOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newdestinationoptions).

### `optionName`

A null-terminated string that represents the name of the option to get.

### `optionValue` [out]

Returned option value.

### `index` [out, optional]

Returned zero-based index of the option.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.