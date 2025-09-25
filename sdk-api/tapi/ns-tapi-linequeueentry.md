# LINEQUEUEENTRY structure

## Description

The
**LINEQUEUEENTRY** structure provides the information for a single queue entry. The
[LINEQUEUELIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linequeuelist) structure can contain an array of
**LINEQUEUEENTRY** structures. This structure requires TAPI 3.0 version negotiation.

## Members

### `dwQueueID`

Unique identifier for a queue. It is the responsibility of the agent handler to generate and maintain uniqueness of this identifier.

### `dwNameSize`

Size of the queue name string including the **null** terminator, in bytes.

### `dwNameOffset`

Offset from the beginning of the structure to a **null**-terminated string that specifies the name of the queue. The size of the string is specified by **dwNameSize**.

## See also

[About Call Center Controls](https://learn.microsoft.com/windows/desktop/Tapi/about-call-center-controls)

[LINEQUEUELIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linequeuelist)

[lineGetQueueList](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetqueuelista)