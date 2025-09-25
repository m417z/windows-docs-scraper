# MSP_EVENT_INFO structure

## Description

The
**MSP_EVENT_INFO** structure defines the type of event returned by the
[GetEvent](https://learn.microsoft.com/windows/desktop/api/msp/nf-msp-itmspaddress-getevent) method.

## Members

### `dwSize`

Total size of structure returned.

### `Event`

### `hCall`

MSP handle; may be **NULL**.

### `MSP_ADDRESS_EVENT_INFO`

Struct returned if MSP event is ME_ADDRESS_EVENT.

### `MSP_ADDRESS_EVENT_INFO.Type`

Describes the
[msp address event](https://learn.microsoft.com/windows/win32/api/msp/ne-msp-msp_address_event) of the event that has occurred.

### `MSP_ADDRESS_EVENT_INFO.pTerminal`

Pointer to
[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal) interface.

### `MSP_CALL_EVENT_INFO`

Struct returned if MSP event is ME_CALL_EVENT.

### `MSP_CALL_EVENT_INFO.Type`

Indicates type of
[MSP_CALL_EVENT](https://learn.microsoft.com/windows/win32/api/msp/ne-msp-msp_call_event) that has occurred.

### `MSP_CALL_EVENT_INFO.Cause`

### `MSP_CALL_EVENT_INFO.pStream`

Pointer to
[ITStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itstream) interface on which event occurred.

### `MSP_CALL_EVENT_INFO.pTerminal`

Pointer to
[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal) interface on which event occurred.

### `MSP_CALL_EVENT_INFO.hrError`

Indicates error, if one has happened.

### `MSP_TSP_DATA`

Struct returned if MSP event is ME_TSP_DATA.

### `MSP_TSP_DATA.dwBufferSize`

Size of buffer returned.

Buffer size, in bytes.

### `MSP_TSP_DATA.pBuffer`

Pointer to buffer.

### `MSP_PRIVATE_EVENT_INFO`

Struct returned if MSP event is ME_PRIVATE_EVENT.

### `MSP_PRIVATE_EVENT_INFO.pEvent`

MSP event.

##### pEvent.pEvent

Pointer to [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface of private object on which event has occurred.

### `MSP_PRIVATE_EVENT_INFO.lEventCode`

### `MSP_FILE_TERMINAL_EVENT_INFO`

### `MSP_FILE_TERMINAL_EVENT_INFO.pParentFileTerminal`

### `MSP_FILE_TERMINAL_EVENT_INFO.pFileTrack`

### `MSP_FILE_TERMINAL_EVENT_INFO.TerminalMediaState`

### `MSP_FILE_TERMINAL_EVENT_INFO.ftecEventCause`

### `MSP_FILE_TERMINAL_EVENT_INFO.hrErrorCode`

### `MSP_ASR_TERMINAL_EVENT_INFO`

### `MSP_ASR_TERMINAL_EVENT_INFO.pASRTerminal`

### `MSP_ASR_TERMINAL_EVENT_INFO.hrErrorCode`

### `MSP_TTS_TERMINAL_EVENT_INFO`

### `MSP_TTS_TERMINAL_EVENT_INFO.pTTSTerminal`

### `MSP_TTS_TERMINAL_EVENT_INFO.hrErrorCode`

### `MSP_TONE_TERMINAL_EVENT_INFO`

### `MSP_TONE_TERMINAL_EVENT_INFO.pToneTerminal`

### `MSP_TONE_TERMINAL_EVENT_INFO.hrErrorCode`

###### - MSP_PRIVATE_EVENT_INFO.pEvent.pEvent

Pointer to [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface of private object on which event has occurred.

## See also

[ITMSPAddress::GetEvent](https://learn.microsoft.com/windows/desktop/api/msp/nf-msp-itmspaddress-getevent)

[Media Service Provider Interface (MSPI)](https://learn.microsoft.com/windows/desktop/Tapi/media-service-provider-interface-mspi-)