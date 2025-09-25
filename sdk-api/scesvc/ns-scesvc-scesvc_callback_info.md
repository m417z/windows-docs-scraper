# SCESVC_CALLBACK_INFO structure

## Description

The **SCESVC_CALLBACK_INFO** structure contains an opaque database handle and callback function pointers to query, set, and free information.

## Members

### `sceHandle`

Specifies the opaque handle passed to the attachment by the Security Configuration tool set. This handle is used by support functions to read information from and write information to the security database.

### `pfQueryInfo`

Pointer to a
[PFSCE_QUERY_INFO](https://learn.microsoft.com/windows/desktop/api/scesvc/nc-scesvc-pfsce_query_info) callback function that queries information in the security database.

### `pfSetInfo`

Pointer to a
[PFSCE_SET_INFO](https://learn.microsoft.com/windows/desktop/api/scesvc/nc-scesvc-pfsce_set_info) callback function that sets information in the security database.

### `pfFreeInfo`

Pointer to a
[PFSCE_FREE_INFO](https://learn.microsoft.com/windows/desktop/api/scesvc/nc-scesvc-pfsce_free_info) callback function that frees information in the security database.

### `pfLogInfo`

Pointer to a
[PFSCE_LOG_INFO](https://learn.microsoft.com/windows/desktop/api/scesvc/nc-scesvc-pfsce_log_info) callback function that logs messages to the configuration log file or analysis log file.

## See also

[SCE_HANDLE](https://learn.microsoft.com/windows/desktop/SecMgmt/sce-handle)