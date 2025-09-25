# PMRX_FINALIZE_NET_ROOT_CALLDOWN callback function

## Description

The **MRxFinalizeNetRoot** routine is called by [RDBSS](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-rdbss-driver-and-library) to request that a network mini-redirector finalize a NET_ROOT structure.

## Parameters

### `NetRoot`

[in, out] A pointer to the NET_ROOT structure to finalize.

### `Force`

[in] A pointer to a Boolean value that indicates if the disconnect is to be forced. RDBSS currently passes **FALSE** for this parameter in all cases.

## Return value

**MRxFinalizeNetRoot** returns STATUS_SUCCESS on success.

## Remarks

**MRxFinalizeNetRoot** is called by RDBSS when RDBSS finalizes a NET_ROOT structure. Because a NET_ROOT structure is always associated with one or more V_NET_ROOT structures, this finalization normally occurs when the last V_NET_ROOT structure on the NET_ROOT structure is finalized.

RDBSS ignores the return value from **MRxFinalizeNetRoot**.

## See also

[**MRxCreateSrvCall**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_create_srvcall)

[**MRxCreateVNetRoot**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_create_v_net_root)

[**MRxExtractNetRootName**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_extract_netroot_name)

[**MRxFinalizeSrvCall**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_finalize_srvcall_calldown)

[**MRxFinalizeVNetRoot**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_finalize_v_net_root_calldown)

[**MRxPreparseName**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_preparse_name)

[**MRxSrvCallWinnerNotify**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_srvcall_winner_notify)