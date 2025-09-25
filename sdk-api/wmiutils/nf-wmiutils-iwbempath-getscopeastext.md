# IWbemPath::GetScopeAsText

## Description

The
**IWbemPath::GetScopeAsText** method retrieves a scope in text format based on an index.

## Parameters

### `uIndex` [in]

Index of the scope.

### `puTextBufSize` [in, out]

Caller sets this to the number of characters that the buffer can hold. After success this is set to the number of characters copied into the buffer including the **NULL** terminator.

### `pszText` [out]

Buffer where the scope is to be copied.

## Return value

This method returns the following values.

## Remarks

This method can be used to determine how big a buffer is needed for *pszText*. This is done by passing in a **NULL** pointer for the buffer, setting *puTextBufSize* to zero (0), and then making the call. When returned, *puTextBufSize* indicates how large a buffer is needed for *pszText* and its terminating **NULL** character.

## See also

[IWbemPath](https://learn.microsoft.com/windows/desktop/api/wmiutils/nn-wmiutils-iwbempath)