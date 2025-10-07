# DSTORAGE_QUEUE_DESC structure (dstorage.h)

Contains the properties of a DirectStorage queue for the queue's creation.

## Members

`SourceType`

The source type of requests that this DirectStorage queue can accept.

`Capacity`

The maximum number of requests that the queue can hold.

`Priority`

The priority of the requests in this queue.

`Name`

Optional name of the queue. Used for debugging.

`Device`

Optional device to use for writing to destination resources, and performing GPU decompression. The destination resource's device must match this device.

This member may be null. If you specify a null device, then the destination type must be [DSTORAGE_REQUEST_DESTINATION_MEMORY](https://learn.microsoft.com/windows/win32/dstorage/dstorage/ne-dstorage-dstorage_request_destination_type).

## Requirements

|   |   |
| ---- |:---- |
| **Header** | dstorage.h |