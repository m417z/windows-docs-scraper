# UcmConnectorTypeCCurrentAdChanged function

## Description

Notifies the USB connector manager framework extension (UcmCx) when the specified connector changes the current advertisement. Either the connector changes it (when it is DFP/Source), or the partner changed it (when it is UFP/Sink).

## Parameters

### `Connector` [in]

Handle to the connector object that the client driver received in the previous call to [UcmConnectorCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectorcreate).

### `CurrentAdvertisement` [in]

The new current advertisement of the connector indicated by one of the [UCM_TYPEC_CURRENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmtypes/ne-ucmtypes-_ucm_typec_current)-typed flags.

## Return value

**UcmConnectorTypeCCurrentAdChanged** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method can return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) value.

## Remarks

When using a Type-C connector for charging, the partner connector sends a current advertisement when it's attached to the local connector. That initial advertisement is report to UcmCx by calling [UcmConnectorTypeCAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectortypecattach). During the lifetime of the connection, the current level advertised by the source might change. The client driver must notify UcmCx about that change by calling method.

## See also

[UcmConnectorCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectorcreate)

[UcmConnectorTypeCAttach](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectortypecattach)

[UcmConnectorTypeCCurrentAdChanged](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucmconnectortypeccurrentadchanged)