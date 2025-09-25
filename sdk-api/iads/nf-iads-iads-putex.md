# IADs::PutEx

## Description

The **IADs::PutEx** method modifies the values of an attribute in the ADSI attribute cache. For example, for properties that allow multiple values, you can append additional values to an existing set of values, modify the values in the set, remove specified values from the set, or delete values from the set.

## Parameters

### `lnControlCode` [in]

Control code that indicates the mode of modification: Append, Replace, Remove, and Delete. For more information and a list of values, see [ADS_PROPERTY_OPERATION_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_property_operation_enum).

### `bstrName` [in]

Contains a **BSTR** that specifies the property name.

### `vProp` [in]

Contains a **VARIANT** array that contains the new value or values of the property. A single-valued property is represented as an array with a single element. If *InControlCode* is set to **ADS_PROPERTY_CLEAR**, the value of the property specified by *vProp* is irrelevant.

## Return value

This method supports standard return values, as well as the following.

For more information, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

**PutEx** is usually used to set values on multi-value attributes. Unlike the [IADs::Put](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-put) method, with **PutEx**, you are not required to get the attribute values before you modify them. However, because **PutEx** only makes changes to attributes values contained in the ADSI property cache, you must use [IADs::SetInfo](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-setinfo) after each **PutEx** call in order to commit changes to the directory.

**PutEx** enables you to append values to an existing set of values in a multi-value attribute using **ADS_PROPERTY_APPEND**. When you update, append, or delete values to a multi-value attribute, you must use an array.

Active Directory does not accept duplicate values on a multi-valued attribute. If you call **PutEx** to append a duplicate value to a multi-valued attribute of an Active Directory object, the **PutEx** call succeeds, but the duplicate value is ignored.

Similarly, if you use **PutEx** to delete one or more values from a multi-valued property of an Active Directory object, the operation succeeds, that is, it will not produce an error, even if any or all of the specified values are not set on the property.

**Note** The WinNT provider ignores the value passed by the *InControlCode* argument and performs the equivalent of an **ADS_PROPERTY_UPDATE** request when using **PutEx**.

#### Examples

The following code example shows how to use the **IADs.PutEx** method.

```vb
Dim x As IADs

On Error GoTo Cleanup

Set x = GetObject("LDAP://CN=JeffSmith,CN=Users,DC=Fabrikam,DC=com")
'----------------------------------------------------------
' Assume the otherHomePhone has the values
' 425-707-9790, 425-707-9791
'----------------------------------------------------------

' Adding a value
x.PutEx ADS_PROPERTY_APPEND, "otherhomePhone", Array("425-707-9792")
x.SetInfo              ' Now the values are 425-707-9790,425-707-9791,425-707-9792.
deleting two values
x.PutEx ADS_PROPERTY_DELETE, "otherHomePhone", Array("425-707-9790", "425-707-9791")
x.SetInfo              ' Now the values are 425-707-9792.

' Changing the remaining value
x.PutEx ADS_PROPERTY_UPDATE, "otherHomePhone", Array("425-707-9793", "425-707-9794")
x.SetInfo              ' Now the values are 425-707-9793,425-707-9794.

' Deleting the value
x.PutEx ADS_PROPERTY_CLEAR, "otherHomePhone",  vbNullString
x.SetInfo              ' Now the property has no value.

Cleanup:
    If(Err.Number<>0) Then
        MsgBox("An error has occurred. " & Err.Number)
    End If
    Set x = Nothing

```

The following code example shows how to use the **IADs::PutEx** method.

```cpp
HRESULT hr;
IADs *pADs=NULL;
LPWSTR pszADsPath = L"LDAP://CN=JeffSmith,CN=Users,DC=Fabrikam,DC=com";

CoInitialize(NULL);

hr = ADsGetObject(pszADsPath, IID_IADs, (void**) &pADs);

if(SUCCEEDED(hr))
{
    VARIANT var;
    VariantInit(&var);

    LPWSTR pszPhones[] = { L"425-707-9790", L"425-707-9791" };
    DWORD dwNumber = sizeof(pszPhones)/sizeof(LPWSTR);
    hr = ADsBuildVarArrayStr(pszPhones, dwNumber, &var);
    hr = pADs->Put(CComBSTR("otherHomePhone"), var);
    VariantClear(&var);
    hr = pADs->SetInfo();   // The phone list is now 425-707-9790, 425-707-9791.

    // Append another number to the list.
    LPWSTR pszAddPhones[]={L"425-707-9792"};
    hr = ADsBuildVarArrayStr(pszAddPhones, 1, &var);
    hr = pADs->PutEx(ADS_PROPERTY_APPEND, CComBSTR("otherHomePhone"), var);
    hr = pADs->SetInfo();   // The list becomes
                            // 425-707-9790, 425-707-9791, 425-707-9792.
    VariantClear(&var);

    hr = ADsBuildVarArrayStr(pszPhones, dwNumber, &var);
    hr = pADs->PutEx(ADS_PROPERTY_DELETE, CComBSTR("otherHomePhone"), var);
    hr = pADs->SetInfo();  // The list becomes 425-707-9792.

    pszPhones[0] = L"425-707-9793";
    pszPhones[1] = L"425-707-9794";
    hr = ADsBuildVarArrayStr(pszPhones, dwNumber, &var);
    hr = pADs->PutEx(ADS_PROPERTY_UPDATE, CComBSTR("otherHomePhone"), var);
    hr = pADs->SetInfo();  // The list becomes 425-707-9793, 425-707-9794.

    VariantClear(&var);
    V_VT(&var)=VT_NULL;
    hr = pADs->PutEx(ADS_PROPERTY_CLEAR, CComBSTR("otherHomePhone"), var);
    hr = pADs->SetInfo();  // The list is empty.

    VariantClear(&var);
    pADs->Release();
}

hr = CoUninitialize();
```

## See also

[IADs](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iads)

[IADs::Get](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-get)

[IADs::GetEx](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-getex)

[IADs::Put](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-put)

[Property
Cache](https://learn.microsoft.com/windows/desktop/ADSI/property-cache-interfaces)