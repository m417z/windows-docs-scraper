# IWbemPath::GetScope

## Description

The
**IWbemPath::GetScope** method retrieves a scope based upon an index. This method retrieves the class name and a
[IWbemPathKeyList](https://learn.microsoft.com/windows/desktop/api/wmiutils/nn-wmiutils-iwbempathkeylist) pointer so that the details of the keys can be retrieved.

## Parameters

### `uIndex` [in]

Index of the scope.

### `puClassNameBufSize` [in, out]

Caller sets this to the number of characters that the buffer can hold. Upon success, this is set to the number of characters copied into the buffer including the **NULL** terminator.

### `pszClass` [out]

Buffer where the scope is to be copied.

### `pKeyList` [out]

Pointer to an
[IWbemPathKeyList](https://learn.microsoft.com/windows/desktop/api/wmiutils/nn-wmiutils-iwbempathkeylist) object.

## Return value

This method returns the following values.

## Remarks

This method can be used to determine how big a buffer is needed for *pszClass*. This is done by passing in a **NULL** pointer for the buffer, setting *puClassNameBufSize* to 0 and then making the call. Upon return, *puClassNameBufSize* indicates how large of a buffer is needed for *pszClass* and its terminating **NULL** character.

## See also

[IWbemPath](https://learn.microsoft.com/windows/desktop/api/wmiutils/nn-wmiutils-iwbempath)