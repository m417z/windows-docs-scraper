# XPS_SIGNATURE_STATUS enumeration

## Description

Describes the status of a document's digital signature.

## Constants

### `XPS_SIGNATURE_STATUS_INCOMPLIANT:1`

The signature violates one or more signing rules stated in section 10.2.1.2 of the [XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification). These rules describe the parts or relationships that must or must not be signed.

A signature that is incompliant must be created as such.
Changing signed content cannot make a valid signature incompliant. One example of an incompliant signature is the signature of a package that has an unknown relationships type at the root.

### `XPS_SIGNATURE_STATUS_INCOMPLETE:2`

The signature does not include parts that must be signed.

If a valid XPS signature is created and the XPS document contents are later modified, the signature will become incomplete or broken.
For example, removing a page from a FixedDocument makes the signature incomplete; it also breaks the signature, but the fact that the signature is incomplete is of greater importance.

### `XPS_SIGNATURE_STATUS_BROKEN:3`

This is a compliant digital signature, but it fails the signature validation routines described in the *Open Packaging Conventions* (refer to See Also).

Modification of the markup in a FixedPage that has been signed breaks the signature.

### `XPS_SIGNATURE_STATUS_QUESTIONABLE:4`

This is not an incompliant or broken digital signature, but the signed content (parts and relationships) includes elements or attributes from an unknown namespace introduced through the markup compatibility mechanisms.

### `XPS_SIGNATURE_STATUS_VALID:5`

This is a valid signature: it is not broken, incompliant, or questionable. The application, however, must still check the certificate trust chain, revocation lists, and expiration dates.

## Remarks

The digital signature status values correspond to section 10.2.1.2 in the [XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification).

The Open Packaging Conventions are specified in the 1st edition, Part 2, "Open Packaging Conventions," of [Standard ECMA-376, Office Open XML File Formats](https://www.ecma-international.org/publications-and-standards/standards/ecma-376/).

**Note** These resources may not be available in some languages

and countries.

## See also

[Standard ECMA-376, Office Open XML File Formats](https://www.ecma-international.org/publications-and-standards/standards/ecma-376/)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)