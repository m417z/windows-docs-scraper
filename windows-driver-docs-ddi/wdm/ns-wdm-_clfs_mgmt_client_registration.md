# _CLFS_MGMT_CLIENT_REGISTRATION structure

## Description

The **CLFS_MGMT_CLIENT_REGISTRATION** structure is given to CLFS management by clients who manage their own logs.

## Members

### `Version`

The version of the **CLFS_MGMT_CLIENT_REGISTRATION** structure. Set this to **CLFS_MGMT_CLIENT_REGISTRATION_VERSION**.

### `AdvanceTailCallback`

A pointer to the log's [ClfsAdvanceTailCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pclfs_client_advance_tail_callback) function.

### `AdvanceTailCallbackData`

A pointer to user-defined data that will be supplied to the *ClfsAdvanceTailCallback* function when the function is invoked.

### `LogGrowthCompleteCallback`

A pointer to the log's [ClfsLogGrowthCompleteCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pclfs_client_lff_handler_complete_callback) function.

### `LogGrowthCompleteCallbackData`

A pointer to user-defined data that will be supplied to the *ClfsLogGrowthCompleteCallback* function when the function is invoked.

### `LogUnpinnedCallback`

A pointer to the log's [ClfsLogUnpinnedCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pclfs_client_log_unpinned_callback) function.

### `LogUnpinnedCallbackData`

A pointer to user-defined data that will be supplied to the *ClfsLogUnpinnedCallback* function when the function is invoked.

## See also

[ClfsAdvanceTailCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pclfs_client_advance_tail_callback)

[ClfsLogGrowthCompleteCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pclfs_client_lff_handler_complete_callback)

[ClfsLogUnpinnedCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pclfs_client_log_unpinned_callback)