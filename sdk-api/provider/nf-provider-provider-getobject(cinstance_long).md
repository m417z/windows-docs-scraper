# Provider::GetObject

## Description

[The [Provider](https://learn.microsoft.com/windows/desktop/api/provider/nl-provider-provider) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **GetObject** method is called by WMI to retrieve an instance of a class.

## Parameters

### `pInstance`

TBD

### `lFlags` [ref]

Query object that indicates the set of properties to be populated, as requested by a call to **Provider::GetObject**.

A provider can realize a significant performance gain by filling in only these requested property values. The provider determines which properties are requested by using [CFrameworkQuery::IsPropertyRequired](https://learn.microsoft.com/windows/desktop/api/frquery/nf-frquery-cframeworkquery-ispropertyrequired). Otherwise, the provider must fill in all property values.

#### - pContext

Bitmask of flags with information about the **GetObject** operation. This is the value specified by the client in the [IWbemServices::GetObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-getobject) method.

The following flags are handled by (and filtered out) by WMI:

* **WBEM_FLAG_USE_AMENDED_QUALIFIERS**
* **WBEM_FLAG_RETURN_WBEM_COMPLETE**
* **WBEM_FLAG_RETURN_IMMEDIATELY**

#### - pParsedObjectPath

Pointer to a [CInstance](https://learn.microsoft.com/windows/desktop/api/instance/nl-instance-cinstance) object to be filled in by the framework provider.

## Return value

The default framework provider implementation of this method returns **WBEM_E_PROVIDER_NOT_CAPABLE** to the calling method. The [IWbemServices::GetObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-getobject) method lists the common return values, although you can choose to implement any COM return value.

## Remarks

WMI often invokes **GetObject** in response to a client call to [IWbemServices::GetObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-getobject). The WMI version of **Provider::GetObject** provides an instance with only the key properties populated. In contrast, an implemented framework provider must fill in all other properties. The following describes a common override of **GetObject**:

1. Determine which instance WMI requested by reading the key properties with a **Get** method from [CInstance](https://learn.microsoft.com/windows/desktop/api/instance/nl-instance-cinstance), such as [CInstance::GetCHString](https://learn.microsoft.com/windows/desktop/api/instance/nf-instance-cinstance-getchstring).
2. Populate the rest of the properties of the instance using the many Set methods of the [CInstance](https://learn.microsoft.com/windows/desktop/api/instance/nl-instance-cinstance) class, such as [CInstance::SetByte](https://learn.microsoft.com/windows/desktop/api/instance/nf-instance-cinstance-setbyte) or [CInstance::SetStringArray](https://learn.microsoft.com/windows/desktop/api/instance/nf-instance-cinstance-setstringarray).