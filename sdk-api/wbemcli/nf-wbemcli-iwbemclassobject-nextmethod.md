# IWbemClassObject::NextMethod

## Description

The
**IWbemClassObject::NextMethod** method is used to retrieve the next method in a method enumeration sequence that starts with
a call to [IWbemClassObject::BeginMethodEnumeration](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemclassobject-beginmethodenumeration).

This call is only supported if the current object is a CIM class definition. Method manipulation is not available from
[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject) pointers that point to CIM instances.

## Parameters

### `lFlags` [in]

Reserved. This parameter must be 0 (zero).

### `pstrName` [out]

A pointer that should point to **NULL** prior to the call. This parameter receives the address of a **BSTR** value containing the method name. The caller must release the string using **SysFreeString** when it is no longer required.

### `ppInSignature` [out]

A pointer that receives a pointer to an
[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject) containing the in parameters for the method.

### `ppOutSignature` [out]

A pointer that receives a pointer to an
[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject) containing the out parameters for the method.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**. For general **HRESULT** values, see [System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The caller begins the enumeration sequence using
[IWbemClassObject::BeginMethodEnumeration](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemclassobject-beginmethodenumeration), and then calls
**IWbemClassObject::NextMethod** until **WBEM_S_NO_MORE_DATA** is returned. The caller, optionally, finishes the sequence with
[IWbemClassObject::EndMethodEnumeration](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemclassobject-endmethodenumeration). The caller may terminate the enumeration early by calling
**IWbemClassObject::EndMethodEnumeration** at any time.

**Note** The caller must call [IWbemClassObject::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the *ppInSignature* and *ppOutSignature* pointers when these objects are no longer required.