# AUTHZ_SECURITY_ATTRIBUTES_INFORMATION structure

## Description

The **AUTHZ_SECURITY_ATTRIBUTES_INFORMATION** structure specifies one or more security attributes.

## Members

### `Version`

The version of this structure. Currently the only value supported is 1.

### `Reserved`

Reserved. Do not use.

### `AttributeCount`

The number of attributes specified by the **Attribute** member.

### `Attribute`

### `Attribute.pAttributeV1`

An array of [AUTHZ_SECURITY_ATTRIBUTE_V1](https://learn.microsoft.com/windows/desktop/api/authz/ns-authz-authz_security_attribute_v1) structures of the length of the **AttributeCount** member.

## See also

[AuthzModifySecurityAttributes](https://learn.microsoft.com/windows/desktop/api/authz/nf-authz-authzmodifysecurityattributes)