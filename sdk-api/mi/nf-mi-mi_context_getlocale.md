# MI_Context_GetLocale function

## Description

Retrieves the requested locale information that the client specified for the operation.

## Parameters

### `context` [in]

A pointer to the request context.

### `localeType`

The type of locale to be returned.

### `locale`

The returned locale.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

There are two types of locale: UI and Data. UI relates to the language of strings. Data relates to data formatting, such as date/time formats in strings and whether a decimal point or some other separator is used.