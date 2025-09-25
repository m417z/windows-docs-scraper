# IWbemClassObject::GetMethod

## Description

The
**IWbemClassObject::GetMethod** method returns information about the requested method. This call is only supported if the current object is a CIM class definition. Method information is not available from
[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject) pointers which point to CIM instances.

## Parameters

### `wszName` [in]

The method name. This cannot be **NULL**, and must point to a valid **LPCWSTR**.

### `lFlags` [in]

Reserved. This parameter must be 0.

### `ppInSignature` [out]

A pointer that receives an
[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject) pointer which describes the in parameters to the method. This parameter is ignored if set to **NULL**. Be aware that Windows Management can set the
**IWbemClassObject** pointer to **NULL** if this method has no in parameters. For more information, see Remarks.

### `ppOutSignature` [out]

A pointer that receives an
[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject) pointer which describes the out-parameters to the method. This parameter will be ignored if set to **NULL**.

## Return value

This method returns an **HRESULT** that indicates the status of the method call. The following list lists the value contained within an **HRESULT**. For general **HRESULT** values, see [System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

For a method, the in and out parameters are described as properties in an
[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject), an instance of the system class
[__Parameters](https://learn.microsoft.com/windows/desktop/WmiSdk/--parameters).

For example, consider the following method:

```
Class MyClass{
    [key] string KeyVal;
    sint32 PropVal;
    sint32 ExampleMethod([in] sint32 Parm1, [in] uint32 Parm2,
      [out] string Parm3);
};
```

In this example, the class has a single method. When the user calls
**IWbemClassObject::GetMethod**, the *ppInSignature* parameter receives an
[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject) object, which contains two properties: **Parm1** and **Parm2**. The *ppOutSignature* parameter contains two properties, **Parm3** and **ReturnValue**.

After filling in the property values of the *ppInSignature* object, the caller can use the object to execute the method by calling
[IWbemServices::ExecMethod](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-execmethod) or
[IWbemServices::ExecMethodAsync](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-execmethodasync).

**Note** The caller must call **IWbemClassObject::Release** on the *ppInSignature* and *ppOutSignature* pointers when these objects are no longer required.

## See also

[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject)

[IWbemClassObject::PutMethod](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemclassobject-putmethod)