# STORAGE_MINIPORT_DESCRIPTOR structure

## Description

Reserved for system use.

## Members

### `Version`

Contains the size of this structure, in bytes. The value of this member will change as members are added to the structure.

### `Size`

Specifies the total size of the data returned, in bytes. This may include data that follows this structure.

### `Portdriver`

Type of port driver as enumerated by the **[STORAGE_PORT_CODE_SET](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/mt668773(v=vs.85))** enumeration.

### `LUNResetSupported`

Indicates whether a LUN reset is supported.

### `TargetResetSupported`

Indicates whether a target reset is supported.

### `IoTimeoutValue`

The timeout value for the device, in milliseconds (ms). Introduced in Windows 8.

### `ExtraIoInfoSupported`

Indicates whether extra I/O info is supported. Introduced in Windows 8.1

### `Flags`

### `Flags.DUMMYSTRUCTNAME`

### `Flags.DUMMYSTRUCTNAME.LogicalPoFxForDisk`

### `Flags.DUMMYSTRUCTNAME.ForwardIo`

Reserved for internal use. Do not use.

### `Flags.DUMMYSTRUCTNAME.Reserved`

Reserved for future use.

### `Flags.AsUCHAR`

### `Reserved0[2]`

Reserved for future use.

### `Reserved0[3]`

Reserved for future use.

### `Reserved1`

Reserved for future use.