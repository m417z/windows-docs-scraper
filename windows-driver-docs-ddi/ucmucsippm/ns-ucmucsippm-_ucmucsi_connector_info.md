# _UCMUCSI_CONNECTOR_INFO structure

## Description

Stores information about connectors that cannot be obtained by sending UCSI commands such as GetConnectorCapability. Initialize this structure by calling [**UCMUCSI_CONNECTOR_INFO_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsippm/nf-ucmucsippm-ucmucsi_connector_info_init). This structure is used in the [**UcmUcsiConnectorCollectionAddConnector**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsippm/nf-ucmucsippm-ucmucsiconnectorcollectionaddconnector) call.

## Members

### `Size`

Size of this structure.

### `ConnectorId`

Connector ID that maps a USB Type-C connector to USB port.

## Remarks

## See also