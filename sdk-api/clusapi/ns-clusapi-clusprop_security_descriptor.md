# CLUSPROP_SECURITY_DESCRIPTOR structure

## Description

Describes a security descriptor. It is used as an entry in a
[value list](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/value-lists) and consists of:

* A [CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value) structure indicating the format
  and type of the resource class information.
* A security descriptor in
  [self-relative](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly)
  format.

## Members

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.sd`

Security descriptor in
[self-relative](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) format.
For more information about self-relative security descriptors, see
[Absolute and Self-Relative Security Descriptors](https://learn.microsoft.com/windows/desktop/SecAuthZ/absolute-and-self-relative-security-descriptors).

### `DUMMYUNIONNAME.rgbSecurityDescriptor`

Byte array to address the entire security descriptor including the owner, group, SACL, and DACL fields (if
present) that follow the **SECURITY_DESCRIPTOR_RELATIVE** structure.

### `CLUSPROP_VALUE`

[CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value) structure with a [CLUSPROP_SYNTAX](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_syntax) with a value
of **CLUSPROP_SYNTAX_LIST_VALUE_SECURITY_DESCRIPTOR** (0x00010009) and a **cbLength** field indicating
the count of bytes in the **DUMMYUNIONNAME** member. Padding bytes are not included in the count.

## See also

[Data Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/data-structures)