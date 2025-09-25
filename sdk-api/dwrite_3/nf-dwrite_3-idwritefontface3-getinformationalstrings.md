# IDWriteFontFace3::GetInformationalStrings

## Description

Gets a localized strings collection that contains the specified informational strings, indexed by locale name.

## Parameters

### `informationalStringID` [in]

Type: **[DWRITE_INFORMATIONAL_STRING_ID](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_informational_string_id)**

A [DWRITE_INFORMATIONAL_STRING_ID](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_informational_string_id)-typed value that identifies the strings to get.

### `informationalStrings` [out]

Type: **[IDWriteLocalizedStrings](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritelocalizedstrings)****

A pointer to a memory block that receives a pointer to a [IDWriteLocalizedStrings](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritelocalizedstrings) interface for the newly created localized strings object.

### `exists` [out]

Type: **BOOL***

A pointer to a variable that receives whether the font contains the specified string ID. **TRUE** if the font contains the specified string ID; otherwise, **FALSE**.

## Return value

Type: **HRESULT**

If the font doesn't contain the specified string, the return value is S_OK, but *informationalStrings* receives a **NULL** pointer and *exists* receives the value **FALSE**.

## See also

[IDWriteFontFace3](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontface3)