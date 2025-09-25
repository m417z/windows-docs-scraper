# IADs::Get

## Description

The **IADs::Get** method retrieves a property of a given name from the property cache. The property can be single-valued, or multi-valued. The property value is represented as either a variant for a single-valued property or a variant array (of **VARIANT** or bytes) for a property that allows multiple values.

## Parameters

### `bstrName` [in]

Contains a **BSTR** that specifies the property name.

### `pvProp` [out]

Pointer to a **VARIANT** that receives the value of the property. For a multi-valued property, *pvProp* is a variant array of **VARIANT**, unless the property is a binary type. In this latter case, *pvProp* is a variant array of bytes (VT_U1 or VT_ARRAY). For the property that refers to an object, *pvProp* is a VT_DISPATCH pointer to the object referred to.

## Return value

This method supports standard return values, as well as the following.

For more information, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

The **IADs::Get** method requires the caller to handle the single- and multi-valued property values differently. Thus, if you know that the property of interest is either single- or multi-valued, use the **IADs::Get** method to retrieve the property value. The following code example shows how you, as a caller, can handle single- and multi-valued properties when calling this method.

When a property is uninitialized, calling this method invokes an implicit call to the [IADs::GetInfo](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-getinfo) method. This loads from the underlying directory store the values of the supported properties that have not been set in the cache. Any subsequent calls to **IADs::Get** deals with property values in the cache only. For more information about the behavior of implicit and explicit calls to **IADs::GetInfo**, see **IADs::GetInfo**.

You can also use [IADs::GetEx](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-getex) to retrieve property values from the property cache. However, the values are returned as a variant array of **VARIANT**s, regardless of whether they are single-valued or multi-valued. That is, ADSI attempts to package the returned property values in consistent data formats. This saves you, as a caller, the effort of validating the data types when unsure that the returned data has single or multiple values.

#### Examples

The following code example retrieves the security descriptor for an object using **IADs::Get**.

```vb
Dim x As IADs
Dim Desc As IADsSecurityDescriptor
On Error GoTo ErrTest:

Set x = GetObject("LDAP://CN=Administrator,CN=Users,DC=Fabrikam,DC=com")

' Single-valued properties.
Debug.Print "Home Phone Number is: " & x.Get("homePhone")

' Some property values represents other ADSI objects.
' Consult your provider documentation.
Set Desc = x.Get("ntSecurityDescriptor")

' Multi-valued property, assuming that multiple values were
' assigned to the "otherHomePhone" properties. Caller must
' enumerate all the available values.
Debug.Print "Other Phone Numbers are: "
otherNumbers = x.Get("otherHomePhone")
For Each homeNum In otherNumbers
  Debug.Print homeNum
Next

Exit Sub

ErrTest:
  Debug.Print Hex(Err.Number)
  Set x = Nothing
  Set Desc = Nothing
```

The following code example shows how to work with property values of binary data using **IADs::Get** and [IADs::Put](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-put).

```vb
Dim oTarget As IADs
Dim Octet(5) As Byte
Dim MultiOctet(2) As Variant
Dim i As Integer, j As Integer

On Error GoTo Cleanup

' Set up MultiOctetString.
For i = 0 To 2
    For j = 0 To 5
        Octet(j) = CByte(i * j)
    Next j
    MultiOctet(i) = Octet
Next i

' Bind to the object and set MultiOctetString.
Set oTarget=GetObject("LDAP://CN=SomeUser,CN=Users,DC=Fabrikam, DC=COM")
oTarget.Put "multiOctetString", MultiOctet
oTarget.SetInfo

Dim GetOctet As Variant
Dim Temp As Variant

' Read back and print MultiOctetString.
GetOctet = oTarget.Get("multiOctetString")
For i = LBound(GetOctet) To UBound(GetOctet)
    Temp = GetOctet(i)
    For j = LBound(Temp) To UBound(Temp)
        Debug.Print Temp(j)
    Next j
    Debug.Print "----"
Next i

Exit Sub

Cleanup:
   MsgBox("An error has occurred. " & Err.Number)
   Set oTarget = Nothing
```

The following code example shows how to retrieve values of the optional properties of an object using **IADs::Get**.

```vb
<HTML>
<head><title></title></head>

<body>
<%
Dim x

On error resume next
Set x = GetObject("WinNT://Fabrikam/Administrator")
Response.Write "Object Name: " & x.Name & "<br>"
Response.Write "Object Class: " & x.Class & "<br>"

' Get optional property values of this object.
Set cls = GetObject(x.Schema)

For Each op In cls.OptionalProperties
   v = obj.Get(op)
   if err.Number = 0 then
       Response.Write "Optional Property: " & op & "=" & v & "<br>"
   end if
Next
%>

</body>
</html>
```

The following code example reads attributes with single and multiple values using **IADs::Get**.

```cpp
HRESULT hr;
IADs *pUsr=NULL;

CoInitialize(NULL);

///////////////////////////////
// Bind to a directory object.
///////////////////////////////
hr = ADsGetObject(L"WinNT://Fabrikam/Administrator,user", IID_IADs, (void**) &pUsr );
if ( !SUCCEEDED(hr) ) { return hr; }

//////////////////////////////////
// Get a single-valued attribute.
//////////////////////////////////
VARIANT var;
VariantInit(&var);

hr = pUsr->Get(CComBSTR("FullName"), &var );
if ( SUCCEEDED(hr) )
{
    printf("FullName: %S\n", V_BSTR(&var) );
    VariantClear(&var);
}

if ( pUsr )
{
    pUsr->Release();
}

///////////////////////////////////////////////////////
// Get a multi-valued attribute from a service object.
///////////////////////////////////////////////////////
IADs *pSvc = NULL;

hr = ADsGetObject(L"WinNT://Fabrikam/Account/Browser,service", IID_IADs, (void**) &pSvc );
if ( !SUCCEEDED(hr) )
{
    return hr;
}

hr = pSvc->Get(CComBSTR("Dependencies"), &var );
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
    printf("Getting service dependencies using IADs :\n");
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
if ( pSvc )
{
    pSvc->Release();
}
```

## See also

[IADs](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iads)

[IADs::GetEx](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-getex)

[IADs::GetInfo](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-getinfo)

[IADs::Put](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-put)

[IADs::PutEx](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-putex)

[Property
Cache](https://learn.microsoft.com/windows/desktop/ADSI/property-cache-interfaces)