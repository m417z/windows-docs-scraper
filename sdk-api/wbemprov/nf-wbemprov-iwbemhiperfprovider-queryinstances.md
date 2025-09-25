# IWbemHiPerfProvider::QueryInstances

## Description

The
**IWbemHiPerfProvider::QueryInstances** method returns instances of the specified class using the supplied
[IWbemObjectSink](https://learn.microsoft.com/windows/desktop/WmiSdk/iwbemobjectsink) instance. The method should return immediately. The [IWbemObjectSink](https://learn.microsoft.com/windows/desktop/WmiSdk/iwbemobjectsink) interface is used to specify results.

**Note** If a provider does not implement this method, it must return **WBEM_E_PROVIDER_NOT_CAPABLE**.

## Parameters

### `pNamespace` [in]

An
[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices) pointer back to WMI that can service any request from the provider. The provider should call [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on this pointer if it needs to call back to WMI during execution.

### `wszClass` [in]

Pointer to a **WCHAR** string that specifies the class whose instances are returned.

### `lFlags` [in]

Integer that contains the flags.

### `pCtx` [in]

Typically **NULL**; otherwise, a pointer to an
[IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext) object that is required by one or more dynamic class providers. The values in the context object must be specified in the provider documentation. For more information, see
[Making Calls to WMI](https://learn.microsoft.com/windows/desktop/WmiSdk/making-calls-to-wmi).

### `pSink` [in]

Pointer to the
[IWbemObjectSink](https://learn.microsoft.com/windows/desktop/WmiSdk/iwbemobjectsink) implementation that is provided by the client to any of the asynchronous methods of
[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices).

## Return value

This method returns an **HRESULT** that indicates the status of the method call. The following list lists the value contained within an **HRESULT**.

HiPerf providers can report success or failure either through the return code from
**QueryInstances** or through a call to the
[SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus) method of *pResponseHandler*. If you call the
**SetStatus** method, the return code sent through *pResponseHandler* takes precedence over the
**QueryInstances** return code.

## Remarks

WMI calls
**QueryInstances** in response to an
[IWbemServices::CreateInstanceEnum](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-createinstanceenum) or
[IWbemServices::CreateInstanceEnumAsync](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-createinstanceenumasync) request.

The
[IWbemObjectSink::SetStatus](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-setstatus) method is called to indicate the end of the result set. When error conditions occur,
**IWbemObjectSink::SetStatus** may also be called with no intervening calls to
[IWbemObjectSink::Indicate](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemobjectsink-indicate).

#### Examples

The following code example shows how to implement
**QueryInstances**.

```cpp
HRESULT CMyHiPerfProvider::QueryInstances(
    /* [in] */ IWbemServices* pNamespace,
    /* [in] */ BSTR strClass,
    /* [in] */ long lFlags,
    /* [in] */ IWbemContext __RPC_FAR *pCtx,
    /* [in] */ IWbemObjectSink __RPC_FAR *pSink
)
{
   IWbemClassObject *pClass = 0;
   IWbemClassObject *pNextInst = 0;

   // The IWbemObjectSink interface must be
   // implemented in a class that you define. You then
   // must assign the pResponseHandler pointer
   // an instance of the class that implements
   // the IWbemObjectSink interface.
   IWbemObjectSink* pResponseHandler = 0;
   HRESULT hRes;

    // Use the namespace pointer to retrieve a class
    // definition.

   hRes = pNamespace ->GetObject(strClass, 0, NULL, &pClass, 0);
   if (WBEM_NO_ERROR==hRes)
       return hRes;

    // Now loop through the private source and create each instance.

     for (int i = 0 ; i < NUM_OF_INSTANCES ; i++)
    {
         hRes = pClass->SpawnInstance(0, &pNextInst);

         // Exit loop if no new instance is spawned
         if (WBEM_S_FALSE == hRes)
            break;

        if(NULL!=pNextInst)
       {
        // Create the instance.
        // For example, call a function (FillInst) that
        // assigns a value to the pNextInst pointer.
        /*FillInst(pNextInst);*/

        // Deliver the class to WMI.
        pResponseHandler->Indicate(1, &pNextInst);
        pNextInst->Release();
        pNextInst=NULL;
       }
    }

   // Send a finish message to WMI.
    pResponseHandler->SetStatus(0, WBEM_S_NO_ERROR, 0, 0);
    // Free memory resources.
    pNamespace->Release();
    pClass->Release();
    SysFreeString(strClass);

  return WBEM_S_NO_ERROR;
}

```

## See also

[Developing a WMI Provider](https://learn.microsoft.com/windows/desktop/WmiSdk/developing-a-wmi-provider)

[IWbemHiPerfProvider](https://learn.microsoft.com/windows/desktop/api/wbemprov/nn-wbemprov-iwbemhiperfprovider)

Making an Instance Provider into a High-Performance Provider

[Performance Counter Provider](https://learn.microsoft.com/windows/desktop/WmiSdk/performance-counter-provider)

[Writing an Instance Provider](https://learn.microsoft.com/windows/desktop/WmiSdk/making-an-instance-provider-into-a-high-performance-provider)