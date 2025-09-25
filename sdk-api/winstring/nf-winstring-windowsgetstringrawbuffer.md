## Description

Retrieves the backing buffer for the specified string.

## Parameters

### `string`

Type: [in, optional] **[HSTRING](https://learn.microsoft.com/windows/win32/winrt/hstring)**

An optional string for which the backing buffer is to be retrieved. Can be **NULL**.

### `length`

Type: [out, optional] **UINT32 \***

An optional pointer to a **UINT32**. If **NULL** is passed for *length*, then it is ignored. If *length* is a valid pointer to a **UINT32**, and *string* is a valid [**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring), then on successful completion the function sets the value pointed to by *length* to the number of Unicode characters in the backing buffer for *string* (including embedded null characters, but excluding the terminating null). If *length* is a valid pointer to a **UINT32**, and *string* is **NULL**, then the value pointed to by *length* is set to 0.

## Return value

Type: **PCWSTR**

A pointer to the buffer that provides the backing store for *string*, or the empty string if *string* is **NULL** or the empty string.

## Remarks

Use the **WindowsGetStringRawBuffer** function to obtain a pointer to the backing buffer of an [**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring).

Don't change the contents of the buffer—an [**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring) is required to be immutable.