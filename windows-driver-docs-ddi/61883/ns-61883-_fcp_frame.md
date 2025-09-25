# _FCP_FRAME structure

## Description

The FCP_FRAME structure describes a function control protocol (FCP) request.

## Members

### `ctype`

The command or response type as defined by the Command/Transaction Set (CTS) used for this request.

### `cts`

The CTS used for this FCP request. The CTS specifies the command set, the structure of the command/response field, and the rules of transactions used for sending FCP commands and responses.

### `payload`

The FCP request for this frame.

## See also

[AV_61883_REQUEST structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_av_61883_request)