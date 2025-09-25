# IADsFileServiceOperations::Sessions

## Description

The **IADsFileServiceOperations::Sessions** method gets a pointer to a pointer to the [IADsCollection](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadscollection) interface on a collection of the session objects that represent the current open sessions for this file service.

## Parameters

### `ppSessions` [out]

Pointer to a pointer to the [IADsCollection](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadscollection) interface used to enumerate objects that implement the [IADsSession](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadssession) interface and represent the current open sessions for this file service.

## Return value

This method supports the standard return values including S_OK. For more information and other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

Traditional directory services supply data only about directory service elements represented in the underlying data store. Data about sessions for file services may not be available from the underlying store.

#### Examples

The following code example shows how to enumerate active sessions managed by a file service.

```vb
Dim fso As IADsFileServiceOperations
On Error GoTo Cleanup

' Bind to a file service operation on "myComputer"
' in the local domain.
Set fso = GetObject("WinNT://myComputer/LanmanServer")

' Enumerate sessions.
For Each session In fso.sessions
    MsgBox "Session name: " & session.Name
Next session

Cleanup:
    If (Err.Number<>0) Then
        MsgBox("An error has occurred. " & Err.Number)
    End If
    Set fso = Nothing

```

For a code example using the **IADsFileServiceOperations::Sessions** interface, see the code example given in [IADsSession](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadssession).

## See also

[IADsCollection](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadscollection)

[IADsFileService](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsfileservice)

[IADsFileServiceOperations](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsfileserviceoperations)

[IADsSession](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadssession)