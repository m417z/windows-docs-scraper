# IADsClass::Qualifiers

## Description

The **IADsClass::Qualifiers** method is an optional method that returns a collection of ADSI objects that describe additional qualifiers for this schema class.

## Parameters

### `ppQualifiers` [out]

Address of an [IADsCollection](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadscollection) pointer variable that receives the interface pointer to the ADSI collection object that represents additional limits for this schema class.

## Return value

This method supports the standard return values, as well as the following.

For more information and other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

The qualifier objects are provider-specific. When supported, this method can be used to obtain extended schema data.

This method is not currently supported by any of Microsoft providers.

#### Examples

The following code example shows how to use this method.

```vb
Dim ads As IADs
Dim cls As IADsClass
On Error GoTo Cleanup

Set ads = GetObject("WinNT://myComputer, computer")
Set cls = GetObject(ads.Schema)

' Show the user where to find additional class data.
ListBox.additem "Additional class information can be found from:"
For Each q In cls.Qualifiers
    listBox.additem q.Name
Next

Cleanup:
    If (Err.Number<>0) Then
        MsgBox("An error has occurred. " & Err.Number)
    End If
    Set ads = Nothing
    Set cls = Nothing

```

## See also

[IADsClass](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsclass)

[IADsProperty::Qualifiers](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsproperty-qualifiers)