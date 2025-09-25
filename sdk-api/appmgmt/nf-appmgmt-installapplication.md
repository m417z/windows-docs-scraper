# InstallApplication function

## Description

The **InstallApplication** function can install applications that have been deployed to target users that belong to a domain. The security context of the user that is calling **InstallApplication** must be that of a domain user logged onto a computer in a domain that trusts the target user's domain. Group Policy must be successfully applied when the target user logs on.

## Parameters

### `pInstallInfo` [in]

A pointer to a [INSTALLDATA](https://learn.microsoft.com/windows/desktop/api/appmgmt/ns-appmgmt-installdata) structure that specifies the application to install.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**. Otherwise, the function returns one of the system error codes. For a complete list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or the header file WinError.h.

## Remarks

The **InstallApplication** function can only install applications that have been deployed by using Group Policy. A domain administrator can deploy applications to target users by using the user configuration section of Group Policy Objects (GPO). The target user must belong to the target domain and the GPO must apply to this user in the target domain. The **InstallApplication** function installs applications according to standard Group Policy inheritance rules. If the same application is deployed in multiple GPOs, the function installs the version of the application deployed in the highest precedence GPO. After an application has been installed for a user, it is not visible to other users on the computer. This is standard for applications that are deployed through user group policy.

The **InstallApplication** function can install deployed applications that use [Windows Installer](https://learn.microsoft.com/windows/desktop/Msi/windows-installer-portal) (.msi files) or software installation settings (.zap files) to handle setup and installation.

The
**InstallApplication** function can install applications that use a [Windows Installer](https://learn.microsoft.com/windows/desktop/Msi/windows-installer-portal) package for their installation. In this case, the user calling **InstallApplication** is not required to have administrator privileges. The system can install the application because the Windows Installer is a trusted application deployed by a domain administrator. The user that receives the application must have access to the location of the .msi files.

Remove applications installed using .msi files by calling the [Windows Installer](https://learn.microsoft.com/windows/desktop/Msi/windows-installer-portal) function [MsiConfigureProduct](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiconfigureproducta) to uninstall the application. Then call [UninstallApplication](https://learn.microsoft.com/windows/desktop/api/appmgmt/nf-appmgmt-uninstallapplication) to inform the system that the application is no longer managed on the client by Group Policy. **UninstallApplication** should be called even if the uninstall fails because this enables the system to keep the [Resultant Set of Policy (RSoP)](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/reporting-group-policy) accurate.

The
**InstallApplication** function can also install applications that use setup applications based on software installation settings (.zap files). The user that receives the application must have access to the location of the .zap files. A .zap file is a text file similar to an .ini file, which enables Windows to publish an application (for example, Setup.exe) for installation with **Add or Remove Programs**. To publish applications that do not use the [Windows Installer](https://learn.microsoft.com/windows/desktop/Msi/windows-installer-portal), you must create a .zap file, copy the .zap file to the software distribution point servers, and then use Group Policy–based software deployment to publish the application for users.
If the application is deployed using .zap files, the user installing the application must have privileges on the machine to install the software. You cannot use .zap files for assigned applications.

Remove applications using software installation settings (.zap files) by calling the uninstall function or a command specific for the installation application.

For information about using installation applications other than the [Windows Installer](https://learn.microsoft.com/windows/desktop/Msi/windows-installer-portal) see article 231747, "How to Publish non-MSI Programs with .zap Files," in the Microsoft Knowledge Base.

## See also

[Group Policy
Functions](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-functions)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[INSTALLDATA](https://learn.microsoft.com/windows/desktop/api/appmgmt/ns-appmgmt-installdata)

[MsiConfigureProduct](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiconfigureproducta)

[Reporting Group Policy](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/reporting-group-policy)

[UninstallApplication](https://learn.microsoft.com/windows/desktop/api/appmgmt/nf-appmgmt-uninstallapplication)

[Windows Installer](https://learn.microsoft.com/windows/desktop/Msi/windows-installer-portal)