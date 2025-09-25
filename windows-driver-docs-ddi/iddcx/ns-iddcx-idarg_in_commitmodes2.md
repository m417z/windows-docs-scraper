## Description

The **IDARG_IN_COMMITMODES2** structure contains input parameters for the [**EVT_IDD_CX_ADAPTER_COMMIT_MODES2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_adapter_commit_modes2) callback function, which allows a driver to report extra information needed for HDR10 or WCG monitor modes.

## Members

### `PathCount`

[in] The number of paths in the array pointed to by **pPaths**.

### `pPaths`

[in] Pointer to an array of [**IDDCX_PATH2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_path2) structures that contain the paths that need to be committed.

## Remarks

For more information about HDR support, see [IddCx version 1.10 updates](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx1.10-updates).

## See also

[**EVT_IDD_CX_ADAPTER_COMMIT_MODES2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_adapter_commit_modes2)

[**IDDCX_PATH2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_path2)