# IWbemClassObject::BeginEnumeration

## Description

The
**IWbemClassObject::BeginEnumeration** method resets an enumeration back to the beginning of the enumeration. The caller must call this method prior to the first call to
[IWbemClassObject::Next](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemclassobject-next) to enumerate all of the properties on an object. The order in which properties are enumerated is guaranteed to be invariant for a given instance of
[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject).

## Parameters

### `lEnumFlags` [in]

Combination of flags described in Remarks.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**. For general **HRESULT** values, see [System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

You can control the properties included in the enumeration by specifying a combination of the following flags. You can combine one flag from each group with any flag from any other group. However, flags from the same group are mutually exclusive.

GROUP 1

GROUP 2

## See also

[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject)

[IWbemClassObject::EndEnumeration](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemclassobject-endenumeration)

[IWbemClassObject::Next](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemclassobject-next)

[WMI System Properties](https://learn.microsoft.com/windows/desktop/WmiSdk/wmi-system-properties)