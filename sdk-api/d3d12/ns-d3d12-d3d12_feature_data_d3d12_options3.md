# D3D12_FEATURE_DATA_D3D12_OPTIONS3 structure

## Description

Indicates the level of support that the adapter provides for timestamp queries, format-casting, immediate write, view instancing, and barycentrics.

## Members

### `CopyQueueTimestampQueriesSupported`

Indicates whether timestamp queries are supported on copy queues.

### `CastingFullyTypedFormatSupported`

Indicates whether casting from one fully typed format to another, compatible, format is supported.

### `WriteBufferImmediateSupportFlags`

Indicates the kinds of command lists that support the ability to write an immediate value directly from the command stream into a specified buffer.

### `ViewInstancingTier`

Indicates the level of support the adapter has for view instancing.

### `BarycentricsSupported`

Indicates whether barycentrics are supported.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)

[D3D12_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_feature)