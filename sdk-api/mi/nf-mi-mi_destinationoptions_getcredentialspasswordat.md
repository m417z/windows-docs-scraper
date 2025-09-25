# MI_DestinationOptions_GetCredentialsPasswordAt function

## Description

Gets a credentials password based on a specified index.

## Parameters

### `options` [in]

[MI_DestinationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_destinationoptions) object returned from [MI_Application_NewDestinationOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newdestinationoptions).

### `index`

Zero-based index of the credentials password.

### `optionName`

A pointer to a null-terminated string containing the returned name of the option.

### `password`

Returned password. This memory should be freed for security purposes when finished.

### `bufferLength` [in]

Length of the **password** buffer. If 0, the **passwordLength** parameter will contain the buffer size needed to hold the password.

### `passwordLength` [out]

Returned amount of the **password** buffer used, including the null terminator.

### `flags` [out, optional]

Returned option flags.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

Passwords should not be stored in memory for long periods of time in an unencrypted manner, as there are ways to snoop for them. After using the password, call the [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)) function to clear out the password before deleting it.