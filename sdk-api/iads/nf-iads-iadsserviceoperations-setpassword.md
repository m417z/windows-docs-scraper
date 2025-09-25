# IADsServiceOperations::SetPassword

## Description

The **IADsServiceOperations::SetPassword** method sets the password for the account used by the service manager. This method is called when the security context for this service is created.

## Parameters

### `bstrNewPassword` [in]

The null-terminated Unicode string to be stored as the new password.

## Return value

This method supports the standard return values, including S_OK. For more information about other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

The property [IADsService::get_ServiceAccountName](https://learn.microsoft.com/windows/desktop/ADSI/iadsservice-property-methods) identifies the account for which this password is to be set.

#### Examples

The following code example shows how to set a password for the Microsoft Fax Service running on Windows 2000.

```vb
Dim cp As IADsComputer
Dim so As IADsServiceOperations
Dim s As IADsService
Dim sPass As String

On Error GoTo Cleanup

Set cp = GetObject("WinNT://myMachine,computer")
Set so = cp.GetObject("Service", "Fax")
' Insert code to securely retrieve a new password from the user.
so.SetPassword sPass

Set s = so
MsgBox "The password for " & so.name & " has been changed on "_
        & s.ServiceAccountName

Cleanup:
    If (Err.Number<>0) Then
        MsgBox("An error has occurred. " & Err.Number)
    End If
    Set cp = Nothing
    Set so = Nothing
    Set s = Nothing

```

The following code example shows how to set a password for the Microsoft Fax Service running on Windows 2000.

```cpp
HRESULT SetServicePassword(LPCWSTR pwszADsPath, LPCWSTR, pwszPasword)
{
    IADsContainer *pCont = NULL;
    IADsServiceOperations *pSrvOp = NULL;
    IDispatch *pDisp = NULL;
    HRESULT hr = S_OK;

    hr = ADsGetObject(pwszADsPath, IID_IADsContainer, (void**)&pCont);
    if(FAILED(hr))
    {
        goto Cleanup;
    }

    hr = pCont->GetObject(CComBSTR("Service"), CComBSTR("Fax"), &pDisp);
    if(FAILED(hr))
    {
        goto Cleanup;
    }

    hr = pDisp->QueryInterface(IID_IADsServiceOperations, (void**)&pSrvOp);
    if(FAILED(hr))
    {
        goto Cleanup;
    }

    // Insert code to securely retrieve the password from the user.
    hr = pSrvOp->SetPassword(CComBSTR(pwszPassword));

Cleanup:
    if(pDisp)
    {
        pDisp->Release();
    }
    if(pCont)
    {
        pCont->Release();
    }
    if(pSrvOp)
    {
        pSrvOp->Release();
    }
}
```

## See also

[IADsService](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsservice)

[IADsService::get_ServiceAccountName](https://learn.microsoft.com/windows/desktop/ADSI/iadsservice-property-methods)

[IADsServiceOperations](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsserviceoperations)