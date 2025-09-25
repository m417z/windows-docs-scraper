# DS_SCHEMA_GUID_MAPW structure

## Description

The **DS_SCHEMA_GUID_MAP** structure contains the results of a call to
[DsMapSchemaGuids](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsmapschemaguidsa). If [DsMapSchemaGuids](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsmapschemaguidsa) succeeds in mapping a GUID, **DS_SCHEMA_GUID_MAP** contains both the GUID and a display name for the object to which the GUID refers.

## Members

### `guid`

[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid) structure that specifies the object GUID.

### `guidType`

Indicates the type of GUID mapped by [DsMapSchemaGuids](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsmapschemaguidsa).

#### DS_SCHEMA_GUID_ATTR

The GUID identifies a property.

#### DS_SCHEMA_GUID_ATTR_SET

The GUID identifies a property set.

#### DS_SCHEMA_GUID_CLASS

The GUID identifies a type of object.

#### DS_SCHEMA_GUID_CONTROL_RIGHT

The GUID identifies an extended access right.

#### DS_SCHEMA_GUID_NOT_FOUND

The GUID cannot be found in the directory service schema.

### `string`

### `unique`

### `pName`

Pointer to a null-terminated string value that specifies the display name associated with the GUID. This value may be **NULL** if [DsMapSchemaGuids](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsmapschemaguidsa) was unable to map the GUID to a display name.

##### - guidType.DS_SCHEMA_GUID_ATTR

The GUID identifies a property.

##### - guidType.DS_SCHEMA_GUID_ATTR_SET

The GUID identifies a property set.

##### - guidType.DS_SCHEMA_GUID_CLASS

The GUID identifies a type of object.

##### - guidType.DS_SCHEMA_GUID_CONTROL_RIGHT

The GUID identifies an extended access right.

##### - guidType.DS_SCHEMA_GUID_NOT_FOUND

The GUID cannot be found in the directory service schema.

## See also

[Domain Controller and Replication Management Structures](https://learn.microsoft.com/windows/desktop/AD/domain-controller-and-replication-management-structures)

[DsFreeSchemaGuidMap](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsfreeschemaguidmapa)

[DsMapSchemaGuids](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsmapschemaguidsa)

[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)

## Remarks

> [!NOTE]
> The ntdsapi.h header defines DS_SCHEMA_GUID_MAP as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).