# CcSetAdditionalCacheAttributesEx function

## Description

Call the **CcSetAdditionalCacheAttributesEx** routine to enable extended cache behavior on a cached file.

## Parameters

### `FileObject` [in]

Pointer to a file object for the cached file.

### `Flags` [in]

Behavior flags to set for **FileObject**. Currently, only the **AGGRESSIVE_UNMAP_BEHIND** flag is available. Setting this flag will allow the cache manager to optimize memory usage when modified writes are disabled for a file object.

## Remarks

**CcSetAdditionalCacheAttributesEx** can be called any time after calling [**CcInitializeCacheMap**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccinitializecachemap).

## See also

[**CcInitializeCacheMap**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccinitializecachemap)

[**CcSetAdditionalCacheAttributes**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccsetadditionalcacheattributes)