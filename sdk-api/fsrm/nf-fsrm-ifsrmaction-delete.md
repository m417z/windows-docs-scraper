# IFsrmAction::Delete

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMAction](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmaction),
[MSFT_FSRMFMJAction](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfmjaction), and
[MSFT_FSRMFMJNotificationAction](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfmjnotificationaction)
classes.]

Removes the action from the quota or file screen's list of actions.

## Return value

The method returns the following return values.

## Remarks

Calling the
[IFsrmQuotaBase::DeleteThreshold](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nf-fsrmquota-ifsrmquotabase-deletethreshold) method also
deletes the actions associated with the threshold.

Note that the actions are not deleted from the object until you call the object's
[Commit](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmobject-commit) method. For example, the actions are not deleted
from the quota until the [IFsrmQuota::Commit](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmobject-commit)
method is called, nor from the file screens until you call the
**IFsrmFileScreen::Commit** method.

## See also

[IFsrmAction](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmaction)