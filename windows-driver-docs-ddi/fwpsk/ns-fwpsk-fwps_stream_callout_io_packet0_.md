# FWPS_STREAM_CALLOUT_IO_PACKET0_ structure

## Description

The **FWPS_STREAM_CALLOUT_IO_PACKET0** structure describes the data passed by the filter engine to a
callout's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function when filtering a
data stream.

**Note** **FWPS_STREAM_CALLOUT_IO_PACKET0** is a specific version of **FWPS_STREAM_CALLOUT_IO_PACKET**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Members

### `streamData`

A pointer to an
[FWPS_STREAM_DATA0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_stream_data0_) structure that
describes the portion of the data stream available to the callout driver's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function for processing.

### `missedBytes`

The number of bytes in the data stream that are missing since the last time the callout driver's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function was called. This
member is nonzero if a higher weight filter in the filter engine prevented the callout driver's
classifyFn callout function from processing a
portion of the data stream.

### `countBytesRequired`

A value set by a callout's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function. This value
specifies how many additional bytes of stream data are required by the callout function if it sets the
**streamAction** member to **FWPS_STREAM_ACTION_NEED_MORE_DATA**. The filter engine waits until it
receives at least this many additional bytes of stream data before calling the callout driver's
classifyFn callout function again.

If a callout's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function sets the
**streamAction** member to a value other than **FWPS_STREAM_ACTION_NEED_MORE_DATA**, then it should set
this member to zero.

### `countBytesEnforced`

A value set by a callout's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function. This value
specifies the number of leading bytes of data in the portion of the data stream being processed to which
the action specified by the
**streamAction** member or by the action returned by the callout function applies. Any remaining data
in the stream buffer will be passed to the callout driver again the next time the filter engine calls
the callout driver's
classifyFn callout function.

### `streamAction`

An **FWPS_STREAM_ACTION_TYPE** value set by a callout's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function that specifies
the action to be applied to the data stream. This action is independent of the action returned by the
callout function. A callout's
classifyFn callout function sets this member
to one of the following:

#### FWPS_STREAM_ACTION_NONE

No stream-specific action is required.

#### FWPS_STREAM_ACTION_ALLOW_CONNECTION

Indicates that all future data segments belonging to a flow are permitted. In this case, WFP stops classifying any data segments to the callout and attempts to offload the flow to the hardware such that no more inspection overhead is incurred.

#### FWPS_STREAM_ACTION_NEED_MORE_DATA

More stream data is required by the callout function.

#### FWPS_STREAM_ACTION_DROP_CONNECTION

The stream connection should be dropped. A callout's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function should only set
the
**streamAction** member to this value if the
**action.type** member of the
[FWPS_FILTER0](https://learn.microsoft.com/windows/win32/api/fwpstypes/ns-fwpstypes-fwps_filter0) structure that the filter
engine passed to the callout driver's
classifyFn callout function contains the value **FWP_ACTION_CALLOUT_UNKNOWN**. If a callout's
classifyFn callout function sets the
**streamAction** member to this value when the
**action.type** member of the **FWPS_FILTER0** structure contains the value
**FWP_ACTION_CALLOUT_INSPECTION**, the connection will not be dropped.

#### FWPS_STREAM_ACTION_DEFER

Processing of the stream data will be deferred until the callout driver calls the
[FwpsStreamContinue0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsstreamcontinue0) function. This
action can only be set for an inbound data stream.

Deferring an inbound data stream will cause the network stack to stop acknowledging data received
from the sender. This will lead to a reduction in the size of the sliding TCP window. A callout driver
can use this behavior to implement flow control to slow down the incoming data rate.

The **FWPS_STREAM_ACTION_TYPE_MAX** value is a maximum value for testing purposes.

If a callout's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function sets this member
to a value other than **FWPS_STREAM_ACTION_NONE**, then the action returned by the callout function is
ignored by the filter engine.

## Remarks

The filter engine passes a pointer to an **FWPS_STREAM_CALLOUT_IO_PACKET0** structure to a callout's
[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/) callout function as the
*layerData* parameter when filtering a data stream.

## See also

[FWPS_STREAM_DATA0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_stream_data0_)

[FwpsStreamContinue0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsstreamcontinue0)

[Types of Callouts](https://learn.microsoft.com/windows-hardware/drivers/network/types-of-callouts)

[classifyFn](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/)