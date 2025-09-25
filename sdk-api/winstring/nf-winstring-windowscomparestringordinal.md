## Description

Compares two specified [**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring) objects and returns an integer that indicates their relative position in a sort order.

## Parameters

### `string1`

Type: [in] **[HSTRING](https://learn.microsoft.com/windows/win32/winrt/hstring)**

The first string to compare.

### `string2`

Type: [in] **[HSTRING](https://learn.microsoft.com/windows/win32/winrt/hstring)**

The second string to compare.

### `result`

Type: [out] **INT32***

A value that indicates the lexical relationship between *string1* and *string2*.

## Return value

Type: **HRESULT**

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The comparison was successful. |
| **E_INVALIDARG** | *result* is **NULL**. |

## Remarks

Use the **WindowsCompareStringOrdinal** function to compare two [**HSTRING**](https://learn.microsoft.com/windows/win32/winrt/hstring) objects. After the comparison completes, the *result* out parameter contains one of three values.

| Value | Condition |
| --- | --- |
| -1 | *string1* is less than *string2*. |
| 0 | *string1* equals *string2*. |
| 1 | *string1* is greater than *string2*. |