# IADsAccessControlList::get__NewEnum

## Description

The **IADsAccessControlList::get__NewEnum** method is used to obtain an enumerator object for the ACL to enumerate ACEs.

## Parameters

### `retval` [out]

Pointer to pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface used to retrieve
[IEnumVARIANT](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ienumvariant) interface on an enumerator object for the ACL.

## Return value

This method returns the standard return values, including **S_OK** and **E_FAIL**. For more information about other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

Be aware that there are two underscores in **get__NewEnum**.

#### Examples

The following code example makes an implicit call to the **get__NewEnum** method in the execution of the **For Each** loop.

```vb
Dim Dacl As IADsAccessControlList
Dim ace As IADsAccessControlEntry

On Error GoTo Cleanup

' Get DACL. Code omitted.

' Display the trustees for each of the ACEs
For Each ace In Dacl
    Debug.Print ace.trustee
Next ace

Cleanup:
    If (Err.Number<>0) Then
        MsgBox("An error has occurred. " & Err.Number)
    End If
    Set Dacl = Nothing
    Set ace = Nothing

```

The following code example shows how to enumerate ACEs using **IADsAccessControlList::get__NewEnum**.

```cpp
HRESULT ListTrustees(IADsAccessControlList *pACL)
{
    IEnumVARIANT *pEnum = NULL;
    LPUNKNOWN     pUnk = NULL;
    ULONG  lFetch = 0;
    BSTR    bstr = NULL;
    IADsAccessControlEntry *pACE = NULL;
    IDispatch *pDisp = NULL;
    VARIANT var;
    HRESULT hr = S_OK;

    VariantInit(&var);

    hr = pACL->get__NewEnum(&pUnk);
    if (FAILED(hr)){goto Cleanup;}

    hr = pUnk->QueryInterface( IID_IEnumVARIANT, (void**) &pEnum );
    pUnk->Release();
    if (FAILED(hr)){goto Cleanup;}

    hr = pEnum->Next( 1, &var, &lFetch );
    if (FAILED(hr)){goto Cleanup;}

    while( hr == S_OK )
    {
        if ( lFetch == 1 )
        {
            if ( VT_DISPATCH != V_VT(&var) )
            {
                goto Cleanup;
            }
            pDisp = V_DISPATCH(&var);
            /////////////////////////
            // Get the individual ACE
            /////////////////////////
            hr = pDisp->QueryInterface( IID_IADsAccessControlEntry,(void**)&pACE );
            if ( SUCCEEDED(hr) )
            {
                pACE->get_Trustee(&bstr);
                printf("\n %S:\n", bstr);
                //ACE manipulation here
                SysFreeString(bstr);
                pACE->Release();
            }
            pACE->Release();
            pDisp->Release();
            VariantClear(&var);
        }
        hr = pEnum->Next( 1, &var, &lFetch );
    }
    Cleanup:
        if(pEnum) pEnum->Release();
        if(pUnk) pUnk->Release();
        if(bstr) SysFreeString(bstr);
        if(pACE) pACE->Release();
        VariantClear(&var);
        return hr;
}
```

## See also

[IADsAccessControlEntry](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsaccesscontrolentry)

[IADsAccessControlList](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsaccesscontrollist)

[IADsSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadssecuritydescriptor)

[IEnumVARIANT](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ienumvariant)