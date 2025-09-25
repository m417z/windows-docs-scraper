# IQueryParser::SetOption

## Description

Sets a single option, such as a specified wordbreaker, for parsing an input string.

## Parameters

### `option` [in]

Type: **[STRUCTURED_QUERY_SINGLE_OPTION](https://learn.microsoft.com/windows/win32/api/structuredquery/ne-structuredquery-structured_query_single_option)**

Identifies the type of option to be set.

### `pOptionValue` [in]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

Pointer to a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) specifying the value to set for the *option* parameter. This value is interpreted differently depending on the value of the *option* parameter.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For more information, see [STRUCTURED_QUERY_SINGLE_OPTION](https://learn.microsoft.com/windows/win32/api/structuredquery/ne-structuredquery-structured_query_single_option).