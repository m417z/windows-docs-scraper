# UcmConnectorPowerDirectionChanged function

## Description

Notifies the USB connector manager framework extension (UcmCx) with the new power role of the partner connector.

## Parameters

### `Connector` [in]

Handle to the connector object that the client driver received in the previous call to [UcmConnectorCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectorcreate).

### `Success` [in]

Used to indicate failure of a power-role swap that was initiated by UcmCx using [EVT_UCM_CONNECTOR_SET_POWER_ROLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nc-ucmmanager-evt_ucm_connector_set_power_role).

If TRUE, the operation was successful. FALSE, otherwise.

### `CurrentPowerRole` [in]

One of the [UCM_POWER_ROLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtypes/ne-ucmtypes-_ucm_power_role)-typed flags that indicates the new data role.

## Remarks

**UcmConnectorPowerDirectionChanged** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this inline function can return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) value.

If the connector partner is attached, UcmCx updates the power role of the partner depending on the *CurrentPowerRole* value.

UcmCx can change the power role of a connector, and invokes [EVT_UCM_CONNECTOR_SET_POWER_ROLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nc-ucmmanager-evt_ucm_connector_set_power_role). In response to that call, the client should perform the PR_Swap operation, and indicate success/failure of the operation by calling **UcmConnectorPowerDirectionChanged**.

Alternatively, the client driver might choose to perform a role-swap autonomously, or the partner might perform a role-swap. In either case, when the role-swap has completed, the driver must report the new role to UcmCx using **UcmConnectorPowerDirectionChanged**.

## See also

- [UcmConnectorCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectorcreate)