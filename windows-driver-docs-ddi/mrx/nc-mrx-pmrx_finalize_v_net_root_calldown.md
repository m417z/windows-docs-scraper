# PMRX_FINALIZE_V_NET_ROOT_CALLDOWN callback function

## Description

The **MRxFinalizeVNetRoot** routine is called by [RDBSS](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-rdbss-driver-and-library) to request that a network mini-redirector finalize a V_NET_ROOT structure.

## Parameters

### `VirtualNetRoot`

[in, out] A pointer to the V_NET_ROOT structure to finalize.

### `Force`

[in] A pointer to a Boolean value that indicates if the disconnect is to be forced. RDBSS currently passes **FALSE** for this parameter in all cases.

## Return value

**MRxFinalizeVNetRoot** returns STATUS_SUCCESS on success.

## Remarks

**MRxFinalizeVNetRoot** is called by RDBSS when it finalizes a NET_ROOT structure.

After the **MRxFinalizeVNetRoot** returns, RDBSS uninitializes the V_NET_ROOT structure members, dereferences the NET_ROOT structure, and releases the memory for the V_NET_ROOT structure.

RDBSS ignores the return value from **MRxFinalizeVNetRoot**.

## See also

[**MRxCreateSrvCall**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_create_srvcall)

[**MRxCreateVNetRoot**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_create_v_net_root)

[**MRxExtractNetRootName**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_extract_netroot_name)

[**MRxFinalizeNetRoot**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_finalize_net_root_calldown)

[**MRxPreparseName**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_preparse_name)

[**MRxSrvCallWinnerNotify**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_srvcall_winner_notify)

[**RxFinalizeSrvCall**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxfinalizesrvcall)