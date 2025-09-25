# GetSystemDEPPolicy function

## Description

Gets the data execution prevention (DEP) policy setting for the system.

## Return value

This function returns a value of type **DEP_SYSTEM_POLICY_TYPE**, which can be one of the following values.

| Return code/value | Description |
| --- | --- |
| **AlwaysOff**<br><br>0 | DEP is disabled for all parts of the system, regardless of hardware support for DEP. The processor runs in PAE mode with 32-bit versions of Windows unless PAE is disabled in the boot configuration data. |
| **AlwaysOn**<br><br>1 | DEP is enabled for all parts of the system. All processes always run with DEP enabled. DEP cannot be explicitly disabled for selected applications. System compatibility fixes are ignored. |
| **OptIn**<br><br>2 | On systems with processors that are capable of hardware-enforced DEP, DEP is automatically enabled only for operating system components. This is the default setting for client versions of Windows. DEP can be explicitly enabled for selected applications or the current process. |
| **OptOut**<br><br>3 | DEP is automatically enabled for operating system components and all processes. This is the default setting for Windows Server versions. DEP can be explicitly disabled for selected applications or the current process. System compatibility fixes for DEP are in effect. |

## Remarks

The system-wide DEP policy is configured at boot time according to the policy setting in the boot configuration data. To change the system-wide DEP policy setting, use the [BCDEdit /set](https://learn.microsoft.com/windows-hardware/drivers/devtest/bcdedit--set) command to set the **nx** boot entry option.

If the system DEP policy is OptIn or OptOut, DEP can be selectively enabled or disabled for the current process by calling the [SetProcessDEPPolicy](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setprocessdeppolicy) function. This function works only for 32-bit processes.

A user with administrative privileges can disable DEP for selected applications by using the **System** Control Panel application. If the system DEP policy is OptOut, DEP is disabled for these applications.

The Application Compatibility Toolkit can be used to create a list of individual applications that are exempt from DEP. If the system DEP policy is OptOut, DEP is automatically disabled for applications on the list.

## See also

[Data Execution Prevention](https://learn.microsoft.com/windows/desktop/Memory/data-execution-prevention)

[GetProcessDEPPolicy](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getprocessdeppolicy)

[GetSystemDEPPolicy](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getsystemdeppolicy)