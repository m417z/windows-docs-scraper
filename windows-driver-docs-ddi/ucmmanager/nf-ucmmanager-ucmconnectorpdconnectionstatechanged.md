# UcmConnectorPdConnectionStateChanged function

## Description

Notifies the USB connector manager framework extension (UcmCx) with the connection capabilities of the currently negotiated PD contract (if any).

## Parameters

### `Connector` [in]

Handle to the connector object that the client driver received in the previous call to [UcmConnectorCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectorcreate).

### `Params` [in]

Pointer to a [UCM_CONNECTOR_PD_CONN_STATE_CHANGED_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/ns-ucmmanager-_ucm_connector_pd_conn_state_changed_params) structure contains driver-supplied state of the connector.

## Return value

**UcmConnectorPdConnectionStateChanged** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method can return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) value.

## See also

[UcmConnectorCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectorcreate)