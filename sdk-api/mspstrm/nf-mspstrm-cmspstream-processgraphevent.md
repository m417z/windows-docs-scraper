# CMSPStream::ProcessGraphEvent

## Description

The
**ProcessGraphEvent** method is called by the MSPCall object to let the stream handle graph events. The default implementation returns S_OK and does nothing. Derived MSPs must override this method if they want to propagate graph events to the application or take some other action in response to graph events.

## Parameters

### `lEventCode`

Implementation-dependent descriptor of the graph event.

### `lParam1`

Implementation-dependent information on the graph event.

### `lParam2`

Implementation-dependent information on the graph event.

## See also

[CMSPStream](https://learn.microsoft.com/windows/desktop/api/mspstrm/nl-mspstrm-cmspstream)