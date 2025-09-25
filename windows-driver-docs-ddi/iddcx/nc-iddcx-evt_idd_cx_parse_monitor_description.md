# EVT_IDD_CX_PARSE_MONITOR_DESCRIPTION callback function

## Description

The OS calls **EVT_IDD_CX_PARSE_MONITOR_DESCRIPTION** to ask the driver to parse a monitor description into a list of modes that the monitor supports. Use [**EVT_IDD_CX_PARSE_MONITOR_DESCRIPTION2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_parse_monitor_description2) to report HDR10 or WCG monitor modes.

## Parameters

### `pInArgs`

[in] Pointer to a [**IDARG_IN_PARSEMONITORDESCRIPTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_parsemonitordescription) structure that contains the input arguments for this callback function.

### `pOutArgs`

[out] Pointer to a [**IDARG_OUT_PARSEMONITORDESCRIPTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_parsemonitordescription) structure that contains the output arguments for this callback function.

## Return value

**EVT_IDD_CX_PARSE_MONITOR_DESCRIPTION** returns an [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) value. If the operation is successful, it returns STATUS_SUCCESS or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise, it returns an appropriate NTSTATUS error code.

## See also

[**EVT_IDD_CX_PARSE_MONITOR_DESCRIPTION2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nc-iddcx-evt_idd_cx_parse_monitor_description2)

[**IDARG_IN_PARSEMONITORDESCRIPTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_in_parsemonitordescription)

[**IDARG_OUT_PARSEMONITORDESCRIPTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_parsemonitordescription)