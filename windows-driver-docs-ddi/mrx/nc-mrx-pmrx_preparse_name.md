# PMRX_PREPARSE_NAME callback function

## Description

The **MRxPreparseName** routine is called by [RDBSS](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-rdbss-driver-and-library) to give a network mini-redirector the opportunity to preparse a name.

## Parameters

### `RxContext`

[in, out] A pointer to the RX_CONTEXT structure. This parameter contains the IRP that is requesting the operation.

### `Name`

[in] A pointer to a Unicode string that contains the name string.

## Return value

**MRxPreparseName** returns STATUS_SUCCESS on success.

## Remarks

**MRxPreparseName** is called by RDBSS after parsing a name to give a network mini-redirector a final opportunity to preparse the name.

RDBSS tries to convert the name to its canonical form, removing a dot (".") and two dots (".."), before calling **MRxPreparseName**. RDBSS will also parse the format used by NTFS streams.

RDBSS ignores the return value from **MRxPreparseName**.

## See also

[**MRxCreateSrvCall**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_create_srvcall)

[**MRxCreateVNetRoot**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_create_v_net_root)

[**MRxExtractNetRootName**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_extract_netroot_name)

[**MRxFinalizeNetRoot**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_finalize_net_root_calldown)

[**MRxFinalizeVNetRoot**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_finalize_v_net_root_calldown)

[**MRxSrvCallWinnerNotify**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_srvcall_winner_notify)

[**RxFinalizeSrvCall**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fcb/nf-fcb-rxfinalizesrvcall)