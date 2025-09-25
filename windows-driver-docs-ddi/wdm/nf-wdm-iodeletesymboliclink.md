# IoDeleteSymbolicLink function

## Description

The **IoDeleteSymbolicLink** routine removes a symbolic link from the system.

## Parameters

### `SymbolicLinkName` [in]

Pointer to a buffered Unicode string that is the user-visible name for the symbolic link.

## Return value

**IoDeleteSymbolicLink** returns STATUS_SUCCESS if the symbolic link object is deleted.

## See also

[IoCreateSymbolicLink](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatesymboliclink)

[IoCreateUnprotectedSymbolicLink](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreateunprotectedsymboliclink)

[IoDeassignArcName](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iodeassignarcname)