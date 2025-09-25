# IWbemContext::GetNames

## Description

The
**IWbemContext::GetNames** method returns a **SAFEARRAY** structure of all of the names of the named context values. After all the names are known,
[GetValue](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemcontext-getvalue) can be called on each name to retrieve the value. This technique is a way of accessing the context values that is different from calling the
[BeginEnumeration](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemcontext-beginenumeration),
[Next](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemcontext-next), and
[EndEnumeration](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemcontext-endenumeration) methods.

## Parameters

### `lFlags` [in]

Reserved. This parameter must be 0.

### `pNames` [out]

This parameter cannot be **NULL**, but on entry it must point to **NULL**. If no error is returned, on exit *pstrNames* receives a pointer to a new **SAFEARRAY** structure of type VT_BSTR containing all the context value names. The caller must call **SafeArrayDestroy** on the returned pointer when the array is no longer required. If an error code is returned, the pointer is left unmodified.

**Note** If there are no named values in the object, the call succeeds and returns an array of length 0.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

## Remarks

For more information about using **SAFEARRAY** structures of **BSTR** values, see
[Retrieving Part of a WMI Instance](https://learn.microsoft.com/windows/desktop/WmiSdk/retrieving-part-of-an-instance).

## See also

[IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext)

[IWbemContext::BeginEnumeration](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemcontext-beginenumeration)

[IWbemContext::GetValue](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemcontext-getvalue)