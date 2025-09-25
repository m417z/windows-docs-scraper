# IWbemServices::PutClassAsync

## Description

The **IWbemServices::PutClassAsync** method
creates a new class, or updates an existing one. The class specified by the *pObject*
parameter must be correctly initialized with all of the required property values. The call immediately returns.
Success or failure is supplied to the object sink specified by the *pResponseHandler*
parameter.

## Parameters

### `pObject` [in]

Pointer to the object containing the class definition.

### `lFlags` [in]

One or more of the following values are valid.

#### WBEM_FLAG_USE_AMENDED_QUALIFIERS

If this flag is set, WMI does not store any qualifiers with the **amended** flavor. If this flag is not set, it is assumed that this object is not localized, and all qualifiers are stored with this instance.

#### WBEM_FLAG_CREATE_OR_UPDATE

This flag causes this class to be created if it does not exist or be overwritten if it exists already.

#### WBEM_FLAG_UPDATE_ONLY

Updates an existing class.

#### WBEM_FLAG_CREATE_ONLY

This flag is for class creation only. The call fails if the class already exists.

#### WBEM_FLAG_SEND_STATUS

This flag registers with Windows Management a request to receive intermediate status reports through the client's implementation of
[IWbemObjectSink::SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus). Provider implementation must support intermediate status reporting for this flag to change behavior.

#### WBEM_FLAG_OWNER_UPDATE

Push providers must specify this flag when calling
**PutClassAsync** to indicate that this class has changed.

#### WBEM_FLAG_UPDATE_COMPATIBLE

This flag allows a class to be updated if there are no derived classes and there are no instances for that class. It also allows updates in all cases if the change is just to non-important qualifiers (for example, the **Description** qualifier). This is the default behavior for this call and is used for compatibility with previous versions of Windows Management. If the class has instances or changes are to important qualifiers, the update fails.

#### WBEM_FLAG_UPDATE_SAFE_MODE

This flag allows updates of classes even if there are child classes, as long as the change does not cause any conflicts with child classes. An example of an update this flag would allow would be to add a new property to the base class that was not previously mentioned in any of the child classes. If the class has instances, the update fails.

#### WBEM_FLAG_UPDATE_FORCE_MODE

This flag forces updates of classes when conflicting child classes exist. An example of an update this flag would force would be if a class qualifier were defined in a child class, and the base class tried to add the same qualifier which conflicted with the existing one. In force mode, this conflict would be resolved by deleting the conflicting qualifier in the child class.

### `pCtx` [in]

Typically **NULL**. Otherwise, this is a pointer to an
[IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext) object that may be used by the provider that is receiving the requested class. The values in the context object must be specified in the documentation for the provider in question. For more information about this parameter, see
[Making Calls to WMI](https://learn.microsoft.com/windows/desktop/WmiSdk/making-calls-to-wmi).

### `pResponseHandler` [in]

Pointer to the caller's implementation of
[IWbemObjectSink](https://learn.microsoft.com/windows/desktop/WmiSdk/iwbemobjectsink). This handler receives the status of the
**Put** request when the status becomes available using the
[SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus) method. If any error code is returned, then the supplied
**IWbemObjectSink** pointer is not used. If **WBEM_S_NO_ERROR** is returned, then the user's
**IWbemObjectSink** implementation is called to indicate the result of the operation. Windows Management only calls **AddRef** to the pointer in cases where **WBEM_S_NO_ERROR** returns. In cases where an error code returns, the reference count is the same as on entry. For a detailed explanation of this parameter, see
[Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

Other status or error codes are reported to the object sink specified by the *pReponseHandler* parameter.

COM-specific error codes also may be returned if network problems cause you to lose the remote connection to Windows Management.

Note that if
[PutInstanceAsync](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-putinstanceasync) returns **WBEM_S_NO_ERROR**, WMI waits for a result from the
**SetStatus** method of the response handler. WMI waits indefinitely on a local connection or until a remote connection time-out occurs.

Because returning **WBEM_E_FAILED** causes other providers to not have a chance to create the class, it should only be returned when the class provider has failed in a way that might later succeed.

**Note** Unpredictable behavior will result if you change class definitions while they are in use by clients or providers. The
[IWbemServices::PutClass](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-putclass) method should only be used to create or update a class when there are no clients or providers currently using the class.

## Remarks

If multiple class providers are installed for one particular class, WMI will not recognize which class
provider is capable of creating that class.

The [IWbemObjectSink::SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus) method is
called to indicate the end of the result set. It may also be called with no intervening calls to
[IWbemObjectSink::Indicate](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-indicate) if error conditions
occur.

Because the call-back might not be returned at the same authentication level as the client requires, it is
recommended that you use semisynchronous instead of asynchronous communication. If you require asynchronous
communication, see [Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

For more information about using methods semisynchronously, see
[IWbemServices::PutClass](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-putclass) and
[Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

#### Examples

The following code example describes a simple implementation of
**PutClassAsync**.

```cpp
HRESULT CStdProvider::PutClassAsync(
            /* [in] */ IWbemClassObject __RPC_FAR *pObject,
            /* [in] */ long lFlags,
            /* [in] */ IWbemContext __RPC_FAR *pCtx,
            /* [in] */ IWbemObjectSink __RPC_FAR *pResponseHandler
            )
{
    // You must implement the ClassIsValid function yourself to
    // determine if the class contains a valid instance
   if (ClassIsValid(lFlags, pObject))
   {
       return WBEM_S_NO_ERROR;
   }

   return WBEM_E_PROVIDER_NOT_CAPABLE;
}
```

## See also

[Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method)

[Creating a Class](https://learn.microsoft.com/windows/desktop/WmiSdk/creating-a-class)

[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices)

[IWbemServices::PutClass](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-putclass)