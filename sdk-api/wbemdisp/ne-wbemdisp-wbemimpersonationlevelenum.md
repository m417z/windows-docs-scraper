# WbemImpersonationLevelEnum enumeration

## Description

The
WbemImpersonationLevelEnum constants define the security impersonation levels. These constants are used with
[SWbemSecurity](https://learn.microsoft.com/windows/desktop/WmiSdk/swbemsecurity).

The WMI scripting type library, wbemdisp.tlb, defines these constants. Visual Basic applications can access this library.

Script languages must use one of the following:

* The short name. For example, for **wbemImpersonationLevelImpersonate** use "Impersonate".

  The following VBScript code example uses the short name.

  ```vb
  Set objWMIService = GetObject("winmgmts:" _
      & "{impersonationLevel=Impersonate}!\\" _
      & strComputer & "\root\cimv2")
  ```
* Windows Script Host (WSH) XML file format in the script. For example, this means that the script can use the **wbemImpersonationLevelImpersonate** constant directly.

  The following WSH script sets the impersonation level. To run the script, save the text in a file with a .wsf extension.

  ```vb
  <?xml version="1.0" encoding="US-ASCII"?>
  <job>
  <reference object="WbemScripting.SWbemLocator"/>
  <script language="VBScript">
      set service = GetObject("winmgmts:")
      ' Following line uses a symbolic
      ' constant from the WMI type library
      service.Security_.impersonationLevel = _
          wbemImpersonationLevelDelegate
  </script>
  </job>
  ```

  For more information, see
  [Using the WMI Scripting Type Library](https://learn.microsoft.com/windows/desktop/WmiSdk/using-the-wmi-scripting-type-library).

## Constants

### `wbemImpersonationLevelAnonymous:1`

Short name: Anonymous

Hides the credentials of the caller. Calls to WMI may fail with this impersonation level.

### `wbemImpersonationLevelIdentify:2`

Short name: Identify

Allows objects to query the credentials of the caller. Calls to WMI may fail with this impersonation level.

### `wbemImpersonationLevelImpersonate:3`

Short name: Impersonate

Allows objects to use the credentials of the caller. This is the recommended impersonation level for Scripting API for WMI calls.

### `wbemImpersonationLevelDelegate:4`

Short name: Delegate

Allows objects to permit other objects to use the credentials of the caller. This impersonation will work with Scripting API for WMI calls but may constitute an unnecessary security risk.

## See also

[SWbemSecurity](https://learn.microsoft.com/windows/desktop/WmiSdk/swbemsecurity)

[Scripting API
Constants](https://learn.microsoft.com/windows/desktop/WmiSdk/scripting-api-constants)

[Setting Client_Application_Process Security](https://learn.microsoft.com/windows/desktop/WmiSdk/setting-client-application-process-security)