# IRegistryKey::QueryRegistryValues

## Description

The `QueryRegistryValues` method allows the caller to query several values from the registry with a single call.

## Parameters

### `QueryTable` [in]

Pointer to an array of one or more RTL_QUERY_REGISTRY_TABLE structures. (This structure is described in [RtlQueryRegistryValues](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlqueryregistryvalues).) Each structure specifies the value name and subkey name for a registry entry that the caller is querying. Each structure also contains a function pointer to a caller-supplied **QueryRoutine** callback that the `QueryRegistryValues` method will call with information about the corresponding registry entry. The array must be terminated by a structure with a **Name** member that is **NULL**.

### `Context` [in, optional]

This is a caller-defined context value. The `QueryRegistryValues` method passes this value as a call parameter to each of the **QueryRoutine** callbacks. The context value is typically a pointer to a caller-defined structure containing context data that the caller's **QueryRoutine** accesses. The context value is cast to pointer type PVOID, but the `QueryRegistryValues` method performs no validation of the pointer.

## Return value

`QueryRegistryValues` returns STATUS_SUCCESS if the call was successful in processing the entire *QueryTable*. Otherwise, the method returns an appropriate error code. The following table shows some of the possible return status codes.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | Indicates that the *QueryTable* parameter that was passed to the method is not valid. |
| **STATUS_OBJECT_NAME_NOT_FOUND** | Indicates that the method was unable to find the object that was specified in one of the *QueryTable* entries. |

## Remarks

This method uses caller-supplied callback routines to enumerate the values of a list of registry entries. If successful, the method returns after calling all the callback routines in the list.

The *QueryTable* parameter points to an array of RTL_QUERY_REGISTRY_TABLE structures. The first member of this structure, **QueryRoutine**, is a function pointer to a caller-supplied callback routine. For more information, see [RtlQueryRegistryValues](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlqueryregistryvalues).

## See also

[IRegistryKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iregistrykey)

[RtlQueryRegistryValues](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlqueryregistryvalues)