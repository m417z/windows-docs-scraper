# IWbemServices::CreateClassEnum

## Description

The
**IWbemServices::CreateClassEnum** method returns an enumerator for all classes that satisfy selection criteria. The caller must use the returned enumerator to retrieve the class definitions, calling
[IEnumWbemClassObject::Next](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-ienumwbemclassobject-next) to obtain each class or blocks of classes. It finishes by calling [IEnumWbemClassObject::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release).

**Note** It is not an error for the returned enumerator to have 0 (zero) elements.

## Parameters

### `strSuperclass` [in]

If not **NULL** or blank, specifies a parent class name. Only classes that are subclasses of this class are returned in the enumerator. If it is **NULL** or blank, and *lFlags* is WBEM_FLAG_SHALLOW, only the top-level classes are returned (that is, classes that have no parent class). If it is **NULL** or blank and *lFlags* is **WBEM_FLAG_DEEP**, all classes within the namespace are returned.

### `lFlags` [in]

The following flags affect the behavior of this method. The suggested value for this parameter is WBEM_FLAG_RETURN_IMMEDIATELY and WBEM_FLAG_FORWARD_ONLY for best performance.

#### WBEM_FLAG_USE_AMENDED_QUALIFIERS

If this flag is set, WMI retrieves the amended qualifiers stored in the localized namespace of the current connection's locale. If not set, only the qualifiers stored in the immediate namespace are retrieved.

#### WBEM_FLAG_DEEP

This flag forces the enumeration to include all subclasses in the hierarchy, but not this class.

#### WBEM_FLAG_SHALLOW

This flag forces the enumeration to include only pure instances of this class, excluding all instances of subclasses that supply properties not found in this class.

#### WBEM_FLAG_RETURN_IMMEDIATELY

This flag causes a semisynchronous call. For more information, see
[Calling a Method](https://learn.microsoft.com/windows/desktop/WmiSdk/calling-a-method).

#### WBEM_FLAG_FORWARD_ONLY

This flag causes a forward-only enumerator to be returned. Typically, forward-only enumerators are faster and use less memory than conventional enumerators, but they do not allow calls to
[Clone](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemclassobject-clone) or
[Reset](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-ienumwbemclassobject-reset).

#### WBEM_FLAG_BIDIRECTIONAL

This flag causes WMI to retain pointers to objects of the enumeration until the client releases the enumerator. Because object pointers are not released immediately, this method may fail with an **HRESULT** of **WBEM_E_OUT_OF_MEMORY** if the client attempts to enumerate a large number of objects. This flag is implied by default if you set the *lFlags* parameter to 0 (zero).

### `pCtx` [in]

Typically **NULL**. Otherwise, this is a pointer to an
[IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext) object that can be used by the provider that is providing the requested classes. The values in the context object must be specified in the documentation for the provider. For more information about this parameter, see
[Making Calls to WMI](https://learn.microsoft.com/windows/desktop/WmiSdk/making-calls-to-wmi).

### `ppEnum` [out]

Receives the pointer to the enumerator. The returned object has a positive reference count. The caller must call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the pointer when it is no longer required.

## Return value

This method returns an **HRESULT** that indicates the status of a method call. The following list lists the value contained within an **HRESULT**.

On failure, you can obtain available information from the COM function [GetErrorInfo](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-geterrorinfo).

COM-specific error codes also can be returned if network problems cause you to lose the remote connection to Windows Management.

## See also

[IEnumWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-ienumwbemclassobject)

[IWbemServices](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemservices)

[IWbemServices::CreateClassEnumAsync](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-createclassenumasync)

[Retrieving an Error Code](https://learn.microsoft.com/windows/desktop/WmiSdk/retrieving-an-error-code)