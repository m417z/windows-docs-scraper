# CF_OPERATION_RESTART_HYDRATION_FLAGS enumeration

## Description

Flags to restart data hydration on a placeholder file or folder.

## Constants

### `CF_OPERATION_RESTART_HYDRATION_FLAG_NONE:0x00000000`

No restart data hydration flag.

### `CF_OPERATION_RESTART_HYDRATION_FLAG_MARK_IN_SYNC:0x00000001`

If this flag is specified, the placeholder will be marked in-sync upon a successful **RESTART_HYDRATION** operation.

## See also

[CfExecute](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfexecute)

[CF_OPERATION_TYPE](https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_operation_type)