# IWbemClassObject::BeginMethodEnumeration

## Description

Use the
**IWbemClassObject::BeginMethodEnumeration** method call to begin an enumeration of the methods available for the object.

This call is only supported if the current object is a CIM class definition. Method manipulation is not available from
[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject) pointers which point to CIM instances. The order in which methods are enumerated is guaranteed to be invariant for a given instance of
**IWbemClassObject**.

## Parameters

### `lEnumFlags` [in]

Specifies the scope of the enumeration.

Possible values:

#### WBEM_FLAG_LOCAL_ONLY

Only include methods that are defined in the class itself.

#### WBEM_FLAG_PROPAGATED_ONLY

Only include methods that are inherited from parent classes.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**. For general **HRESULT** values, see [System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject)

[IWbemClassObject::NextMethod](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemclassobject-nextmethod)