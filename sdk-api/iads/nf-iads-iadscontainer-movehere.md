# IADsContainer::MoveHere

## Description

The **IADsContainer::MoveHere** method moves a specified object to the container that implements this interface.The method can be used to rename an object.

## Parameters

### `SourceName` [in]

The null-terminated Unicode string that specifies the **ADsPath** of the object to be moved.

### `NewName` [in]

The null-terminated Unicode string that specifies the relative name of the new object within the container. This can be
**NULL**, in which case the object is moved. If it is not **NULL**, the object is
renamed accordingly in the process.

### `ppObject` [out]

Pointer to a pointer to the
[IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface on the moved
object.

## Return value

This method supports standard return values, including
**S_OK**, for a successful operation. For more information about error codes, see
[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

In Active Directory, you can move an object within the same domain
or from different domains in the same directory forest. For the cross domain
move, the following restrictions apply:

* The destination domain must be in the native mode.
* Objects to be moved must be a leaf object or an empty
  container.
* NT LAN Manager (NTLM) cannot perform authentication; use Kerberos authentication or delegation. Be aware that if Kerberos authentication is not used, the password transmits in plaintext over the network. To avoid this, use delegation with secure authentication.
* You cannot move security principals (for example, user, group, computer, and
  so on) belonging to a global group. When a security principal is moved, a new
  SID is created for the object at the destination. However, its old SID from the
  source, stored in the **sIDHistory** attribute,
  is preserved, as well as the password of the object.

**Note** Use the Movetree.exe utility to move a subtree among
different domains. To move objects from a source domain to a destination domain
using the Movetree command-line tool, you must connect to the domain controller
holding the source domain's RID master role. If the RID master is unavailable
then objects cannot be moved to other domains. If you attempt to move an object
from one domain to another using the Movetree.exe tool and you specify a source
domain controller that is not the RID master, a nonspecific "Movetree failed"
error message results.

**Note** When using the
[ADsOpenObject](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsopenobject) function to bind to
an ADSI object, you must use the **ADS_USE_DELEGATION** flag of the
[ADS_AUTHENTICATION_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_authentication_enum) in the *dwReserved* parameter of this function
in order to create cross-domain moves with **IADsContainer::MoveHere**. The
**ADsOpenObject** function is equivalent to the
[IADsOpenDSObject::OpenDsObject](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsopendsobject-opendsobject) method. Likewise, using the **OpenDsObject** method to bind to an ADSI object, the *InReserved* parameter of this method must contain the
**ADS_USE_DELEGATION** flag of the
**ADS_AUTHENTICATION_ENUM** in order to make cross-domain moves with
**IADsContainer::MoveHere**.

The following code example moves the user, "jeffsmith" from the
"South.Fabrikam.Com" domain to the "North.Fabrikam.Com" domain. First, it gets
an [IADsContainer](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadscontainer) pointer to the destination
container, then the **MoveHere** call specifies
the path of the object to move.

```vb
Set ou = GetObject("LDAP://server1/OU=Support,DC=North,DC=Fabrikam,DC=COM")
ou.MoveHere("LDAP://server2/CN=jeffsmith,OU=Sales,DC=South,DC=Fabrikam,DC=Com", vbNullString)
```

A serverless ADsPath can be used for either the source or the
destination or both.

The **IADsContainer::MoveHere** method can be used either to rename an object within the same container or to
move an object among different containers. Moving an object retains the
object RDN, whereas renaming an object alters the RDN.

For example, the following code example performs the rename action.

```vb
set cont = GetObject("LDAP://dc=dom,dc=com")
set newobj = cont.MoveHere("LDAP://cn=Jeff Smith,dc=dom,dc=com", "cn=Denise Smith")
```

The following code example performs the move.

```vb
set cont = GetObject("LDAP://dc=dom,dc=com")
set newobj = cont.MoveHere("LDAP://cn=jeffsmith,ou=sales,dc=dom,dc=com", "cn=jeffsmith")
```

In Visual Basic applications, you can pass
**vbNullString** as the second parameter when
moving an object from one container to another.

```vb
Set newobj =  cont.MoveHere("LDAP://cn=jeffsmith,ou=sale,dc=dom,dc=com", vbNullString)
```

However, you cannot do the same with VBScript. This is because
VBScript maps **vbNullString** to an empty string instead of to a null string, as
does Visual Basic. You must use the RDN explicitly, as shown in the previous
example.

**Note** The WinNT provider supports **IADsContainer::MoveHere**, but only for renaming users &
groups within a domain.

#### Examples

The following code example shows how to use this method to rename
an object.

```vb
Dim cont As IADsContainer
Dim usr As IADsUser

On Error GoTo Cleanup
' Rename an object.
Set cont = GetObject("LDAP://OU=Sales, DC=Fabrikam,DC=com")
Set usr = cont.MoveHere("LDAP://CN=jeffsmith,OU=Sales, DC=Fabrikam,DC=com", "CN=jayhenningsen")

' Move an object.
cont.MoveHere("LDAP://CN=denisesmith,OU=Engineer,DC=Fabrikam,DC=com", vbNullString)

Cleanup:
    If (Err.Number<>0) Then
        MsgBox("An error has occurred. " & Err.Number)
    End If
    Set cont = Nothing
    Set usr = Nothing

```

The following code example moves a user object using the
**IADsContainer::MoveHere** method.

```cpp
/////////////////////////////////////////////
// First, bind to the destination container.
////////////////////////////////////////////
HRESULT hr;
IADsContainer *pCont=NULL;
CoInitialize(NULL);
hr = ADsGetObject(
        L"LDAP://OU=MCS,DC=windows2000,DC=mytest,DC=fabrikam,DC=com",
        IID_IADsContainer,
        (void**) &pCont );

if ( !SUCCEEDED(hr) )
{
    goto Cleanup;
}

//////////////////////////////////////////////////
// Second, move the object to the bound container.
//////////////////////////////////////////////////
IDispatch *pDisp=NULL;

hr = pCont->MoveHere(CComBSTR("LDAP://CN=Jeff Smith,OU=DSys,DC=windows2000,DC=mytest,DC=fabrikam,DC=com"), NULL, &pDisp );
pCont->Release();

if (SUCCEEDED(hr) )
{
// You can perform another operation here, such as updating attributes.
pDisp->Release();
}

Cleanup:
    if(pCont)
        pCont->Release();

    if(pDisp)
        pDisp->Release();

    CoUninitialize();
```

## See also

[ADSI Error
Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[ADS_AUTHENTICATION_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_authentication_enum)

[ADsOpenObject](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsopenobject)

[IADsContainer](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadscontainer)

[IADsContainer::CopyHere](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadscontainer-copyhere)

[IADsOpenDSObject::OpenDsObject](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsopendsobject-opendsobject)

[IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch)