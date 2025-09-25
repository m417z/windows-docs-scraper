## Description

The **SID_AND_ATTRIBUTES_HASH** structure specifies a hash values for the specified array of security identifiers ([SIDs](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)).

## Members

### `SidCount`

The number of SIDs pointed to by the **SidAttr** parameter.

### `SidAttr`

Pointer to an array of [**SID_AND_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid_and_attributes) structures that represent SIDs and their attributes.

### `Hash[SID_HASH_SIZE]`

Array of pointers to hash values. These values correspond to the [**SID_AND_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid_and_attributes) structures pointed to by the **SidAttr** parameter.

The SID_HASH_ENTRY data type is defined in *ntifs.h* as a ULONG_PTR.

The SID_HASH_SIZE array dimension is defined in *ntifs.h* as 32.

## See also

[**TOKEN_ACCESS_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-token_access_information)