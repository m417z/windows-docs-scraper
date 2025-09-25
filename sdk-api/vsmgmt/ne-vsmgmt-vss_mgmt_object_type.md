# VSS_MGMT_OBJECT_TYPE enumeration

## Description

The **VSS_MGMT_OBJECT_TYPE** enumeration type is a discriminant for the [VSS_MGMT_OBJECT_UNION](https://learn.microsoft.com/openspecs/windows_protocols/ms-scmp/63b53947-2649-4eac-a883-498f77361396) union within the [VSS_MGMT_OBJECT_PROP](https://learn.microsoft.com/windows/desktop/api/vsmgmt/ns-vsmgmt-vss_mgmt_object_prop) structure.

## Constants

### `VSS_MGMT_OBJECT_UNKNOWN:0`

The object type is unknown.

### `VSS_MGMT_OBJECT_VOLUME`

The object is a volume to be shadow copied.

### `VSS_MGMT_OBJECT_DIFF_VOLUME`

The object is a volume to hold a shadow copy storage area.

### `VSS_MGMT_OBJECT_DIFF_AREA`

The object is an association between a volume to be shadow copied and a volume to hold the shadow copy storage area.

## See also

[VSS_MGMT_OBJECT_PROP](https://learn.microsoft.com/windows/desktop/api/vsmgmt/ns-vsmgmt-vss_mgmt_object_prop)

[VSS_MGMT_OBJECT_UNION](https://learn.microsoft.com/openspecs/windows_protocols/ms-scmp/63b53947-2649-4eac-a883-498f77361396)