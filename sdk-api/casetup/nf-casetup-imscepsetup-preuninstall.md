# IMSCEPSetup::PreUnInstall

## Description

The **PreUnInstall** method removes registry and IIS settings for the Network Device Enrollment Service (NDES) role.

## Remarks

You can use this method to support an uninstall of an NDES role. The role must be already installed on the computer. This method should be called before calling the role-specific component-based servicing (CBS) uninstall process.

## See also

[IMSCEPSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-imscepsetup)