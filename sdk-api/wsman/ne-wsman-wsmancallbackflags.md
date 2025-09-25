# WSManCallbackFlags enumeration

## Description

Defines a set of flags used by all callback functions.

## Constants

### `WSMAN_FLAG_CALLBACK_END_OF_OPERATION:0x1`

Indicates the end of a single step of a multi-step operation. This flag is used for optimization purposes if the shell cannot be determined.

### `WSMAN_FLAG_CALLBACK_END_OF_STREAM:0x8`

Indicates the end of a particular stream. This flag is used for optimization purposes if an indication has been provided to the shell that no more output will occur for this stream.

### `WSMAN_FLAG_CALLBACK_SHELL_SUPPORTS_DISCONNECT:0x20`

### `WSMAN_FLAG_CALLBACK_SHELL_AUTODISCONNECTED:0x40`

### `WSMAN_FLAG_CALLBACK_NETWORK_FAILURE_DETECTED:0x100`

### `WSMAN_FLAG_CALLBACK_RETRYING_AFTER_NETWORK_FAILURE:0x200`

### `WSMAN_FLAG_CALLBACK_RECONNECTED_AFTER_NETWORK_FAILURE:0x400`

### `WSMAN_FLAG_CALLBACK_SHELL_AUTODISCONNECTING:0x800`

### `WSMAN_FLAG_CALLBACK_RETRY_ABORTED_DUE_TO_INTERNAL_ERROR:0x1000`

### `WSMAN_FLAG_CALLBACK_RECEIVE_DELAY_STREAM_REQUEST_PROCESSED:0X2000`