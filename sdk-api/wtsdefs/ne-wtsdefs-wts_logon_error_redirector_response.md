# WTS_LOGON_ERROR_REDIRECTOR_RESPONSE enumeration

## Description

Contains values that specify the preferred response of the protocol to a logon error.

## Constants

### `WTS_LOGON_ERR_INVALID:0`

This value is used for safe initialization.

### `WTS_LOGON_ERR_NOT_HANDLED`

Specifies that the client logon was not handled by the redirector and should be handled by the logon user interface.

### `WTS_LOGON_ERR_HANDLED_SHOW`

Specifies that the client logon was handled by the redirector and that the logon user interface should display itself normally.

### `WTS_LOGON_ERR_HANDLED_DONT_SHOW`

Specifies that the client logon was handled by the redirector and should not be passed to the next redirector. The logon user interface should not display an error message but should attempt to collect credentials again.

### `WTS_LOGON_ERR_HANDLED_DONT_SHOW_START_OVER`

Specifies that the client logon was handled by the redirector and should not be passed to the next redirector. The logon user interface should not be displayed and should not attempt to collect credentials again.

## Remarks

This enumeration is used by the following methods:

* [RedirectStatus](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwtsprotocollogonerrorredirector-redirectstatus)
* [RedirectMessage](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwtsprotocollogonerrorredirector-redirectmessage)
* [RedirectLogonError](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwtsprotocollogonerrorredirector-redirectlogonerror)