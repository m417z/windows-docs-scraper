# DSTORAGE_ERROR_FIRST_FAILURE structure (dstorage.h)

Structure to receive the detailed record of the first failed DirectStorage request.

## Members

`HResult`

The **HRESULT** code of the failure.

`CommandType`

Type of the **Enqueue** command that caused the failure.

`Request`

The parameters passed to the **Enqueue** call.

`Status`

The parameters passed to the **Enqueue** call.

`Signal`

The parameters passed to the **Enqueue** call.

## Requirements

|   |   |
| ---- |:---- |
| **Header** | dstorage.h |