# MSP_EVENT enumeration

## Description

The **MSP_EVENT** enumerator defines the type of event information contained in
[MSP_EVENT_INFO](https://learn.microsoft.com/windows/win32/api/msp/ns-msp-msp_event_info).

## Constants

### `ME_ADDRESS_EVENT:0`

The event buffer is an
[MSP_ADDRESS_EVENT_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms733454(v=vs.85)) structure.

### `ME_CALL_EVENT`

The event buffer is an
[MSP_CALL_EVENT_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms733464(v=vs.85)) structure.

### `ME_TSP_DATA`

The event buffer is an
[MSP_TSP_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms733475(v=vs.85)) structure.

### `ME_PRIVATE_EVENT`

The event buffer is an
[MSP_PRIVATE_EVENT_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms733472(v=vs.85)) structure.

### `ME_ASR_TERMINAL_EVENT`

### `ME_TTS_TERMINAL_EVENT`

### `ME_FILE_TERMINAL_EVENT`

### `ME_TONE_TERMINAL_EVENT`

## See also

[ITMSPAddress::GetEvent](https://learn.microsoft.com/windows/desktop/api/msp/nf-msp-itmspaddress-getevent)

[MSP_EVENT_INFO](https://learn.microsoft.com/windows/win32/api/msp/ns-msp-msp_event_info)

[Media Service Provider Interface (MSPI)](https://learn.microsoft.com/windows/desktop/Tapi/media-service-provider-interface-mspi-)