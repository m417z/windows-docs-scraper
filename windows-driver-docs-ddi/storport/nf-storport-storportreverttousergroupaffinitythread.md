## Description

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport's hardware device extension.

### `ThreadContext` [in/optional]

Pointer to the thread context received in a prior call to [**StorPortCreateSystemThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportcreatesystemthread).

### `PreviousAffinity` [in]

Pointer to a [**STOR_GROUP_AFFINITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_group_affinity) structure with the group affinity to restore. This group affinity was obtained in a prior call to [**StorPortSetSystemGroupAffinityThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportsetprioritythread).

## Return value

**StorPortRevertToUserGroupAffinityThread** returns one of the following values:

| Return code | Description |
| ----------- | ----------- |
| STOR_STATUS_SUCCESS | The original group affinity was restored successfully. |
| STOR_STATUS_INVALID_IRQL | IRQL level must be <= DISPATCH_LEVEL. |
| STOR_STATUS_INVALID_PARAMETER | One or more of the provided parameters are invalid. |
| STOR_STATUS_UNSUCCESSFUL | Returned for other internal system reasons. |

## Remarks

If a miniport calls [**StorPortSetSystemGroupAffinityThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportsetsystemgroupaffinitythread) to temporarily change the group affinity of the thread, then it should call **StorPortRevertToUserGroupAffinityThread** to revert thread affinity to its original value before the thread exits.

## See also

[**STOR_GROUP_AFFINITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_group_affinity)

[**StorPortCreateSystemThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportcreatesystemthread)

[**StorPortSetSystemGroupAffinityThread**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportsetsystemgroupaffinitythread)