## Description

Defines the processor topology node structure.

## Members

### `Type`

Defines the **UCHAR** member **Type**.

### `Length`

Defines the **UCHAR** member **Length**.

### `Reserved[2]`

Reserved for future use.

### `HierarchyNode`

Defines the **HierarchyNode** member structure.

### `HierarchyNode.Flags`

Defines the **PROC_TOPOLOGY_NODE_FLAGS** member **Flags**.

### `HierarchyNode.Parent`

Defines the **ULONG** member **Parent**.

### `HierarchyNode.ACPIProcessorId`

Defines the **ULONG** member **ACPIProcessorId**.

### `HierarchyNode.NumberPrivateResources[ANYSIZE_ARRAY]`

Defines the **ULONG** member **NumberPrivateResources**.

### `HierarchyNode.PrivateResources`

Defines the **ULONG** member **PrivateResources**.

### `CacheNode`

Defines the **CacheNode** member structure.

### `CacheNode.Flags`

Defines the **PROC_TOPOLOGY_CACHE_FLAGS** member **Flags**.

### `CacheNode.NextLevelCacheOffset`

Defines the **ULONG** member **NextLevelCacheOffset**.

### `CacheNode.Size`

Defines the **ULONG** member **Size**.

### `CacheNode.Sets`

Defines the **ULONG** member **Sets**.

### `CacheNode.Associativity`

Defines the **UCHAR** member **Associativity**.

### `CacheNode.Attributes`

Defines the **PROC_TOPOLOGY_CACHE_ATTRIBUTES** member **Attributes**.

### `CacheNode.LineSize`

Defines the **USHORT** member **LineSize**.

### `CacheNode.CacheId`

Defines the **ULONG** member **CacheId**.

### `IdNode`

Defines the **IdNode** member structure.

### `IdNode.Vendor`

Defines the **ULONG** member **Vendor**.

### `IdNode.Level1`

Defines the **ULONG64** member **Level1**.

### `IdNode.Level2`

Defines the **ULONG64** member **Level2**.

### `IdNode.Major`

Defines the **USHORT** member **Major**.

### `IdNode.Minor`

Defines the **USHORT** member **Minor**.

### `IdNode.Spin`

Defines the **USHORT** member **Spin**.

## Remarks

## See also