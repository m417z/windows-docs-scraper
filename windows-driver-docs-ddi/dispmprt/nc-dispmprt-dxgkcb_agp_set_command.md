# DXGKCB_AGP_SET_COMMAND callback function

## Description

The **AgpSetCommand** function sets the AGP rate and specifies whether side band addressing and fast write transactions are enabled.

## Parameters

### `Context` [in]

A handle to a context block that is associated with an AGP interface. The display miniport driver previously received this handle in the **Context** member of the DXGK_AGP_INTERFACE structure that was filled in by [DxgkCbQueryServices](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_query_services).

### `Command` [in]

A set of flags that specify the AGP rate and the types of AGP transactions that will be used.

The caller must set one, and only one, of the following flags.

| **Flag** | **Meaning** |
|:--|:--|
| DXGK_AGPCOMMAND_AGP1X | The AGP transfer rate is 1X. |
| DXGK_AGPCOMMAND_AGP2X | The AGP transfer rate is 2X. |
| DXGK_AGPCOMMAND_AGP4X | The AGP transfer rate is 4X. |
| DXGK_AGPCOMMAND_AGP8X | The AGP transfer rate is 8X. |

The caller might also choose to set or clear the following flags.

| **Flag** | **Meaning** |
|:--|:--|
| DXGK_AGPCOMMAND_DISABLE_SBA | If this flag is set, side band addressing is disabled. If this flag is cleared, side band addressing is enabled. |
| DXGK_AGPCOMMAND_DISABLE_FW | If this flag is set, fast write transactions are disabled. If this flag is cleared, fast write transactions are enabled. Note that fast write transactions cannot be used with AGP1X. |

## Return value

**AgpSetCommand** returns STATUS_SUCCESS if it succeeds. Otherwise, it returns one of the error codes defined in *Ntstatus.h*.

## Remarks

None.

## See also

[AgpAllocatePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_agp_allocate_pool)

[AgpFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_agp_free_pool)

[DXGK_AGP_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_agp_interface)

[DxgkCbQueryServices](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_query_services)