# DsMapSchemaGuidsW function

## Description

The **DsMapSchemaGuids** function converts GUIDs of directory service schema objects to their display names.

## Parameters

### `hDs` [in]

Contains a directory service handle obtained from either the
[DSBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda) or
[DSBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda) function.

### `cGuids` [in]

Indicates the number of elements in *rGuids*.

### `rGuids` [in]

Pointer to an array of **GUID** values for the objects to be mapped.

### `ppGuidMap` [out]

Pointer to a variable that receives a pointer to an array of
[DS_SCHEMA_GUID_MAP](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_schema_guid_mapa) structures that contain the display names of the objects in *rGuids*. This array must be deallocated using
[DsFreeSchemaGuidMap](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsfreeschemaguidmapa).

## Return value

Returns a standard error code that includes the following values.

## See also

[DS_SCHEMA_GUID_MAP](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_schema_guid_mapa)

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsFreeSchemaGuidMap](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsfreeschemaguidmapa)

## Remarks

> [!NOTE]
> The ntdsapi.h header defines DsMapSchemaGuids as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).