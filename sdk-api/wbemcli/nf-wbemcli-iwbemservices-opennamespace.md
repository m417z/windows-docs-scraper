# IWbemServices::OpenNamespace

## Description

The
**IWbemServices::OpenNamespace** method provides the caller with a new
[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices) pointer that has the specified child namespace as its operating context. All operations through the new pointer, such as class or instance creation, only affect that namespace. The namespace must be a child namespace of the current object through which this method is called.

## Parameters

### `strNamespace` [in]

Path to the target namespace. For more information, see
[Creating Hierarchies within WMI](https://learn.microsoft.com/windows/desktop/WmiSdk/creating-hierarchies-within-wmi). This namespace can only be relative to the current namespace associated with the
[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices) interface pointer. This parameter cannot be an absolute path or **NULL**.

### `lFlags` [in]

This parameter can be set to 0 to make this a synchronous call. To make this a semisynchronous call, set *lFlags* to **WBEM_FLAG_RETURN_IMMEDIATELY**, provide a valid pointer for the *ppResult* parameter, and this call will return immediately. For more information, see
[Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

### `pCtx` [in]

Reserved. This parameter must be **NULL**.

### `ppWorkingNamespace` [out]

Receives the object that represents the new namespace context. The returned pointer has a positive reference count. The caller must call **Release** on this pointer when it is no longer needed. This pointer is set to **NULL** when there are errors. If this parameter is specified, then *ppResult* must be **NULL**.

### `ppResult` [out]

Typically **NULL**. If not **NULL**, then *ppWorkingNamespace* must be **NULL**. In this case, the parameter receives a pointer to a new
[IWbemCallResult](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcallresult) object. If the *lFlags* parameter is set to **WBEM_FLAG_RETURN_IMMEDIATELY** this call returns immediately. Then the caller can periodically poll the
[IWbemCallResult::GetResultServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemcallresult-getresultservices) method until the pointer for the requested namespace becomes available. This parameter is set to point to **NULL** when there is an error and a new object is not returned.

**Note** It is important to note that when you use this parameter, you must set *ppResult* to point to **NULL** before calling the method. This is a COM rule.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

On failure, you can obtain any available information from the COM function [GetErrorInfo](https://learn.microsoft.com/windows/desktop/api/oleauto/nf-oleauto-geterrorinfo).

COM-specific error codes may also be returned if network problems cause you to lose the remote connection to Windows Management.

## Remarks

The
[IWbemLocator::ConnectServer](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemlocator-connectserver) method can also be used to open the same namespace. The only difference is that the
**OpenNamespace** method allows you to place relative object paths in the *Namespace* parameter to open child namespaces recursively;
**IWbemLocator::ConnectServer** requires a full object path. For more information, see
[Describing a WMI Namespace Object Path](https://learn.microsoft.com/windows/desktop/WmiSdk/describing-a-wmi-namespace-object-path).

For example, if the current namespace associated with the
[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices) interface pointer is root, then using Default in the *Namespace* parameter yields a new pointer bound to the root\default namespace.

The namespace is closed when **Release** is called and the reference count reaches 0 (zero).

## See also

[Creating Hierarchies within WMI](https://learn.microsoft.com/windows/desktop/WmiSdk/creating-hierarchies-within-wmi)

[IWbemLocator::ConnectServer](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemlocator-connectserver)

[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices)

[Retrieving an Error Code](https://learn.microsoft.com/windows/desktop/WmiSdk/retrieving-an-error-code)