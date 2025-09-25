# _BIDI_REQUEST_DATA structure

## Description

The BIDI_REQUEST_DATA structure holds a single bidi request.

## Members

### `dwReqNumber`

Specifies the index of the request, which is used to match a response with a request in a multirequest operation.

### `pSchema`

Pointer to a memory location containing the first byte of the schema string.

### `data`

Specifies a [BIDI_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/winspool/ns-winspool-_bidi_data) structure containing the data associated with the schema.

## See also

[BIDI_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/winspool/ns-winspool-_bidi_data)

[BIDI_REQUEST_CONTAINER](https://learn.microsoft.com/windows-hardware/drivers/ddi/winspool/ns-winspool-_bidi_request_container)