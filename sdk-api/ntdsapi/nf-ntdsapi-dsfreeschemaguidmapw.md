# DsFreeSchemaGuidMapW function

## Description

The **DsFreeSchemaGuidMap** function frees memory that the
[DsMapSchemaGuids](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsmapschemaguidsa) function has allocated for a
[DS_SCHEMA_GUID_MAP](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_schema_guid_mapa) structure.

## Parameters

### `pGuidMap` [in]

Pointer to a [DS_SCHEMA_GUID_MAP](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_schema_guid_mapa) structure to deallocate.

## Return value

This function does not return a value.

## See also

[DS_SCHEMA_GUID_MAP](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_schema_guid_mapa)

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsMapSchemaGuids](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsmapschemaguidsa)

## Remarks

> [!NOTE]
> The ntdsapi.h header defines DsFreeSchemaGuidMap as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).