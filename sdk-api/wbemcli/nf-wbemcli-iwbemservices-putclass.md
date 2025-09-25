# IWbemServices::PutClass

## Description

The
**IWbemServices::PutClass** method creates a new class or updates an existing one. The class specified by the *pObject* parameter must have been correctly initialized with all of the required property values.

The user may not create classes with names that begin or end with an underscore (_). This is reserved for system classes.

## Parameters

### `pObject` [in]

Must point to a valid class definition. The reference count is not changed.

### `lFlags` [in]

The following flags affect the behavior of this method.

#### WBEM_FLAG_USE_AMENDED_QUALIFIERS

If this flag is set, WMI does not store any qualifiers with the amended flavor. If this flag is not set, it is assumed that this object is not localized, and all qualifiers are stored with this instance.

#### WBEM_FLAG_CREATE_OR_UPDATE

This flag causes the class to be created if it does not exist, or overwritten if it exists already.

#### WBEM_FLAG_UPDATE_ONLY

This flag causes this call to update. The class must exist for the call to be successful.

#### WBEM_FLAG_CREATE_ONLY

This flag is used for creation only. The call fails if the class already exists.

#### WBEM_FLAG_RETURN_IMMEDIATELY

This flag causes this to be a semisynchronous call. For more information, see
[Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

#### WBEM_FLAG_OWNER_UPDATE

Push providers must specify this flag when calling
**PutClass**, to indicate that this class has changed.

#### WBEM_FLAG_UPDATE_COMPATIBLE

This flag allows a class to be updated if there are no derived classes and there are no instances for that class. It also allows updates in all cases if the change is just to nonimportant qualifiers (for example, the **Description** qualifier). This is the default behavior for this call and is used for compatibility with previous versions of Windows Management. If the class has instances or changes are to important qualifiers, the update fails.

#### WBEM_FLAG_UPDATE_SAFE_MODE

This flag allows updates of classes even if there are child classes as long as the change does not cause any conflicts with child classes. An example of an update this flag would allow would be to add a new property to the base class that was not previously mentioned in any of the child classes. If the class has instances, the update fails.

#### WBEM_FLAG_UPDATE_FORCE_MODE

This flag forces updates of classes when conflicting child classes exist. An example of an update this flag would force would be if a class qualifier were defined in a child class, and the base class tried to add the same qualifier which conflicted with the existing one. In force mode, this conflict would be resolved by deleting the conflicting qualifier in the child class.

### `pCtx` [in]

Typically **NULL**. Otherwise, this is a pointer to an
[IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext) object required by the dynamic class provider that is producing the class instances. The values in the context object must be specified in the documentation for the provider in question. For more information about this parameter, see
[Making Calls to WMI](https://learn.microsoft.com/windows/desktop/WmiSdk/making-calls-to-wmi).

### `ppCallResult` [out]

If **NULL**, this parameter is not used. If the *lFlags* parameter contains **WBEM_FLAG_RETURN_IMMEDIATELY**, this call returns immediately with **WBEM_S_NO_ERROR**. The *ppCallResult* parameter receives a pointer to a new
[IWbemCallResult](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcallresult) object, which can then be polled to obtain the result using the
[IWbemCallResult::GetCallStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemcallresult-getcallstatus) method.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

On failure, you can obtain any available information from the COM function [GetErrorInfo](https://learn.microsoft.com/windows/desktop/api/oleauto/nf-oleauto-geterrorinfo).

COM-specific error codes also may be returned if network problems cause you to lose the remote connection to Windows Management.

**Note** Unpredictable behavior will result if you change class definitions while they are in use by clients or providers. The
**IWbemServices::PutClass** method should only be used to create or update a class when there are no clients or providers currently using the class.

## See also

[Creating a Class](https://learn.microsoft.com/windows/desktop/WmiSdk/creating-a-class)

[IWbemCallResult](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcallresult)

[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices)

[Retrieving an Error Code](https://learn.microsoft.com/windows/desktop/WmiSdk/retrieving-an-error-code)