# VSS_OBJECT_TYPE enumeration

## Description

The **VSS_OBJECT_TYPE** enumeration is used by
requesters to identify an object as a shadow copy set, shadow copy, or provider.

## Constants

### `VSS_OBJECT_UNKNOWN:0`

The object type is not known.

This indicates an application error.

### `VSS_OBJECT_NONE`

The interpretation of this value depends on whether it is used as an input to a VSS method or returned as
an output from a VSS method.

When used as an input to a VSS method, it indicates that the method is not restricted to any particular
object type, but should act on all appropriate objects. In this sense,
**VSS_OBJECT_NONE** can be thought of as a wildcard input.

When returned as an output, the object type is not known and means that there has been an application
error.

### `VSS_OBJECT_SNAPSHOT_SET`

Shadow copy set.

### `VSS_OBJECT_SNAPSHOT`

Shadow copy.

### `VSS_OBJECT_PROVIDER`

Shadow copy provider.

### `VSS_OBJECT_TYPE_COUNT`

Reserved value.

## Remarks

**VSS_OBJECT_TYPE** is used when calling
[IVssBackupComponents::Query](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-query) to specify the
types of objects about which to obtain information. An input of **VSS_OBJECT_NONE** will
return information about all objects.

In addition, **VSS_OBJECT_TYPE** is used as an input to
[IVssBackupComponents::DeleteSnapshots](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-deletesnapshots).
However, **DeleteSnapshots** accepts
only **VSS_OBJECT_TYPE** values of
**VSS_OBJECT_SNAPSHOT_SET** or **VSS_OBJECT_SNAPSHOT**.

The **Type** member of
[VSS_OBJECT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_object_prop) is a member of the
**VSS_OBJECT_TYPE** enumeration.

## See also

[IVssBackupComponents::DeleteSnapshots](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-deletesnapshots)

[IVssBackupComponents::Query](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-query)

[IVssEnumObject](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssenumobject)

[VSS_COMPONENT_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_component_type)

[VSS_OBJECT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_object_prop)