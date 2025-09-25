# IFsrmQuotaObject::get_UserSid

## Description

[This property is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota) class.]

Retrieves the string form of the user's security identifier (SID) that is associated with the
object.

This property is read-only.

## Parameters

## Remarks

This method always returns the well-known SID of
[WinNULLSid](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-well_known_sid_type).

## See also

[IFsrmQuotaObject](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmquotaobject)

[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota)