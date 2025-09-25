# IRelationship::DefaultPhrase

## Description

Retrieves the default phrase to use for this relationship in restatements.

## Parameters

### `ppszPhrase` [out, retval]

Type: **LPWSTR***

Receives the default phrase as a Unicode string. The calling application must free the string by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.