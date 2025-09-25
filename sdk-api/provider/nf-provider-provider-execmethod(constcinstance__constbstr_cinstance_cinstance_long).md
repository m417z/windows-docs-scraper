# Provider::ExecMethod

## Description

[The [Provider](https://learn.microsoft.com/windows/desktop/api/provider/nl-provider-provider) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **ExecMethod** method is called by WMI to invoke a method on a class or instance.

## Parameters

### `cInstance` [ref]

Key properties of the instance in question if the client called an instance method. If the client called a static method, *Instance* contains a class object.

### `bstrMethodName`

Name of the method that is invoked.

### `pInParams`

Pointer to the method input parameters.

### `pOutParams`

Pointer to the method output parameters.

### `lFlags`

Bitmask of flags with information about the execute method operation. This is the value specified by the client in the [IWbemServices::ExecMethod](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-execmethod) method. Few clients use the *lFlags* parameters. You can safely ignore *lFlags* in most provider implementations.

The following flag is handled by (and filtered out) by WMI:

* **WBEM_FLAG_RETURN_IMMEDIATELY**

## Return value

The default framework provider implementation of this method returns **WBEM_E_PROVIDER_NOT_CAPABLE** to the calling method. The [IWbemServices::ExecMethod](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-execmethod) method lists the most common return values, although you can choose to return any COM return code.

Return values for methods may be one of two types:

* **HRESULT** is used to indicate WMI type errors: **WBEM_E_OUT_OF_MEMORY**, **WBEM_E_NOT_FOUND**, and so on.
* The return value from the method (such as **uint32**) returns the result from the method.

## Remarks

WMI calls **ExecMethod** when a client calls [IWbemServices::ExecMethod](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-execmethod) against your class. Therefore, you must implement **ExecMethod** if your provider supports one or more methods. The following list describes a common implementation of **ExecMethod**:

1. Determine which method the client called by examining the *bstrMethodName* parameter.
2. Retrieve the input parameters from the *pInParams* parameter, using the **Get** methods from the [CInstance](https://learn.microsoft.com/windows/desktop/api/instance/nl-instance-cinstance) class, such as [CInstance::GetCHString](https://learn.microsoft.com/windows/desktop/api/instance/nf-instance-cinstance-getchstring).

   A method may have input parameters, output parameters, both input and output parameters, or no input or output parameters.
3. Set the output parameters in the *pOutParams* parameter, using the Set methods of the [CInstance](https://learn.microsoft.com/windows/desktop/api/instance/nl-instance-cinstance) class, such as [CInstance::SetByte](https://learn.microsoft.com/windows/desktop/api/instance/nf-instance-cinstance-setbyte) or [CInstance::SetStringArray](https://learn.microsoft.com/windows/desktop/api/instance/nf-instance-cinstance-setstringarray).

   In addition to declaring the [out] properties as specified in the return declaration, you must also declare the return value for the method, as defined in the **ReturnValue** property. You do not have to declare a return value if the return value is **void**.

For more information, see [IWbemServices::ExecMethod](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-execmethod).