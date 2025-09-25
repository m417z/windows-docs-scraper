# _USBPM_HUB_CONNECTOR_HANDLES structure

## Description

Stores the connector handles for all connectors on a hub. This structure is used in the [**UsbPm_RetrieveHubConnectorHandles**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nf-usbpmapi-usbpm_retrievehubconnectorhandles) function.

## Members

### `HubHandle`

The handle of this hub.

### `ConnectorCount`

 The number of connectors on this hub.

### `ConnectorHandles`

A pointer to a connector handle array of all the connectors on this hub. The array is allocated by the Policy Manager is valid during the life time of the hub. The client driver must not change the array or release the array after use.

## Remarks

## See also