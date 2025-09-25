# WSManGetSessionOptionAsString function

## Description

Gets the value of a session option.

## Parameters

### `session` [in]

Specifies the session handle returned by a [WSManCreateSession](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmancreatesession) call. This parameter cannot be **NULL**.

### `option`

Specifies the option to get. Not all session options can be retrieved. The values for the options are defined in the [WSManSessionOption](https://learn.microsoft.com/windows/desktop/api/wsman/ne-wsman-wsmansessionoption) enumeration.

### `stringLength`

Specifies the length of the storage location for *string* parameter.

### `string` [out, optional]

A pointer to the storage location for the value of the specified session option.

### `stringLengthUsed` [out]

Specifies the length of the string returned in the *string* parameter.

## Return value

This method returns zero on success. Otherwise, this method returns an error code.