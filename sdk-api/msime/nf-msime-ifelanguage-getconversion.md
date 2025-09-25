# IFELanguage::GetConversion

## Description

Converts the input string (which usually contains the Hiragana character) to converted strings.

## Parameters

### `string` [in]

A string of phonetic characters to convert.

### `start` [in]

The starting character from which [IFELanguage](https://learn.microsoft.com/windows/desktop/api/msime/nn-msime-ifelanguage) begins conversion. The first character of *string* is represented by 1 (not 0).

### `length` [in]

The number of characters to convert. If this value is -1, all of the remaining characters from *start* are converted.

### `result` [out, retval]

The converted string. This string is allocated by [SysAllocStringLen](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstringlen) and must be freed by the client.

## Return value

**S_OK** if successful, otherwise **E_FAIL**.

## See also

[IFELanguage](https://learn.microsoft.com/windows/desktop/api/msime/nn-msime-ifelanguage)