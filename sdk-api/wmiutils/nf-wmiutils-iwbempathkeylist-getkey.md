# IWbemPathKeyList::GetKey

## Description

The
**IWbemPathKeyList::GetKey** method retrieves a key's name or value. Keys are indexed from 0 (zero), though the order of the keys is not significant.

## Parameters

### `uKeyIx` [in]

Key index beginning at 0 (zero).

### `uFlags` [in]

Reserved. Must be 0 (zero).

### `puNameBufSize` [in, out]

Caller sets this to the number of characters that the name buffer can hold. Upon success, this is set to the number of characters copied into the buffer including the terminating **NULL**.

### `pszKeyName` [in, out]

Buffer into which the name is to be copied. Because not all keys have a name, this parameter value would be **NULL** for an implicit key.

### `puKeyValBufSize` [in, out]

Caller sets this to the number of characters that the value buffer can hold. Upon success, this is set to the number of characters copied into the buffer including the **NULL** terminator.

### `pKeyVal` [in, out]

Buffer where data is to be copied.

### `puApparentCimType` [in, out]

Pointer to a long which is set to the CIM type.

## Return value

This method returns an **HRESULT** indicating the status of the method call.

## Remarks

It is a recommended practice to determine how big a buffer is needed by calling this method, passing in a **NULL** pointer for the buffer, and setting its size parameter to 0 (zero). Upon return, the size parameter of the buffer indicates how large of a buffer is needed for the string and its **NULL** terminator. Then you can call the method to get the buffer value.

## See also

[IWbemPath](https://learn.microsoft.com/windows/desktop/api/wmiutils/nn-wmiutils-iwbempath)

[IWbemPathKeyList](https://learn.microsoft.com/windows/desktop/api/wmiutils/nn-wmiutils-iwbempathkeylist)

[IWbemPathKeyList::GetKey2](https://learn.microsoft.com/windows/desktop/api/wmiutils/nf-wmiutils-iwbempathkeylist-getkey2)