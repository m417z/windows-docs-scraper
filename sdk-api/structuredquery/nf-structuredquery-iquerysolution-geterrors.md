# IQuerySolution::GetErrors

## Description

Identifies parts of the input string that the parser did not recognize or did not use when constructing the [IQuerySolution](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iquerysolution) condition tree.

## Parameters

### `riid` [in]

Type: **REFIID**

The desired IID of the result, either IID_IEnumUnknown or IID_IEnumVARIANT.

### `ppParseErrors` [out, retval]

Type: **void****

Receives a pointer to an enumeration of zero or more [IRichChunk](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-irichchunk) objects, each describing one parsing error.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Each parsing error is represented by an [IRichChunk](https://learn.microsoft.com/windows/win32/api/structuredquery/ne-structuredquery-structured_query_parse_error) object in which the position information reflects token counts. The **IRichChunk** object *ppsz* string is **NULL**, and the *pValue* is a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) that contains a **lVal** identifying the [STRUCTURED_QUERY_PARSE_ERROR](https://learn.microsoft.com/windows/desktop/api/structuredquery/ne-structuredquery-structured_query_parse_error) enumeration.

The valid values for *riid* are __uuidof(IEnumUnknown) and __uuidof(IEnumVARIANT).