# IADsCollection::GetObject

## Description

The **IADsCollection::GetObject** method retrieves an item of the collection.

## Parameters

### `bstrName` [in]

The null-terminated Unicode string that specifies the name of the item. This is the same name passed to [IADsCollection::Add](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadscollection-add) when the item is added to the collection.

### `pvItem` [in]

Current value of the item. For an object, this corresponds to the [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface pointer on the object.

## Return value

This method supports the standard return values, including S_OK. For more information and other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

If you know the name of a session in the **Sessions** collection, call the **IADsCollection::GetObject** method explicitly to retrieve the session object.

#### Examples

The following Visual Basic code example shows how to retrieve a named session object from a collection of active file service sessions.

```vb
Dim fso As IADsFileServiceOperations
Dim ses As IADsSession
Dim coll As IADsCollection
Dim mySessionName As String

Set fso = GetObject("WinNT://myComputer/FabrikamServer")
Set coll = fso.Sessions

' Insert code to set mySessionName to the name of mySession.

' The following statement invokes IADsCollection::GetObject.
Set ses = coll.GetObject(mySessionName)
```

The following C++ code example shows how to retrieve a named session object from a collection of active file service sessions.

```cpp
HRESULT GetASessionObjectFromCollection(BSTR mySession)
{
    LPWSTR adspath = L"WinNT://myComputer/FabrikamServer";
    IUnknown *pUnk=NULL;
    HRESULT hr = S_OK;
    IADsCollection *pColl = NULL;
    IADsFileServiceOperations *pFso = NULL;
    IADs *pADsObj = NULL;
    VARIANT varObj;
    BSTR bstrObj = NULL;

    VariantInit(&varObj);
    hr = ADsGetObject(adspath,
                      IID_IADsFileServiceOperations,
                      (void**)&pFso);
    if(FAILED(hr)) {goto Cleanup;}

    hr = pFso->Sessions(&pColl);
    if(FAILED(hr)) {goto Cleanup;}

    hr = pColl->GetObject(mySession, &varObj);
    V_DISPATCH(&varObj)->QueryInterface(IID_IADs,(void**)&pADsObj);
    hr = pADsObj->get_Class(&bstrObj);
    printf("Class of the object obtained from GetObject: %S\n",
             bstrObj);

Cleanup:
    if(bstrObj) SysFreeString(bstrObj);
    if(pFso) pFso->Release();
    VariantClear(&varObj);
    if(pADsObj) pADsObj->Release();
    if(pColl) pColl->Release();

    return hr;
}
```

## See also

[ADSI Error
Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[IADsCollection](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadscollection)

[IADsCollection::Add](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadscollection-add)

[IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch)

[IEnumVARIANT](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ienumvariant)