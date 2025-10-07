# DSTORAGE_CUSTOM_DECOMPRESSION_RESULT structure (dstorage.h)

The result of a custom decompression operation. If the request failed, then the *Result* code is passed back through the standard DirectStorage status/error reporting mechanism.

## Members

`Id`

The identifier for the request, from [DSTORAGE_CUSTOM_DECOMPRESSION_REQUEST](https://learn.microsoft.com/windows/win32/dstorage/dstorage/ns-dstorage-dstorage_custom_decompression_request).

`Result`

The result of this decompression. **S_OK** indicates success.

## Requirements

|   |   |
| ---- |:---- |
| **Header** | dstorage.h |