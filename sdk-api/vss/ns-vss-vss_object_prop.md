# VSS_OBJECT_PROP structure

## Description

The **VSS_OBJECT_PROP** structure defines the
properties of a provider, volume, shadow copy, or shadow copy set.

## Members

### `Type`

Object type. Refer to [VSS_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_object_type).

### `Obj`

Object properties: a union of [VSS_SNAPSHOT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_snapshot_prop)
and [VSS_PROVIDER_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_provider_prop) structures. (See
[VSS_OBJECT_UNION](https://learn.microsoft.com/openspecs/windows_protocols/ms-scmp/f63af19f-bc5c-4a20-afaf-4f6e0f7c1045).)

It contains information for an object of the type specified by the **Type** member of
the **VSS_OBJECT_PROP** structure. Objects can be
providers, volumes, shadow copies, or shadow copy sets.

## Remarks

A requester obtains **VSS_OBJECT_PROP** structures by
using [IVssEnumObject::Next](https://learn.microsoft.com/windows/desktop/api/vss/nf-vss-ivssenumobject-next) to iterate over the list
of objects returned by a call to
[IVssBackupComponents::Query](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-query).

As its members are filled by a COM interface, prior to deleting the property structures
[VSS_SNAPSHOT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_snapshot_prop) and
[VSS_PROVIDER_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_provider_prop), the memory they contain must be
released by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) for every string and
byte array value contained in each structure.

In the case of [VSS_SNAPSHOT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_snapshot_prop), this can be done
manually, or the utility function
[VssFreeSnapshotProperties](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-vssfreesnapshotproperties) can be used.

## See also

[VSS_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_object_type)

[VSS_OBJECT_UNION](https://learn.microsoft.com/openspecs/windows_protocols/ms-scmp/f63af19f-bc5c-4a20-afaf-4f6e0f7c1045)

[VSS_PROVIDER_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_provider_prop)

[VSS_SNAPSHOT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_snapshot_prop)