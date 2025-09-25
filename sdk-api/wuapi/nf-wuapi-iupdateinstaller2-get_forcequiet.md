# IUpdateInstaller2::get_ForceQuiet

## Description

Gets and sets a Boolean value that indicates whether Windows Installer is forced to install the updates without user interaction.

This property is read/write.

## Parameters

## Remarks

You cannot forcibly silence some updates. If an update does not support this action, and you try to install the update, the update returns the following: WU_E_UH_DOESNOTSUPPORTACTION.

## See also

[IUpdateInstaller2](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateinstaller2)