# IWbemContext::Clone

## Description

The
**IWbemContext::Clone** method makes a logical copy of the current
[IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext) object. This method can be useful when many calls must be made which have largely identical
**IWbemContext** objects.

## Parameters

### `ppNewCopy` [out]

Must point to **NULL** on entry. It receives a pointer to the new object containing the clone of the current object. The returned pointer has a positive reference count. The caller must call **IWbemServices::Release** on this pointer when it is no longer needed. On error, this pointer is left unmodified, and a new object is not returned.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.