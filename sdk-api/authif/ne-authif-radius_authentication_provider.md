# RADIUS_AUTHENTICATION_PROVIDER enumeration

## Description

**Note** Internet Authentication Service (IAS) was renamed Network Policy Server (NPS) starting with Windows Server 2008. The content of this topic applies to both IAS and NPS. Throughout the text, NPS is used to refer to all versions of the service, including the versions originally referred to as IAS.

The
**RADIUS_AUTHENTICATION_PROVIDER** type enumerates the possible authentication providers that NPS can use.

## Constants

### `rapUnknown`

The authentication provider is unknown.

### `rapUsersFile`

A users' file provides the authentication information.

### `rapProxy`

Authentication is provided by a RADIUS proxy server.

### `rapWindowsNT`

Authentication is provided by Windows Domain Authentication.

### `rapMCIS`

Authentication is provided by a Microsoft Commercial Internet System (MCIS) database.

### `rapODBC`

Authentication is provided by an Open Database Connectivity (ODBC) compliant database.

### `rapNone`

Access is unauthenticated.

## Remarks

The **ratProvider** extended attribute in
[RADIUS_ATTRIBUTE_TYPE](https://learn.microsoft.com/windows/desktop/api/authif/ne-authif-radius_attribute_type) uses values from the
**RADIUS_AUTHENTICATION_PROVIDER** enumeration type.

## See also

[About NPS Extensions](https://learn.microsoft.com/windows/desktop/Nps/ias-about-internet-authentication-service)

[NPS Extensions Enumerations](https://learn.microsoft.com/windows/desktop/Nps/ias-internet-authentication-service-enumerations)

[NPS Extensions Reference](https://learn.microsoft.com/windows/desktop/Nps/ias-internet-authentication-service-reference)

[RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/authif/ns-authif-radius_attribute)

[RADIUS_ATTRIBUTE_TYPE](https://learn.microsoft.com/windows/desktop/api/authif/ne-authif-radius_attribute_type)