# CLIENTPROPERTIES enumeration

## Description

The values of the
**CLIENTPROPERTIES** type enumerate the properties of a RADIUS client. The SDO computer is the RADIUS server.

## Constants

### `PROPERTY_CLIENT_REQUIRE_SIGNATURE`

Specifies whether the RADIUS server checks for a digital signature.

**Note** If client and server use Extensible Authentication Protocol (EAP), then they use digital signatures regardless of this property.

### `PROPERTY_CLIENT_UNUSED`

This value indicates that the property is not used at this time.

### `PROPERTY_CLIENT_SHARED_SECRET`

The secret shared by both the RADIUS client and RADIUS server.

### `PROPERTY_CLIENT_NAS_MANUFACTURER`

The manufacturer of the Network Access Server (NAS), that is the RADIUS client.

### `PROPERTY_CLIENT_ADDRESS`

The IP address of the RADIUS client.

### `PROPERTY_CLIENT_QUARANTINE_COMPATIBLE`

Used by NPS user interface to indicate whether a RADIUS Client can receive NAP specific quarantine attributes.

### `PROPERTY_CLIENT_ENABLED`

Specifies if the RADIUS Client is enabled. If the RADIUS Client is not enabled, the configuration is present but it is not applied by NPS.

### `PROPERTY_CLIENT_SECRET_TEMPLATE_GUID`

#### - PROPERTY_CLIENT_FILTER_VSAS

This value must be set before a client SDO object can be saved.

## See also

[IASCOMMONPROPERTIES](https://learn.microsoft.com/windows/desktop/api/sdoias/ne-sdoias-iascommonproperties)

[RADIUSPROPERTIES](https://learn.microsoft.com/windows/desktop/api/sdoias/ne-sdoias-radiusproperties)