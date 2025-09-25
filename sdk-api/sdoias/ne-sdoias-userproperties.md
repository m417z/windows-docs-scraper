# USERPROPERTIES enumeration

## Description

The values of the
**USERPROPERTIES** enumeration type enumerate the user properties supported by the SDO API.

## Constants

### `PROPERTY_USER_CALLING_STATION_ID`

The number from which the user must call.

### `PROPERTY_USER_SAVED_CALLING_STATION_ID`

The number stored in the user interface when calling-station ID is disabled.

### `PROPERTY_USER_RADIUS_CALLBACK_NUMBER`

The number at which to callback this user.

### `PROPERTY_USER_RADIUS_FRAMED_ROUTE`

Specifies static routes assigned to this user.

### `PROPERTY_USER_RADIUS_FRAMED_IP_ADDRESS`

Specifies a static IP address assigned to this user.

### `PROPERTY_USER_SAVED_RADIUS_CALLBACK_NUMBER`

The callback number stored in the user interface when callback is disabled.

### `PROPERTY_USER_SAVED_RADIUS_FRAMED_ROUTE`

The routes stored in the user interface when static routes are disabled.

### `PROPERTY_USER_SAVED_RADIUS_FRAMED_IP_ADDRESS`

The static IP address stored in the user interface when static IP addresses are disabled.

### `PROPERTY_USER_ALLOW_DIALIN`

Specifies whether dial-in allowed, denied, or determined by policy.

### `PROPERTY_USER_SERVICE_TYPE`

Specifies whether callback is enabled for this user. See
[RAS_USER_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-ras_user_1) for more information about the possible values for this property.

### `PROPERTY_USER_RADIUS_FRAMED_IPV6_ROUTE`

Specifies routing information to be configured for
the user on the NAS. See the Framed-IPv6-Route section in [RFC 3162](https://www.ietf.org/rfc/rfc3162.txt) for more information.

### `PROPERTY_USER_SAVED_RADIUS_FRAMED_IPV6_ROUTE`

Specifies saved routing information for
the user on the NAS. See the Framed-IPv6-Route section in [RFC 3162](https://www.ietf.org/rfc/rfc3162.txt) for more information.

### `PROPERTY_USER_RADIUS_FRAMED_INTERFACE_ID`

Used for IPv6. Specifies the interface identifier to be
configured for the user. See the Framed-Interface-Id section in [RFC 3162](https://www.ietf.org/rfc/rfc3162.txt) for more information.

### `PROPERTY_USER_SAVED_RADIUS_FRAMED_INTERFACE_ID`

Used for IPv6. Specifies the saved interface identifier for the user. See the Framed-Interface-Id section in [RFC 3162](https://www.ietf.org/rfc/rfc3162.txt) for more information.

### `PROPERTY_USER_RADIUS_FRAMED_IPV6_PREFIX`

Specifies an IPv6 prefix (and corresponding route)
to be configured for the user. See the Framed-IPv6-Prefix section in [RFC 3162](https://www.ietf.org/rfc/rfc3162.txt) for more information.

### `PROPERTY_USER_SAVED_RADIUS_FRAMED_IPV6_PREFIX`

Specifies an IPv6 prefix (and corresponding route)
saved for the user. See the Framed-IPv6-Prefix section in [RFC 3162](https://www.ietf.org/rfc/rfc3162.txt) for more information.

## Remarks

The properties that are available for a user object depend on where the user object is stored.

## See also

[ISdo](https://learn.microsoft.com/windows/desktop/api/sdoias/nn-sdoias-isdo)

[ISdoMachine::GetUserSDO](https://learn.microsoft.com/windows/desktop/api/sdoias/nf-sdoias-isdomachine-getusersdo)