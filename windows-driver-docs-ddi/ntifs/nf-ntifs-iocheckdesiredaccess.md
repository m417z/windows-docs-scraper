# IoCheckDesiredAccess function

## Description

The **IoCheckDesiredAccess** routine determines whether the requested access rights to a file can be granted.

## Parameters

### `DesiredAccess`

Pointer to a variable containing a mask that identifies the requested access to the file.

### `GrantedAccess`

Mask value that specifies the access currently granted to the file.

## Return value

**IoCheckDesiredAccess** returns STATUS_SUCCESS if *DesiredAccess* is allowed given the current *GrantedAccess*; otherwise, it returns STATUS_ACCESS_DENIED.

## See also

[SeAccessCheck](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-seaccesscheck)