# MI_DestinationOptions_GetCredentialsAt function

## Description

Get the credentials at the specified index.

## Parameters

### `options` [in]

[MI_DestinationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_destinationoptions) object returned from [MI_Application_NewDestinationOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newdestinationoptions).

### `index`

Zero-based index of the credentials.

### `optionName`

Returned name of the credentials option.

### `credentials` [out]

Returned [MI_UserCredentials](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_usercredentials) structure. If the credentials include a password, it will be filled with 6 asterisks for security purposes.

### `flags` [out, optional]

Returned credentials option flags.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.