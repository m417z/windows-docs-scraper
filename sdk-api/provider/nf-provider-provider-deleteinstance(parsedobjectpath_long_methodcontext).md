# Provider::DeleteInstance(ParsedObjectPath,long,MethodContext)

## Description

[The [Provider](https://learn.microsoft.com/windows/desktop/api/provider/nl-provider-provider) class is part of the WMI
Provider Framework which is now considered in final state, and no further development, enhancements, or updates
will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **DeleteInstance** method is called by WMI to delete an instance.

## Parameters

### `pParsedObjectPath`

TBD

### `lFlags`

Bitmask of flags with information about the delete operation. This is the value specified by the client in the [IWbemServices::DeleteInstance](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-deleteinstance) function.

The following flag is handled by (and filtered out) by WMI:

* **WBEM_FLAG_RETURN_IMMEDIATELY**

### `pContext`

TBD

#### - newInstance [ref]

Instance to be deleted.

## Return value

The default framework provider implementation of this method returns **WBEM_E_PROVIDER_NOT_CAPABLE** to the calling function. The [IWbemServices::DeleteInstance](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-deleteinstance) function lists the most common return values, although you can choose to return any COM return code.

## Remarks

WMI invokes **DeleteInstance** when a client calls [IWbemServices::DeleteInstance](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-deleteinstance) against a class. Therefore, you must implement **DeleteInstance** if your framework provider supports deleting instances. The following list describes a common implementation of **DeleteInstance**:

1. Determine which instance the client requested by reading the key properties with one of the **Get** methods for [CInstance](https://learn.microsoft.com/windows/desktop/api/instance/nl-instance-cinstance), such as [CInstance::GetCHString](https://learn.microsoft.com/windows/desktop/api/instance/nf-instance-cinstance-getchstring).
2. Delete the instance.

For more information about deleting instances, see [IWbemServices::DeleteInstance](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-deleteinstance).