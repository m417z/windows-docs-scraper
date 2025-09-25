# VSS_MGMT_OBJECT_PROP structure

## Description

The **VSS_MGMT_OBJECT_PROP** structure defines the properties of a volume, shadow copy storage volume, or a shadow copy storage area.

## Members

### `Type`

Object type. For more information, see [VSS_MGMT_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/vsmgmt/ne-vsmgmt-vss_mgmt_object_type).

### `Obj`

Management object properties: a union of [VSS_VOLUME_PROP](https://learn.microsoft.com/windows/desktop/api/vsmgmt/ns-vsmgmt-vss_volume_prop), [VSS_DIFF_VOLUME_PROP](https://learn.microsoft.com/windows/desktop/api/vsmgmt/ns-vsmgmt-vss_diff_volume_prop), and [VSS_DIFF_AREA_PROP](https://learn.microsoft.com/windows/desktop/api/vsmgmt/ns-vsmgmt-vss_diff_area_prop) structures. (For more information, see [VSS_MGMT_OBJECT_UNION](https://learn.microsoft.com/openspecs/windows_protocols/ms-scmp/63b53947-2649-4eac-a883-498f77361396).)

It contains information for an object of the type specified by the **Type** member. Management objects can be volumes, shadow copy storage volumes, or shadow copy storage areas.

## See also

[IVssEnumMgmtObject::Next](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nf-vsmgmt-ivssenummgmtobject-next)

[VSS_DIFF_AREA_PROP](https://learn.microsoft.com/windows/desktop/api/vsmgmt/ns-vsmgmt-vss_diff_area_prop)

[VSS_DIFF_VOLUME_PROP](https://learn.microsoft.com/windows/desktop/api/vsmgmt/ns-vsmgmt-vss_diff_volume_prop)

[VSS_MGMT_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/vsmgmt/ne-vsmgmt-vss_mgmt_object_type)

[VSS_MGMT_OBJECT_UNION](https://learn.microsoft.com/openspecs/windows_protocols/ms-scmp/63b53947-2649-4eac-a883-498f77361396)

[VSS_VOLUME_PROP](https://learn.microsoft.com/windows/desktop/api/vsmgmt/ns-vsmgmt-vss_volume_prop)

[Volume Shadow Copy API Structures](https://learn.microsoft.com/windows/desktop/VSS/volume-shadow-copy-api-structures)