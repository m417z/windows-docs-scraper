# DSTORAGE_DESTINATION_BUFFER structure (dstorage.h)

Describes the destination for a request with [DSTORAGE_REQUEST_OPTIONS::DestinationType](https://learn.microsoft.com/windows/win32/dstorage/dstorage/ns-dstorage-dstorage_request_options) set to [DSTORAGE_REQUEST_DESTINATION_BUFFER](https://learn.microsoft.com/windows/win32/dstorage/dstorage/ne-dstorage-dstorage_request_destination_type).

## Members

`Resource`

Address of the resource to receive the final result of this request.

`Offset`

The offset, in bytes, in the buffer resource to write into.

`Size`

Number of bytes to write to the destination buffer.

## Requirements

|   |   |
| ---- |:---- |
| **Header** | dstorage.h |