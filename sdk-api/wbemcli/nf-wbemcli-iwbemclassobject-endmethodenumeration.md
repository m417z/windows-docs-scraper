# IWbemClassObject::EndMethodEnumeration

## Description

The
**IWbemClassObject::EndMethodEnumeration** method is used to terminate a method enumeration sequence started with
[IWbemClassObject::BeginMethodEnumeration](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemclassobject-beginmethodenumeration).

This call is only supported if the current object is a CIM class definition. Method manipulation is not available from
[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject) pointers which point to CIM instances.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**. For general **HRESULT** values, see [System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The caller begins the enumeration sequence using
[IWbemClassObject::BeginMethodEnumeration](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemclassobject-beginmethodenumeration), and then calls
[IWbemClassObject::NextMethod](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemclassobject-nextmethod) until **WBEM_S_NO_MORE_DATA** is returned. The caller optionally finishes the sequence with
**IWbemClassObject::EndMethodEnumeration**. The caller may terminate the enumeration early by calling
**IWbemClassObject::EndMethodEnumeration** at any time.