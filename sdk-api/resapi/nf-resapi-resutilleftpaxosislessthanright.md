# ResUtilLeftPaxosIsLessThanRight function

## Description

Indicates whether a specified Paxos tag contains older cluster configuration information than another specified Paxos tag.

## Parameters

### `left` [in]

The [PaxosTagCStruct](https://learn.microsoft.com/windows/desktop/api/resapi/ns-resapi-paxostagcstruct) structure that represents the first Paxos tag to use in the comparison.

### `right` [in]

The [PaxosTagCStruct](https://learn.microsoft.com/windows/desktop/api/resapi/ns-resapi-paxostagcstruct) structure that represents the 2nd Paxos tag to use in the comparison.

## Return value

**TRUE** if the cluster configuration of the first Paxos tag is older than the that of the second Paxos tag; otherwise **FALSE**.

## See also

[Resource Utility Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-utility-functions)