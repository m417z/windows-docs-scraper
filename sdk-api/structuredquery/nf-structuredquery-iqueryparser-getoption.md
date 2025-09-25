# IQueryParser::GetOption

## Description

Retrieves a specified simple option value for this query parser.

## Parameters

### `option` [in]

Type: **[STRUCTURED_QUERY_SINGLE_OPTION](https://learn.microsoft.com/windows/win32/api/structuredquery/ne-structuredquery-structured_query_single_option)**

The [STRUCTURED_QUERY_SINGLE_OPTION](https://learn.microsoft.com/windows/win32/api/structuredquery/ne-structuredquery-structured_query_single_option) enumerated type that specifies the option to be retrieved.

### `pOptionValue` [out, retval]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

Receives a pointer to the specified option value. For more information, see [STRUCTURED_QUERY_SINGLE_OPTION](https://learn.microsoft.com/windows/win32/api/structuredquery/ne-structuredquery-structured_query_single_option).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.