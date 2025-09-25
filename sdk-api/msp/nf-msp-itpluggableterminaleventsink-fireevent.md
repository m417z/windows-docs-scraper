# ITPluggableTerminalEventSink::FireEvent

## Description

The
**FireEvent** method results in a message that notifies the client application of a change in the pluggable terminal. For example, if the terminal is no longer available, the **event** member of the
[MSP_EVENT_INFO](https://learn.microsoft.com/windows/win32/api/msp/ns-msp-msp_event_info) structure is set to **ME_ADDRESS_EVENT** and the **type** member is set to **ADDRESS_TERMINAL_UNAVAILABLE**.

## Parameters

### `pMspEventInfo` [in]

Pointer to a const cast of the
[MSP_EVENT_INFO](https://learn.microsoft.com/windows/win32/api/msp/ns-msp-msp_event_info) structure.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITPluggableTerminalEventSink](https://learn.microsoft.com/windows/desktop/api/msp/nn-msp-itpluggableterminaleventsink)

[MSP_EVENT_INFO](https://learn.microsoft.com/windows/win32/api/msp/ns-msp-msp_event_info)