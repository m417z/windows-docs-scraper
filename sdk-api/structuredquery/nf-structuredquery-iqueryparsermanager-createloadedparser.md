# IQueryParserManager::CreateLoadedParser

## Description

Creates a new instance of a [IQueryParser](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iqueryparser) interface implementation. This instance of the query parser is loaded with the schema for the specified catalog and is localized to a specified language. All other settings are initialized to default settings.

## Parameters

### `pszCatalog` [in]

Type: **LPCWSTR**

The name of the catalog to use. Permitted values are `SystemIndex` and an empty string (for a trivial schema with no properties).

### `langidForKeywords` [in]

Type: **LANGID**

The [LANGID](https://learn.microsoft.com/windows/desktop/Intl/language-identifiers) used to select the localized language for keywords.

### `riid` [in]

Type: **REFIID**

The IID of the [IQueryParser](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iqueryparser) interface implementation.

### `ppQueryParser` [out, retval]

Type: **void****

Receives a pointer to the newly created parser. The calling application must release it by calling its [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If %LOCALAPPDATA% is not available, then this method fails. You should call [IQueryParserManager::SetOption](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-iqueryparsermanager-setoption) to point to a different folder like %ProgramData%.