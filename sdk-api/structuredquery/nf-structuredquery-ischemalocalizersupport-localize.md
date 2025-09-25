# ISchemaLocalizerSupport::Localize

## Description

Localizes keywords from an input string.

## Parameters

### `pszGlobalString` [in]

Type: **LPCWSTR**

Pointer to a null-terminated Unicode string to be localized. It may be in one of two forms: (1) a set of keywords separated by the vertical bar character (Unicode character code 007C) (for example "date modified|modified|modification date"), or (2) a string of the form "@some.dll,-12345". This example refers to resource ID 12345 of the some.dll binary. That resource must be a string of the previous (1) form.

### `ppszLocalString` [out, retval]

Type: **LPWSTR***

Returns a null-terminated Unicode string that is the localized string. The calling application must free the returned string by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree). If the method does not succeed, this parameter is set to **NULL**.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or S_FALSE otherwise.