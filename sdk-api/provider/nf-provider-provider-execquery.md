# Provider::ExecQuery

## Description

[The [Provider](https://learn.microsoft.com/windows/desktop/api/provider/nl-provider-provider) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **ExecQuery** method is called by WMI to process a WMI Query Language (WQL) query.

## Parameters

### `pMethodContext`

Pointer to the context object for this call. This value contains any [IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext) properties specified by the client. Also, this pointer must be used as a parameter to any calls back into WMI.

### `cQuery` [ref]

Pointer to a query that has already been parsed by the provider framework.

### `lFlags`

Bitmask of flags with information about the execute query operation. This is the value specified by the client in the [IWbemServices::ExecQuery](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-execquery) method.

The following flags are handled by (and filtered out) by WMI:

* **WBEM_FLAG_ENSURE_LOCATABLE**
* **WBEM_FLAG_FORWARD_ONLY**
* **WBEM_FLAG_BIDIRECTIONAL**
* **WBEM_FLAG_USE_AMENDED_QUALIFIERS**
* **WBEM_FLAG_RETURN_IMMEDIATELY**
* **WBEM_FLAG_PROTOTYPE**

## Return value

The default framework provider implementation of this method returns **WBEM_E_PROVIDER_NOT_CAPABLE** to the calling method. The [IWbemServices::ExecQuery](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-execquery) method lists the common return values, although you can choose to return any COM return code.

## Remarks

WMI often calls **ExecQuery** in response to a client call to [IWbemServices::ExecQuery](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-execquery), where the client passes in either a list of selected properties or a WHERE clause. WMI can also call **ExecQuery** if the client query contains an "ASSOCIATORS OF" or "REFERENCES OF" statement describing your class. If your implementation of **ExecQuery** returns **WBEM_E_NOT_SUPPORTED**, the client relies on WMI to handle the query.

WMI handles a query by calling your implementation of [CreateInstanceEnum](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-createinstanceenum) to provide all the instances. WMI then filters the resulting instances before returning the instances to the client. Therefore, any implementation of [ExecQuery](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-execquery) you create must be more efficient than **CreateInstanceEnum**.

The following describes a common implementation of [ExecQuery](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-execquery):

1. Create an empty instance of your class using [Provider::CreateNewInstance](https://learn.microsoft.com/windows/desktop/api/provider/nf-provider-provider-createnewinstance).
2. Determine the subset of instances that you should create.

   You can use methods such as [IsPropertyRequired](https://learn.microsoft.com/windows/desktop/api/frquery/nf-frquery-cframeworkquery-ispropertyrequired) to see what properties are required, and [GetValuesForProp](https://learn.microsoft.com/windows/desktop/api/frquery/nf-frquery-cframeworkquery-getvaluesforprop(lpcwstr_chstringarray_)) to see what instances WMI requires. Other methods that deal with requested properties include [CFrameworkQuery::GetRequiredProperties](https://learn.microsoft.com/windows/desktop/api/frquery/nf-frquery-cframeworkquery-getrequiredproperties), [CFrameworkQuery::AllPropertiesAreRequired](https://learn.microsoft.com/windows/desktop/api/frquery/nf-frquery-cframeworkquery-allpropertiesarerequired), and [CFrameworkQuery::KeysOnly](https://learn.microsoft.com/windows/desktop/api/frquery/nf-frquery-cframeworkquery-keysonly).
3. Populate the properties of the empty instance using the Set methods of the [CInstance](https://learn.microsoft.com/windows/desktop/api/instance/nl-instance-cinstance) class, such as [CInstance::SetByte](https://learn.microsoft.com/windows/desktop/api/instance/nf-instance-cinstance-setbyte) or [CInstance::SetStringArray](https://learn.microsoft.com/windows/desktop/api/instance/nf-instance-cinstance-setstringarray).
4. Send the instance back to the client using [CInstance::Commit](https://learn.microsoft.com/windows/desktop/api/instance/nf-instance-cinstance-commit).
5. Return the appropriate return values.

   The default **ExecQuery** framework provider implementation returns **WBEM_E_PROVIDER_NOT_CAPABLE**. If you implement **ExecQuery**, you should use the common return values listed in [IWbemServices::ExecQuery](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-execquery). If necessary, however, you can return any COM return code.

WMI does not send "ASSOCIATORS OF" or "REFERENCES OF" queries through to framework providers. Instead, WMI uses the schema to determine which classes are related to the class in question, and generates an appropriate WQL query to retrieve the results. Therefore, you do not need to code any additional support of "ASSOCIATORS OF" and "REFERENCES OF" queries.

However, you should keep the following in mind when writing your framework provider:

* Make sure you support standard queries in your association class, especially queries where the reference properties are used in a WHERE clause. For more information, see [CFrameworkQuery::GetValuesForProp](https://learn.microsoft.com/windows/desktop/api/frquery/nf-frquery-cframeworkquery-getvaluesforprop(lpcwstr_chstringarray_)).
* In your association class support, when you check to see if the endpoints exist, ensure you use the [CWbemProviderGlue::GetInstanceKeysByPath](https://learn.microsoft.com/windows/desktop/api/wbemglue/nf-wbemglue-cwbemproviderglue-getinstancekeysbypath) or [CWbemProviderGlue::GetInstancePropertiesByPath](https://learn.microsoft.com/windows/desktop/api/wbemglue/nf-wbemglue-cwbemproviderglue-getinstancepropertiesbypath) methods.

  These methods allow the endpoints to skip populating resource-intensive or unneeded properties.
* Make sure any association endpoint classes support per-property **Get** methods. For more information, see [Supporting Partial-Instance Operations](https://learn.microsoft.com/windows/desktop/WmiSdk/supporting-partial-instance-operations). For more information about the query parameter, see [CFrameworkQuery](https://learn.microsoft.com/windows/desktop/api/frquery/nl-frquery-cframeworkquery).