# SoH structure

## Description

**Note** The Network Access Protection platform is not available starting with Windows 10

The **SoH** structure contains the Statement of Health (SoH) data.

## Members

### `count`

The number of attributes contained in the SoH as a number between 0 (zero) and [maxSoHAttributeCount](https://learn.microsoft.com/windows/desktop/NAP/nap-type-constants).

### `attributes`

An array of [SoHAttribute](https://learn.microsoft.com/windows/desktop/api/naptypes/ns-naptypes-sohattribute) structures that contain the collection of attributes defined by this SoH.

## Remarks

SoH packets are collections of attributes, stored as type-length-value objects (TLVs). The attribute type is specified by [SoHAttributeType](https://learn.microsoft.com/windows/desktop/NAP/sohattributetype-enum), and the attribute value is specified by [SoHAttributeValue](https://learn.microsoft.com/windows/desktop/NAP/sohattributevalue-union). The TLVs are ordered
such that certain TLVs (such as the **sohAttributeTypeSystemHealthId** TLV or the
**sohAttributeTypeHealthClass** TLV) separate groups or
sub-groups of TLVs.

The [sohAttributeTypeSystemHealthId](https://learn.microsoft.com/windows/desktop/NAP/sohattributetype-enum) TLV must be the first TLV in both **SoHRequest** and **SoHResponse** packets.
A **SoHResponse** packet can have at most one **sohAttributeTypeIpv4FixupServers** or **sohAttributeTypeIpv6FixupServers** TLV.

## See also

[NAP Reference](https://learn.microsoft.com/windows/desktop/NAP/nap-reference)

[NAP Structures](https://learn.microsoft.com/windows/desktop/NAP/nap-structures)