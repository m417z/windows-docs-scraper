## Description

The **BdaCheckChanges** function verifies a new set of BDA topology changes before they are committed.

## Parameters

### `pIrp` [in]

Points to the IRP for the request to verify changes. The BDA minidriver receives this IRP with the [KSMETHOD_BDA_CHECK_CHANGES](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-bda-check-changes) request.

## Return value

Returns STATUS_SUCCESS or an appropriate error code. Returns the result that the **BdaCommitChanges** function would have returned.

## Remarks

A BDA minidriver calls the **BdaCheckChanges** function to verify a group of BDA topology changes after the minidriver receives a [KSMETHOD_BDA_CHECK_CHANGES](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-bda-check-changes) request of the [KSMETHODSETID_BdaChangeSync](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethodsetid-bdachangesync) method set from the network provider. BDA minidrivers define dispatch and filter-automation tables so that those minidrivers either dispatch the **BdaCheckChanges** function directly or intercept this request using an internal method ([KStrMethodHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkshandler)), which then calls the **BdaCheckChanges** function. For example, BDA minidrivers that intercept this request can obtain a pointer to the BDA filter from the passed IRP so that they can validate the new list of resources for the filter. See [Defining Automation Tables](https://learn.microsoft.com/windows-hardware/drivers/stream/defining-automation-tables) and [Changing BDA Filter Properties](https://learn.microsoft.com/windows-hardware/drivers/stream/changing-bda-filter-properties) for more information.

## See also

[BdaCommitChanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/nf-bdasup-bdacommitchanges)

[KSMETHODSETID_BdaChangeSync](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethodsetid-bdachangesync)

[KSMETHOD_BDA_CHECK_CHANGES](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-bda-check-changes)

[KStrMethodHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkshandler)