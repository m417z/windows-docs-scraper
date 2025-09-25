# ITPluggableTerminalEventSinkRegistration::RegisterSink

## Description

The
**RegisterSink** method registers the application for pluggable terminal event notification.

## Parameters

### `pEventSink` [in]

Pointer to the
[ITPluggableTerminalEventSink](https://learn.microsoft.com/windows/desktop/api/msp/nn-msp-itpluggableterminaleventsink) interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITPluggableTerminalEventSink](https://learn.microsoft.com/windows/desktop/api/msp/nn-msp-itpluggableterminaleventsink)

[ITPluggableTerminalEventSinkRegistration](https://learn.microsoft.com/windows/desktop/api/msp/nn-msp-itpluggableterminaleventsinkregistration)

[UnregisterSink](https://learn.microsoft.com/windows/desktop/api/msp/nf-msp-itpluggableterminaleventsinkregistration-unregistersink)