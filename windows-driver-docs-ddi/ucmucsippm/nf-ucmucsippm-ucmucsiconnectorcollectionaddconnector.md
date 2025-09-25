# UcmUcsiConnectorCollectionAddConnector function

## Description

Adds a connector to the connector collection object.

## Parameters

### `ConnectorCollectionObject` [in]

The handle to the connector collection object that the client driver retrieved in a previous call to [**UcmUcsiConnectorCollectionCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsippm/nf-ucmucsippm-ucmucsiconnectorcollectioncreate).

### `ConnectorInfo` [in]

A pointer to a [**UCMUCSI_CONNECTOR_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsippm/ns-ucmucsippm-_ucmucsi_connector_info) structure that contains information about the connector to add.

## Return value

Returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method can return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) value.

## Remarks

The client driver must not call **UcmUcsiConnectorCollectionAddConnector** after [**UcmUcsiPpmCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsippm/nf-ucmucsippm-ucmucsippmcreate) because it would have no effect on the already existing PPM object.

## See also

[**UCMUCSI_CONNECTOR_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsippm/ns-ucmucsippm-_ucmucsi_connector_info)

[**UcmUcsiConnectorCollectionCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsippm/nf-ucmucsippm-ucmucsiconnectorcollectioncreate)

[**UcmUcsiPpmCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsippm/nf-ucmucsippm-ucmucsippmcreate)