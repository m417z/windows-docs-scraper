## Description

The **IDARG_IN_QUERYTARGET_INFO** structure contains input arguments for the [**EVT_IDD_CX_ADAPTER_QUERY_TARGET_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_adapter_query_target_info) callback function.

## Members

### `ConnectorIndex`

The connector index of the target monitor being queried. The driver provided this index in a prior call to [**IddCxMonitorCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorcreate).

## Remarks

For more information about HDR support, see [IddCx version 1.10 updates](https://learn.microsoft.com/windows-hardware/drivers/display/iddcx1.10-updates).

## See also

[**EVT_IDD_CX_ADAPTER_QUERY_TARGET_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_adapter_query_target_info)

[**IddCxMonitorCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxmonitorcreate)