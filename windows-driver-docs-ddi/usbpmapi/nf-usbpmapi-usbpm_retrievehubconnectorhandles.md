# UsbPm_RetrieveHubConnectorHandles function

## Description

Retrieves connector handles for all connectors of a hub.

## Parameters

### `ClientHandle` [In]

The handle that the client driver received in a previous call to **[UsbPm_Register](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nf-usbpmapi-usbpm_register)**.

### `HubHandle` [In]

The handle to the hub.

### `HubConnectorHandles` [Out]

A pointer to a **[USBPM_HUB_CONNECTOR_HANDLES](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/ns-usbpmapi-_usbpm_hub_connector_handles)** structures that contains the connector handles. Initialize this structure by calling **[USBPM_HUB_CONNECTOR_HANDLES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nf-usbpmapi-usbpm_hub_connector_handles_init)**. The array is allocated by the Policy Manager is valid during the life time of the hub. The client driver must not change the array or release the array after use.

## Return value

This function returns NTSTATUS.

## Remarks

## See also