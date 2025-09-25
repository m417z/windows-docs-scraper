# UcmConnectorDataDirectionChanged function

## Description

Notifies the USB connector manager framework extension (UcmCx) with the new data role of a change in data role.

## Parameters

### `Connector` [in]

Handle to the connector object that the client driver received in the previous call to [UcmConnectorCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectorcreate).

### `Success` [in]

Used to indicate failure of a data-role swap that was initiated by UcmCx using [EVT_UCM_CONNECTOR_SET_DATA_ROLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nc-ucmmanager-evt_ucm_connector_set_data_role).

If TRUE, the operation was successful. FALSE, otherwise.

### `CurrentDataRole` [in]

A [UCM_TYPEC_PARTNER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtypes/ne-ucmtypes-_ucm_typec_partner) value that indicates the new data role.

## Remarks

**UcmConnectorDataDirectionChanged** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this inline function can return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) value.

If the connector partner is attached, UcmCx updates the data role of the partner depending on the *CurrentDataRole* value. For example, if the client driver changes the data role to **UcmTypeCPortStateUfp**, UcmCx updates the role of the connector partner to **UcmTypeCPortStateDfp**.

UcmCx can change the data role of a connector, and invokes [EVT_UCM_CONNECTOR_SET_DATA_ROLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nc-ucmmanager-evt_ucm_connector_set_data_role). In response to that call, the client should perform the DR_Swap operation, and indicate success/failure of the operation by calling **UcmConnectorDataDirectionChanged**.

Alternatively, the client driver might choose to perform a role-swap autonomously, or the partner might perform a role-swap. In either case, when the role-swap has completed, the driver must report the new role to UcmCx using **UcmConnectorDataDirectionChanged**.

## See also

- [UcmConnectorCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectorcreate)