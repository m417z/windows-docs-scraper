# IWbemHiPerfProvider::GetObjects

## Description

The
**IWbemHiPerfProvider::GetObjects** method inserts the non-key properties of the objects in the supplied array. WMI calls
**GetObjects** in response to a
[IWbemServices::GetObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-getobject) call. If a provider does not implement
**GetObjects**, WMI attempts to service a
**GetObject** request with a call to the
[IWbemHiPerfProvider::CreateRefreshableObject](https://learn.microsoft.com/windows/desktop/api/wbemprov/nf-wbemprov-iwbemhiperfprovider-createrefreshableobject) method.

**Note** If a provider does not implement this method, it must return **WBEM_E_PROVIDER_NOT_CAPABLE**.

## Parameters

### `pNamespace` [in]

An
[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices) pointer back into Windows Management, which can service any request made by the provider. The provider should call [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on this pointer if it is going to call back into Windows Management during its execution.

### `lNumObjects` [in]

Integer that contains the number of objects you are retrieving.

### `apObj` [in, out]

Pointer to an array of
[IWbemObjectAccess](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemobjectaccess) objects. The **GetObjects** method inserts the key properties of each object into this array.

### `lFlags`

Reserved. This parameter must be 0.

### `pContext`

Typically **NULL**; otherwise, a pointer to an
[IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext) object that is required by one or more dynamic class providers. The values in the context object must be specified in specific provider documentation. For more information about this parameter, see
[Making Calls to WMI.](https://learn.microsoft.com/windows/desktop/WmiSdk/making-calls-to-wmi).

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

## Remarks

The requested objects will have their key properties filled out.

#### Examples

The following code example describes how to implement
**GetObjects**.

```cpp
HRESULT CMyHiPerfProvider::GetObjects(
  /* [in] */IWbemServices *pNamespace,
  /* [in] */  long lNumObjects,
  /* [in,out] */IWbemObjectAccess **apObj,
  /* [in] */long lFlags,
  /* [in] */IWbemContext *pCtx
)
{

  for ( long i = 0; i < lNumObjects; i++ )
  {
      // Validate the instance (that is, ensure
      // the path is good); if it fails, return
      // the error.

      // For example, create a method that validates
      // the IWbemObjectAccess instance and returns
      // false if validation failed.
      /*if ( !ValidateInstance( apObj[i] ) )
          return WBEM_E_NOT_FOUND;*/

      // Fill out the instance.
      // For example, create a method that assigns
      // a value to the IWbemObjectAccess instance.
      /*FillInstance( apObj[i] );*/
  }

  return WBEM_S_NO_ERROR;
}
```

## See also

[Developing a WMI Provider](https://learn.microsoft.com/windows/desktop/WmiSdk/developing-a-wmi-provider)

[IWbemHiPerfProvider](https://learn.microsoft.com/windows/desktop/api/wbemprov/nn-wbemprov-iwbemhiperfprovider)

Making an Instance Provider into a High-Performance Provider

[Performance Counter Provider](https://learn.microsoft.com/windows/desktop/WmiSdk/performance-counter-provider)

[Writing an Instance Provider](https://learn.microsoft.com/windows/desktop/WmiSdk/making-an-instance-provider-into-a-high-performance-provider)