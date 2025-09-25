# IWbemClassObject::Delete

## Description

The
**IWbemClassObject::Delete** method deletes the specified property from a CIM class definition and all of its qualifiers. Because instances cannot have contents that are different from the owning class, delete operations for properties are only possible on class definitions. If you invoke
**Delete** on a property in an instance, the operation succeeds; however, rather than removing the value, it is simply reset to the default value for the class.

It is not possible to delete a property inherited from a parent class. However, if an override default value for a property inherited from a parent class was specified, it is possible to revert to the parent's default value by invoking this method. In this case, **WBEM_S_RESET_TO_DEFAULT** is returned.

[System properties](https://learn.microsoft.com/windows/desktop/WmiSdk/wmi-system-properties) cannot be deleted.

## Parameters

### `wszName` [in]

Property name to delete. This must point to a valid **LPCWSTR**. It is treated as read-only.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**. For general **HRESULT** values, see [System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject)

[WMI System Properties](https://learn.microsoft.com/windows/desktop/WmiSdk/wmi-system-properties)