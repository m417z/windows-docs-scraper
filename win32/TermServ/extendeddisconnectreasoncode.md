# ExtendedDisconnectReasonCode enumeration

Defines extended information about the control's reason for disconnection.

## Constants

**exDiscReasonNoInfo**

No additional information is available.

**exDiscReasonAPIInitiatedDisconnect**

An application initiated the disconnection.

**exDiscReasonAPIInitiatedLogoff**

An application logged off the client.

**exDiscReasonServerIdleTimeout**

The server has disconnected the client because the client has been idle for a period of time longer than the designated time-out period.

**exDiscReasonServerLogonTimeout**

The server has disconnected the client because the client has exceeded the period designated for connection.

**exDiscReasonReplacedByOtherConnection**

The client's connection was replaced by another connection.

**exDiscReasonOutOfMemory**

No memory is available.

**exDiscReasonServerDeniedConnection**

The server denied the connection.

**exDiscReasonServerDeniedConnectionFips**

The server denied the connection for security reasons.

**exDiscReasonServerInsufficientPrivileges**

The server denied the connection for security reasons.

**exDiscReasonServerFreshCredsRequired**

Fresh credentials are required.

**exDiscReasonRpcInitiatedDisconnectByUser**

User activity has initiated the disconnect.

**exDiscReasonLogoffByUser**

The user logged off, disconnecting the session.

**exDiscReasonLicenseInternal**

Internal licensing error.

**exDiscReasonLicenseNoLicenseServer**

No license server was available.

**exDiscReasonLicenseNoLicense**

No valid software license was available.

**exDiscReasonLicenseErrClientMsg**

The remote computer received a licensing message that was not valid.

**exDiscReasonLicenseHwidDoesntMatchLicense**

The hardware ID does not match the one designated on the software license.

**exDiscReasonLicenseErrClientLicense**

Client license error.

**exDiscReasonLicenseCantFinishProtocol**

Network problems occurred during the licensing protocol.

**exDiscReasonLicenseClientEndedProtocol**

The client ended the licensing protocol prematurely.

**exDiscReasonLicenseErrClientEncryption**

A licensing message was encrypted incorrectly.

**exDiscReasonLicenseCantUpgradeLicense**

The local computer's client access license could not be upgraded or renewed.

**exDiscReasonLicenseNoRemoteConnections**

The remote computer is not licensed to accept remote connections.

**exDiscReasonLicenseCreatingLicStoreAccDenied**

An access denied error was received while creating a registry key for the license store.

**exDiscReasonRdpEncInvalidCredentials**

Invalid credentials were encountered.

**exDiscReasonProtocolRangeStart**

Beginning the range of internal protocol errors. Check the server event log for additional details.

**exDiscReasonProtocolRangeEnd**

Ending the range of internal protocol errors.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista<br> |
| Minimum supported server<br> | Windows Server 2008<br> |
| Type library<br> | MsTscAx.dll |

## See also

[**ExtendedDisconnectReason**](https://learn.microsoft.com/windows/win32/termserv/imsrdpclient-extendeddisconnectreason)

