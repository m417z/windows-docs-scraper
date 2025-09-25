# RADIUS_VSA_FORMAT structure

## Description

**Note** Internet Authentication Service (IAS) was renamed Network Policy Server (NPS) starting with Windows Server 2008. The content of this topic applies to both IAS and NPS.

The
**RADIUS_VSA_FORMAT** structure represents the format of the string portion of a RADIUS vendor-specific attribute.

## Members

### `VendorId`

The SMI Network Management Private Enterprise Code of the vendor for this attribute.

### `VendorType`

Numeric identifier for the attribute assigned by the vendor.

### `VendorLength`

The combined size of the **VendorType**, **VendorLength**, **AttributeSpecific** members.

### `AttributeSpecific`

Array of bytes that contains information for this attribute.

## Remarks

The
**RADIUS_VSA_FORMAT** structure is useful for interpreting the **lpValue** member of a
[RADIUS_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/authif/ns-authif-radius_attribute) structure when the **dwAttrType** member has a value **ratVendorSpecific**.

See
[RFC 2865](https://www.ietf.org/rfc/rfc2865.txt) for a description of RADIUS vendor-specific attributes. See
[RFC 2548](https://www.ietf.org/rfc/rfc2548.txt) for examples of RADIUS vendor-specific attributes used by Microsoft.

## See also

[About NPS Extensions](https://learn.microsoft.com/windows/desktop/Nps/ias-about-internet-authentication-service)

[NPS Extensions Reference](https://learn.microsoft.com/windows/desktop/Nps/ias-internet-authentication-service-reference)

[NPS Extensions Structures](https://learn.microsoft.com/windows/desktop/Nps/ias-internet-authentication-service-structures)