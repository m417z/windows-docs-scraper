# UcmConnectorChargingStateChanged function

## Description

Notifies the USB connector manager framework extension (UcmCx) with the updated charging state of the partner connector.

## Parameters

### `Connector` [in]

Handle to the connector object that the client driver received in the previous call to [UcmConnectorCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectorcreate).

### `ChargingState` [in]

One of the [UCM_CHARGING_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtypes/ne-ucmtypes-_ucm_charging_state)-typed flags that indicates the new charging state.

## Return value

**UcmConnectorChargingStateChanged** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method can return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) value.

## Remarks

If the client driver determines that the charging state is non-optimal, it should report slow or trickle charging to UcmCx. Then, the operating system notifies the user of this condition.

## See also

[UcmConnectorCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectorcreate)