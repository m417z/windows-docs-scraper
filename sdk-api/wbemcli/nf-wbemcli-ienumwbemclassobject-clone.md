# IEnumWbemClassObject::Clone

## Description

The **IEnumWbemClassObject::Clone** method makes
a logical copy of the entire enumerator, retaining its current position in an enumeration. This method makes only
a "best effort" copy. Due to the dynamic nature of many CIM objects, it is possible that the new enumerator does
not enumerate the same set of objects as the source enumerator.

**Note**

When the enumeration is initialized with the **WBEM_FLAG_FORWARD_ONLY** flag,
**IEnumWbemClassObject::Clone** is not
supported.

Any pending asynchronous deliveries begun by
[NextAsync](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-ienumwbemclassobject-nextasync) are not cloned.

## Parameters

### `ppEnum` [out]

Receives a pointer to a new
[IEnumWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-ienumwbemclassobject) object. The caller must call
[Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) when the interface pointer is no longer
required. On error, there will not be a return of a new object.

## Return value

On error, you can call the COM function
[GetErrorInfo](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-geterrorinfo) to obtain more error
information. COM-specific error codes may also be returned if network problems cause you to lose the remote
connection to Windows Management.

The following list lists the value contained within an **HRESULT**.

## Remarks

Because the call-back to the sink might not be returned at the same authentication level as the client
requires, it is recommended that you use semisynchronous communication instead of asynchronous. If you require
asynchronous communication, see
[Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

For more information about using methods semisynchronously, see
[IEnumWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-ienumwbemclassobject) and
[Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

#### Examples

The following code shows how to use the **IEnumWbemClassObject::Clone** method.

```cpp
BOOL CloneEnum(IEnumWbemClassObject *pSrc)
{
    IEnumWbemClassObject *pCopy = 0;

    HRESULT hRes = pSrc->Clone(&pCopy);

    if (hRes != WBEM_S_NO_ERROR)       // Failed to clone it.
        return FALSE;

    // Use the copy of the enumerator.
    // ...

    pCopy->Release();

    return TRUE;
}
```