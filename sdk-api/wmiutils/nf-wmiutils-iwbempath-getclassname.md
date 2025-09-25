# IWbemPath::GetClassName

## Description

The **IWbemPath::GetClassName** method retrieves the class name portion from the path.

## Parameters

### `puBuffLength` [in, out]

Caller sets this to the number of characters the buffer can hold. Upon success, this is set to the number of characters copied into the buffer, including the **NULL** terminator.

### `pszName` [in, out]

Buffer into which the class name is copied.

## Return value

This method returns an **HRESULT** indicating the status of the method call.

## Remarks

This method can be used to determine how big a buffer is needed for *pszName*. This is done by passing in a **NULL** pointer for the buffer, setting *puBuffLength* to 0 and then making the call. Upon return, *puBuffLength* indicates how large of a buffer is needed for *pszName* and its terminating **NULL** character.

## See also

[IWbemPath](https://learn.microsoft.com/windows/desktop/api/wmiutils/nn-wmiutils-iwbempath)