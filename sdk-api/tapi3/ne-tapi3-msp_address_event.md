# MSP_ADDRESS_EVENT enumeration

## Description

The **MSP_ADDRESS_EVENT** constant is returned within the
[MSP_EVENT_INFO](https://learn.microsoft.com/windows/win32/api/msp/ns-msp-msp_event_info) struct by the
[GetEvent](https://learn.microsoft.com/windows/desktop/api/msp/nf-msp-itmspaddress-getevent) method when
[MSP_EVENT](https://learn.microsoft.com/windows/win32/api/msp/ne-msp-msp_event) is ME_ADDRESS_EVENT.

## Constants

### `ADDRESS_TERMINAL_AVAILABLE:0`

A new terminal arrived by PNP.

### `ADDRESS_TERMINAL_UNAVAILABLE`

A terminal has been removed by PNP.

## See also

[ITMSPAddress::GetEvent](https://learn.microsoft.com/windows/desktop/api/msp/nf-msp-itmspaddress-getevent)

[MSP_EVENT](https://learn.microsoft.com/windows/win32/api/msp/ne-msp-msp_event)

[MSP_EVENT_INFO](https://learn.microsoft.com/windows/win32/api/msp/ns-msp-msp_event_info)

[Media Service Provider Interface (MSPI)](https://learn.microsoft.com/windows/desktop/Tapi/media-service-provider-interface-mspi-)