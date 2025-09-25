# PMRX_SRVCALL_WINNER_NOTIFY callback function

## Description

The **MRxSrvCallWinnerNotify** routine is called by [RDBSS](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-rdbss-driver-and-library) to notify a network mini-redirector that it was chosen when multiple redirectors could fulfill the request.

## Parameters

### `SrvCall`

[in, out] A pointer to an SRV_CALL structure that is created by the network mini-redirector.

### `ThisMinirdrIsTheWinner`

[in] A Boolean value that indicates that this network mini-redirector was chosen.

### `RecommunicateContext`

[in/out] Pointer to the network mini-redirector-provided value in [**PMRX_CREATE_SRVCALL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_create_srvcall).

## Return value

**MRxSmbSrvCallWinnerNotify** returns STATUS_SUCCESS on success.

## Remarks

**MRxSrvCallWinnerNotify** was originally designed to be called by RDBSS to notify a network mini-redirector that it was chosen when multiple redirectors could fulfill the request. The chosen network mini-redirector is expected to create the SRV_CALL structure and establish a connection with the server.

The network mini-redirector should complete the context for the SRV_CALL structure. If the network mini-redirector supports case-insensitive names for NET_ROOT structures and for filenames, then the SRV_CALL **Flags** member should set the bits for SRVCALL_FLAG_CASE_INSENSITIVE_NETROOTS and SRVCALL_FLAG_CASE_INSENSITIVE_FILENAMES.

Under the current implementation of RDBSS, each network mini-redirector has its own copy of RDBSS, so there are no competing network redirectors at the RDBSS layer. All network mini-redirectors will receive a call to **MRxSrvCallWinnerNotify** with the **ThisMinirdrIsTheWinner** parameter set to **TRUE** after receiving a call to [**MRxCreateSrvCall**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_create_srvcall) to create the SRV_CALL structure.

When multiple redirectors are installed for handling the same UNC namespace, the redirector to service a request is chosen by multiple UNC provider (MUP) based on the order of redirectors specified in the registry.

## See also

[**MRxCreateSrvCall**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_create_srvcall)

[**MRxCreateVNetRoot**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_create_v_net_root)

[**MRxExtractNetRootName**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_extract_netroot_name)

[**MRxFinalizeNetRoot**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_finalize_net_root_calldown)

[**MRxFinalizeVNetRoot**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_finalize_v_net_root_calldown)

[**MRxPreparseName**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_preparse_name)

[**RxFinalizeSrvCall**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxfinalizesrvcall)