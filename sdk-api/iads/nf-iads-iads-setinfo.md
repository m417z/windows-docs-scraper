# IADs::SetInfo

## Description

The **IADs::SetInfo** method saves the cached property values of the ADSI object to the underlying directory store.

## Return value

This method supports the standard return values, including S_OK for a successful operation. For more information, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

It is important to emphasize the differences between the [IADs::Put](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-put) and **IADs::SetInfo** methods. The former sets (or modifies) values of a given property in the property cache whereas the latter propagates the changes from the property cache into the underlying directory store. Therefore, any property value changes made by **IADs::Put** will be lost if [IADs::GetInfo](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-getinfo) (or [IADs::GetInfoEx](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-getinfoex)) is invoked before **IADs::SetInfo** is called.

Because **IADs::SetInfo** sends data across networks, minimize the usage of this method. This reduces the number of trips a client makes to the server. For example, you should commit all, or most, of the changes to the properties from the cache to the persistent store in one batch.

This guideline pertains only to the relationship of **IADs::SetInfo** with the [IADs::Put](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-put) method, which differs from the relationship with the [IADs::PutEx](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-putex) method.

The following code example illustrates the recommended relation between [IADs::Put](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-put) and **IADs::SetInfo**.

```vb
Dim obj as IADs

obj.Put(prop1,val1)
obj.Put(prop2.val2)
obj.Put(prop3.val3)
obj.SetInfo
```

The following code example illustrates what is not recommended between [IADs::Put](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-put) and **IADs::SetInfo**.

```vb
obj.Put(prop1,val1)
obj.SetInfo
obj.Put(prop2.val2)
obj.SetInfo
obj.Put(prop3.val3)
obj.SetInfo
```

When used with [IADs::PutEx](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-putex), **IADs::SetInfo** passes the operational requests specified by control codes, such as ADS_PROPERTY_UPDATE or ADS_PROPERTY_CLEAR, to the underlying directory store.

#### Examples

The following Visual Basic code example uses the **IADs::SetInfo** method to save the property value of a user to the underlying directory.

```vb
Dim x as IADs
On Error GoTo Cleanup

Set x = GetObject("LDAP://CN=Administrator,CN=Users,DC=Fabrikam,DC=com")
'
' Update values in the cache.
'
x.Put "sn", "Smith"
x.Put "givenName", "Jeff"
x.Put "street", "1 Tanka Place"
x.Put "l", "Sammamish"
x.Put "st", "Washington"
'
' Commit changes to the directory.
x.SetInfo

Cleanup:
   If (Err.Number<>0) Then
      MsgBox("An error has occurred. " & Err.Number)
   End If
   Set x = Nothing

```

The following C++ code example updates property values in the property cache and commits the change to the directory store using **IADs::SetInfo**. For brevity, error checking is omitted.

```cpp
IADs *pAds NULL;
VARIANT var;
HRESULT hr = S_OK;
LPWSTR path=L"LDAP://CN=Administrator,CN=Users,DC=Fabrikam,DC=com";
hr = ADsGetObject( path, IID_IADs, (void**) pADs);

if(!(hr==S_OK)) {return hr;}

VariantInit(&var);
// Update values in the cache.
V_BSTR(&var) = SysAllocString(L"Smith");
V_VT(&var) = VT_BSTR;
hr = pADs->Put(CComBSTR("sn"), var );
VariantClear(&var);

V_BSTR(&var) = SysAllocString(L"Jeff");
V_VT(&var) = VT_BSTR;
hr = pADs->Put(CComBSTR("givenName"), var );
VariantClear(&var);

V_BSTR(&var) = SysAllocString(L"1 Tanka Place");
V_VT(&var) = VT_BSTR;
hr = pADs->Put(CComBSTR("street"), var );
VariantClear(&var);

V_BSTR(&var) = SysAllocString(L"Sammamish");
V_VT(&var) = VT_BSTR;
hr = pADs->Put(CComBSTR("l"), var );
VariantClear(&var);

V_BSTR(&var) = SysAllocString(L"Washington");
V_VT(&var) = VT_BSTR;
hr = pADs->Put(CComBSTR("st"), var );
VariantClear(&var);

// Commit changes to the directory store.
hr = pADs->SetInfo();

if(pADs)
   pADs->Release();
```

## See also

[IADs](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iads)

[IADs::GetInfo](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-getinfo)

[IADs::GetInfoEx](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-getinfoex)

[IADs::Put](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-put)

[IADs::PutEx](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-putex)