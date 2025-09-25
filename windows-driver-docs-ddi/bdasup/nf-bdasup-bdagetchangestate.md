## Description

The **BdaGetChangeState** function returns the current change state of BDA topology.

## Parameters

### `pIrp` [in]

Points to the IRP for the request to get the current change state. The BDA minidriver receives this IRP with the [KSMETHOD_BDA_GET_CHANGE_STATE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-bda-get-change-state) request.

### `pChangeState` [out, optional]

Points to a variable that receives the current change state of BDA topology. The BDA change state can be one of the following values from the [BDA_CHANGE_STATE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff556518(v=vs.85)) enumerated type:

| Value | Description |
|--|--|
| BDA_CHANGES_COMPLETE | BDA topology changes are complete. |
| BDA_CHANGES_PENDING | BDA topology changes are pending. |

## Return value

Returns STATUS_SUCCESS or an appropriate error code.

## Remarks

A BDA minidriver calls the **BdaGetChangeState** function to retrieve the current change state of BDA topology after the minidriver receives a [KSMETHOD_BDA_GET_CHANGE_STATE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-bda-get-change-state) request of the [KSMETHODSETID_BdaChangeSync](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethodsetid-bdachangesync) method set from the network provider. BDA minidrivers define dispatch and filter-automation tables so that those minidrivers either dispatch the **BdaGetChangeState** function directly or intercept this request using an internal method ([KStrMethodHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkshandler)), which then calls the **BdaGetChangeState** function. For example, BDA minidrivers that intercept this request can obtain a pointer to the BDA filter from the passed IRP so that they can:

- Not only check for pending topology changes but also for pending changes on the filter.

- Return the current change state for both BDA topology and the BDA filter.

See [Defining Automation Tables](https://learn.microsoft.com/windows-hardware/drivers/stream/defining-automation-tables) and [Changing BDA Filter Properties](https://learn.microsoft.com/windows-hardware/drivers/stream/changing-bda-filter-properties) for more information.

## See also

[BDA_CHANGE_STATE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff556518(v=vs.85))

[KSMETHODSETID_BdaChangeSync](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethodsetid-bdachangesync)

[KSMETHOD_BDA_GET_CHANGE_STATE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-bda-get-change-state)

[KStrMethodHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkshandler)