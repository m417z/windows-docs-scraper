# Provider::EnumerateInstances

## Description

[The [Provider](https://learn.microsoft.com/windows/desktop/api/provider/nl-provider-provider) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **EnumerateInstances** method is called by WMI to retrieve all instances of a framework provider's class.

## Parameters

### `pMethodContext`

Pointer to the context object for this call. This value contains any [IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext) properties specified by the client. Also, this pointer must be used as a parameter to any calls back into WMI.

### `lFlags`

Bitmask of flags with information about the **EnumerateInstances** operation. This is the value specified by the client in the [IWbemServices::CreateInstanceEnum](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-createinstanceenum) method.

The following flags are handled by (and filtered out) by WMI:

* **WBEM_FLAG_DEEP**
* **WBEM_FLAG_SHALLOW**
* **WBEM_FLAG_RETURN_IMMEDIATELY**
* **WBEM_FLAG_FORWARD_ONLY**
* **WBEM_FLAG_BIDIRECTIONAL**
* **WBEM_FLAG_USE_AMENDED_QUALIFIERS**

## Return value

The default framework provider implementation of this method returns **WBEM_E_PROVIDER_NOT_CAPABLE** to the calling method. The [IWbemServices::CreateInstanceEnum](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-createinstanceenum) method lists the most common return values, but you can choose to return any COM return code.

## Remarks

It is not an error for **EnumerateInstances** to return zero instances by instantiating zero [CInstance](https://learn.microsoft.com/windows/desktop/api/instance/nl-instance-cinstance) instances and setting the return value to **WBEM_S_NO_ERROR**.

WMI often calls **EnumerateInstances** when a client application calls [IWbemServices::CreateInstanceEnum](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-createinstanceenum), although WMI may call **EnumerateInstances** in other situations as well. The following is a common way to override **EnumerateInstances**:

1. Create an empty instance of your class using [Provider::CreateNewInstance](https://learn.microsoft.com/windows/desktop/api/provider/nf-provider-provider-createnewinstance).
2. Populate the properties of the empty instance using the Set methods of the [CInstance](https://learn.microsoft.com/windows/desktop/api/instance/nl-instance-cinstance) class, such as [CInstance::SetByte](https://learn.microsoft.com/windows/desktop/api/instance/nf-instance-cinstance-setbyte) or [CInstance::SetStringArray](https://learn.microsoft.com/windows/desktop/api/instance/nf-instance-cinstance-setstringarray).
3. Send the instance back to the client using [CInstance::Commit](https://learn.microsoft.com/windows/desktop/api/instance/nf-instance-cinstance-commit).

If you are building a method-only provider and do not have any instances, or if enumerating instances of your class would return too many instances, you may decide to support queries that retrieve only specific instances.