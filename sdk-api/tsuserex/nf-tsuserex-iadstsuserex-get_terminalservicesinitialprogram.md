# IADsTSUserEx::get_TerminalServicesInitialProgram

## Description

The path and file name of the application that the user wants to start automatically when the user logs on to the Remote Desktop Session Host (RD Session Host) server.

This property is read/write.

## Parameters

## Remarks

To set an initial application to start when the user logs on, you must first set this property and then set the [TerminalServicesWorkDirectory](https://learn.microsoft.com/windows/desktop/api/tsuserex/nf-tsuserex-iadstsuserex-get_terminalservicesworkdirectory) property. If you set only the **TerminalServicesInitialProgram** property, the application starts in the user's session in the default user directory.

#### Examples

The following example shows a script that binds to the Active Directory database without credentials.

```vb
Set DSO = GetObject("LDAP:")
Set usr = DSO.OpenDSObject(
    "LDAP://DOMAIN/CN=Test,CN=Users,DC=Server1,DC=Domain,DC=com")
Wscript.echo usr.TerminalServicesWorkDirectory
Wscript.echo usr.TerminalServicesInitialProgram
usr.TerminalServicesInitialProgram= "cmd.exe"
usr.TerminalServicesWorkDirectory= "D:\path"
usr.SetInfo
WScript.echo usr.TerminalServicesInitialProgram
Wscript.echo usr.TerminalServicesWorkDirectory

```

## See also

[IADsTSUserEx](https://learn.microsoft.com/windows/desktop/api/tsuserex/nn-tsuserex-iadstsuserex)