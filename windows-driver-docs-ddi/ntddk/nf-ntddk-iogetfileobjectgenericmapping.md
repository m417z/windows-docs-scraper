# IoGetFileObjectGenericMapping function

## Description

The **IoGetFileObjectGenericMapping** routine returns information about the mapping between each generic access right and the set of specific access rights for file objects.

## Return value

**IoGetFileObjectGenericMapping** returns a pointer to the [GENERIC_MAPPING](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_generic_mapping) structure that describes the mapping between each generic access right and the implied set of specific access rights.

## See also

[GENERIC_MAPPING](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_generic_mapping)

[IoCheckShareAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocheckshareaccess)

[IoSetShareAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetshareaccess)

[ZwCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile)