# LINEQUEUELIST structure

## Description

The
**LINEQUEUELIST** structure describes a list of queues. This structure can contain an array of
[LINEQUEUEENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linequeueentry) structures. The
[lineGetQueueList](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetqueuelista) function returns the
**LINEQUEUELIST** structure.
**LINEQUEUELIST** requires TAPI 3.0 version negotiation.

## Members

### `dwTotalSize`

Total size allocated to this structure, in bytes.

### `dwNeededSize`

Size needed to hold all the information requested, in bytes.

### `dwUsedSize`

Size of the portion of this structure that contains useful information, in bytes.

### `dwNumEntries`

Number of
[LINEQUEUEENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linequeueentry) structures that appear in the list array. The value is zero if no queue is available.

### `dwListSize`

Size of the agent information array, in bytes.

### `dwListOffset`

Offset from the beginning of the structure to an array of
[LINEQUEUEENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linequeueentry) structure that specify information about agents. The **dwListOffset** member is **dwNumEntries** times SIZEOF(LINEQUEUEENTRY). The size of the field is specified by **dwListSize**.

## See also

[About Call Center Controls](https://learn.microsoft.com/windows/desktop/Tapi/about-call-center-controls)

[LINEQUEUEENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linequeueentry)

[lineGetQueueList](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetqueuelista)