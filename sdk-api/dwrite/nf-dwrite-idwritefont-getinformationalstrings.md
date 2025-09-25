# IDWriteFont::GetInformationalStrings

## Description

 Gets a localized strings collection containing the specified informational strings, indexed by locale name.

## Parameters

### `informationalStringID`

Type: **[DWRITE_INFORMATIONAL_STRING_ID](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_informational_string_id)**

A value that identifies the informational string to get. For example, [DWRITE_INFORMATIONAL_STRING_DESCRIPTION](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_informational_string_id) specifies a string that contains a description of the font.

### `informationalStrings` [out]

Type: **[IDWriteLocalizedStrings](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritelocalizedstrings)****

When this method returns, contains an address of a pointer to the newly created localized strings object.

### `exists` [out]

Type: **BOOL***

When this method returns, **TRUE** if the font contains the specified string ID; otherwise, **FALSE**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

 If the font does not contain the string specified by *informationalStringID*, the return value is **S_OK** but
*informationalStrings* receives a **NULL** pointer and *exists* receives the value **FALSE**.

## See also

[IDWriteFont](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefont)