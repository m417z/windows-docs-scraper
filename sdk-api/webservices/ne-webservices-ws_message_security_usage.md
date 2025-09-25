# WS_MESSAGE_SECURITY_USAGE enumeration

## Description

Defines how a message security binding attaches the security token
corresponding to it to a message using WS-Security mechanisms.

## Constants

### `WS_SUPPORTING_MESSAGE_SECURITY_USAGE:1`

The security token obtained security binding is used for client
authentication, but not message protection. Message protection should
be provided by a transport security binding or a message security
binding with symmetric or asymmetric usage.