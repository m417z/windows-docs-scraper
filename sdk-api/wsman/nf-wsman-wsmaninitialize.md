# WSManInitialize function

## Description

Initializes the Windows Remote Management Client API. **WSManInitialize** can be used by different clients on the same process.

## Parameters

### `flags`

A flag of type **WSMAN_FLAG_REQUESTED_API_VERSION_1_0** or **WSMAN_FLAG_REQUESTED_API_VERSION_1_1**.
The client that will use the disconnect-reconnect functionality should use the
**WSMAN_FLAG_REQUESTED_API_VERSION_1_1** flag.

### `apiHandle` [out]

Defines a handle that uniquely identifies the client. This parameter cannot be **NULL**. When you have finished used the handle, close it by calling the [WSManDeinitialize](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmandeinitialize) method.

## Return value

This method returns zero on success. Otherwise, this method returns an error code.