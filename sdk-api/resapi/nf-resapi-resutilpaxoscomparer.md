# ResUtilPaxosComparer function

## Description

Compares two Paxos tags and indicates whether they have the same values.

## Parameters

### `left` [in]

The [PaxosTagCStruct](https://learn.microsoft.com/windows/desktop/api/resapi/ns-resapi-paxostagcstruct) structure that represents the first Paxos tag to use in the comparison.

### `right` [in]

The [PaxosTagCStruct](https://learn.microsoft.com/windows/desktop/api/resapi/ns-resapi-paxostagcstruct) structure that represents the second Paxos tag to use in the comparison.

## Return value

**TRUE** if the Paxos tags have the same values; otherwise **FALSE**.

## See also

[Resource Utility Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-utility-functions)