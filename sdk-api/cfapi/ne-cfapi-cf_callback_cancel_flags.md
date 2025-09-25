# CF_CALLBACK_CANCEL_FLAGS enumeration

## Description

Callback flags for canceling data fetching for a placeholder file or folder.

## Constants

### `CF_CALLBACK_CANCEL_FLAG_NONE:0x00000000`

No cancel flag.

### `CF_CALLBACK_CANCEL_FLAG_IO_TIMEOUT:0x00000001`

Flag to be set if the user request is cancelled as a result of the expiration of the 60 second timer.

### `CF_CALLBACK_CANCEL_FLAG_IO_ABORTED:0x00000002`

Flag to be set if the user request is cancelled as a result of the user explicitly terminating the hydration from app-initiated download toast.

## See also

[CF_CALLBACK_TYPE](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_callback_type)