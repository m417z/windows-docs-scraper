# SID_AND_ATTRIBUTES_HASH structure

## Description

The **SID_AND_ATTRIBUTES_HASH** structure specifies a hash values for the specified array of [security identifiers](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SIDs).

## Members

### `SidCount`

The number of SIDs pointed to by the *SidAttr* parameter.

### `SidAttr`

A pointer to an array of [SID_AND_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid_and_attributes) structures that represent SIDs and their attributes.

### `Hash`

An array of pointers to hash values. These values correspond to the [SID_AND_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid_and_attributes) structures pointed to by the *SidAttr* parameter.

The **SID_HASH_ENTRY** data type is defined in Winnt.h as a **ULONG_PTR**.

The **SID_HASH_SIZE** array dimension is defined in Winnt.h as 32.

## See also

[TOKEN_ACCESS_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_access_information)

[TOKEN_INFORMATION_CLASS](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-token_information_class)