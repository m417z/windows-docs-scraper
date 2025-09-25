## Description

Contains information about how a device is joined to Microsoft Azure Active Directory.

## Members

### `joinType`

An enumeration value that specifies the type of the join.

### `pJoinCertificate`

Representations of the certification for the join.

### `pszDeviceId`

The identifier of the device.

### `pszIdpDomain`

A string that represents Azure Active Directory (Azure AD).

### `pszTenantId`

The identifier of the joined Azure AD tenant.

### `pszJoinUserEmail`

The email address for the joined account.

### `pszTenantDisplayName`

The display name for the joined account.

### `pszMdmEnrollmentUrl`

The URL to use to enroll in the Mobile Device Management (MDM) service.

### `pszMdmTermsOfUseUrl`

The URL that provides information about the terms of use for the MDM service.

### `pszMdmComplianceUrl`

The URL that provides information about compliance for the MDM service.

### `pszUserSettingSyncUrl`

The URL for synchronizing user settings.

### `pUserInfo`

Information about the user account that was used to join a device to Azure AD.

## See also

[CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context)

[DSREG_JOIN_TYPE](https://learn.microsoft.com/windows/desktop/api/lmjoin/ne-lmjoin-dsreg_join_type)

[DSREG_USER_INFO](https://learn.microsoft.com/windows/desktop/api/lmjoin/ns-lmjoin-dsreg_user_info)