# IWSManConnectionOptions::put_UserName

## Description

Sets and gets the user name of a local or a domain account on the remote computer. This property determines the user name for authentication. If no value is supplied and the **WSManFlagCredUsernamePassword** flag is not set, then the user name of the account that is running the script is used.

 If the **WSManFlagCredUsernamePassword** flag is set but no user name is specified, the script prompts the user to enter the user name and password. If no user name and password are entered then an access denied error is returned. For more information, see [Authentication for Remote Connections](https://learn.microsoft.com/windows/desktop/WinRM/authentication-for-remote-connections).

This property is read/write.

## Parameters

## Remarks

You can supply [UserName](https://learn.microsoft.com/windows/desktop/WinRM/connectionoptions-username) and [Password](https://learn.microsoft.com/windows/desktop/WinRM/connectionoptions-password) for a domain account when using [Negotiate](https://learn.microsoft.com/windows/desktop/WinRM/windows-remote-management-glossary) or *Kerberos* authentication, or for a local account with [Basic](https://learn.microsoft.com/windows/desktop/WinRM/windows-remote-management-glossary) authentication. To connect to a local account, the [WSMan.CreateSession](https://learn.microsoft.com/windows/desktop/WinRM/wsman-createsession) flags must contain the combination of the **WSManFlagUseBasic** flag and the **WsmanFlagCredUserNamePassword** flag. To connect to a domain account, the **WSMan.CreateSession** flags must contain the combination of the **WSManFlagUseNegotiate** flag and the **WsmanFlagCredUserNamePassword** flag, or the combination of the **WSManFlagUseKerberos** flag and the **WsmanFlagCredUserNamePassword** flag. For a domain account, **UserName** must be specified in the form "computer\username", where the "computer" part of the string can be either the name or the IP address. For more information, see [Authentication for Remote Connections](https://learn.microsoft.com/windows/desktop/WinRM/authentication-for-remote-connections).

## See also

[ConnectionOptions.UserName](https://learn.microsoft.com/windows/desktop/WinRM/connectionoptions-username)

[IWSManConnectionOptions](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmanconnectionoptions)