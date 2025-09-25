# WTSSetListenerSecurityW function

## Description

Configures the security descriptor of a Remote Desktop Services listener.

## Parameters

### `hServer` [in]

A handle to an RD Session Host server. Always set this parameter to **WTS_CURRENT_SERVER_HANDLE**.

### `pReserved` [in]

This parameter is reserved. Always set this parameter to **NULL**.

### `Reserved` [in]

This parameter is reserved. Always set this parameter to zero.

### `pListenerName` [in]

A pointer to a null-terminated string that contains the name of the listener.

### `SecurityInformation` [in]

A [SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information) value that specifies the security information to set. Always enable the **DACL_SECURITY_INFORMATION** and **SACL_SECURITY_INFORMATION** flags.

For more information about possible values, see [SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information).

### `pSecurityDescriptor` [in]

A pointer to a [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure that contains the security information associated with the listener. For more information about possible values, see **SECURITY_DESCRIPTOR**. For information about **STANDARD_RIGHTS_REQUIRED**, see [Standard Access Rights](https://learn.microsoft.com/windows/desktop/SecAuthZ/standard-access-rights).

The discretionary access control list (DACL) of the security descriptor can contain one or more of the following values.

#### WTS_SECURITY_ALL_ACCESS

Combines these values:

* **STANDARD_RIGHTS_REQUIRED**
* **WTS_SECURITY_CONNECT**
* **WTS_SECURITY_DISCONNECT**
* **WTS_SECURITY_LOGON**
* **WTS_SECURITY_MESSAGE**
* **WTS_SECURITY_QUERY_INFORMATION**
* **WTS_SECURITY_REMOTE_CONTROL**
* **WTS_SECURITY_RESET**
* **WTS_SECURITY_SET_INFORMATION**
* **WTS_SECURITY_VIRTUAL_CHANNELS**

#### WTS_SECURITY_CONNECT (256 (0x100))

The right to connect.

#### WTS_SECURITY_CURRENT_GUEST_ACCESS

Combines these values:

* **WTS_SECURITY_LOGOFF**
* **WTS_SECURITY_VIRTUAL_CHANNELS**

#### WTS_SECURITY_CURRENT_USER_ACCESS

Combines these values:

* **WTS_SECURITY_DISCONNECT**
* **WTS_SECURITY_LOGOFF**
* **WTS_SECURITY_RESET**
* **WTS_SECURITY_SET_INFORMATION**
* **WTS_SECURITY_VIRTUAL_CHANNELS**

#### WTS_SECURITY_DISCONNECT (512 (0x200))

The right to disconnect.

#### WTS_SECURITY_GUEST_ACCESS

Defined as **WTS_SECURITY_LOGON**.

#### WTS_SECURITY_LOGOFF (64 (0x40))

The right to log off.

#### WTS_SECURITY_LOGON (32 (0x20))

The right to log on.

#### WTS_SECURITY_MESSAGE (128 (0x80))

The right to send a message to the user.

#### WTS_SECURITY_QUERY_INFORMATION (1 (0x1))

The right to query for information.

#### WTS_SECURITY_REMOTE_CONTROL (16 (0x10))

The right to use remote control.

#### WTS_SECURITY_RESET (4 (0x4))

The right to reset information.

#### WTS_SECURITY_SET_INFORMATION (2 (0x2))

The right to set information.

#### WTS_SECURITY_USER_ACCESS

Combines these values:

* **WTS_SECURITY_CONNECT**
* **WTS_SECURITY_CURRENT_GUEST_ACCESS**
* **WTS_SECURITY_QUERY_INFORMATION**

#### WTS_SECURITY_VIRTUAL_CHANNELS (8 (0x8))

The right to use virtual channels.

##### - pSecurityDescriptor.WTS_SECURITY_ALL_ACCESS

Combines these values:

* **STANDARD_RIGHTS_REQUIRED**
* **WTS_SECURITY_CONNECT**
* **WTS_SECURITY_DISCONNECT**
* **WTS_SECURITY_LOGON**
* **WTS_SECURITY_MESSAGE**
* **WTS_SECURITY_QUERY_INFORMATION**
* **WTS_SECURITY_REMOTE_CONTROL**
* **WTS_SECURITY_RESET**
* **WTS_SECURITY_SET_INFORMATION**
* **WTS_SECURITY_VIRTUAL_CHANNELS**

##### - pSecurityDescriptor.WTS_SECURITY_CONNECT (256 (0x100))

The right to connect.

##### - pSecurityDescriptor.WTS_SECURITY_CURRENT_GUEST_ACCESS

Combines these values:

* **WTS_SECURITY_LOGOFF**
* **WTS_SECURITY_VIRTUAL_CHANNELS**

##### - pSecurityDescriptor.WTS_SECURITY_CURRENT_USER_ACCESS

Combines these values:

* **WTS_SECURITY_DISCONNECT**
* **WTS_SECURITY_LOGOFF**
* **WTS_SECURITY_RESET**
* **WTS_SECURITY_SET_INFORMATION**
* **WTS_SECURITY_VIRTUAL_CHANNELS**

##### - pSecurityDescriptor.WTS_SECURITY_DISCONNECT (512 (0x200))

The right to disconnect.

##### - pSecurityDescriptor.WTS_SECURITY_GUEST_ACCESS

Defined as **WTS_SECURITY_LOGON**.

##### - pSecurityDescriptor.WTS_SECURITY_LOGOFF (64 (0x40))

The right to log off.

##### - pSecurityDescriptor.WTS_SECURITY_LOGON (32 (0x20))

The right to log on.

##### - pSecurityDescriptor.WTS_SECURITY_MESSAGE (128 (0x80))

The right to send a message to the user.

##### - pSecurityDescriptor.WTS_SECURITY_QUERY_INFORMATION (1 (0x1))

The right to query for information.

##### - pSecurityDescriptor.WTS_SECURITY_REMOTE_CONTROL (16 (0x10))

The right to use remote control.

##### - pSecurityDescriptor.WTS_SECURITY_RESET (4 (0x4))

The right to reset information.

##### - pSecurityDescriptor.WTS_SECURITY_SET_INFORMATION (2 (0x2))

The right to set information.

##### - pSecurityDescriptor.WTS_SECURITY_USER_ACCESS

Combines these values:

* **WTS_SECURITY_CONNECT**
* **WTS_SECURITY_CURRENT_GUEST_ACCESS**
* **WTS_SECURITY_QUERY_INFORMATION**

##### - pSecurityDescriptor.WTS_SECURITY_VIRTUAL_CHANNELS (8 (0x8))

The right to use virtual channels.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## See also

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)

[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information)

## Remarks

> [!NOTE]
> The wtsapi32.h header defines WTSSetListenerSecurity as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).