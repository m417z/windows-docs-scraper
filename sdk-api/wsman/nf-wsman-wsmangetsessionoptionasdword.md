# WSManGetSessionOptionAsDword function

## Description

Gets the value of a session option.

## Parameters

### `session` [in]

Specifies the handle returned by a [WSManCreateSession](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmancreatesession) call. This parameter cannot be **NULL**.

### `option`

Specifies the option to get. Not all session options can be retrieved. The options are defined in the [WSManSessionOption](https://learn.microsoft.com/windows/desktop/api/wsman/ne-wsman-wsmansessionoption) enumeration.

### `value` [in, out]

Specifies the value of specified session option.

## Return value

This method returns zero on success. Otherwise, this method returns an error code.