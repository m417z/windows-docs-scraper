# WSManSetSessionOption function

## Description

Sets an extended set of options for the session.

## Parameters

### `session` [in]

Specifies the session handle returned by a [WSManCreateSession](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmancreatesession) call. This parameter cannot be **NULL**.

### `option`

Specifies the option to be set. This parameter must be set to one of the values in the [WSManSessionOption](https://learn.microsoft.com/windows/desktop/api/wsman/ne-wsman-wsmansessionoption) enumeration.

### `data` [in]

A pointer to a [WSMAN_DATA](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_data) structure that defines the option value.

## Return value

This method returns zero on success. Otherwise, this method returns an error code.

## Remarks

If the **WSManSetSessionOption** method is called with different values specified for the *option* parameter, the order of the different options is important. The first time **WSManSetSessionOption** is called, the transport is set for the session. If a second call requests a different type of transport, the call will fail.

For example, the second method call will fail if the methods are called in the following order:

* `WSManSetSessionOption(WSMAN_OPTION_UNENCRYPTED_MESSAGES)`
* `WSManSetSessionOption(WSMAN_OPTION_ALLOW_NEGOTIATE_IMPLICIT_CREDENTIALS)`

The first method call sets the transport to HTTP because the *option* parameter is set to **WSMAN_OPTION_UNENCRYPTED_MESSAGES**. The second call fails because the option that was passed is applicable for HTTPS and the transport was set to HTTP by the first message.