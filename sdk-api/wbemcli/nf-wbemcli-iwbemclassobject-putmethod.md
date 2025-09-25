# IWbemClassObject::PutMethod

## Description

The **IWbemClassObject::PutMethod** is used to create a method. This call is only supported if the current object is a CIM class definition. Method manipulation is not available from
[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject) pointers that point to CIM instances.

The user cannot create methods with names that begin or end with an underscore. This is reserved for system classes and properties.

## Parameters

### `wszName` [in]

The method name that is created.

### `lFlags` [in]

Reserved. This parameter must be 0 (zero).

### `pInSignature` [in]

A pointer to a copy of the [__Parameters](https://learn.microsoft.com/windows/desktop/WmiSdk/--parameters) system class that contains the in parameters for the method. This parameter is ignored if set to **NULL**.

### `pOutSignature` [in]

A pointer to a copy of the [__Parameters](https://learn.microsoft.com/windows/desktop/WmiSdk/--parameters) system class that contains the out parameters for the object. This parameter is ignored if set to **NULL**.

## Return value

This method returns an **HRESULT** that indicates the status of the method call. The following list lists the value contained within an **HRESULT**. For general **HRESULT** values, see [System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

For a method, the in and out parameters are described as properties in
[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject) objects.

For example, consider the following method:

```
Class MyClass{
    [key] string KeyVal;
    sint32 PropVal;
    sint32 ExampleMethod([in] sint32 Param1, [in] uint32 Param2,
        [out] string Param3);
    HRESULT ReturnValue;
};
```

In the previous example, the class has one method. To create the method programmatically, the user calls
**IWbemClassObject::PutMethod** with the *pInSignature* parameter that points to a copy of the system class
[__Parameters](https://learn.microsoft.com/windows/desktop/WmiSdk/--parameters) that contains two properties: **Param1** and **Param2**. The *pOutSignature* points to a copy of the system class **__Parameters** that contains two properties: **Param3** and **ReturnValue**.

The **ReturnValue** property of the object pointed to by *pOutSignature* determines the method return type. If *pOutSignature* is set to **NULL**, the return type is assumed to be VOID.

An [in/out] parameter can be defined by adding the same property to both objects pointed to by the *pInSignature* and *pOutSignature* parameters. In this case, the properties share the same **ID** qualifier value.

Each property in a [__Parameters](https://learn.microsoft.com/windows/desktop/WmiSdk/--parameters) class object other than **ReturnValue** must have an **ID** qualifier, a zero-based numeric that identifies the order in which the parameters appear. In this example, **Param1** would be 0, **Param2** 1, and **Param3** 2. No two parameters can have the same **ID** value, and no **ID** value can be skipped. If either condition occurs,
**IWbemClassObject::PutMethod** returns **WBEM_E_NONCONSECUTIVE_PARAMETER_IDS**.

**Note** The caller must call **IWbemClassObject::Release** on the *pInSignature* and *pOutSignature* pointers when these objects are no longer required.

## See also

[Creating a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/creating-a-method)

[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject)

[IWbemClassObject::GetMethod](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemclassobject-getmethod)