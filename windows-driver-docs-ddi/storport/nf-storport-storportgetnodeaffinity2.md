## Description

 A miniport can call **StorPortGetNodeAffinity2** to get the current multi-group processor affinity of the given NUMA node.

## Parameters

### `HwDeviceExtension`

[in] Pointer to the miniport's device extension.

### `NodeNumber`

[in] The node number of the node to query.

### `GroupAffinities`

[out] Pointer to an array of [**GROUP_AFFINITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniport/ns-miniport-_group_affinity) structures that, upon success, receive a group number and the affinity mask of the identified group.

### `GroupAffinitiesCount`

[in] The number of elements in the array that **GroupAffinities** points to. If the array is too small to hold the node affinity then STATUS_BUFFER_TOO_SMALL is returned and the number of elements required is returned in **GroupAffinitiesRequired**.

### `GroupAffinitiesCountRequired`

[out] Pointer to a value that receives the number of group affinities required to represent the node affinity.

## Return value

**StorPortGetNodeAffinity2** returns STOR_STATUS_SUCCESS if the node affinity was queried successfully. Possible error return values include the following.

| Return code | Description |
| ----------- | ----------- |
| STOR_STATUS_INVALID_PARAMETER | There is an invalid parameter, such as an invalid **NodeNumber** value. |
| STOR_STATUS_BUFFER_TOO_SMALL | The supplied array is too small. |
| STOR_STATUS_UNSUCCESSFUL | An error occurred for internal reasons. |

## Remarks

See the *Remarks* section of [**KeQueryNodeActiveAffinity2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerynodeactiveaffinity2) for details.

## See also

[**GROUP_AFFINITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniport/ns-miniport-_group_affinity)