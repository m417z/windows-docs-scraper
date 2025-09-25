# IDARG_IN_COMMITMODES structure

## Description

The **IDARG_IN_COMMITMODES** structure contains input parameters for the [**EVT_IDD_CX_ADAPTER_COMMIT_MODES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_adapter_commit_modes) callback function.

## Members

### `PathCount`

[in] The number of paths in the array that **pPaths** points to.

### `pPaths`

[in] A pointer to the array of [**IDDCX_PATH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_path) structures containing the paths that need to be committed.

## See also

[**EVT_IDD_CX_ADAPTER_COMMIT_MODES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_adapter_commit_modes)

[**IDDCX_PATH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_path)