## Description

The types of operations that can be performed on placeholder files and directories.

Also see [Cloud Mirror sample](https://learn.microsoft.com/windows/win32/cfapi/build-a-cloud-file-sync-engine#cloud-mirror-sample).

## Constants

### `CF_OPERATION_TYPE_TRANSFER_DATA`

A sync provider performs **TRANSFER_DATA** to hydrate a placeholder file. This operation can be performed as a response to a **FETCH_DATA** callback, a **VALIDATE_DATA** callback, or as part of a preemptive background hydration effort outside of any callback context.

### `CF_OPERATION_TYPE_RETRIEVE_DATA`

A sync provider performs a **RETRIEVE_DATA** operation as part of the placeholder hydration in order to validate the integrity of the data that was previously transferred to the placeholder. This operation can be performed as a response to a **FETCH_DATA** callback, a **VALIDATE_DATA** callback, or as part of a preemptive background hydration effort outside of any callback context.

### `CF_OPERATION_TYPE_ACK_DATA`

A sync provider performs a **ACK_DATA** operation as part of the placeholder hydration after validating the integrity of the data that was previously transferred to the platform. This operation can be performed as a response to a **FETCH_DATA** callback, a **VALIDATE_DATA** callback, or as part of a preemptive background hydration effort outside of any callback context

### `CF_OPERATION_TYPE_RESTART_HYDRATION`

A sync provider performs a **RESTART_HYDRATION** operation to restart an ongoing hydration. This operation can be performed as a response to a **FETCH_DATA** callback, a **VALIDATE_DATA** callback, or as part of a preemptive background hydration effort outside of any callback context.

### `CF_OPERATION_TYPE_TRANSFER_PLACEHOLDERS`

Transfers placeholders. The sync provider must transfer all placeholders matching the pattern but not necessarily in one-shot, as a minimum requirement. The sync provider may additionally choose to transfer placeholders not matching the pattern.

### `CF_OPERATION_TYPE_ACK_DEHYDRATE`

Acknowledge and dehydrate a placeholder.

### `CF_OPERATION_TYPE_ACK_DELETE`

Acknowledge and delete a placeholder.

### `CF_OPERATION_TYPE_ACK_RENAME`

Acknowledge and rename a placeholder.

## See also

[Cloud Mirror sample](https://learn.microsoft.com/windows/win32/cfapi/build-a-cloud-file-sync-engine#cloud-mirror-sample)

[CfExecute](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfexecute)

[CF_OPERATION_INFO](https://learn.microsoft.com/windows/win32/api/cfapi/ns-cfapi-cf_operation_info)

[CF_OPERATION_PARAMETERS](https://learn.microsoft.com/windows/win32/api/cfapi/ns-cfapi-cf_operation_parameters)