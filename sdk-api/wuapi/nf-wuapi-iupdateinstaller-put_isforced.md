# IUpdateInstaller::put_IsForced

## Description

Gets or sets a Boolean value that indicates whether to forcibly install or uninstall an update.

This property is read/write.

## Parameters

## Remarks

A forced installation is an installation in which an update is installed even if the metadata indicates that the update is already installed. A forced uninstallation is an uninstallation in which an update is removed even if the metadata indicates that the update is not installed.

Before you use **IsForced** to force an installation, determine whether the update is installed and available. If an update is not installed, a forced installation fails. For example, an update can be downloaded, and then its corresponding files removed from the cache after the expiration limit. In this case, if the files are not installed, a forced installation of the update fails.

## See also

[IUpdateInstaller](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateinstaller)