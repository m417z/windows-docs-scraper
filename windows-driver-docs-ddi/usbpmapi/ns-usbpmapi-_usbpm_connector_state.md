# _USBPM_CONNECTOR_STATE structure

## Description

Describes the state of a connector. This structure is used in the [**UsbPm_RetrieveConnectorState**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nf-usbpmapi-usbpm_retrieveconnectorstate) call. The client driver must initialize this structure by calling [**USBPM_CONNECTOR_STATE_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nf-usbpmapi-usbpm_connector_state_init).

## Members

### `ConnectorHandle`

A handle to this connector.

### `ChangeToken`

The change token number of this state. This value is changed for every connector state change.

### `Attached`

Indicates whether this connector is attached.

### `AttachCount`

Indicates the number of attached events that have occurred on this connector. If client driver sees the transition from one “Attached” state to another “Attached” state but with different “AttachCount”, it indicates two attaches and with two different port partners.

### `Partner`

The type of the port partner, defined in the [**USBC_PARTNER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbctypes/ne-usbctypes-_usbc_partner) enumeration.

### `CurrentAdvertisement`

The amount of Type-C current advertised.

### `PdConnState`

Indicates the PD contract state over the connection on this connector.

### `Rdo`

The PD Request Data Object that has sent to the port partner of this connector. See [**USBC_PD_REQUEST_DATA_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbctypes/ns-usbctypes-_usbc_pd_request_data_object).

### `DataRole`

Indicates the USB Type-C data role of the connector, defined in the [**USBC_DATA_ROLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbctypes/ne-usbctypes-_usbc_data_role) enumeration.

### `PowerRole`

Indicates the USB Type-C power role of the connector, defined in the [**USBC_POWER_ROLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbctypes/ne-usbctypes-_usbc_power_role) enumeration.

### `SourceCapsCount`

The number of power data objects in the source caps array.

### `SourceCaps`

The source capabilities of the connector. See [**USBC_PD_POWER_DATA_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbctypes/ns-usbctypes-_usbc_pd_power_data_object).

### `SinkCapsCount`

The number of power data objects in the corresponding array.

### `SinkCaps`

The sink capability of the connector. See [**USBC_PD_POWER_DATA_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbctypes/ns-usbctypes-_usbc_pd_power_data_object).

### `PartnerSourceCapsCount`

The number of power data objects in the corresponding array.

### `PartnerSourceCaps`

The source capabilities of the port partner in the corresponding array. See [**USBC_PD_POWER_DATA_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbctypes/ns-usbctypes-_usbc_pd_power_data_object).

### `PdAlternateModesEnteredCount`

The number of alternate modes entered.

## Remarks

## See also