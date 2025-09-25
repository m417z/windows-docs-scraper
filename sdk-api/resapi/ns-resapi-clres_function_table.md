# CLRES_FUNCTION_TABLE structure

## Description

Describes a function table for any version of the
[Resource API](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-api).

## Members

### `TableSize`

Count of bytes in the structure.

This can contain one of these values:

#### CLRES_V1_FUNCTION_SIZE

The size of the function table for Resource API version 1.0.

#### CLRES_V2_FUNCTION_SIZE

The size of the function table for Resource API version 2.0.

**Windows Server 2008 R2:** This value is not supported before Windows Server 2012.

#### CLRES_V3_FUNCTION_SIZE

The size of the function table for Resource API version 3.0.

**Windows Server 2008 R2 and Windows Server 2012:** This value is not supported before Windows Server 2012 R2.

### `Version`

The supported version of the Resource API.

This can contain one of these values:

#### CLRES_VERSION_V1_00 (0x100)

Resource API version 1.0.

#### CLRES_VERSION_V2_00 (0x200)

Resource API version 2.0.

**Windows Server 2008 R2:** This value is not supported before Windows Server 2012.

#### CLRES_VERSION_V3_00 (0x300)

Resource API version 3.0.

**Windows Server 2008 R2 and Windows Server 2012:** This value is not supported before Windows Server 2012 R2.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.V1Functions`

A [CLRES_V1_FUNCTIONS](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-clres_v1_functions) structure that contains the
table of entry points included in the Resource API version 1.0.

### `DUMMYUNIONNAME.V2Functions`

A [CLRES_V2_FUNCTIONS](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-clres_v2_functions) structure that contains the
table of entry points included in the Resource API version 2.0.

**Windows Server 2008 R2:** This member was added in Windows Server 2012.

### `DUMMYUNIONNAME.V3Functions`

A [CLRES_V3_FUNCTIONS](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-clres_v3_functions) structure that contains the
table of entry points included in the Resource API version 3.0.

**Windows Server 2008 R2 and Windows Server 2012:** This member was added in Windows Server 2012 R2.

### `DUMMYUNIONNAME.V4Functions`

## Remarks

Only the first two members are guaranteed to be at the same offset within the
**CLRES_FUNCTION_TABLE** structure. All other entries
within this structure are dependent on the
[Resource API](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-api) version supported.

The **V1Functions** member is a
[CLRES_V1_FUNCTIONS](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-clres_v1_functions) structure containing pointers to
all Resource API entry points except [Startup](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pstartup_routine). All pointers
must be non-**NULL** except for pointers to the following entry point functions:

* [Arbitrate](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-parbitrate_routine)
* [Release](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-prelease_routine)

For more information, see
[Implementing Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/implementing-resource-dlls).

To create a function table for version 1.0 of the Resource API, use the
[CLRES_V1_FUNCTION_TABLE](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nf-resapi-clres_v1_function_table) macro.

#### Examples

See [Defining Structures and Constants](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/defining-structures-and-constants)
in [Implementing Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/implementing-resource-dlls).

## See also

[Arbitrate](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-parbitrate_routine)

[CLRES_V1_FUNCTIONS](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-clres_v1_functions)

[CLRES_V1_FUNCTION_TABLE](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nf-resapi-clres_v1_function_table)

[Release](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-prelease_routine)

[ResourceControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-presource_control_routine)

[ResourceTypeControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-presource_type_control_routine)