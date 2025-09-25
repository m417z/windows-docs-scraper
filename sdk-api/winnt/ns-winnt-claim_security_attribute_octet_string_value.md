# CLAIM_SECURITY_ATTRIBUTE_OCTET_STRING_VALUE structure

## Description

The **CLAIM_SECURITY_ATTRIBUTE_OCTET_STRING_VALUE** structure specifies the **OCTET_STRING** value type of the claim security attribute.

## Members

### `pValue`

A pointer buffer that contains the **OCTET_STRING** value. The value is a series of bytes of the length indicated in the **ValueLength** member.

### `ValueLength`

The length, in bytes, of the **OCTET_STRING** value.