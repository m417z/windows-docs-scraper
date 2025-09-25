# IWbemServices::CreateInstanceEnum

## Description

The
**IWbemServices::CreateInstanceEnum** method creates an enumerator that returns the instances of a specified class according to user-specified selection criteria. This method supports simple WQL queries; more complex queries can be processed using the
[IWbemServices::ExecQuery](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-execquery) method.

## Parameters

### `strFilter` [in]

Valid **BSTR** containing the name of the class for which instances are desired. This parameter cannot be **NULL**.

### `lFlags` [in]

The following flags affect the behavior of this method. The suggested value for this parameter is **WBEM_FLAG_RETURN_IMMEDIATELY** and **WBEM_FLAG_FORWARD_ONLY** for best performance.

#### WBEM_FLAG_USE_AMENDED_QUALIFIERS

If this flag is set, WMI retrieves the amended qualifiers stored in the localized namespace of the current connection's locale. If not set, only the qualifiers stored in the immediate namespace are retrieved.

#### WBEM_FLAG_DEEP

This flag forces the enumeration to include this and all subclasses in the hierarchy.

#### WBEM_FLAG_SHALLOW

This flag forces the enumeration to include only pure instances of this class, excluding all instances of subclasses which supply properties not found in this class.

#### WBEM_FLAG_RETURN_IMMEDIATELY

This flag causes this to be a semisynchronous call. For more information, see
[Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

#### WBEM_FLAG_FORWARD_ONLY

This flag causes a forward-only enumerator to be returned. Forward-only enumerators are generally much faster and use less memory than conventional enumerators but do not allow calls to
[Clone](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-ienumwbemclassobject-clone) or
[Reset](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-ienumwbemclassobject-reset).

#### WBEM_FLAG_BIDIRECTIONAL

This flag causes Windows Management to retain pointers to objects of the enumeration until the client releases the enumerator. Because object pointers are not released immediately, this method may fail with a *hResult* of **WBEM_E_OUT_OF_MEMORY** if the client attempts to enumerate a large number of objects. This flag is implied by default if you set the *lFlags* parameter to 0 (zero).

#### WBEM_FLAG_DIRECT_READ

This flag causes direct access to the provider for the class specified without any regard to its parent class or subclasses.

### `pCtx` [in]

Typically **NULL**. Otherwise, this is a pointer to an
[IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext) object that may be used by the provider that is providing the requested instances. The values in the context object must be specified in the documentation for the provider in question. For more information about this parameter, see
[Making Calls to WMI](https://learn.microsoft.com/windows/desktop/WmiSdk/making-calls-to-wmi).

### `ppEnum` [out]

Receives the pointer to the enumerator, which has a positive reference count. The caller must call **IUnknown::Release** on the pointer after it is no longer required.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

On failure, you can obtain any available information from the COM function [GetErrorInfo](https://learn.microsoft.com/windows/desktop/api/oleauto/nf-oleauto-geterrorinfo).

COM-specific error codes also may be returned if network problems cause you to lose the remote connection to Windows Management.

## Remarks

It is not an error for the returned enumerator to have zero elements.

## See also

[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices)

[IWbemServices::CreateInstanceEnumAsync](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-createinstanceenumasync)

[Retrieving an Error Code](https://learn.microsoft.com/windows/desktop/WmiSdk/retrieving-an-error-code)