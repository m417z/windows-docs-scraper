# WSManCloseSession function

## Description

Closes a session object.

## Parameters

### `session` [in, out, optional]

Specifies the session handle to close. This handle is returned by a [WSManCreateSession](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmancreatesession) call. This parameter cannot be NULL.

### `flags`

Reserved for future use. Must be zero.

## Return value

This method returns zero on success. Otherwise, this method returns an error code.

## Remarks

The **WSManCloseSession** method frees the memory associated with a session and closes all related operations before returning. This is a synchronous call. All operations are explicitly canceled. It is recommended that all pending operations are either completed or explicitly canceled before calling this function.