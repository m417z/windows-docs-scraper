# IADsTSUserEx::get_TerminalServicesHomeDrive

## Description

The root drive for the user. In a network environment, this property is a string that contains a drive specification (a drive letter followed by a colon) to which the UNC path specified as the root directory is mapped.

This property is read/write.

## Parameters

## Remarks

To set a root directory in a network environment, you must first set this property and then set the [TerminalServicesHomeDirectory](https://learn.microsoft.com/windows/desktop/api/tsuserex/nf-tsuserex-iadstsuserex-get_terminalserviceshomedirectory) property.

#### Examples

The following example shows a script that binds to the SAM database without credentials.

```vb
Set DSO = GetObject("WinNT:")
Set usr = DSO.OpenDSObject("WinNT://Server1/Test,user")
WScript.echo usr.TerminalServicesHomeDrive
Wscript.echo usr.TerminalServicesHomeDirectory

usr.TerminalServicesHomeDrive = "Z:"
usr.TerminalServicesHomeDirectory = "\\servername\share\path"
usr.SetInfo

WScript.echo usr.TerminalServicesHomeDrive
WScript.echo usr.TerminalServicesHomeDirectory

```

## See also

[IADsTSUserEx](https://learn.microsoft.com/windows/desktop/api/tsuserex/nn-tsuserex-iadstsuserex)