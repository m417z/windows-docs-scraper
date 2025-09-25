# _PEP_PPM_QUERY_VETO_REASONS structure (pepfx.h)

## Description

The **PEP_PPM_QUERY_VETO_REASONS** structure specifies the total number of veto reasons that the PEP uses in calls to the [ProcessorIdleVeto](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pofxcallbackprocessoridleveto) and [PlatformIdleVeto](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/nc-pepfx-pofxcallbackplatformidleveto) routines.

## Members

### `VetoReasonCount` [out]

The number of veto codes used by the PEP.

## Remarks

This structure is used by the [PEP_NOTIFY_PPM_QUERY_VETO_REASONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_veto_reason) notification. The **VetoReasonCount** member contains an output value that the PEP writes to this member in response to the notification.

## See also

[PEP_NOTIFY_PPM_QUERY_VETO_REASONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_veto_reason)