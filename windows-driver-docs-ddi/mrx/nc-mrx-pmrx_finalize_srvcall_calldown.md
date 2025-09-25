# PMRX_FINALIZE_SRVCALL_CALLDOWN callback function

## Description

The **MRxFinalizeSrvCall** routine is called by [RDBSS](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-rdbss-driver-and-library) to request that a network mini-redirector finalize an SRV_CALL structure.

## Parameters

### `SrvCall`

[in, out] A pointer to the SRV_CALL structure to finalize.

### `Force`

[in] A pointer to a Boolean value that indicates if the disconnect is to be enforced immediately, ignoring the reference count on the SRV_CALL structure. The **Force** parameter is the **ForceFinalize** parameter passed to the [**RxFinalizeSrvCall**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxfinalizesrvcall) routine. This action triggers a call to **MRxFinalizeSrvCall**.

## Return value

**MRxFinalizeSrvCall** returns STATUS_SUCCESS on success.

## Remarks

**MRxFinalizeSrvCall** is called when RDBSS is tearing down an SRV_CALL structure. The network mini-redirector is expected to close its connection to the server.

**MRxFinalizeSrvCall** is called by RDBSS after receiving an [**RxFinalizeSrvCall**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxfinalizesrvcall) call. If [**RxFinalizeSrvCall**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxfinalizenetroot) is called from a different process than the RDBSS system process, then the call to **MRxFinalizeSrvCall** is posted to a worker thread for later execution. At some later time **RxFinalizeSrvCall** is called to complete the finalization of the SRV_CALL structure.

RDBSS ignores the return value from the **MRxFinalizeSrvCall** call.

## See also

[**MRxCreateSrvCall**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_create_srvcall)

[**MRxCreateVNetRoot**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_create_v_net_root)

[**MRxExtractNetRootName**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_extract_netroot_name)

[**MRxFinalizeNetRoot**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_finalize_net_root_calldown)

[**MRxFinalizeVNetRoot**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_finalize_v_net_root_calldown)

[**MRxPreparseName**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_preparse_name)

[**MRxSrvCallWinnerNotify**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_srvcall_winner_notify)

[**RxFinalizeSrvCall**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxfinalizesrvcall)