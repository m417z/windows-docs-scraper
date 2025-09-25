# IOCTL_EHSTOR_BANDMGMT_ACTIVATE IOCTL

## Description

This **IOCTL_EHSTOR_BANDMGMT_ACTIVATE** request is sent to activate the security features and band management on a storage device. The request includes activation options and the authentication key.

## Parameters

### Major code

### Input buffer

The input buffer at **Irp->AssociatedIrp.SystemBuffer** contains an **ACTIVATE_REVERT_PARAMETERS** structure. **ACTIVATE_REVERT_PARAMETERS** is declared in *ehstorbandmgmt.h* as the following.

```
typedef struct _ACTIVATE_REVERT_PARAMETERS
{
    ULONG           StructSize;
    ULONG           Flags;
    ULONG           AuthKeyOffset;
} ACTIVATE_REVERT_PARAMETERS;
```

Following **ACTIVATE_REVERT_PARAMETERS** in the system buffer is an **AUTH_KEY** structure. This holds the key data bytes for the authentication key. **AUTH_KEY** is declared in *ehstorbandmgmt.h* as the following.

```
typedef struct _AUTH_KEY
{
    ULONG   KeySize;
    UCHAR   Key[ANYSIZE_ARRAY];
} AUTH_KEY;
```

### Input buffer length

The length of an **ACTIVATE_REVERT_PARAMETERS** structure.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

One of the following values can be returned in the **Status** field.

| Status Value | Description |
| --- | --- |
| STATUS_SUCCESS | Security features on the storage device were activated. |
| STATUS_INVALID_DEVICE_REQUEST | The storage device does not support band management. |
| STATUS_INVALID_BUFFER_SIZE | The input buffer size is invalid. |
| STATUS_INVALID_PARAMETER | Information in the input buffer is invalid. |
| STATUS_ACCESS_DENIED | The authentication key is invalid. Activation is denied. |
| STATUS_DEVICE_CONFIGURATION_ERROR | The system cannot configure the device in a supported mode. |
| STATUS_IO_DEVICE_ERROR | Communication failed. The storage device might be incompatible with security protocols. |
| STATUS_INVALID_DEVICE_STATE | The storage device is already activated. |
| STATUS_NOT_SUPPORTED | Security features on the device were not activated because of a Group Policy setting. |

## -AuthKeyOffset

The offset from the beginning of the system buffer to the location of an **AUTH_KEY** structure.

## -Flags

A bitmask of activation flags. This is a bitwise OR value of the following.

| Flag | Description |
| --- | --- |
| ACTIVATE_DISABLE_SID | SID authority will be disabled after activation. |
| ACTIVATE_IGNORE_POLICY | Activate will ignore the global policy for security activation. |

## -Key

A variable length byte array that contains the key data.

## -KeySize

The size of the key, in bytes, of the key data at **Key**. If **KeySize** is set to 0, a default key is used.

## -StructSize

The size of the structure. This is set to **sizeof**(ACTIVATE_REVERT_PARAMETERS).

## Remarks

If STATUS_SUCCESS is returned from this request, a driver or application can then send an [IOCTL_EHSTOR_BANDMGMT_QUERY_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_query_capabilities) request to retrieve the enabled band management capabilities of the device.

Before a successful return from **IOCTL_EHSTOR_BANDMGMT_ACTIVATE**, the device is not activated. Until the device is activated, the only band management IOCTL that will return successfully is [IOCTL_EHSTOR_BANDMGMT_QUERY_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_query_capabilities). After activation, the remaining band management IOCTLs are available.

Activation of Enhanced Storage devices is controlled by the Group Policy settings of the system. The registry value at *HKLM\Software\Policies\Microsoft\Windows\EnhancedStorageDevices\TCGSecurityActivationDisabled* determines whether security activation is
enabled. A REG_DWORD value of 0 allows security activation on the storage device. Otherwise, a value of 1 disables security activation and the **IOCTL_EHSTOR_BANDMGMT_ACTIVATE** request will return with **STATUS_NOT_SUPPORTED.**

## See also

[IOCTL_EHSTOR_BANDMGMT_QUERY_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_query_capabilities)

[IOCTL_EHSTOR_BANDMGMT_REVERT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_revert)