# WSManDeinitialize function

## Description

Deinitializes the Windows Remote Management client stack. All operations must be complete before a call to this function will return. This is a synchronous call. It is recommended that all operations are explicitly canceled and that all sessions are closed before calling this function.

## Parameters

### `apiHandle` [in, out, optional]

Specifies the API handle returned by a [WSManInitialize](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmaninitialize) call. This parameter cannot be **NULL**.

### `flags`

Reserved for future use. Must be zero.

## Return value

This method returns zero on success. Otherwise, this method returns an error code.