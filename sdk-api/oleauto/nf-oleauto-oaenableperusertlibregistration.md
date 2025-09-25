# OaEnablePerUserTLibRegistration function

## Description

Enables the [RegisterTypeLib](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-registertypelib) function to override default registry mappings under Windows Vista Service Pack 1 (SP1), Windows Server 2008, and later operating system versions.

## Remarks

Consider the following scenario: You are running an application on a computer that is running Windows Vista SP1 or later. In your application, you have overridden the HKEY_CLASSES_ROOT registry subtree and mapped it to another registry subtree. (For example, perhaps you mapped HKEY_CLASSES_ROOT to HKEY_CURRENT_USER.) You then attempt to register a type library by calling [RegisterTypeLib](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-registertypelib), and you receive an "access denied" error message. Additionally, **RegisterTypeLib** returns the TYPE_E_REGISTRYACCESS (0x8002801c) value.

This problem occurs if User Account Control (UAC) is enabled, and the application is running under a limited user account.

You can resolve this problem in one of two ways:

* Use the **OaEnablePerUserTLibRegistration** function. Before your application calls [RegisterTypeLib](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-registertypelib), it should call **OaEnablePerUserTLibRegistration**. This enables **RegisterTypeLib** to accept the registry override mapping. The **OaEnablePerUserTLibRegistration** function is exported from the Oleaut32.dll file. You must reference this file by using run-time dynamic linking and the [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) function.
* Set the OAPERUSERTLIBREG environment variable. [RegisterTypeLib](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-registertypelib) will check the value of this variable. If the value of OAPERUSERTLIBREG is 1, **RegisterTypeLib** will use the appropriate override mapping. Because this environment variable is read during the initialization of the **DLLMain** function, you must set the variable before you run your application. To do this, run one of the following commands at a command prompt:

  **set OAPERUSERTLIBREG=1**

  - or -

  **start cmd.exe /c "set OAPERUSERTLIBREG=1 &&** *MyApp.exe***"**

When using run-time dynamic linking it should be noted that the setting to enable per-user type library registration is a global setting in oleaut32.dll, so if oleaut32.dll is unloaded then this setting is lost.