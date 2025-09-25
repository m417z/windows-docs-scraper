# IWbemPath::GetNamespaceAt

## Description

The
**IWbemPath::GetNamespaceAt** method retrieves a namespace based upon its index. The leftmost namespace in the path has an index of 0 with each namespace moving to the right having a progressively higher index value.

## Parameters

### `uIndex` [in]

Index of the namespace to be read. The leftmost namespace in the path is index 0 with each namespace to the right having a progressively higher index value. The maximum permitted value is one less than the current number of namespaces.

### `puNameBufLength` [in, out]

Caller sets this to the number of characters the buffer can hold. Upon success, this is set to the number of characters copied into the buffer including the **NULL** terminator.

### `pName` [in, out]

Namespace name.

## Return value

This method returns an **HRESULT** indicating the status of the method call.

## Remarks

This method can be used to determine how big a buffer is needed for *pName*. This is done by passing in a **NULL** pointer for the buffer, setting *puNameBufLength* to 0 and then making the call. Upon return, *puNameBufLength* indicates how large of a buffer is needed for *pName* and its terminating **NULL** character.

## See also

[IWbemPath](https://learn.microsoft.com/windows/desktop/api/wmiutils/nn-wmiutils-iwbempath)