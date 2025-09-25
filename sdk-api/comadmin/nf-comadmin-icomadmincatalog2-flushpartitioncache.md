# ICOMAdminCatalog2::FlushPartitionCache

## Description

Empties the cache that maps users to their default partitions.

COM+ caches users' default partitions to avoid repetitive Active Directory requests. You might want to call this method after changing a user's default partition in Active Directory.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[ICOMAdminCatalog2](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icomadmincatalog2)