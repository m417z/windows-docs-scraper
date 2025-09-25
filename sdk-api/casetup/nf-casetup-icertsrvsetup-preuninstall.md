# ICertSrvSetup::PreUnInstall

## Description

The **PreUnInstall** method temporarily saves role-specific state information and then it uninstalls the role.

## Parameters

### `bClientOnly` [in]

A value that indicates whether the caller wants to only uninstall the Certification Authority Web Enrollment role. A value of **VARIANT_TRUE** specifies to only uninstall the Certification Authority Web Enrollment role. This only applies if both the Certification Authority and Certification Authority Web Enrollment roles are installed on the computer.

## Remarks

The **PreUnInstall** method should be called before performing a role-specific uninstall.

## See also

[ICertSrvSetup](https://learn.microsoft.com/windows/desktop/api/casetup/nn-casetup-icertsrvsetup)