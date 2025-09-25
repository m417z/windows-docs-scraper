# WCN_VENDOR_EXTENSION_SPEC structure

## Description

The **WCN_VENDOR_EXTENSION_SPEC** structure contains data that defines a vendor extension.

## Members

### `VendorId`

Set this value to the SMI Enterprise ID Number of the vendor that defines the vendor extension. For example, the Microsoft ID is '311' (WCN_MICROSOFT_VENDOR_ID).

### `SubType`

The subtype, as defined by the first two bytes of the vendor extension. If the vendor has not provided the two-byte subtype prefix, use WCN_NO_SUBTYPE.

### `Index`

Distinguishes between multiple vendor extensions with the same VendorID and SubType. The index begins at zero.

### `Flags`

Applications must specify one of the following flag values:

| Value | Meaning |
| --- | --- |
| **WCN_FLAG_DISCOVERY_VE**<br><br>0x0001 | The vendor extension was not available before the session started. The vendor extension is not secure. |
| **WCN_FLAG_AUTHENTICATED_VE**<br><br>0x0002 | The vendor extension is authentic. Only devices that pass authentication can read or write authenticated vendor extensions. |
| **WCN_FLAG_ENCRYPTED_VE**<br><br>0x0004 | The vendor extension is authentic and encrypted. In addition to the guarantee of authenticated vendor extensions, vendor extensions are encrypted before transmission. |