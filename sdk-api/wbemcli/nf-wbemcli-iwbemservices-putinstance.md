# IWbemServices::PutInstance

## Description

The
**IWbemServices::PutInstance** method creates or updates an instance of an existing class. The instance is written to the WMI repository.

## Parameters

### `pInst` [in]

Pointer to the instance to be written. The caller cannot make assumptions about the reference count at the completion of this call.

### `lFlags` [in]

One or more of the following values can be set.

#### WBEM_FLAG_CREATE_OR_UPDATE

This flag causes the instance to be created if it does not exist or overwritten if it exists already.

#### WBEM_FLAG_UPDATE_ONLY

This flag causes this call to update. The instance must exist for the call to be successful.

#### WBEM_FLAG_CREATE_ONLY

This flag is used for creation only. The call fails if the instance already exists.

#### WBEM_FLAG_RETURN_IMMEDIATELY

This flag causes this to be a semisynchronous call. For more information, see
[Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

#### WBEM_FLAG_USE_AMENDED_QUALIFIERS

If this flag is set, WMI does not store any qualifiers with the **Amended** flavor. If this flag is not set, it is assumed that this object is not localized, and all qualifiers are stored with this instance.

### `pCtx` [in]

Typically **NULL**, indicating that every property in the instance is to be updated. Otherwise, this is a pointer to an
[IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext) object containing more information about the instance. The data in the context object must be documented by the provider responsible for the instance. A non-**NULL****IWbemContext** object can indicate whether support exists for partial-instance updates.

For more information about how to support full and partial-instance updates, see
[IWbemServices::PutInstanceAsync](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-putinstanceasync). For more information about requesting a full or partial-instance update operation, see
[Modifying an Instance Property](https://learn.microsoft.com/windows/desktop/WmiSdk/modifying-an-instance-property).

### `ppCallResult` [out]

If **NULL**, this parameter is not used. If the *lFlags* parameter contains **WBEM_FLAG_RETURN_IMMEDIATELY**, this call returns immediately with **WBEM_S_NO_ERROR**. The *ppCallResult* parameter then receives a pointer to a new
[IWbemCallResult](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcallresult) object, which can be polled with
[IWbemCallResult::GetCallStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemcallresult-getcallstatus) to obtain the result.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

COM-specific error codes also may be returned if network problems cause you to lose the remote connection to Windows Management.

## Remarks

Applications and providers call
**PutInstance** to create or update an instance of an existing class. Depending on how the *pCtx* parameter is set, either some or all of the properties of the instance are updated. For more information about how to support partial instance updating, see
[IWbemServices::PutInstanceAsync](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-putinstanceasync). For more information about requesting a partial instance update, see
[Modifying an Instance Property](https://learn.microsoft.com/windows/desktop/WmiSdk/modifying-an-instance-property).

The
**PutInstance** method supports creating instances and updating instances only. It does not support moving instances. That is, a caller cannot set the *pInst* parameter to an instance that has a key that is the same as another instance in a sibling class. For example, suppose **ClassA** is the base class to **ClassB** and **ClassC**. The **ClassA** class defines the **KeyProp** property as its key and **ClassB** has an instance that has **KeyProp** set to 1. To create an instance of **ClassC** with **KeyProp** set to 1, an application must first delete the **ClassB** instance by calling
[DeleteInstance](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-deleteinstance) and then save the **ClassC** instance with
**PutInstance**.

When the instance pointed to by *pInst* belongs to a subclass, Windows Management calls all of the providers responsible for the classes from which the subclass derives. All of these providers must succeed for the original
**PutInstance** request to succeed. The provider supporting the topmost class in the hierarchy is called first. The calling order continues with the subclass of the topmost class and proceeds from top to bottom until Windows Management reaches the provider for the class owning the instance pointed to by *pInst*.

Windows Management does not call the providers for any of the child classes of an instance. Therefore, if an application wants to change the values of inherited properties, the application must call
**PutInstance** on the full instance of the child class rather than a corresponding instance of the parent class.

When an application must update an instance that belongs to a class hierarchy, the *pInst* parameter must point to the instance containing the properties to be modified. That is, consider a target instance that belongs to **ClassB**. The **ClassB** instance derives from **ClassA**, and **ClassA** defines the property **PropA**. If an application wants to make a change to the value of **PropA** in the **ClassB** instance, it must set *pInst* to that instance rather than an instance of **ClassA**.

Calling
**PutInstance** on an instance of an abstract class is not allowed.

## See also

[Creating an Instance](https://learn.microsoft.com/windows/desktop/WmiSdk/creating-an-instance)

[IWbemCallResult](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcallresult)

[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices)

[IWbemServices::PutInstanceAsync](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-putinstanceasync)

[Retrieving an Error Code](https://learn.microsoft.com/windows/desktop/WmiSdk/retrieving-an-error-code)