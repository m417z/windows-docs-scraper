# IADsTSUserEx::get_TerminalServicesHomeDirectory

## Description

The root directory for the user. Each user on a Remote Desktop Session Host (RD Session Host) server has a unique root directory. This ensures that application information is stored separately for each user in a multiuser environment.

This property is read/write.

## Parameters

## Remarks

To set a root directory on the local computer, specify a local path; for example, C:\Path. To set a root directory in a network environment, you must first set the [TerminalServicesHomeDrive](https://learn.microsoft.com/windows/desktop/api/tsuserex/nf-tsuserex-iadstsuserex-get_terminalserviceshomedrive) property, and then set this property to a UNC path.

#### Examples

For an example, see [TerminalServicesHomeDrive](https://learn.microsoft.com/windows/desktop/api/tsuserex/nf-tsuserex-iadstsuserex-get_terminalserviceshomedrive).

## See also

[IADsTSUserEx](https://learn.microsoft.com/windows/desktop/api/tsuserex/nn-tsuserex-iadstsuserex)