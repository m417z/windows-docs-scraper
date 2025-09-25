# IWbemPathKeyList::GetKey2

## Description

The
**IWbemPathKeyList::GetKey2** method retrieves a key name or value, and returns the value as a **VARIANT**. A key is indexed from 0 (zero), but the key order is not significant.

## Parameters

### `uKeyIx` [in]

Key index begins at 0 (zero).

### `uFlags` [in]

Reserved. Must be 0 (zero).

### `puNameBufSize` [in, out]

Caller sets this parameter to the number of characters that the name buffer can hold. When successful, this is set to the number of characters that are copied into the buffer—including the terminating **NULL**.

### `pszKeyName` [out]

Buffer into which the name is copied. Because not all keys have a name, this parameter value is **NULL** for an implicit key.

### `pKeyValue` [out]

Pointer to a variant that contains the key value.

### `puApparentCimType` [out]

Pointer to a long integer that is set to the CIM type.

## Return value

This method returns an **HRESULT** that indicates the status of the method call.

## Remarks

This method can be used to determine how big a buffer is needed by passing in a **NULL** pointer for the buffer and setting its size parameter to 0 (zero). When returned, the buffer size parameter indicates the size buffer that is needed for the string and its **NULL** terminator.

## See also

[IWbemPath](https://learn.microsoft.com/windows/desktop/api/wmiutils/nn-wmiutils-iwbempath)

[IWbemPathKeyList](https://learn.microsoft.com/windows/desktop/api/wmiutils/nn-wmiutils-iwbempathkeylist)

[IWbemPathKeyList::GetKey](https://learn.microsoft.com/windows/desktop/api/wmiutils/nf-wmiutils-iwbempathkeylist-getkey)