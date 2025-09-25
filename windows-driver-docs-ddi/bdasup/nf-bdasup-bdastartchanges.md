## Description

The **BdaStartChanges** function initiates the setting of new BDA topology changes.

## Parameters

### `pIrp` [in]

Points to the IRP for the request to initiate changes. The BDA minidriver receives this IRP with the [KSMETHOD_BDA_START_CHANGES](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-bda-start-changes) request.

## Return value

Returns STATUS_SUCCESS or an appropriate error code.

## Remarks

A BDA minidriver calls the **BdaStartChanges** function to initiate the setting of new BDA topology changes after the minidriver receives a [KSMETHOD_BDA_START_CHANGES](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-bda-start-changes) request of the [KSMETHODSETID_BdaChangeSync](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethodsetid-bdachangesync) method set from the network provider. BDA minidrivers define dispatch and filter-automation tables so that those minidrivers either dispatch the **BdaStartChanges** function directly or intercept this request using an internal method ([KStrMethodHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkshandler)), which then calls the **BdaStartChanges** function. For example, BDA minidrivers that intercept this request can obtain a pointer to the BDA filter from the passed IRP so that they can subsequently reset pending filter resources to the new requirements and set the change state of the filter to BDA_CHANGES_COMPLETE. See [Defining Automation Tables](https://learn.microsoft.com/windows-hardware/drivers/stream/defining-automation-tables) and [Changing BDA Filter Properties](https://learn.microsoft.com/windows-hardware/drivers/stream/changing-bda-filter-properties) for more information.

Calling the **BdaStartChanges** function causes any previously requested topology changes that have not yet been committed to be ignored.

## See also

[BDA_CHANGE_STATE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff556518(v=vs.85))

[BdaCommitChanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/nf-bdasup-bdacommitchanges)

[KSMETHODSETID_BdaChangeSync](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethodsetid-bdachangesync)

[KSMETHOD_BDA_START_CHANGES](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-bda-start-changes)

[KStrMethodHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkshandler)