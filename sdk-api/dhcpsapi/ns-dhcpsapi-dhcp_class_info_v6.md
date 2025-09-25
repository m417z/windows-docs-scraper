# DHCP_CLASS_INFO_V6 structure

## Description

The **DHCP_CLASS_INFO_V6** structure contains the information for a particular DHCPv6 user class or vendor class.

## Members

### `ClassName`

A pointer to a null-terminated Unicode string that contains the class name.

### `ClassComment`

A pointer to a null-terminated Unicode string that contains the comment for the class.

### `ClassDataLength`

The length of data as pointed to by **ClassData**.

### `IsVendor`

If **TRUE**, this information applies to a vendor class; if **FALSE**, it applies to a user class.

### `EnterpriseNumber`

 The vendor class identifier. It is default (0x00000000) for user class.

### `Flags`

This field MUST be set to zero (0x00000000) when sending and ignored on receipt.

### `ClassData`

Pointer to a BYTE blob that contains an array of bytes of length specified by **ClassDataLength**. This contains opaque data regarding a user class or a vendor class.

### `ClassData.size_is`

### `ClassData.size_is.ClassDataLength`