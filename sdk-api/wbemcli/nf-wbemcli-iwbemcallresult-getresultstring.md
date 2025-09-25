# IWbemCallResult::GetResultString

## Description

The
**IWbemCallResult::GetResultString** method returns the assigned object path of an instance newly created by
[IWbemServices::PutInstance](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-putinstance).

**Note** The call result object is primarily used when the
[PutInstance](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-putinstance) call is carried out by a provider and the client needs to know the object path (the values of the key properties) assigned the provider. For example, if the class key property is a globally unique identifier (GUID), assigned by the provider during the
**PutInstance** operation, the client would have no way of knowing this GUID unless the provider was able to return it in this way.

## Parameters

### `lTimeout` [in]

Specifies the maximum time in milliseconds that this call blocks before returning. If you use the constant **WBEM_INFINITE** (0xFFFFFFFF), the call blocks until the object path is available. If you use 0, the call immediately returns either the object path or a status code.

### `pstrResultString` [out]

Cannot be **NULL**. This parameter receives a pointer to the object path, which, in turn, leads to the newly created object. The returned string must be deallocated using the system call *SysFreeString*. On error, a new string is not returned.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

On error, you can call the COM function **GetErrorInfo** to obtain more error information.

COM-specific error codes may also be returned if network problems cause you to lose the remote connection to Windows Management.

## See also

[IWbemCallResult](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcallresult)

[IWbemServices::PutInstance](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-putinstance)