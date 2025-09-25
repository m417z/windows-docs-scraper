# IEnumWbemClassObject::Next

## Description

Use the **IEnumWbemClassObject::Next** method to
get one or more objects starting at the current position in an enumeration. This method advances the current
position in the enumeration by *uCount* objects, so that subsequent calls return the
subsequent objects.

## Parameters

### `lTimeout` [in]

Specifies the maximum amount of time in milliseconds that the call blocks before returning. If you use the
constant **WBEM_INFINITE** (0xFFFFFFFF), the call blocks until objects are available. If
you use the value 0 (**WBEM_NO_WAIT**), the call returns immediately, whether any objects
are available or not.

### `uCount` [in]

Number of requested objects.

### `apObjects` [out]

Pointer to enough storage to hold the number of
[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject) interface pointers specified by
*uCount*. This storage must be supplied by the caller. This parameter cannot be
**NULL**. The caller must call **Release** on each of the received
interface pointers when they are no longer needed.

### `puReturned` [out]

Pointer to a **ULONG** that receives the number of objects returned. This number can
be less than the number requested in *uCount*. This pointer cannot be
**NULL**.

**Note** The **Next** method returns
**WBEM_S_FALSE** when you have reached the end of the enumeration, even if objects have
been returned successfully. The **WBEM_S_NO_ERROR** value returns only when the number of
objects returned matches the number requested in *uCount*. The
**WBEM_S_TIMEDOUT** value is returned when the number of objects returned is less than
the number requested but you are not at the end of the enumeration. Therefore, you should use loop termination
logic that examines the *puReturned* value to ensure that you have reached the end of
the enumeration.

## Return value

The **Next** method returns an **HRESULT** indicating
the status of the method call. The following list lists the value contained within an
**HRESULT**.

## Remarks

You may see COM-specific error codes returned if network problems cause you to lose the remote connection to Windows Management. On error, you can call the COM function [GetErrorInfo](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-geterrorinfo) to obtain more error information.

If more than one object is requested, and if the number of requested objects is returned, the function returns **WBEM_S_NO_ERROR**. If less than the requested number of objects is available, and if the enumeration has completed, those objects are returned and the function returns **WBEM_S_FALSE**.

If the enumeration has not completed, the call waits for objects to be available up to the specified time-out. If the enumeration times out before the objects are available, the function returns **WBEM_S_TIMEDOUT**.

**Note** Because the call-back to the sink might not be returned at the same authentication level as the client requires, it is recommended that you use semisynchronous instead of asynchronous communication. For more information, see [Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

#### Examples

For an extended discussion and example of making queries in C++ and WMI, see Making [WMI Queries In C++](https://www.codeproject.com/Articles/10539/Making-WMI-Queries-In-C) on CodeProject.

In the following code, more than one object is requested:

```cpp
HRESULT ProcessEnum( IEnumWbemClassObject*    pEnum )
{
    HRESULT    hRes = WBEM_S_NO_ERROR;

    // Final Next will return WBEM_S_FALSE
    while ( WBEM_S_NO_ERROR == hRes )
    {
        ULONG            uReturned;
        IWbemClassObject*    apObj[10];

        hRes = pEnum->Next( WBEM_INFINITE, 10, apObj, &uReturned );

        if ( SUCCEEDED( hRes ) )
        {
            // Do something with the objects.
            //ProcessObjects( uReturned,  apObj );

            for ( ULONG n = 0; n < uReturned; n++ )
            {
                apObj[n]->Release();
            }

        }    // If Enum succeeded...
    }    // While Enum is returning objects...

    return hRes;
}
```

## See also

[Enumerating WMI](https://learn.microsoft.com/windows/desktop/WmiSdk/enumerating-wmi)

[IEnumWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-ienumwbemclassobject)