# IItemNameLimits::GetValidCharacters

## Description

Loads a string that contains each of the characters that are valid or invalid in the namespace under which it is called.

## Parameters

### `ppwszValidChars` [out]

Type: **LPWSTR***

A pointer to a string that contains all valid characters in the namespace. If the namespace provides *any* invalid characters in *ppwszInvalidChars*, then this value returns **NULL**. See Remarks for more details.

### `ppwszInvalidChars` [out]

Type: **LPWSTR***

A pointer to a string that contains all invalid characters in the namespace.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

As an example, the standard file system returns the string "\/:*?"<>|" in *ppwszInvalidChars* and **NULL** in *ppwszValidChars*.

Both parameters cannot return non-**NULL** values, so *ppwszValidChars* is assigned a value of **NULL** because of the non-**NULL** value

in *ppwszInvalidChars*. It is assumed that when there are specified invalid characters, everything else is valid. Only when *ppwszInvalidChars* is **NULL** does *ppwszValidChars* contain a list of all valid characters.

If the method returns a success code, the allocated string must be freed using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).