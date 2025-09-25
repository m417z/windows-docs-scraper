# IWbemClassObject::GetMethodOrigin

## Description

The
**IWbemClassObject::GetMethodOrigin** method is used to determine the class for which a method was declared.

This call is only supported if the current object is a CIM class definition. Method manipulation is not available from
[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject) pointers which point to CIM instances.

## Parameters

### `wszMethodName` [in]

Name of the method for the object whose owning class is being requested.

### `pstrClassName` [out]

Receives the name of the class which owns the method. The user must call **SysFreeString** on the returned *BSTR* when it is no longer required.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**. For general **HRESULT** values, see [System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

Because methods are inherited from class to class, it is often desirable to determine the owning class for a given method.