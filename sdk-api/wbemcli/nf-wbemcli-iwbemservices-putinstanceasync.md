# IWbemServices::PutInstanceAsync

## Description

The **IWbemServices::PutInstanceAsync**
method asynchronously creates or updates an instance of an existing class. Update confirmation or error reporting
is provided through the [IWbemObjectSink](https://learn.microsoft.com/windows/desktop/WmiSdk/iwbemobjectsink) interface
implemented by the caller.

## Parameters

### `pInst` [in]

Pointer to the instance to be written to the WMI repository. The caller cannot make assumptions about the
reference count at the completion of this call.

### `lFlags` [in]

Specifies whether the caller wants the instance created if the instance does not currently exist.

When implementing an instance provider, you can choose to support a limited number of the flags in
*lFlags* by returning **WBEM_E_PROVIDER_NOT_CAPABLE**.

This property can have one or more of the following values.

#### WBEM_FLAG_CREATE_OR_UPDATE

This flag causes this instance to be created if it does not exist or be overwritten if it exists already.

#### WBEM_FLAG_UPDATE_ONLY

Updates an existing instance.

#### WBEM_FLAG_CREATE_ONLY

This flag is for instance creation only. The call fails if the class already exists.

#### WBEM_FLAG_SEND_STATUS

This flag registers with Windows Management a request to receive intermediate status reports through the
clients implementation of
[IWbemObjectSink::SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus). Provider
implementation must support intermediate status reporting for this flag to change behavior.

#### WBEM_FLAG_USE_AMENDED_QUALIFIERS

If this flag is set, WMI does not store any qualifiers with the
**Amended** flavor. If this flag is not set, it is assumed that this object is
not localized, and all qualifiers are stored with this instance.

### `pCtx` [in]

Pointer describing if the client is requesting a partial-instance update or full-instance update. A partial-instance update modifies a subset of the properties of the instance. In contrast, a full-instance update modifies all of the properties. If **NULL**, this parameter indicates that the caller application is requesting a full-instance update. Otherwise, this is a pointer to an
[IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext) object required by the dynamic class provider that is producing the class instances. For more information about this parameter, see
[Making Calls to WMI](https://learn.microsoft.com/windows/desktop/WmiSdk/making-calls-to-wmi).

### `pResponseHandler` [in]

Pointer to the caller's implementation of
[IWbemObjectSink](https://learn.microsoft.com/windows/desktop/WmiSdk/iwbemobjectsink). This handler receives the status of this call when it becomes available using the
[IWbemObjectSink::SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus) method. If any error code is returned, then the supplied
**IWbemObjectSink** pointer is not used. If **WBEM_S_NO_ERROR** is returned, then the user's
**IWbemObjectSink** implementation is called to indicate the result of the operation. Windows Management only calls **AddRef** on the pointer in cases where **WBEM_S_NO_ERROR** returns. In cases where an error code returns, the reference count is the same as on entry. For more information about how to make asynchronous calls, see
[Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

Note that if
**PutInstanceAsync** returns **WBEM_S_NO_ERROR**, WMI waits for a result from the
**SetStatus** method of the response handler. WMI waits indefinitely on a local connection or until a remote connection time-out occurs.

COM-specific error codes also may be returned if network problems cause you to lose the remote connection to Windows Management.

## Remarks

Clients that call
**PutInstanceAsync** must always expect the results of the call to be reported using their
[IWbemObjectSink::Indicate](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-indicate) method.

When the instance pointed to by *pInst* belongs to a class that is derived from other classes, the success of
**PutInstanceAsync** depends on the success of the providers responsible for the parent classes. For example, if *pInst* belongs to **ClassB** and **ClassB** derives from **ClassA**, a call to the
**PutInstanceAsync** method implemented by the provider for **ClassA** must succeed for the update operation on **ClassB** to succeed. For more information, see Remarks in
[IWbemServices::PutInstance](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-putinstance).

When implementing an instance provider, if the instance has a key property set to **NULL**,
**PutInstanceAsync** should choose a value guaranteed to be unique within the class. When WMI services a request to update an instance with a **NULL** key property, it internally generates a **GUID** and assigns it to the key property. Further, when the instance being updated belongs to a child class, the success of the operation is dependent on the success of a
**PutInstanceAsync** call to each of the providers responsible for the classes higher in the hierarchy. Do not return **WBEM_S_NO_ERROR** until you are sure that all of the other providers have succeeded. For more information, see
[IWbemServices::PutInstance](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-putinstance).

Instance providers supporting a partial update must check for the existence of the **__PUT_EXTENSIONS** context value. A system context value is a value defined by WMI to have specific meanings, is set by the client application, and is supported by an instance provider. The
[IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext) interface provides access to the system context values and other provider-specific context values. The following list lists the context values that support partial-instance update operations.

The
[IWbemObjectSink::SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus) method is called to indicate the end of the result set. It may also be called with no intervening calls to
[IWbemObjectSink::Indicate](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-indicate) if error conditions occur.

Because the call-back might not be returned at the same authentication level as the client requires, it is recommended that you use semisynchronous instead of asynchronous communication. If you require asynchronous communication, see [Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

For more information about using methods semisynchronously, see [IWbemServices::PutInstance](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-putinstance) and [Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

| System context value | Description |
| --- | --- |
| **__PUT_EXTENSIONS**<br><br>(**VT_BOOL**) | The client application has set one or more of the other system context values to provide more information about the update operation. |
| **__PUT_EXT_STRICT_NULLS**<br><br>(**VT_BOOL**) | The instance provider must force the setting of properties to **VT_NULL** when appropriate and raise an error on failure. |
| **__PUT_EXT_PROPERTIES**<br><br>(**VT_ARRAY** | **VT_BSTR**) | Contains a list of the properties to update. The instance provider should ignore all other properties. |
| **__PUT_EXT_ATOMIC**<br><br>(**VT_BOOL**) | All updates must succeed or the instance provider must revert back. There can be no partial success. |

When implementing an instance provider, you should respond to a **NULL** property in *pCtx* in the following manner:

* If the property type is **VT_NULL**, the provider can either ignore the property without making a change or fail the operation.
* If the property type is not **VT_NULL** and the property cannot be updated, the provider should return an error, because the provider is obligated to update the property with the new value.

If *pCtx* is not **NULL** and points to valid context information, the caller application is requesting a partial-instance update. As before, an instance providers that does not support partial-instance updating should fail the operation by returning **WBEM_E_PROVIDER_NOT_CAPABLE**.

When implementing an async operation, the async operation not complete until you release any [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref)'s you have performed on *pResponseHandler*. This is the case even if you call [SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus) on *pResponseHander*. If *pResponseHandler* is leaked, any sync or semi-sync clients will also not complete and possibly stop responding, depending on your implementation.

Even in catastrophic cases, you must release the references for decoupled providers. This is because in sync and semi-sync cases, the WMI service owns the implementation of *pResponseHandler*: even if your decoupled provider's process exits, the clients will still not be responding.

#### Examples

The following example describes how to structure
**PutInstanceAsync**.

```cpp
HRESULT CStdProvider::PutInstanceAsync(
            /* [in] */ IWbemClassObject __RPC_FAR *pInst,
            /* [in] */ long lFlags,
            /* [in] */ IWbemContext __RPC_FAR *pCtx,
            /* [in] */ IWbemObjectSink __RPC_FAR *pResponseHandler
            )
{
   // You must implement the InstanceIsValid method
   // to check to see if the instance in the pInst variable
   // is valid.
   if (InstanceIsValid(lFlags, pInst))
   {
       return WBEM_S_NO_ERROR;
   }

   return WBEM_E_PROVIDER_NOT_CAPABLE;
}
```

## See also

[Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method)

[Creating an Instance](https://learn.microsoft.com/windows/desktop/WmiSdk/creating-an-instance)

[IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext)

[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices)