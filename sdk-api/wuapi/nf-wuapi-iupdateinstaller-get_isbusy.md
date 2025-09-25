# IUpdateInstaller::get_IsBusy

## Description

Gets a Boolean value that indicates whether an installation or uninstallation is in progress on a computer at a specific time.

This property is read-only.

## Parameters

## Remarks

A new installation or uninstallation is processed only when no other installation or uninstallation is in progress. While an installation or uninstallation is in progress, a new installation or uninstallation immediately fails with the **WU_E_OPERATIONINPROGRESS** error. The **IsBusy** property does not secure an opportunity for the caller to begin a new installation or uninstallation. If the **IsBusy** property or a recent installation or uninstallation failure indicates that another installation or uninstallation is already in progress, the caller should attempt the installation or uninstallation later.

## See also

[IUpdateInstaller](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateinstaller)