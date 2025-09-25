# IOfflineFilesCache::GetEncryptionStatus

## Description

Retrieves the current encryption state (encrypted or unencrypted) of the Offline Files cache.

## Parameters

### `pbEncrypted` [out]

Receives **TRUE** if the Offline Files cache is configured to be encrypted; **FALSE** if configured to be unencrypted.

### `pbPartial` [out]

Receives **TRUE** if the Offline Files cache is partially encrypted or partially unencrypted based on the value returned in *pbEncrypted*; **FALSE** if it is fully encrypted or unencrypted.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## Remarks

This encryption state is read from the Offline Files cache and reflects the state of the cache at that instant.

This method returns two values that indicate if the cache is fully encrypted, partially encrypted, fully unencrypted or partially unencrypted.

To change the encryption state of the cache, use the [IOfflineFilesCache::Encrypt](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilescache-encrypt) method.

#### Examples

The following example shows how to use this method.

```cpp
    //
    // Assume we already have a cache ptr.
    //
    IOfflineFilesCache *pCache;
    BOOL bEncrypted;
    BOOL bPartial;
    HRESULT hr = pCache->GetEncryptionStatus(&bEncrypted, &bPartial);
    if (SUCCEEDED(hr))
    {
        if (bEncrypted)
        {
            if (bPartial)
            {
                // Cache is partially encrypted.
            }
            else
            {
                // Cache is fully encrypted.
            }
        }
        else
        {
            if (bPartial)
            {
                // Cache is partially unencrypted.
            }
            else
            {
                // Cache is fully unencrypted.
            }
        }
    }

```

## See also

[IOfflineFilesCache](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilescache)