# LINEQUEUEINFO structure

## Description

The
**LINEQUEUEINFO** structure provides information about a queue on a line device. The
[lineGetQueueInfo](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetqueueinfo) function returns the
**LINEQUEUEINFO** structure. This structure requires TAPI 3.0 version negotiation.

## Members

### `dwTotalSize`

Total size allocated to this structure, in bytes.

### `dwNeededSize`

Size needed to hold all the information requested, in bytes.

### `dwUsedSize`

Size of the portion of this structure that contains useful information, in bytes.

### `dwMeasurementPeriod`

Period for which the switch or implementation stores and calculates information, in seconds. For example, **dwTotalCallsAbandoned** holds the number of abandoned calls; **dwMeasurementPeriod** would indicate if this value referenced the calls queued in an hour, day, or month, for example.

### `dwTotalCallsQueued`

Total number of incoming calls for this queue during this measurement period.

### `dwCurrentCallsQueued`

Number of incoming calls currently waiting.

### `dwTotalCallsAbandoned`

Number of abandoned calls during this measurement period.

### `dwTotalCallsFlowedIn`

Total number of calls that flowed into this queue (passed down from another queue or ACD group) during this measurement period.

### `dwTotalCallsFlowedOut`

Total number of calls that flowed out of this queue (passed down to another queue or ACD group) during this measurement period.

### `dwLongestEverWaitTime`

Longest time any call has waited in queue, in seconds.

### `dwCurrentLongestWaitTime`

Longest time that a current call (call still in queue) has been waiting, in seconds.

### `dwAverageWaitTime`

Average time that a call has waited in queue, in seconds.

### `dwFinalDisposition`

Final disposition of the queue.

## See also

[About Call Center Controls](https://learn.microsoft.com/windows/desktop/Tapi/about-call-center-controls)

[lineGetQueueInfo](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetqueueinfo)