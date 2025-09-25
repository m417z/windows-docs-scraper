# PPP_ATCP_INFO structure

## Description

The
**PPP_ATCP_INFO** structure contains the result of a PPP AppleTalk projection operation.

## Members

### `dwError`

Specifies the result of the PPP control protocol negotiation. A value of zero indicates success. A nonzero value indicates failure, and is the actual fatal error that occurred during the control protocol negotiation.

### `wszAddress`

Specifies a Unicode string that holds the client's AppleTalk address on the RAS connection.

## See also

[PPP_INFO](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ppp_info)

[RAS Administration Structures](https://learn.microsoft.com/windows/desktop/RRAS/ras-administration-structures)

[Remote Access Service Administration Reference](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-administration-reference)