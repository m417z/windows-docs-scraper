# IADsTSUserEx::put_TerminalServicesProfilePath

## Description

The roaming or mandatory profile path to be used when the user logs on to the Remote Desktop Session Host (RD Session Host) server.

This property is read/write.

## Parameters

## Remarks

The profile path is
in the following network path format:

**\\\\***ServerName***\\***ProfilesFolderName***\\***UserName*

**Note** A Remote Desktop Services profile path is used only for logging on to an RD Session Host server.

#### Examples

The following example shows a program that binds to the Active Directory database without credentials.

```cpp
 IADsContainer *pContainer = NULL;
 IDispatch *pNewObject = NULL;
 IADsTSUserEx *pTSUser = NULL;
 IADsUser *pUser = NULL;
 HRESULT hr = ERROR_SUCCESS;

 CoInitialize(NULL);
 //
 // Bind to the known container.
 //
 hr = ADsGetObject(
    L"LDAP://DOMAIN/CN=Users,DC=Server1,DC=Domain,DC=com",
    IID_IADsContainer,
    (void**)&pContainer);

 if( !SUCCEEDED(hr)) {
  wprintf(L"ADsGetObject ret failed with 0x%x\n", hr);
  return FALSE;
 }
 //
 // Create the new Active Directory Service Interfaces User object.
 //
 hr = pContainer->Create(L"user",
                         L"cn=test3",
                         &pNewObject);
 pContainer->Release();

 if( !SUCCEEDED(hr)) {
  wprintf(L"Create ret failed with 0x%x\n", hr);
  return FALSE;
 }
 //
 // Get the IADsTSUser interface from the user object.
 //
 hr = pNewObject->QueryInterface(IID_IADsTSUserEx, (void**)&pTSUser);

 if( !SUCCEEDED(hr)) {
  wprintf(L"QueryInterface for IADsTSUserEx failed with ret 0x%x\n",
          hr);
  return FALSE;
 }
 //
 // Get the IADsTSUser interface from the user object.
 //
 hr = pNewObject->QueryInterface(IID_IADsUser, (void**)&pUser);

 if( !SUCCEEDED(hr)) {
  wprintf(L"QueryInterface for IAsUser failed with 0x%x\n", hr);
  return FALSE;
 }
 pNewObject->Release();

 //
 // Set TerminalServicesProfilePath
 //
 pTSUser->put_TerminalServicesProfilePath(L"c:\\windows");
 pTSUser->Release();

 //
 // Commit the object data to the directory.
 //
 pUser->SetInfo();
 pUser->Release();
 CoUninitialize();

```

You can use the following script examples to bind to a provider's namespace. Two examples bind with supplied
credentials; two bind without credentials.

The first example shows a script that binds to the Security Accounts Manager (SAM) database with the
supplied credentials.

The second example shows a script that binds to the Active Directory database with the supplied
credentials.

```vb
Set DSO = GetObject("WinNT:")
Set usr = DSO.OpenDSObject(
    "WinNT://Server1/Test,user",
    Domain\User,
    Password,
    ADS_SECURE_AUTHENTICATION)
Wscript.echo usr.TerminalServicesProfilePath
usr.TerminalServicesProfilePath = "profile path"
usr.SetInfo
WScript.echo usr.TerminalServicesProfilePath

```

```vb
Set DSO = GetObject("LDAP:")
Set usr = DSO.OpenDSObject(
    "LDAP://DOMAIN/CN=Test,CN=Users,DC=Server1,DC=Domain,DC=com",
    Domain\User,
    Password,
    ADS_SECURE_AUTHENTICATION)
Wscript.echo usr.TerminalServicesProfilePath
usr.TerminalServicesProfilePath = "profile path"
usr.SetInfo
WScript.echo usr.TerminalServicesProfilePath

```

## See also

[IADsTSUserEx](https://learn.microsoft.com/windows/desktop/api/tsuserex/nn-tsuserex-iadstsuserex)