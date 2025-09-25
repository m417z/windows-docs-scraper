# WTS_POLICY_DATA structure

## Description

Contains policy information that is passed by the Remote Desktop Services service to the protocol.

## Members

### `fDisableEncryption`

Specifies whether to disable encryption for communication between the client and server.

### `fDisableAutoReconnect`

Specifies whether to disable automatic reconnect of the client.

### `ColorDepth`

Specifies the monitor color depth policy. This can be one of the following values.

#### 1

8 bits per pixel

#### 2

15 bits per pixel

#### 3

16 bits per pixel

#### 4

24 bits per pixel

#### 5

32 bits per pixel

### `MinEncryptionLevel`

Specifies the minimum permitted encryption level.

### `fDisableCpm`

Specifies whether to disable printer mapping.

### `fDisableCdm`

Specifies whether to disable drive mapping.

### `fDisableCcm`

Specifies whether to disable COM communication port mapping.

### `fDisableLPT`

Specifies whether to disable LPT (line print terminal) printer redirection.

### `fDisableClip`

Specifies whether to disable clipboard redirection.

### `fDisablePNPRedir`

Specifies whether to disable Plug and Play redirection.

## Remarks

This structure is used by the following methods:

* [SendPolicyData](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwtsprotocolconnection-sendpolicydata)
* [GetUserData](https://learn.microsoft.com/windows/desktop/api/wtsprotocol/nf-wtsprotocol-iwtsprotocolconnection-getuserdata)