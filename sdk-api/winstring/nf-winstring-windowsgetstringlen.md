## Description

Gets the length, in Unicode characters, of the specified string.

## Parameters

### `string`

Type: [in] **[HSTRING](https://learn.microsoft.com/windows/win32/winrt/hstring)**

The string whose length is to be found.

## Return value

Type: **UINT32**

The number of Unicode characters in *string*, including embedded null characters, but excluding the terminating null; or 0 if *string* is **NULL**.