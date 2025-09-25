# SendSAS function

## Description

Simulates a [secure attention sequence](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SAS).

## Parameters

### `AsUser` [in]

**TRUE** if the caller is running as the current user; otherwise, **FALSE**.

## Remarks

To successfully call the **SendSAS** function, an application must either be running as a service or have the **uiAccess** attribute of the **requestedExecutionLevel** element set to "true" in its application manifest. If an application is not running as a service, it must be running as either the current user or the LocalSystem account to call **SendSAS**. In addition, if an application is not running as a service, [User Account Control](https://learn.microsoft.com/windows/desktop/SecAuthZ/user-account-control) must be turned on to call **SendSAS**.

**Important** Applications with the **uiAccess** attribute set to "true" must be signed by using [Authenticode](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms537359(v=vs.85)). In addition, the application must reside in a protected location in the file system. Currently, there are two allowable protected locations:

**\Program Files\**

**\windows\system32\**

The local security policy of a computer must be configured to allow services and applications to simulate a SAS. To configure the policy, modify settings in the Group Policy Editor (GPE) Microsoft Management Console (MMC) snap-in. The GPE settings that control delegation are in the following location:

**Computer Configuration | Administrative Templates | Windows Components | Windows Logon Options | Disable or enable software Secure Attention Sequence**

A service can impersonate the token of another process that calls that service. In this case, a call to the **SendSAS** function by that service simulates a SAS on the session associated with the impersonated token.

**Windows Server 2008 and Windows Vista:** Sas.dll is not available natively. You must download the Windows 7 version of the Microsoft Windows Software Development Kit (SDK) to use this function. In addition, an application must refer to Sas.dll to call this function.