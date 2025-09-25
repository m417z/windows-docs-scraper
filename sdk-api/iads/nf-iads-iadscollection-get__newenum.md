# IADsCollection::get__NewEnum

## Description

The **IADsCollection::get__NewEnum** method gets a dependent enumerator object that implements [IEnumVARIANT](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ienumvariant) for this ADSI collection object. Be aware that there are two underscore characters in the function name (**get__NewEnum**).

## Parameters

### `ppEnumerator` [out]

Pointer to a pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface on the enumerator object for this collection.

## Return value

This method supports the standard return values including **S_OK**, **E_FAIL**, or **E_NOTIMPL**. For more information and other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

When a server supports paged search and the client has specified the page limit greater than the maximum search results allowed on the server, the **IADsCollection::get__NewEnum** method returns errors in the following ways:

* If the server returns an error with no results, the function returns the error only.
* If the server returns partial results with or without an error, for example, the maximum search results allowed on the server, the function returns the partial results from the server to the user.
* If the server returns all results with or without an error, for example, maximum search results on each page and all results through multiple pages, the function returns all the results from the server to the user.

#### Examples

The **For Each**…**In**…**Next** statement in the following Visual Basic code example invokes **get__NewEnum** method implicitly.

```vb
Dim fso As IADsFileServiceOperations
On Error GoTo Cleanup

Set fso = GetObject("WinNT://myComputer/Fabrikam01")

Dim coll As IADsCollection
Set coll = fso.Sessions

' The following statement invokes IADsCollection::get__NewEnum.
For Each session In coll
   MsgBox "Session name: " & session.Name
Next session

Cleanup:
    If (Err.Number<>0) Then
        MsgBox("An error has occurred... " & Err.Number)
    End If
    Set fso = Nothing
```

The following C++ code example shows how **IADsCollection::get__NewEnum** is used to enumerate active file service sessions.

```cpp
HRESULT EnumCollection(IADsCollection *);

HRESULT GetACollectionOfSessions()
{
    LPWSTR adspath = L"WinNT://myComputer/LanmanServer";
    HRESULT hr = S_OK;
    IADsCollection *pColl = NULL;

    // Bind to file service operations.
    IADsFileServiceOperations *pFso = NULL;
    hr = ADsGetObject(adspath,
                      IID_IADsFileServiceOperations,
                      (void**)&pFso);
    if(FAILED(hr)) {goto Cleanup;}

    // Get the pointer to the collection.
    hr = pFso->Sessions(&pColl);
    if(FAILED(hr)) {goto Cleanup;}

    hr = EnumCollection(pColl);

Cleanup:
    if(pColl) pColl->Release();
    if(pFso) pFso->Release();

    return hr;
}

HRESULT EnumCollection(IADsCollection *pColl)
{
    IUnknown *pUnk=NULL;
    HRESULT hr = S_OK;
    // Get the Enumerator object on the collection object.
    hr = pColl->get__NewEnum(&pUnk);
    if(FAILED(hr)) {goto Cleanup;}

    IEnumVARIANT *pEnum;
    hr = pUnk->QueryInterface(IID_IEnumVARIANT,(void**)&pEnum);
    if(FAILED(hr)) {goto Cleanup;}

    // Enumerate the collection.
    BSTR bstr = NULL;
    VARIANT var;
    IADs *pADs = NULL;
    ULONG lFetch;
    IDispatch *pDisp = NULL;

    VariantInit(&var);
    hr = pEnum->Next(1, &var, &lFetch);
    while(hr == S_OK)
    {
        if (lFetch == 1)
        {
             pDisp = V_DISPATCH(&var);
             pDisp->QueryInterface(IID_IADs, (void**)&pADs);
             pADs->get_Name(&bstr);
             printf("Session name: %S\n",bstr);
             SysFreeString(bstr);
             pADs->Release();
        }
        VariantClear(&var);
        pDisp->Release();
        pDisp = NULL;
        hr = pEnum->Next(1, &var, &lFetch);
    };

Cleanup:
    if(pDisp) pDisp->Release();
    if(pUnk) pUnk->Release();
    if(pColl) pColl->Release();
    if(pEnum) pEnum->Release();
    return hr;
}
```

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[IADsCollection](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadscollection)

[IEnumVARIANT](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ienumvariant)

[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)