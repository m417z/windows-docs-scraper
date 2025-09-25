# RADIUS_CODE enumeration

## Description

**Note** Internet Authentication Service (IAS) was renamed Network Policy Server (NPS) starting with Windows Server 2008. The content of this topic applies to both IAS and NPS.

The
**RADIUS_CODE** enumeration type enumerates the possible RADIUS packet codes.

## Constants

### `rcUnknown`

The packet type is unrecognized. This is used to indicate that the disposition of a request is not being set by this extension DLL.

### `rcAccessRequest`

RADIUS Access-Request packet. See
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information.

### `rcAccessAccept`

RADIUS Access-Accept packet. See
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information.

### `rcAccessReject`

RADIUS Access-Reject packet. See
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information.

### `rcAccountingRequest`

RADIUS Accounting-Request packet. See
[RFC 2866](https://www.ietf.org/rfc/rfc2866.txt) for more information.

### `rcAccountingResponse`

RADIUS Accounting-Response packet. See
[RFC 2866](https://www.ietf.org/rfc/rfc2866.txt) for more information.

### `rcAccessChallenge`

RADIUS Access-Challenge packet. See
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for more information.

### `rcDiscard`

The packet was discarded.

## See also

[About NPS Extensions](https://learn.microsoft.com/windows/desktop/Nps/ias-about-internet-authentication-service)

[GetResponse](https://learn.microsoft.com/previous-versions/ms688270(v=vs.85))

[NPS Extensions Enumerations](https://learn.microsoft.com/windows/desktop/Nps/ias-internet-authentication-service-enumerations)

[NPS Extensions Reference](https://learn.microsoft.com/windows/desktop/Nps/ias-internet-authentication-service-reference)

[RADIUS_EXTENSION_CONTROL_BLOCK](https://learn.microsoft.com/windows/desktop/api/authif/ns-authif-radius_extension_control_block)

[SetResponseType](https://learn.microsoft.com/previous-versions/ms688462(v=vs.85))