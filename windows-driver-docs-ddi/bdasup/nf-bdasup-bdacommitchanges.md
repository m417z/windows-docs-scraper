## Description

The **BdaCommitChanges** function commits the changes to BDA topology that have occurred since the last call to the **BdaStartChanges** function.

## Parameters

### `pIrp` [in]

Points to the IRP for the request to commit changes. The BDA minidriver receives this IRP with the [KSMETHOD_BDA_COMMIT_CHANGES](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-bda-commit-changes) request.

## Return value

Returns STATUS_SUCCESS or an appropriate error code.

## Remarks

A BDA minidriver calls the **BdaCommitChanges** function to commit a set of BDA topology changes after the minidriver receives a [KSMETHOD_BDA_COMMIT_CHANGES](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-bda-commit-changes) request of the [KSMETHODSETID_BdaChangeSync](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethodsetid-bdachangesync) method set from the network provider. BDA minidrivers define dispatch and filter-automation tables so that those minidrivers either dispatch the **BdaCommitChanges** function directly or intercept this request using an internal method ([KStrMethodHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkshandler)), which then calls the **BdaCommitChanges** function. For example, BDA minidrivers that intercept this request can obtain a pointer to the BDA filter from the passed IRP so that they can:

- Set the new list of resources for the filter to the pending list of resources.

- Set the change state of the filter to BDA_CHANGES_COMPLETE.

- Commit the resources on the underlying device.

See [Defining Automation Tables](https://learn.microsoft.com/windows-hardware/drivers/stream/defining-automation-tables) and [Changing BDA Filter Properties](https://learn.microsoft.com/windows-hardware/drivers/stream/changing-bda-filter-properties) for more information.

## See also

[BDA_CHANGE_STATE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff556518(v=vs.85))

[BdaCheckChanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/nf-bdasup-bdacheckchanges)

[BdaStartChanges](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/nf-bdasup-bdastartchanges)

[KSMETHODSETID_BdaChangeSync](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethodsetid-bdachangesync)

[KSMETHOD_BDA_COMMIT_CHANGES](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-bda-commit-changes)

[KStrMethodHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkshandler)