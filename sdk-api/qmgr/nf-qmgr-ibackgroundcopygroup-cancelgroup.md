# IBackgroundCopyGroup::CancelGroup

## Description

[**IBackgroundCopyGroup** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [BITS interfaces](https://learn.microsoft.com/windows/desktop/Bits/bits-interfaces).]

Use the **CancelGroup** method to remove the group from the queue. Files completely downloaded before calling this method are available to the client. You can cancel a group at anytime; however, the group cannot be recovered once it is canceled.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | The group was successfully canceled. |

## See also

[IBackgroundCopyGroup](https://learn.microsoft.com/windows/desktop/api/qmgr/nn-qmgr-ibackgroundcopygroup)