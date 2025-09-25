# UninstallApplication function

## Description

The
**UninstallApplication** function uninstalls a group policy application that handles setup and installation using [Windows Installer](https://learn.microsoft.com/windows/desktop/Msi/windows-installer-portal) .msi files. The **UninstallApplication** function should only be called in the context of the user for whom the user group policy application has previously attempted an uninstall by calling the [MsiConfigureProduct](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiconfigureproducta) function. The [InstallApplication](https://learn.microsoft.com/windows/desktop/api/appmgmt/nf-appmgmt-installapplication) function can install group policy applications.

**Note** Failure to call **UninstallApplication** as part of the protocol for uninstalling a group policy-based application can cause the [Resultant Set of Policy (RSoP)](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/reporting-group-policy) to indicate inaccurate information.

## Parameters

### `ProductCode` [in]

The [Windows Installer](https://learn.microsoft.com/windows/desktop/Msi/windows-installer-portal) product code of the product being uninstalled. The [product code](https://learn.microsoft.com/windows/desktop/Msi/product-codes) of the application should be provided in the form of a [Windows Installer GUID](https://learn.microsoft.com/windows/desktop/Msi/guid) as a string with braces.

### `dwStatus` [in]

The status of the uninstall attempt. The *dwStatus* parameter is the Windows success code of the uninstall attempt returned by [MsiConfigureProduct](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiconfigureproducta). The system can use this to ensure that the [Resultant Set of Policy (RSoP)](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/reporting-group-policy) indicates whether the uninstall failed or succeeded.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**. Otherwise, the function returns one of the system error codes. For a complete list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or the header file WinError.h.

## Remarks

Remove a group policy application that uses .msi files by calling the [Windows Installer](https://learn.microsoft.com/windows/desktop/Msi/windows-installer-portal) function [MsiConfigureProduct](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiconfigureproducta) to uninstall the application. Then call **UninstallApplication** to inform the system that the application is no longer managed on the client by Group Policy. **UninstallApplication** should be called even if the uninstall fails because this enables the system to keep the [Resultant Set of Policy (RSoP)](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/reporting-group-policy) accurate.

Remove applications installed using software installation settings (.zap files) by calling the uninstall function or command specific for the installation application. For information about using installation applications other than the [Windows Installer](https://learn.microsoft.com/windows/desktop/Msi/windows-installer-portal) see article 231747, "How to Publish non-MSI Programs with .zap Files," in the Microsoft Knowledge Base.

## See also

[Group Policy
Functions](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-functions)

[Group Policy
Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[InstallApplication](https://learn.microsoft.com/windows/desktop/api/appmgmt/nf-appmgmt-installapplication)

[MsiConfigureProduct](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiconfigureproducta)