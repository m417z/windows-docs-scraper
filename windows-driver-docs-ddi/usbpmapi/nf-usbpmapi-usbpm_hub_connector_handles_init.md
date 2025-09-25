# USBPM_HUB_CONNECTOR_HANDLES_INIT function

## Description

Initializes a [**USBPM_HUB_CONNECTOR_HANDLES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/ns-usbpmapi-_usbpm_hub_connector_handles) structure.

## Parameters

### `HubConnectorHandles` [Out]

A pointer to a [**USBPM_HUB_CONNECTOR_HANDLES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/ns-usbpmapi-_usbpm_hub_connector_handles) structure to initialize.

### `ConnectorCount` [In]

The number of connectors on this hub.

### `ConnectorHandlesBuffer` [Out]

A pointer to a connector handle array of all the connectors on this hub.

## Remarks

## See also