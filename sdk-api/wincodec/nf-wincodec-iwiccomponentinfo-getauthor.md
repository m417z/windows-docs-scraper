# IWICComponentInfo::GetAuthor

## Description

Retrieves the name of component's author.

## Parameters

### `cchAuthor` [in]

Type: **UINT**

The size of the *wzAuthor* buffer.

### `wzAuthor` [in, out]

Type: **WCHAR***

A pointer that receives the name of the component's author.
The locale of the string depends on the value that the codec wrote to the registry at install time. For built-in components, these strings are always in English.

### `pcchActual` [out]

Type: **UINT***

A pointer that receives the actual length of the component's authors name. The author name is optional; if an author name is not specified by the component, the length returned is 0.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If *cchAuthor* is 0 and *wzAuthor* is **NULL**, the required buffer size is returned in *pccchActual*.