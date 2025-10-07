# DSTORAGE_QUEUE_INFO structure (dstorage.h)

Contains the properties and current state of a DirectStorage queue.

## Members

`Desc`

The [DSTORAGE_QUEUE_DESC](https://learn.microsoft.com/windows/win32/dstorage/dstorage/ns-dstorage-dstorage_queue_desc) structure used for the queue's creation.

`EmptySlotCount`

The number of available empty slots. If a queue is empty, then the number of empty slots equals `capacity - 1`. The reserved slot is used to distinguish between empty and full cases.

`RequestCountUntilAutoSubmit`

The number of entries that would need to be enqueued in order to trigger automatic submission.

## Requirements

|   |   |
| ---- |:---- |
| **Header** | dstorage.h |