# _WSK_REGISTRATION structure

## Description

The WSK_REGISTRATION structure is used by the WSK subsystem to register or unregister a WSK
application as a WSK client.

## Members

### `ReservedRegistrationState`

Reserved for system use. Do not use.

### `ReservedRegistrationContext`

Reserved for system use. Do not use.

### `ReservedRegistrationLock`

Reserved for system use. Do not use.

## Remarks

This structure is provided by a client application to register or unregister a WSK client instance. Do
not update any of the members of this structure.

For more information about attaching a WSK application to the WSK subsystem, see
[Registering a Winsock Kernel
Application](https://learn.microsoft.com/windows-hardware/drivers/network/registering-a-winsock-kernel-application).