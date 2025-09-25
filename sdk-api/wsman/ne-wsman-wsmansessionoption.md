# WSManSessionOption enumeration

## Description

Defines a set of extended options for the session. These options are used with the [WSManSetSessionOption](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmansetsessionoption) method.

## Constants

### `WSMAN_OPTION_DEFAULT_OPERATION_TIMEOUTMS:1`

Default time-out in milliseconds that applies to all operations on the client side.

### `WSMAN_OPTION_MAX_RETRY_TIME:11`

### `WSMAN_OPTION_TIMEOUTMS_CREATE_SHELL:12`

Time-out in milliseconds for [WSManCreateShell](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmancreateshell) operations.

### `WSMAN_OPTION_TIMEOUTMS_RUN_SHELL_COMMAND:13`

Time-out in milliseconds for [WSManRunShellCommand](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanrunshellcommand) operations.

### `WSMAN_OPTION_TIMEOUTMS_RECEIVE_SHELL_OUTPUT:14`

Time-out in milliseconds for [WSManReceiveShellOutput](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanreceiveshelloutput) operations.

### `WSMAN_OPTION_TIMEOUTMS_SEND_SHELL_INPUT:15`

Time-out in milliseconds for [WSManSendShellInput](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmansendshellinput) operations.

### `WSMAN_OPTION_TIMEOUTMS_SIGNAL_SHELL:16`

Time-out in milliseconds for [WSManSignalShell](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmansignalshell) and [WSManCloseCommand](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanclosecommand) operations.

### `WSMAN_OPTION_TIMEOUTMS_CLOSE_SHELL:17`

Time-out in milliseconds for [WSManCloseShell](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmancloseshell) operations connection options.

### `WSMAN_OPTION_SKIP_CA_CHECK:18`

Set to 1 to not validate the CA on the server certificate. The default is 0.

### `WSMAN_OPTION_SKIP_CN_CHECK:19`

Set to 1 to not validate the CN on the server certificate. The default is 0.

### `WSMAN_OPTION_UNENCRYPTED_MESSAGES:20`

Set to 1 to not encrypt messages. The default is 0.

### `WSMAN_OPTION_UTF16:21`

Set to 1 to send all network packets for remote operations in UTF16. Default of 0 causes network packets to be sent in UTF8.

### `WSMAN_OPTION_ENABLE_SPN_SERVER_PORT:22`

Set to 1 when using Negotiate authentication and the port number is included in the connection. Default is 0.

### `WSMAN_OPTION_MACHINE_ID:23`

Set to 1 to identify this machine to the server by including the MachineID. The default is 0.

### `WSMAN_OPTION_LOCALE:25`

The language locale options. For more information about the language locales, see the RFC 3066 specification from the Internet Engineering Task Force at [http://www.ietf.org/rfc/rfc3066.txt](https://www.ietf.org/rfc/rfc3066.txt).

### `WSMAN_OPTION_UI_LANGUAGE:26`

The UI language options. The UI language options are defined in RFC 3066 format. For more information about the UI language options, see the RFC 3066 specification from the Internet Engineering Task Force at [http://www.ietf.org/rfc/rfc3066.txt](https://www.ietf.org/rfc/rfc3066.txt).

### `WSMAN_OPTION_MAX_ENVELOPE_SIZE_KB:28`

The maximum Simple Object Access Protocol (SOAP) envelope size. The default is 150 KB.

### `WSMAN_OPTION_SHELL_MAX_DATA_SIZE_PER_MESSAGE_KB:29`

The maximum size of the data that is provided by the client.

### `WSMAN_OPTION_REDIRECT_LOCATION:30`

The redirect location.

**Note** It is recommended that all redirection use Secure Sockets Layer (SSL) and that all applications validate the redirected URI before creating a new session.

### `WSMAN_OPTION_SKIP_REVOCATION_CHECK:31`

Set to 1 to not validate the revocation status on the server certificate. The default is 0.

### `WSMAN_OPTION_ALLOW_NEGOTIATE_IMPLICIT_CREDENTIALS:32`

Set to 1 to allow default credentials for Negotiate. The default is 0.

### `WSMAN_OPTION_USE_SSL:33`

### `WSMAN_OPTION_USE_INTEARACTIVE_TOKEN:34`