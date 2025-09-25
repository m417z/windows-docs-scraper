# IADsFileServiceOperations::Resources

## Description

The **IADsFileServiceOperations::Resources** method gets a pointer to a pointer to the [IADsCollection](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadscollection) interface on a collection of the resource objects representing the current open resources on this file service.

## Parameters

### `ppResources` [out]

Pointer to a pointer to the [IADsCollection](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadscollection) interface that can then be used to enumerate objects implementing the [IADsResource](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsresource) interface and representing the current open resources for this file service.

## Return value

This method supports the standard return values including S_OK. For more information and other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

Traditional directory services supply data only about directory service elements represented in the underlying data store. Data about resources for file services may not be available from the underlying directory store.

#### Examples

The following code example shows how to enumerate open resources managed by a file service.

```vb
Dim fso As IADsFileServiceOperations
On Error GoTo Cleanup

' Bind to a file service operation on "myComputer"
' in the local domain.
Set fso = GetObject("WinNT://myComputer/LanmanServer")

' Enumerate resources.
For Each resource In fso.Resources
    MsgBox "Resource path: " & resource.Path
Next resource

Cleanup:
    If (Err.Number<>0) Then
        MsgBox("An error has occurred. " & Err.Number)
    End If
    Set fso = Nothing

```

For a code example using the **IADsFileServiceOperations::Resources** method, see the code example given in [IADsResource](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsresource).

## See also

[IADsFileService](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsfileservice)

[IADsFileServiceOperations](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsfileserviceoperations)

[IADsResource](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsresource)