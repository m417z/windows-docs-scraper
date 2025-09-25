# PMRX_EXTRACT_NETROOT_NAME callback function

## Description

The **MRxExtractNetRootName** routine is called by [RDBSS](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-rdbss-driver-and-library) to request that a network mini-redirector extract the name of the NET_ROOT structure from a given pathname.

## Parameters

### `FilePathName`

[in] A pointer to a Unicode string that contains a pathname.

### `SrvCall`

[in] A pointer to the SRV_CALL structure.

### `NetRootName`

[out] On input, a pointer for storing a Unicode string. On success, this parameter will contain a pointer to a Unicode string that contains a NET_ROOT structure name.

### `RestOfName`

[out, optional] A pointer to a Unicode string that contains the rest of the name on success. This parameter is optional and can be a NULL pointer on input.

## Remarks

**MRxExtractNetRootName** parses the input name into the SRV_CALL structure, the NET_ROOT structure, and the rest of the pathname.

## See also

[**MRxCreateSrvCall**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_create_srvcall)

[**MRxCreateVNetRoot**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_create_v_net_root)

[**MRxFinalizeNetRoot**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_finalize_net_root_calldown)

[**MRxFinalizeSrvCall**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_finalize_srvcall_calldown)

[**MRxFinalizeVNetRoot**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_finalize_v_net_root_calldown)

[**MRxPreparseName**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_preparse_name)

[**MRxSrvCallWinnerNotify**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mrx/nc-mrx-pmrx_srvcall_winner_notify)