# _FILE_ACCESS_INFORMATION structure

## Description

The **FILE_ACCESS_INFORMATION** structure is used to query for or set the access rights of a file.

## Members

### `AccessFlags`

Flags that specify a set of access rights in the access mask of an access control entry. This member is a value of type [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask).

## Remarks

This structure is used by the [ZwQueryInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile) routine.

The *AccessFlags* parameter is an access mask that encodes the user rights to a file object. An access mask can be used to encode the rights to an object that is assigned to a user or a user group, or to encode the requested access when a user opens an object. For more information, see [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask).

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[ZwQueryInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile)