# IOCTL_EHSTOR_BANDMGMT_REVERT IOCTL

## Description

This **IOCTL_EHSTOR_BANDMGMT_REVERT** request is sent to deactivate the security features and band management on a storage device. The request includes revert options and the authentication key.

## Parameters

### Major code

### Input buffer

The input buffer at **Irp->AssociatedIrp.SystemBuffer** contains an  **ACTIVATE_REVERT_PARAMETERS** structure. **ACTIVATE_REVERT_PARAMETERS** is declared in *ehstorbandmgmt.h* as the following.

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

The length of an  **ACTIVATE_REVERT_PARAMETERS** structure.

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
| STATUS_SUCCESS | Security features on the storage device were deactivated. |
| STATUS_INVALID_DEVICE_REQUEST | The storage device does not support band management. |
| STATUS_INVALID_BUFFER_SIZE | The input buffer size is invalid. |
| STATUS_INVALID_PARAMETER | Information in the input buffer is invalid. |
| STATUS_ACCESS_DENIED | The authentication key is invalid. Deactivation is denied. |
| STATUS_DEVICE_CONFIGURATION_ERROR | The system cannot configure the device in a supported mode. |
| STATUS_IO_DEVICE_ERROR | Communication failed. The storage device might be incompatible with security protocols. |
| STATUS_INVALID_DEVICE_STATE | The storage device is not activated. |

## -AuthKeyOffset

The offset from the beginning of the system buffer to the location of an **AUTH_KEY** structure.

## -Flags

A bitmask of deactivation flags. This is a bitwise OR value of the following.

| Flag | Description |
| --- | --- |
| REVERT_PSID_AUTHKEY | The authentication key at **AuthKeyOffset** is a PSID key. |

## -Key

A variable length byte array that contains the key data.

## -KeySize

The size of the key, in bytes, of the key data at **Key**. If **KeySize** is set to 0, a default key is used.

## -StructSize

The size of the structure. This is set to **sizeof**(ACTIVATE_REVERT_PARAMETERS).

## Remarks

On successful return from an **IOCTL_EHSTOR_BANDMGMT_REVERT** request, the storage device will return to an inactive security state and all band management IOCTLs, except for [IOCTL_EHSTOR_BANDMGMT_QUERY_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_query_capabilities) and [IOCTL_EHSTOR_BANDMGMT_ACTIVATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_activate), become unavailable.

## See also

[IOCTL_EHSTOR_BANDMGMT_ACTIVATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_activate)

[IOCTL_EHSTOR_BANDMGMT_QUERY_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorbandmgmt/ni-ehstorbandmgmt-ioctl_ehstor_bandmgmt_query_capabilities)