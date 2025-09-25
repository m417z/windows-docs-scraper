# InstallationImpact enumeration

## Description

Defines the possible levels of impact that can be caused by installing or uninstalling an update.

## Constants

### `iiNormal:0`

Installing or uninstalling an update results in a level of impact on the target computer that is typical of most updates. Therefore, the update does not qualify for any of the special impact ratings that are defined in this topic.

### `iiMinor:1`

Installing or uninstalling an update results in an insignificant impact on the target computer.

The update must meet strict requirements to qualify for this rating. The requirements include, but are not limited to, the following requirements:

* It must not perform or require a system restart.
* It must not display a user interface.
* The installation or uninstallation must succeed even if it affects an application or service that is currently being used.

Updates that qualify for this rating may be eligible for special handling in Windows Update Agent (WUA). For example, they may be eligible for accelerated distribution.

### `iiRequiresExclusiveHandling:2`

This update cannot be installed in the same [IUpdateInstaller::Install](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateinstaller-install) or [IUpdateInstaller::BeginInstall](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateinstaller-begininstall) call as any other update. If you make an **IUpdateInstaller::Install** or **IUpdateInstaller::BeginInstall** call that includes an exclusive update along with one or more other updates, the call will return **WU_E_EXCLUSIVE_INSTALL_CONFLICT**, and no updates will be installed.