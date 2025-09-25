# MI_Context_SetStringOption function

## Description

Sets a context-specific option.

## Parameters

### `context` [in]

Request context.

### `name`

A null-terminated string that represents the name of the option to change.

### `value`

A null-terminated string that represents the new value for the specified option.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

This function allows the provider to adjust the server's behavior.

On Windows Server 2012, this function only supports the "SECURITY" option, which is used only by an indication provider to control which users have permission to subscribe to the indication class. The function is valid if and only if it is called inside the indication class's *_Load function.

## See also

[MI_Context](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_context)

[MI_Context_GetCustomOption](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_getcustomoption)

[MI_Context_GetCustomOptionAt](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_getcustomoptionat)

[MI_Context_GetCustomOptionCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_getcustomoptioncount)

[MI_Context_GetNumberOption](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_getnumberoption)

[MI_Context_GetStringOption](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_getstringoption)