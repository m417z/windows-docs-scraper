# EAP_TYPE structure

## Description

The **EAP_TYPE** structure contains type and vendor identification information for an EAP method.

## Members

### `type`

The numeric type code for this EAP method.

**Note** For more information on the allocation of EAP method types, see section 6.2 of [RFC 3748](http://tools.ietf.org/html/rfc3748).

### `dwVendorId`

The vendor ID for the EAP method.

### `dwVendorType`

The numeric type code for the vendor of this EAP method.

## See also

[Common EAPHost API Structures](https://learn.microsoft.com/windows/win32/eaphost/common-eap-host-api-structures)