# IUpdate::get_LastDeploymentChangeTime

## Description

Gets the last published date of the update, in Coordinated Universal Time (UTC) date and time, on the server that deploys the update.

This property is read-only.

## Parameters

## Remarks

On computers that are running Windows XP, the **LastDeploymentChangeTime** property retrieves the same date and time that are retrieved by the [CreationDate](https://learn.microsoft.com/previous-versions/windows/desktop/ms750903(v=vs.85)) property of the **IUpdateApproval** interface. The [CreationDate](https://learn.microsoft.com/previous-versions/windows/desktop/ms750903(v=vs.85)) property is used on computers that are running Windows Server 2003.

## See also

[IUpdate](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdate)