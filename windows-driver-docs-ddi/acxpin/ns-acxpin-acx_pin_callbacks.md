## Description

The **ACX_PIN_CALLBACKS** structure specifies pin event callback functions.

## Members

### `Size`

The size of all of the data in the **ACX_PIN_CALLBACKS** structure in bytes.

### `EvtAcxPinSetDataFormat`

A pointer to an [EVT_ACX_PIN_SET_DATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/nc-acxpin-evt_acx_pin_set_dataformat) callback function.

### `EvtAcxPinRetrieveName`

A pointer to an [EVT_ACX_PIN_RETRIEVE_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/nc-acxpin-evt_acx_pin_retrieve_name) callback function.

### `EvtAcxPinRetrieveJackSinkInfo`

A pointer to an [EVT_ACX_PIN_RETRIEVE_JACK_SINK_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/nc-acxpin-evt_acx_pin_retrieve_jack_sink_info) callback function.

### `EvtAcxPinProcessJackRequest`

A pointer to an [EVT_ACX_OBJECT_PROCESS_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/nc-acxrequest-evt_acx_object_process_request) callback function.

### `EvtAcxPinConnected`

A pointer to an [EVT_ACX_PIN_CONNECTED](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/nc-acxpin-evt_acx_pin_connected) callback function.

### `EvtAcxPinDisconnected`

A pointer to an [EVT_ACX_PIN_DISCONNECTED](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/nc-acxpin-evt_acx_pin_disconnected) callback function.

### `EvtAcxPinDataFormatChangeNotification`

A pointer to an [EVT_ACX_PIN_DATAFORMAT_CHANGE_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/nc-acxpin-evt_acx_pin_dataformat_change_notification) callback function.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)