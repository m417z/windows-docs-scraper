# PIBIO_ENGINE_REFRESH_CACHE_FN callback function

## Description

Called by the Windows Biometric Framework to notify the Engine Adapter that it should discard any cached templates that it may be keeping in memory.

## Parameters

### `Pipeline` [in, out]

Pointer to the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

## Return value

The function will return one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **E_POINTER** | The *Pipeline* parameter cannot be **NULL**. |
| **S_OK** | This value is returned in all other cases. |

## Remarks

An Engine Adapter that maintains a private in-memory cache of templates (e.g., for performance reasons) should discard the contents of its cache when it receives this method call. The call indicates that the cache contents are no longer valid. Depending on the Engine Adapter’s cache policy, the adapter may also choose to reload its cache at this time from the template database.

The biometric service calls this method in the following situations:

* Once, when the [StorageAdapterAttach](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_storage_attach_fn) routine has successfully opened its connection to the template database.
* Again, after performing any operation that changes the state of the template database.
  + Adding a new template to the database.
  + Deleting one or more existing templates from the database.