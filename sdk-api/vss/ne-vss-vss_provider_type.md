# VSS_PROVIDER_TYPE enumeration

## Description

The **VSS_PROVIDER_TYPE** enumeration specifies
the provider type.

## Constants

### `VSS_PROV_UNKNOWN:0`

The provider type is unknown.

This indicates an error in the application or the VSS service, or that no provider is available.

### `VSS_PROV_SYSTEM:1`

The default provider that ships with Windows.

### `VSS_PROV_SOFTWARE:2`

A software provider.

### `VSS_PROV_HARDWARE:3`

A hardware provider.

### `VSS_PROV_FILESHARE:4`

A file share provider.

**Windows 7, Windows Server 2008 R2, Windows Vista, Windows Server 2008, Windows XP and Windows Server 2003:** This enumeration value is not supported until Windows 8 and Windows Server 2012.

## See also

[IVssBackupComponents::Query](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-query)

[IVssEnumObject](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssenumobject)

[VSS_COMPONENT_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_component_type)

[VSS_OBJECT_UNION](https://learn.microsoft.com/openspecs/windows_protocols/ms-scmp/f63af19f-bc5c-4a20-afaf-4f6e0f7c1045)

[VSS_PROVIDER_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_object_prop)

[VSS_SOURCE_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_source_type)