# IUpdate4::get_PerUser

## Description

Gets a Boolean value that indicates whether this is a per-user update.

This property is read-only.

## Parameters

## Remarks

Per-user updates are designed to alter the current user’s environment only; not the environment of the machine as a whole. For example, an update which only alters files in the current user’s user directory could be a per-user update; an update which alters files in the Program Files directory or the Windows directory would not be a per-user update. Per-user updates are currently not processed by Automatic Updates or displayed in the Windows Update user interface. Instead, they are only available to callers who specifically request them in searches by using the [IUpdateSearcher3](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdatesearcher3) interface. On computers running versions of Windows Update Agent that do not implement the [IUpdate4](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdate4) interface, only per-machine updates will be available; per-user updates will never be detected.

## See also

[IUpdate4](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdate4)