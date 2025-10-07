# DSTORAGE_DESTINATION union (dstorage.h)

Describes the destination for a DirectStorage request. For a request, the value of `request.Options.DestinationType` determines which of these union fields is active. See [IDStorageQueue::EnqueueRequest](https://learn.microsoft.com/windows/win32/dstorage/dstorage/nf-dstorage-idstoragequeue-enqueuerequest).

## Members

`Memory`

See [DSTORAGE_DESTINATION_MEMORY](https://learn.microsoft.com/windows/win32/dstorage/dstorage/ns-dstorage-dstorage_destination_memory).

`Buffer`

See [DSTORAGE_DESTINATION_BUFFER](https://learn.microsoft.com/windows/win32/dstorage/dstorage/ns-dstorage-dstorage_destination_buffer).

`Texture`

See [DSTORAGE_DESTINATION_TEXTURE_REGION](https://learn.microsoft.com/windows/win32/dstorage/dstorage/ns-dstorage-dstorage_destination_texture_region).

`MultipleSubresources`

See [DSTORAGE_DESTINATION_MULTIPLE_SUBRESOURCES](https://learn.microsoft.com/windows/win32/dstorage/dstorage/ns-dstorage-dstorage_destination_multiple_subresources).

`Tiles`

See [DSTORAGE_DESTINATION_TILES](https://learn.microsoft.com/windows/win32/dstorage/dstorage/ns-dstorage-dstorage_destination_tiles).

`MultipleSubresourcesRange`

See [DSTORAGE_DESTINATION_MULTIPLE_SUBRESOURCES_RANGE](https://learn.microsoft.com/windows/win32/dstorage/dstorage/ns-dstorage-dstorage_destination_multiple_subresources_range).

## Requirements

|   |   |
| ---- |:---- |
| **Header** | dstorage.h |