# IADs::Put

## Description

The **IADs::Put** method sets the values of an attribute in the ADSI attribute cache.

## Parameters

### `bstrName` [in]

Contains a **BSTR** that specifies the property name.

### `vProp` [in]

Contains a **VARIANT** that specifies the new values of the property.

## Return value

This method supports the standard return values, as well as the following.

For more information, and other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

The assignment of the new property values, performed by **Put** takes place in the property cache only. To propagate the changes to the directory store, call [IADs::SetInfo](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-setinfo) on the object after calling **Put**.

To manipulate the property values beyond a simple assignment, use **Put** to append or remove a value from an existing array of attribute values.

#### Examples

The following code example shows how to use the **IADs::Put** method.

```vb
Dim x As IADs
On Error GoTo Cleanup

Set x = GetObject("LDAP://CN=JeffSmith,CN=Users,DC=Fabrikam, DC=Com")
x.Put "givenName", "Jeff"
x.Put "sn", "Smith"
x.SetInfo    ' Commit to the directory.

Cleanup:
   If(Err.Number<>0) Then
      MsgBox("An error has occurred. " & Err.Number)
   End If
   Set x = Nothing
```

The following code example shows how to use the **IADs::Put** method.

```cpp
HRESULT hr;
IADs *pADs = NULL;
LPWSTR pszADsPath = L"LDAP://CN=JeffSmith,CN=Users,DC=Fabrikam,DC=com";

CoInitialize(NULL);

//////////////////////////////////
// Modifying attributes using IADs
//////////////////////////////////
hr = ADsGetObject(pszADsPath, IID_IADs, (void**) &pADs);

if(SUCCEEDED(hr))
{
    VARIANT var;
    VariantInit(&var);

    // Set the first name.
    V_BSTR(&var) = SysAllocString(L"Jeff");
    V_VT(&var) = VT_BSTR;
    hr = pADs->Put(CComBSTR("givenName"), var);

    // Set the last name.
    VariantClear(&var);
    V_BSTR(&var) = SysAllocString(L"Smith");
    V_VT(&var) = VT_BSTR;
    hr = pADs->Put(CComBSTR("sn"), var);
    VariantClear(&var);

    // Other Telephones.
    LPWSTR pszPhones[] = { L"425-707-9790", L"425-707-9791" };
    DWORD dwNumber = sizeof(pszPhones)/sizeof(LPWSTR);
    hr = ADsBuildVarArrayStr(pszPhones, dwNumber, &var);
    hr = pADs->Put(CComBSTR("otherTelephone"), var);
    VariantClear(&var);

    // Commit the change to the directory.
    hr = pADs->SetInfo();
    pADs->Release();
}

CoUninitialize();
```

## See also

[IADs](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iads)

[IADs::Get](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-get)

[IADs::GetEx](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-getex)

[IADs::PutEx](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-putex)

[Property
Cache](https://learn.microsoft.com/windows/desktop/ADSI/property-cache-interfaces)