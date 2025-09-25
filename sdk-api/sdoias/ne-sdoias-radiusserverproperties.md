# RADIUSSERVERPROPERTIES enumeration

## Description

The values of the
**RADIUSSERVERPROPERTIES** enumeration type enumerate the properties of the RADIUS server, that is the SDO computer.

## Constants

### `PROPERTY_RADIUSSERVER_AUTH_PORT`

Comma separated list of the UDP ports over which RADIUS authentication packets are sent and received.

### `PROPERTY_RADIUSSERVER_AUTH_SECRET`

The shared secret for authentication.

### `PROPERTY_RADIUSSERVER_ACCT_PORT`

Comma separated list of the UDP ports over which RADIUS authentication packets are sent and received.

### `PROPERTY_RADIUSSERVER_ACCT_SECRET`

The shared secret for accounting.

### `PROPERTY_RADIUSSERVER_ADDRESS`

The IP address of the server, or a DNS name that corresponds to the server.

### `PROPERTY_RADIUSSERVER_FORWARD_ACCT_ONOFF`

Specifies whether to forward, that is proxy, accounting packets.

### `PROPERTY_RADIUSSERVER_PRIORITY`

Specifies the priority for server. Lower priorities have higher precedence.

### `PROPERTY_RADIUSSERVER_WEIGHT`

Specifies the weight for the server. If two servers have the same priority, then weight is used to determine which server is used.

### `PROPERTY_RADIUSSERVER_TIMEOUT`

Specifies the timeout for the server.

### `PROPERTY_RADIUSSERVER_MAX_LOST`

The number of packets that can be dropped in a row before the server is considered unavailable.

### `PROPERTY_RADIUSSERVER_BLACKOUT`

Number of seconds that are waited before checking if an unavailable server is available again.

### `PROPERTY_RADIUSSERVER_SEND_SIGNATURE`

Specifies whether the Message-Authenticator attribute of [RFC 3579](https://www.ietf.org/rfc/rfc3579.txt) is sent by the server or not. It is always sent for EAP authentications.

### `PROPERTY_RADIUSSERVER_AUTH_SECRET_TEMPLATE_GUID`

### `PROPERTY_RADIUSSERVER_ACCT_SECRET_TEMPLATE_GUID`

## See also

[IASCOMMONPROPERTIES](https://learn.microsoft.com/windows/desktop/api/sdoias/ne-sdoias-iascommonproperties)