# WbemAuthenticationLevelEnum enumeration

## Description

The
**WbemAuthenticationLevelEnum** constants define the security authentication levels. These constants are used with
[SWbemSecurity](https://learn.microsoft.com/windows/desktop/WmiSdk/swbemsecurity) and in moniker connections to WMI.

The WMI scripting type library, wbemdisp.tlb, defines these constants. Visual Basic applications can access this library.

Script languages must use one of the following:

* The short name. For example, for **WbemAuthenticationLevelPktPrivacy** use "PktPrivacy".

  ```vb

  strComputer = "RemoteComputer"
  Set objWMIServices = GetObject("WINMGMTS:" _
      & "{authenticationLevel=pktPrivacy}!\\" _
      & strComputer & "\ROOT\CIMV2")
  ```
* Windows Script Host (WSH) XML file format in the script. For example, this means that the script can use the **WbemAuthenticationLevelPkt** constant directly.

  The following WSH script sets the authentication level. To run the script, save the text in a file with a .wsf extension.

  ```vb
  <?xml version="1.0" encoding="US-ASCII"?>
  <job>
  <reference object="WbemScripting.SWbemLocator"/>
  <script language="VBScript">
      set service = GetObject("winmgmts:")
      ' Following line uses a symbolic
      ' constant from the WMI type library
      service.Security_.authenticationLevel = _
          WbemAuthenticationLevelPktPrivacy
  </script>
  </job>

  ```

  For more information, see
  [Using the WMI Scripting Type Library](https://learn.microsoft.com/windows/desktop/WmiSdk/using-the-wmi-scripting-type-library).

## Constants

### `wbemAuthenticationLevelDefault:0`

### `wbemAuthenticationLevelNone:1`

### `wbemAuthenticationLevelConnect:2`

### `wbemAuthenticationLevelCall:3`

### `wbemAuthenticationLevelPkt:4`

### `wbemAuthenticationLevelPktIntegrity:5`

### `wbemAuthenticationLevelPktPrivacy:6`

### `WbemAuthenticationLevelCall`

Short name: Call

Authenticates only at the beginning of each call when the server receives the request.

### `WbemAuthenticationLevelConnect`

Short name: Connect

Authenticates the credentials of the client only when the client establishes a relationship with the server.

### `WbemAuthenticationLevelDefault`

Short name: Default

WMI uses the default Windows Authentication setting.

### `WbemAuthenticationLevelNone`

Short name: None

Uses no authentication.

### `WbemAuthenticationLevelPkt`

Short name: Pkt

Authenticates that all data received is from the expected client.

### `WbemAuthenticationLevelPktIntegrity`

Short name: PktIntegrity

Authenticates and verifies that none of the data transferred between client and server has been modified.

### `WbemAuthenticationLevelPktPrivacy`

Short name: PktPrivacy

Authenticates all previous impersonation levels and encrypts the argument value of each remote procedure call.

## See also

[Constructing a Moniker String](https://learn.microsoft.com/windows/desktop/WmiSdk/constructing-a-moniker-string)

[SWbemSecurity](https://learn.microsoft.com/windows/desktop/WmiSdk/swbemsecurity)

[Scripting API Constants](https://learn.microsoft.com/windows/desktop/WmiSdk/scripting-api-constants)

[Setting Security on an Asynchronous Call in VBScript](https://learn.microsoft.com/windows/desktop/WmiSdk/setting-security-on-an-asynchronous-call-in-vbscript)

[Setting the Default Process Security Level Using VBScript](https://learn.microsoft.com/windows/desktop/WmiSdk/setting-the-default-process-security-level-using-vbscript)