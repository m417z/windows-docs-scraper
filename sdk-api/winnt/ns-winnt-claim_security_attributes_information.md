# CLAIM_SECURITY_ATTRIBUTES_INFORMATION structure

## Description

The **CLAIM_SECURITY_ATTRIBUTES_INFORMATION** structure defines the security attributes for the claim.

## Members

### `Version`

The version of the security attribute. This must be CLAIM_SECURITY_ATTRIBUTES_INFORMATION_VERSION_V1.

### `Reserved`

This member is currently reserved and must be zero when setting an attribute and is ignored when getting an attribute.

### `AttributeCount`

The number of values.

### `Attribute`

The actual attribute.

### `Attribute.pAttributeV1`

Pointer to an array that contains the **AttributeCount** member of the [CLAIM_SECURITY_ATTRIBUTE_V1](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-claim_security_attribute_v1) structure.