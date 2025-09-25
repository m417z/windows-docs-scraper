# IQueryParserManager::SetOption

## Description

Changes a single option in this [IQueryParserManager](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iqueryparsermanager) object. For example, this method could change the name of the schema binary to load or the location of localized schema binaries.

## Parameters

### `option` [in]

Type: **[QUERY_PARSER_MANAGER_OPTION](https://learn.microsoft.com/windows/win32/api/structuredquery/ne-structuredquery-query_parser_manager_option)**

The [QUERY_PARSER_MANAGER_OPTION](https://learn.microsoft.com/windows/win32/api/structuredquery/ne-structuredquery-query_parser_manager_option) to be changed.

### `pOptionValue` [in]

Type: **PROPVARIANT const***

A pointer to the value to use for the option selected.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.