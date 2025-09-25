# KSPROPERTY_STREAM enumeration

## Description

## Constants

### `KSPROPERTY_STREAM_ALLOCATOR`

Specify if the pin allocates stream buffers or can provide an allocator.

### `KSPROPERTY_STREAM_QUALITY`

Specify if the pin generates Quality Management complaints.

### `KSPROPERTY_STREAM_DEGRADATION`

Specify if the pin allows degradation strategies.

### `KSPROPERTY_STREAM_MASTERCLOCK`

Specify if the pin uses or produces a master clock that can be used for synchronization.

### `KSPROPERTY_STREAM_TIMEFORMAT`

Specify to retrieve the time format used on a particular pin connection.

### `KSPROPERTY_STREAM_PRESENTATIONTIME`

Specify to retrieve and set the current presentation time of a filter pin.

### `KSPROPERTY_STREAM_PRESENTATIONEXTENT`

Specify to query the stream extent.

### `KSPROPERTY_STREAM_FRAMETIME`

Specify to determine the duration of the next frame based on the particular media stream, and use that information to step-frame a sequence.

### `KSPROPERTY_STREAM_RATECAPABILITY`

Specify to allow a graph manager to query all connection points involved in the flow of a particular stream (obtained through KSPROPERTY_PIN_DATAROUTING) for their capability in adjusting a requested rate to the nominal rate.

### `KSPROPERTY_STREAM_RATE`

Specify in conjunction with KSPROPERTY_STREAM_RATECAPABILITY and use this to set the rate of a segment after querying the capability of the pin.

### `KSPROPERTY_STREAM_PIPE_ID`

Used internally for communication between the KSProxy system driver and AVStream.