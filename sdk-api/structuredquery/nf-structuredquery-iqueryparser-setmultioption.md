# IQueryParser::SetMultiOption

## Description

Sets a complex option, such as a specified condition generator, to use when parsing an input string.

## Parameters

### `option` [in]

Type: **[STRUCTURED_QUERY_MULTIOPTION](https://learn.microsoft.com/windows/win32/api/structuredquery/ne-structuredquery-structured_query_multioption)**

The complex option to be set.

### `pszOptionKey` [in]

Type: **LPCWSTR**

A Unicode string that is interpreted differently for each value of the *option* parameter. For more information, see [STRUCTURED_QUERY_MULTIOPTION](https://learn.microsoft.com/windows/win32/api/structuredquery/ne-structuredquery-structured_query_multioption).

### `pOptionValue` [in]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

Pointer to a [PROPVARIANT](https://learn.microsoft.com/windows/win32/api/structuredquery/ne-structuredquery-structured_query_multioption) that is interpreted differently for each value of the *option* parameter. For more information, see [STRUCTURED_QUERY_MULTIOPTION](https://learn.microsoft.com/windows/desktop/api/structuredquery/ne-structuredquery-structured_query_multioption).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.