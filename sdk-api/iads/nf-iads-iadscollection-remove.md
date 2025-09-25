# IADsCollection::Remove

## Description

The **IADsCollection::Remove** method removes the named item from this ADSI collection object.

## Parameters

### `bstrItemToBeRemoved` [in]

The null-terminated Unicode string that specifies the name of the item as it was specified by [IADsCollection::Add](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadscollection-add).

## Return value

This method supports the standard return values, including **S_OK**. For more information and other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

Collections for a directory service can also consist of a set of immutable objects.

Collections that do not support direct removal of items are required to return **E_NOTIMPL**.

#### Examples

The following Visual Basic code example shows how to remove a named session object from a collection of active file service sessions.

```vb
Dim fso As IADsFileServiceOperations
Dim ses As IADsSession
Dim coll As IADsCollection
Dim mySessionName As String

On Error GoTo Cleanup

Set fso = GetObject("WinNT://myComputer/FabrikamServer")
Set coll = fso.Sessions

' Insert code to set mySessionName to the name of the mySession
' session object.

' The following statement invokes IADsCollection::Remove.
coll.Remove mySessionName

Cleanup:
    If (Err.Number<>0) Then
        MsgBox("An error has occurred. " & Err.Number)
    End If
    Set fso = Nothing
    Set ses = Nothing
    Set coll = Nothing

```

The following C++ code example shows how to remove a named session object from a collection of active file service sessions.

```cpp
HRESULT RemoveASessionObjectFromCollection()
{
    LPWSTR adspath = L"WinNT://myComputer/FabrikamServer";
    HRESULT hr = S_OK;
    IADsCollection *pColl = NULL;
    IADsFileServiceOperations *pFso = NULL;

    hr = ADsGetObject(adspath,IID_IADsFileServiceOperations,(void**)&pFso);
    if(FAILED(hr)) {goto Cleanup;}

    hr = pFso->Sessions(&pColl);
    if(FAILED(hr)) {goto Cleanup;}

    hr = pColl->Remove(CComBSTR("MySession"));

Cleanup
    if(pFso) pFso->Release();
    if(pColl) pColl->Release();

    return hr;
}
```

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[IADsCollection](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadscollection)

[IADsCollection::Add](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadscollection-add)