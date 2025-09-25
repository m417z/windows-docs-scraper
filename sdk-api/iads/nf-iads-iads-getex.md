# IADs::GetEx

## Description

The **IADs::GetEx** method retrieves, from the property cache, property values of a given attribute. The returned property values can be single-valued or multi-valued. Unlike the [IADs::Get](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-get) method, the property values are returned as a variant array of **VARIANT**, or a variant array of bytes for binary data. A single-valued property is then represented as an array of a single element.

## Parameters

### `bstrName` [in]

Contains a **BSTR** that specifies the property name.

### `pvProp` [out]

Pointer to a **VARIANT** that receives the value, or values, of the property.

## Return value

This method supports the standard return values as well as the return values listed in the following list.

For more information, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

The [IADs::Get](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-get) and **IADs::GetEx** methods return a different variant structure for a single-valued property value. If the property is a string, **IADs::Get** returns a variant of string (VT_BSTR), whereas **IADs::GetEx** returns a variant array of a **VARIANT** type string with a single element. Thus, if you are not sure that a multi-valued attribute will return a single value or multiple values, use **IADs::GetEx**. As it does not require you to validate the result's data structures, you may want to use **IADs::GetEx** to retrieve a property when you are not sure whether it has single or multiple values. The following list compares the two methods.

| IADs::Get version | IADs::GetEx version |
| --- | --- |
| ```vb Dim x as IADs<br><br>otherNumbers = x.Get("otherHomePhone") If VarType(otherNumbers) = vbString Then Debug.Print otherNumbers Else For Each homeNum In otherNumbers Debug.Print homeNum Next End If ``` | ```cpp Dim x as IADs<br><br>otherNumbers = x.GetEx("otherHomePhone") For Each homeNum In otherNumbers Debug.Print homeNum Next ``` |

Like the [IADs::Get](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-get) method, **IADs::GetEx** implicitly calls [IADs::GetInfo](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-getinfo) against an uninitialized property cache. For more information about implicit and explicit calls to **IADs::GetInfo**, see **IADs::GetInfo**.

#### Examples

The following code example shows how to use **IADs::GetEx** to retrieve object properties.

```vb
Dim x As IADs
On Error GoTo ErrTest:

Set x = GetObject("LDAP://CN=Administrator,CN=Users,DC=Fabrikam,DC=com")

' Single value property.
Debug.Print "Home Phone Number is: "
phoneNumber = x.GetEx(""homePhone")
For Each homeNum in phoneNumber
    Debug.Print homeNum
Next

' Multiple value property.
Debug.Print "Other Phone Numbers are: "
otherNumbers = x.GetEx("otherHomePhone")
For Each homeNum In otherNumbers
    Debug.Print homeNum
Next
Exit Sub

ErrTest:
    Debug.Print Hex(Err.Number)
    Set x = Nothing

```

The following code example shows how to retrieve values of the optional properties of an object using the [IADs::Get](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-get) method.

```vb
<HTML>
<head><title></title></head>

<body>
<%
Dim x

On Error Resume Next
Set x = GetObject("WinNT://Fabrikam/Administrator")
Response.Write "Object Name: " & x.Name & "<br>"
Response.Write "Object Class: " & x.Class & "<br>"

' Get the optional property values for this object.
Set cls = GetObject(x.Schema)
For Each op In cls.OptionalProperties
   vals = obj.GetEx(op)
   if err.Number = 0 then
       Response.Write "Optional Property: & op & "="
       for each v in vals
          Response.Write v & " "
       next
       Response.Write "<br>"
   end if
Next
%>

</body>
</html>
```

The following code example retrieves the "homePhone" property values using **IADs::GetEx**.

```cpp
IADs *pADs = NULL;

hr = ADsGetObject(L"LDAP://CN=Administrator,CN=Users,DC=Fabrikam,DC=Com", IID_IADs, (void**) &pADs );
if ( !SUCCEEDED(hr) ) { return hr;}

hr = pADs->GetEx(CComBSTR("homePhone"), &var);
if ( SUCCEEDED(hr) )
{
    LONG lstart, lend;
    SAFEARRAY *sa = V_ARRAY( &var );
    VARIANT varItem;

    // Get the lower and upper bound.
    hr = SafeArrayGetLBound( sa, 1, &lstart );
    hr = SafeArrayGetUBound( sa, 1, &lend );

    // Iterate and print the content.
    VariantInit(&varItem);
    printf("Getting Home Phone using IADs::Get.\n");
    for ( long idx=lstart; idx <= lend; idx++ )
    {
        hr = SafeArrayGetElement( sa, &idx, &varItem );
        printf("%S ", V_BSTR(&varItem));
        VariantClear(&varItem);
    }
    printf("\n");

    VariantClear(&var);
}

// Cleanup.
if ( pADs )
{
    pADs->Release();
}
```

## See also

[IADs](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iads)

[IADs::Get](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-get)

[IADs::GetInfo](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-getinfo)

[IADs::Put](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-put)

[IADs::PutEx](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-putex)

[Property Cache Interfaces](https://learn.microsoft.com/windows/desktop/ADSI/property-cache-interfaces)