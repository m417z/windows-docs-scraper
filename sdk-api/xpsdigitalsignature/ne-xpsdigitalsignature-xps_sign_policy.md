# XPS_SIGN_POLICY enumeration

## Description

A bitwise enumerator that indicates which, if any, optional parts of an XPS document are signed.

## Constants

### `XPS_SIGN_POLICY_NONE:0`

No optional parts or relationships are signed.

### `XPS_SIGN_POLICY_CORE_PROPERTIES:0x1`

The CoreProperties part and the relationships that include it are signed.

### `XPS_SIGN_POLICY_SIGNATURE_RELATIONSHIPS:0x2`

The signature relationships from the signature origin part are signed. *Signature relationships* are those relationships that have a *digital signature* relationship type.

**Note**

Setting the **XPS_SIGN_POLICY_SIGNATURE_RELATIONSHIPS** flag will cause the signature relationships that start from the signature origin part to be signed. Signatures that are made with this flag set will break when new signatures are added later, because new signatures add new signature relationships.

### `XPS_SIGN_POLICY_PRINT_TICKET:0x4`

The PrintTicket part and the relationships that include it are signed.

### `XPS_SIGN_POLICY_DISCARD_CONTROL:0x8`

The DiscardControl part and the relationships that include it are signed.

### `XPS_SIGN_POLICY_ALL:0xf`

The CoreProperties part and the relationships that include it, the digital signature relationship type from the SignatureOrigin part, the PrintTicket part and the relationships that include it, and the DiscardControl part and the relationships that include it are all signed.

**Note**

Setting the **XPS_SIGN_POLICY_ALL** sets the **XPS_SIGN_POLICY_SIGNATURE_RELATIONSHIPS** flag, which will cause the signature relationships that start from the signature origin part to be signed. Signatures that are made with this flag set will break when new signatures are added later, because new signatures add new signature relationships.

## Remarks

More than one value may be set.

## See also

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)