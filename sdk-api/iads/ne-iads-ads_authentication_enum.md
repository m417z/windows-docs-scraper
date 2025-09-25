# ADS_AUTHENTICATION_ENUM enumeration

## Description

The **ADS_AUTHENTICATION_ENUM** enumeration
specifies authentication options used in ADSI for binding to directory service objects. When
calling [IADsOpenDSObject](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsopendsobject) or
[ADsOpenObject](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsopenobject) to bind to an ADSI object, provide at least
one of the options. In general, different providers will have different implementations. The options documented
here apply to the providers supplied by Microsoft included with the ADSI SDK. For more information, see
[ADSI System Providers](https://learn.microsoft.com/windows/desktop/ADSI/adsi-system-providers).

## Constants

### `ADS_SECURE_AUTHENTICATION:0x1`

Requests secure authentication. When this flag is set, the WinNT provider uses NT LAN Manager (NTLM) to
authenticate the client. Active Directory will use Kerberos, and possibly NTLM, to authenticate the client. When
the user name and password are **NULL**, ADSI binds to the object using the security
context of the calling thread, which is either the security context of the user account under which the
application is running or of the client user account that the calling thread represents.

### `ADS_USE_ENCRYPTION:0x2`

Requires ADSI to use encryption for data exchange over the network.

**Note** This option is not supported by the WinNT provider.

### `ADS_USE_SSL:0x2`

The channel is encrypted using Secure Sockets Layer (SSL). Active Directory requires that the Certificate
Server be installed to support SSL.

If this flag is not combined with the **ADS_SECURE_AUTHENTICATION** flag and the
supplied credentials are **NULL**, the bind will be performed anonymously. If this flag
is combined with the **ADS_SECURE_AUTHENTICATION** flag and the supplied credentials are
**NULL**, then the credentials of the calling thread are used.

**Note** This option is not supported by the WinNT provider.

### `ADS_READONLY_SERVER:0x4`

A writable domain controller is not required. If your application only reads or queries data from Active
Directory, you should use this flag to open the sessions. This allows the application to take advantage of
Read-Only DCs (RODCs).

In Windows Server 2008, ADSI attempts to connect to either Read-Only DCs (RODCs) or writable DCs. This
allows the use of an RODC for the access and enables the application to run in a branch or perimeter network
(also known as DMZ, demilitarized zone, and screened subnet), without the need for direct connectivity with a
writable DC.

For more information about programming for RODC compatibility, see the
[Read-Only Domain Controllers Application Compatibility Guide](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2008-R2-and-2008/cc755190(v=ws.10)).

### `ADS_PROMPT_CREDENTIALS:0x8`

This flag is not supported.

### `ADS_NO_AUTHENTICATION:0x10`

Request no authentication. The providers may attempt to bind the client, as an anonymous user, to the
target object. The WinNT provider does not support this flag. Active Directory establishes a connection between
the client and the targeted object, but will not perform authentication. Setting this flag amounts to requesting
an anonymous binding, which indicates all users as the security context.

### `ADS_FAST_BIND:0x20`

When this flag is set, ADSI will not attempt to query the **objectClass**
property and thus will only expose the base interfaces supported by all ADSI objects instead of the full object
support. A user can use this option to increase the performance in a series of object manipulations that involve
only methods of the base interfaces. However, ADSI will not verify that any of the requested objects actually
exist on the server. For more information, see
[Fast Binding Options for Batch Write/Modify Operations](https://learn.microsoft.com/windows/desktop/ADSI/fast-binding-option-for-batch-writemodify-operations).

This option is also useful for binding to non-Active Directory directory services, for example Exchange 5.5,
where the **objectClass** query would fail.

### `ADS_USE_SIGNING:0x40`

Verifies data integrity. The **ADS_SECURE_AUTHENTICATION** flag must also be set also
to use signing.

**Note** This option is not supported by the WinNT provider.

### `ADS_USE_SEALING:0x80`

Encrypts data using Kerberos. The **ADS_SECURE_AUTHENTICATION** flag must also be set
to use sealing.

**Note** This option is not supported by the WinNT provider.

### `ADS_USE_DELEGATION:0x100`

Enables ADSI to delegate the user security context, which is necessary for moving objects across domains.

### `ADS_SERVER_BIND:0x200`

If an Active Directory DNS server name is passed in the LDAP path, this forces an A-record lookup and
bypasses any SRV record lookup when resolving the host name.

**Note** This option is not supported by the WinNT provider.

### `ADS_NO_REFERRAL_CHASING:0x400`

Specify this flag to turn referral chasing off for the life of the connection. However, even when this flag
is specified, ADSI still allows the setting of referral chasing behavior for container enumeration when set
using **ADS_OPTION_REFERRALS** in
[ADS_OPTION_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_option_enum) (as documented in container enumeration
with referral chasing in
[IADsObjectOptions::SetOption](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsobjectoptions-setoption)) and
searching separately (as documented in
[Referral Chasing with IDirectorySearch](https://learn.microsoft.com/windows/desktop/ADSI/referral-chasing-with-idirectorysearch)).

**Note** This option is not supported by the WinNT provider.

### `ADS_AUTH_RESERVED:0x80000000`

Reserved.

## Remarks

The **ADS_SECURE_AUTHENTICATION** flag can be used in combination with other flags such
as **ADS_READONLY_SERVER**, **ADS_PROMPT_CREDENTIALS**,
**ADS_FAST_BIND**, and so on.

Serverless binding refers to a process in which a client attempts to bind to an Active Directory object
without explicitly specifying an Active Directory server in the binding string. This is possible because the LDAP
provider relies on the locator services of Windows to find the best domain controller (DC) for the client.
However, the client must have an account on the Active Directory domain controller to take advantage of the
serverless binding feature, and the DC used by a serverless bind will always be located in the default domain;
that is, the domain associated with the current security context of the thread that performs the binding.

Because VBScript cannot read data from a type library, VBScript applications do not recognize the symbolic
constants as defined above. Use the numerical constants instead to set the appropriate flags in your VBScript
applications. To use the symbolic constants as a good programming practice, write explicit declarations of such
constants, as done here, in your Visual Basic Scripting edition application.

#### Examples

The following code example shows how to use
[IADsOpenDSObject](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsopendsobject) to open an object on fabrikam with
secure authentication for the WinNT provider.

```vb
Const ADS_SECURE_AUTHENTICATION = 1

Dim dso As IADsOpenDSObject
Dim domain As IADsDomain

Set dso = GetObject("WinNT:")
Set domain = dso.OpenDSObject("WinNT://Fabrikam", vbNullString, vbNullString, ADS_SECURE_AUTHENTICATION)
```

The following code example shows how the **ADS_SECURE_AUTHENTICATION** flag is used
with [ADsOpenObject](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsopenobject) for validating the user bound as
"JeffSmith". The user name can be of the UPN format: "JeffSmith@Fabrikam.com", as well as the distinguished name
format: "CN=JeffSmith,DC=Fabrikam,DC=COM".

```cpp
IADs *pObject = NULL;
HRESULT hr;
hr = ADsOpenObject(_bstr_t("LDAP://CN=JeffSmith, DC=fabrikam, DC=com"),
                   NULL,
                   NULL,
                   ADS_SECURE_AUTHENTICATION,
                   IID_IADs,
                   (void**) &pObject);
if (hr != S_OK)
    {} // Handle open object errors here.
else
    {} // Object was retrieved, continue processing here.
```

## See also

[ADSI Enumerations](https://learn.microsoft.com/windows/desktop/ADSI/adsi-enumerations)

[ADSI System Providers](https://learn.microsoft.com/windows/desktop/ADSI/adsi-system-providers)

[ADsOpenObject](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsopenobject)

[IADsAccessControlEntry](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsaccesscontrolentry)

[IADsOpenDSObject](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsopendsobject)