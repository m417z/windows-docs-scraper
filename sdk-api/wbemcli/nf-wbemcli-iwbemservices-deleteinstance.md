# IWbemServices::DeleteInstance

## Description

The
**IWbemServices::DeleteInstance** method deletes an instance of an existing class in the current namespace.

## Parameters

### `strObjectPath` [in]

Valid **BSTR** containing the object path to the instance to be deleted.

### `lFlags` [in]

One of the following values are valid.

#### WBEM_FLAG_RETURN_IMMEDIATELY

This flag causes this to be a semisynchronous call. For more information, see
[Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

### `pCtx` [in]

Typically NULL. Otherwise, this is a pointer to an
[IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext) object that may be used by the provider that is deleting the instance. The values in the context object must be specified in the documentation for the provider in question.

### `ppCallResult` [out]

If NULL, this parameter is not used. If *ppCallResult* is specified, it must be set to point to **NULL** on entry. If the *lFlags* parameter contains **WBEM_FLAG_RETURN_IMMEDIATELY**, this call returns immediately with **WBEM_S_NO_ERROR**. The *ppCallResult* parameter receives a pointer to a new
[IWbemCallResult](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcallresult) object, which can then be polled to obtain the result using the
[GetCallStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemcallresult-getcallstatus) method.

## Return value

This method returns an **HRESULT** that indicates the status of the method call. The following list lists the value contained within an **HRESULT**.

On failure, you can obtain any available information from the COM function [GetErrorInfo](https://learn.microsoft.com/windows/desktop/api/oleauto/nf-oleauto-geterrorinfo).

COM-specific error codes also may be returned if network problems cause you to lose the remote connection to Windows Management.

## Remarks

The
**IWbemServices::DeleteInstance** method is called to delete an existing instance in the current namespace. Instances in other namespaces cannot be deleted. When
**DeleteInstance** is called to delete an instance that belongs to a class in a hierarchy, Windows Management calls the
[DeleteInstanceAsync](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-deleteinstanceasync) method for all of the providers responsible for non-abstract classes in the hierarchy. That is, if the *strObjectPath* parameter identifies an instance of ClassB, and ClassB derives from ClassA, a non-abstract class, and is the parent class of ClassC and ClassD, also non-abstract classes, the providers for all four classes are called.

Windows Management calls each provider with an object path that is modified to point to their class. For example, if *strObjectPath* for the original call is set to "ClassB.k=1", the call to the provider of ClassA would set *strObjectPath* to "ClassA.k=1".

The success of a
**DeleteInstance** call depends only on the success of a
[DeleteInstanceAsync](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-deleteinstanceasync) call to the provider of the topmost non-abstract class. A non-abstract class has an abstract class as its parent. If the provider for any one of such classes succeeds, the operation succeeds; if all such classes fail, the operation fails.

For example, assume that ClassX is the base class for the following hierarchy:

1. ClassA derives from ClassX.
2. ClassB derives from ClassA.
3. ClassC and ClassD derive from ClassB.

If ClassX is the only abstract class in the hierarchy and the *strObjectPath* parameter in
**DeleteInstance** points to an instance of ClassB, only the provider for ClassA needs to succeed in its
[DeleteInstanceAsync](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-deleteinstanceasync) call.

If ClassX, ClassA, and ClassB are all abstract and the *strObjectPath* parameter in
**DeleteInstance** again points to an instance of ClassB, either the provider for ClassC or the provider for ClassD must succeed.

## See also

[Describing an Instance Object Path](https://learn.microsoft.com/windows/desktop/WmiSdk/describing-an-instance-object-path)

[IWbemCallResult](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcallresult)

[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices)

[IWbemServices::DeleteInstanceAsync](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-deleteinstanceasync)

[Retrieving an Error Code](https://learn.microsoft.com/windows/desktop/WmiSdk/retrieving-an-error-code)