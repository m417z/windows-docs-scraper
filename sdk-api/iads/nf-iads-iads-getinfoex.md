# IADs::GetInfoEx

## Description

The **IADs::GetInfoEx** method loads the values of specified properties of the ADSI object from the underlying directory store into the property cache.

## Parameters

### `vProperties` [in]

Array of null-terminated Unicode string entries that list the properties to load into the Active Directory property cache. Each property name must match one in this object's schema class definition.

### `lnReserved` [in]

Reserved for future use. Must be set to zero.

## Return value

This method supports the standard return values, as well as the following.

For more information, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

The **IADs::GetInfoEx** method overwrites any previously cached values of the specified properties with those in the directory store. Therefore, any change made to the cache will be lost if [IADs::SetInfo](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-setinfo) was not invoked before the call to **IADs::GetInfoEx**.

Use **IADs::GetInfoEx** to refresh values of the selected property in the property cache of an ADSI object. Use [IADs::GetInfo](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-getinfo) to refresh all the property values.

For an ADSI container object, **IADs::GetInfoEx** caches only the property values of the container, but not those of the child objects.

#### Examples

The following code example shows how to use the **IADs::GetInfoEx** to obtain values of the selected properties, assuming that the desired property values can be found in the directory.

```vb
Dim x As IADs
On Error GoTo Cleanup

Set x = GetObject("LDAP://CN=JeffSmith,CN=Users,DC=Fabrikam,DC=com")

' Retrieve givenName and sn from the underlying directory storage.
' Cache should have givenName and sn values.
x.GetInfoEx Array("givenName", "sn"), 0
Debug.Print x.Get("givenName")  ' Property is in the cache.
Debug.Print x.Get("sn")         ' Property is in the cache.

' If the "homePhone" property is not in the cache (in the next line),
' GetInfo is called implicitly.
Debug.Print x.Get("homePhone")

Cleanup:
   If(Err.Number<>0) Then
      MsgBox("An error has occurred. " & Err.Number);
   End If

   Set x = Nothing

```

The following code example shows how to use the **IADs::GetInfoEx** to obtain values of the selected properties, assuming that the desired property values can be found in the directory. For brevity, error checking has been omitted.

```cpp
IADs *pADs = NULL;
VARIANT var;
HRESULT hr = S_OK;

hr = ADsGetObject(L"WinNT://somecomputer,computer",
                  IID_IADs,
                  (void**)&pADs);

if(!(hr==S_OK)){return hr;}

VariantInit(&var);

// Get "Owner" and "Division" attribute values.
LPWSTR pszAttrs[] = { L"Owner", L"Division" };
DWORD dwNumber = sizeof( pszAttrs ) /sizeof(LPWSTR);
hr = ADsBuildVarArrayStr( pszAttrs, dwNumber, &var );
hr = pADs->GetInfoEx(var, 0);
VariantClear(&var);

hr = pADs->Get(CComBSTR("Division"), &var);
printf("    division   = %S\n", V_BSTR(&var));
VariantClear(&var);
hr = pADs->Get(CComBSTR("Owner"), &var);
printf("    owner      = %S\n", V_BSTR(&var));
VariantClear(&var);

if(pADs)
   pADs->Release();

```

## See also

[IADs](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iads)

[IADs::GetInfo](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-getinfo)

[IADs::SetInfo](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-setinfo)

[Property
Cache](https://learn.microsoft.com/windows/desktop/ADSI/property-cache-interfaces)