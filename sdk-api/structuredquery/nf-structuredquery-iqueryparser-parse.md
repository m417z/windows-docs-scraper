# IQueryParser::Parse

## Description

Parses an input string that contains Structured Query keywords and/or contents to produce an [IQuerySolution](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iquerysolution) object.

## Parameters

### `pszInputString` [in]

Type: **LPCWSTR**

A pointer to the Unicode input string to be parsed.

### `pCustomProperties` [in]

Type: **[IEnumUnknown](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumunknown)***

An enumeration of [IRichChunk](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-irichchunk) objects, one for each custom property the application has recognized. This parameter can be **NULL**, which is equivalent to an empty enumeration.

### `ppSolution` [out, retval]

Type: **[IQuerySolution](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iquerysolution)****

Receives an [IQuerySolution](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iquerysolution) object. The caller must release it by calling its [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For each [IRichChunk](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-irichchunk) object, the position information identifies the character span of the custom property, the string value is the name of an actual property, and the [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) is unused. Although any property could be used, these generic properties are included specifically for this purpose:

* System.StructuredQuery.CustomProperty.Boolean
* System.StructuredQuery.CustomProperty.DateTime
* System.StructuredQuery.CustomProperty.Integer
* System.StructuredQuery.CustomProperty.FloatingPoint
* System.StructuredQuery.CustomProperty.String

An application can use them in the enumeration passed in the *pCustomProperties* parameter and look for them in the resulting condition tree.