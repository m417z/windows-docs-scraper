# Provider::PutInstance(const CInstance &,long)

## Description

[The [Provider](https://learn.microsoft.com/windows/desktop/api/provider/nl-provider-provider) class is part of the WMI
Provider Framework which is now considered in final state, and no further development, enhancements, or updates
will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **PutInstance** method updates an instance.

## Parameters

### `newInstance` [ref]

Instance that is updated.

### `lFlags`

Bitmask of flags with information about the update operation. This is the value specified by the client in the [IWbemServices::PutInstance](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-putinstance) method.

The following flag is handled by (and filtered out) by WMI:

* **WBEM_FLAG_RETURN_IMMEDIATELY**

Valid *lFlags* values are:

* **WBEM_FLAG_CREATE_ONLY**
* **WBEM_FLAG_CREATE_OR_UPDATE**
* **WBEM_FLAG_UPDATE_ONLY**

## Return value

The default framework provider implementation of this method returns **WBEM_E_PROVIDER_NOT_CAPABLE** to the calling method. The [IWbemServices::PutInstance](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-putinstance) method lists the most common return values, although you can choose to return any COM return code.

## Remarks

WMI invokes **PutInstance** when a client calls [IWbemServices::PutInstance](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-putinstance) against your class. You must implement **PutInstance** if your framework provider updates instances. The following list describes a common implementation of **PutInstance**:

1. Examine the key properties passed in by the client with the Get methods for [CInstance](https://learn.microsoft.com/windows/desktop/api/instance/nl-instance-cinstance), such as [CInstance::GetCHString](https://learn.microsoft.com/windows/desktop/api/instance/nf-instance-cinstance-getchstring).

   Your implementation should determine if your provider supports the changes requested by the client.
2. Create or update the appropriate managed object, as necessary.
3. Return the appropriate return value.

   If your provider does not support the changes requested by the client, you should return an appropriate error code. For a complete listing of valid error codes, see [IWbemServices::PutInstance](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-putinstance).