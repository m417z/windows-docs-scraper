# IWbemServices::GetObjectAsync

## Description

The
**IWbemServices::GetObjectAsync** method retrieves an object, either a class definition or instance, based on its path. This is similar to
[IWbemServices::GetObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-getobject) except that the call returns immediately, and the object is provided to the supplied object sink.

Currently, this method retrieves objects only from the namespace associated with the
[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices) pointer.

## Parameters

### `strObjectPath` [in]

Path of the object to retrieve. For an instance provider, *StrObjectPath* can be in the following format:

* Namespace:Class.Key = "Value"
* Namespace:Class = "Value"
* Namespace:Class.Key = "Value", Key2 = "Value2"

Specifying the namespace before the class is optional. Object paths without namespaces refer to instances in the current namespace. If necessary, you can substitute the single-quotation mark character (') for the double-quotation mark character (") to delimit the start and end of string property types.

If this is **NULL**, an empty object, which can become a new class, is returned. For more information, see
[Creating a Class](https://learn.microsoft.com/windows/desktop/WmiSdk/creating-a-class).

### `lFlags` [in]

The following flags affect the behavior of this method.

#### WBEM_FLAG_USE_AMENDED_QUALIFIERS

If this flag is set, WMI retrieves the amended qualifiers stored in the localized namespace of the current connection's locale. If not set, only the qualifiers stored in the immediate namespace are retrieved.

#### WBEM_FLAG_DIRECT_READ

This flag causes direct access to the provider for the class specified without any regard to its parent class or subclasses.

#### WBEM_FLAG_SEND_STATUS

Registers a request to receive intermediate status reports through the client's implementation of
[IWbemObjectSink::SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus). Provider implementation must support intermediate status reporting for this flag to change behavior.

### `pCtx` [in]

Typically **NULL**. Otherwise, this is a pointer to an
[IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext) object that can be used by the provider that produces the requested class or instance. The values in the context object must be specified in the documentation for the provider in question. For more information about this parameter, see
[Making Calls to WMI](https://learn.microsoft.com/windows/desktop/WmiSdk/making-calls-to-wmi).

### `pResponseHandler` [in]

Pointer to the caller's implementation of
[IWbemObjectSink](https://learn.microsoft.com/windows/desktop/WmiSdk/iwbemobjectsink). This handler receives the requested object when it becomes available through the
[IWbemObjectSink::Indicate](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-indicate) method. The *pObjParam* parameter contains the object. If any error code is returned, then the supplied
**IWbemObjectSink** pointer is not used. If **WBEM_S_NO_ERROR** is returned, then the user's
**IWbemObjectSink** implementation is called to indicate the result of the operation. Windows Management only calls AddRef to the pointer in cases where **WBEM_S_NO_ERROR** returns. In cases where an error code returns, the reference count is the same as on entry. For more information about this parameter, see
[Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

## Return value

This method returns an **HRESULT** that indicates the status of the method call. The following list lists the value contained within an **HRESULT**.

On failure, you can obtain any available information from the COM function [GetErrorInfo](https://learn.microsoft.com/windows/desktop/api/oleauto/nf-oleauto-geterrorinfo)**GetErrorInfo**.

COM-specific error codes can also be returned if network problems cause you to lose the remote connection to Windows Management.

## Remarks

When implementing an instance provider, you should use the object path parser sample code in the WMI section of the PSDK to parse the object path for recognizing which object the client requests. Further, a provider that supports a derived class need only supply the values for the local properties of the class, rather than the inherited properties. WMI requests that the provider of the base class handle inherited properties.

When implementing a class provider,
**GetObjectAsync** must determine which class is being requested by parsing the class name object path stored in the *strObjectPath* parameter. The
**GetObjectAsync** method then either builds the class dynamically or takes the class from a private cache. Then,
**GetObjectAsync** sends the class to WMI using the
[IWbemObjectSink](https://learn.microsoft.com/windows/desktop/WmiSdk/iwbemobjectsink) pointer pointed to by the *pResponseHandler* parameter. The
[IWbemObjectSink::SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus) method is called to indicate the end of the result set. It can also be called with no intervening calls to
[IWbemObjectSink::Indicate](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-indicate) if error conditions occur.

Because the call-back might not be returned at the same authentication level as the client requires, it is recommended that you use semisynchronous instead of asynchronous communication. If you require asynchronous communication, see [Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

For more information about using methods semisynchronously, see [IWbemServices::GetObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-getobject) and [Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

#### Examples

The following example describes how to implement
**GetObjectAsync** for an instance provider.

```cpp
SCODE CInstPro::GetObjectAsync (BSTR ObjectPath,
                                long lFlags, IWbemContext *pCtx,
                                IWbemObjectSink FAR* pHandler)
{
    ULONG cRef;         // Reference count
    SCODE sc;
    BOOL bOK = FALSE;

    IWbemServices *  m_pNamespace;
    IWbemClassObject FAR* pObj;

    // Check arguments.

    if(ObjectPath == NULL || pHandler == NULL ||
        m_pNamespace == NULL)
        return WBEM_E_INVALID_PARAMETER;

    // Based on the object path, produce an empty instance
    // of the class and gather required data,
    // setting the instance's property values accordingly.
    // This example assumes that GetByPath is implemented
    // by the provider to do this.
    // The IWbemPath interface can be used to parse
    // the object path, separating the namespace and class name.

    sc = GetByPath (ObjectPath, &pObj, pCtx);
    if(sc == S_OK)
    {
        pHandler->Indicate (1, &pObj);
        pObj->Release();
        bOK = TRUE;
    }

    sc = (bOK) ? S_OK : WBEM_E_NOT_FOUND;

    // Set status.

    pHandler->SetStatus(0,sc, NULL, NULL);

    // Free memory resources.

    SysFreeString(ObjectPath);
    m_pNamespace->Release();
    pObj->Release();

    return sc;

}
```

The following example shows how a typical class provider implements
**GetObjectAsync**.

```cpp
HRESULT CStdProvider::GetObjectAsync(
            /* [in] */ BSTR strObjectPath,
            /* [in] */ long lFlags,
            /* [in] */ IWbemContext __RPC_FAR *pCtx,
            /* [in] */ IWbemObjectSink __RPC_FAR *pResponseHandler
            )
{

    IWbemClassObject *pClass = 0;

// Assume there is an IWbemServices pointer available.
// Retrieve an 'empty' object which is built up
// into the class definition.

    HRESULT hRes = m_pSvc->GetObject(NULL, 0, NULL, &pClass, 0);
    if (hRes)
        return hRes;

// Parse the object path and determine which class is
// required. The path string is the required class name.
// Fill in the properties required for the class definition
// using pClass->Put(...), and so on.

    // ...

    // Send the class definition back to WMI.
    pResponseHandler->Indicate(1, &pClass);

// Indicate that it is now finished.

    pResponseHandler->SetStatus(0, WBEM_S_NO_ERROR, 0, 0);
    SysFreeString(strObjectPath);
    m_pSvc->Release();
    pClass->Release();  // This is no longer needed.
    return WBEM_S_NO_ERROR;
}
```

## See also

[Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method)

[Creating a Class](https://learn.microsoft.com/windows/desktop/WmiSdk/creating-a-class)

[Describing the Location of a WMI Object](https://learn.microsoft.com/windows/desktop/WmiSdk/describing-the-location-of-a-wmi-object)

[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices)

[IWbemServices::GetObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-getobject)