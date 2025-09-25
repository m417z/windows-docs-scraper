# IWbemClassObject::GetObjectText

## Description

The
**IWbemClassObject::GetObjectText** method returns a textual rendering of the object in the MOF syntax. Notice that the MOF text returned does not contain all the information about the object, but only enough information for the MOF compiler to be able to re-create the original object. For instance, no propagated qualifiers or parent class properties are displayed.

## Parameters

### `lFlags` [in]

Normally 0. If **WBEM_FLAG_NO_FLAVORS** is specified, qualifiers will be presented without propagation or flavor information.

### `pstrObjectText` [out]

This must point to **NULL** on entry. This parameter receives from Windows Management a newly allocated **BSTR** that was initialized with **SysAllocString**. You must call **SysFreeString** on the pointer when the string is no longer required. This pointer points to a MOF syntax rendering of the object upon return from the call. Because this is an out parameter, the pointer must not point to a string that is valid before this method is called, because the pointer will not be deallocated.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**. For general **HRESULT** values, see [System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The following algorithm is used to reconstruct the text of the parameters of a method:

1. Parameters are resequenced in the order of their identifier values.
2. Parameters that are specified as [in] and [out] will be combined into a single parameter.

## See also

[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject)

[IWbemQualifierSet](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemqualifierset)

[WBEM_TEXT_FLAG_TYPE](https://learn.microsoft.com/windows/win32/api/wbemcli/ne-wbemcli-wbem_text_flag_type)