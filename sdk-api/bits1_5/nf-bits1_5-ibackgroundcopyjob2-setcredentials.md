# IBackgroundCopyJob2::SetCredentials

## Description

Specifies the credentials to use for a proxy or remote server user authentication request.

## Parameters

### `credentials` [in]

Identifies the target (proxy or server), authentication scheme, and the user's credentials to use for user authentication. For details, see the
[BG_AUTH_CREDENTIALS](https://learn.microsoft.com/windows/desktop/api/bits1_5/ns-bits1_5-bg_auth_credentials) structure.

## Return value

This method returns the following return values, as well as others.

| Return code | Description |
| --- | --- |
| **S_OK** | Success |
| **BG_E_INVALID_AUTH_TARGET** | Unrecognized target enumeration value. |
| **BG_E_INVALID_AUTH_SCHEME** | Unrecognized scheme enumeration value. |
| **BG_E_USERNAME_TOO_LARGE** | The user name is too long. For the limit, see the [BG_BASIC_CREDENTIALS](https://learn.microsoft.com/windows/desktop/api/bits1_5/ns-bits1_5-bg_basic_credentials) structure. |
| **BG_E_PASSWORD_TOO_LARGE** | The password is too long. For the limit, see the [BG_BASIC_CREDENTIALS](https://learn.microsoft.com/windows/desktop/api/bits1_5/ns-bits1_5-bg_basic_credentials) structure. |
| **E_INVALIDARG** | The UserName and Password members of the [BG_BASIC_CREDENTIALS](https://learn.microsoft.com/windows/desktop/api/bits1_5/ns-bits1_5-bg_basic_credentials) structure cannot be **NULL** if you specify the Basic or Digest scheme. |

## Remarks

 BITS provides the credentials to a proxy or server in response to a request for user authentication. Set the credentials before the initial call to [Resume](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-resume).

You must call this method for each target and scheme pair that you want to provide. For example, if you want to specify proxy credentials for both Basic and Digest authentication, you would call this method once to specify the Basic credentials and a second time to specify the Digest credentials.

If the job currently contains credentials with the same target and scheme pair, the existing credentials are replaced with the new credentials. The credentials persist for the life of the job. To remove the credentials from the job, call the
[IBackgroundCopyJob2::RemoveCredentials](https://learn.microsoft.com/windows/desktop/api/bits1_5/nf-bits1_5-ibackgroundcopyjob2-removecredentials) method.

If you know the schemes the proxy or server will request, you can provide only those credentials. Otherwise, provide credentials for all schemes.

The job enters the **BG_JOB_STATE_ERROR** state if you do not provide the credentials requested by the proxy or server, or the proxy or server cannot authenticate the credentials. Check the error code to determine if the authentication failed at the server (**BG_E_HTTP_ERROR_401**) or proxy (**BG_E_HTTP_ERROR_407**). To retrieve the error code, call the
[IBackgroundCopyJob::GetError](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-geterror) method to retrieve an
[IBackgroundCopyError](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopyerror) interface pointer. Then, call the
[IBackgroundCopyError::GetError](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyerror-geterror) method to retrieve the error code. After you determine where the authentication failed (proxy or server), specify new credentials to use for the proxy or server and call the
[IBackgroundCopyJob::Resume](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-resume) method to resume the job. Because you cannot determine which scheme failed, specify credentials for all schemes before calling the
**Resume** method.

There is no method to retrieve credentials that you have set.

You must call this method in the context of the job's owner.

Calling the
[IBackgroundCopyJob::TakeOwnership](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-takeownership) method removes the credentials from the job.

To specify implicit credentials (the logged on user's credentials), set the scheme to NTLM and the user name and password to **NULL**. If you specify implicit credentials for a proxy, BITS will also use the implicit credentials for server authentication unless you specify explicit server credentials.

**Note** BITS ignores credentials for [remote names](https://learn.microsoft.com/windows/desktop/api/bits/ns-bits-bg_file_info) that specify an SMB path.

**Note** BITS does not authenticate the server or encrypt the channel. Use HTTPS if this is an issue for your application.

#### Examples

The following example shows how to call the
**SetCredentials** method to specify Basic credentials for a server user authentication request. The example uses the
[CredUIPromptForCredentials](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-creduipromptforcredentialsa) function to capture the user name and password. The example assumes a valid
[IBackgroundCopyJob](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopyjob) interface pointer, pJob. The example uses the [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)) function to clear the memory locations associated with the sensitive information. The **SecureZeroMemory** function is defined in WinBase.h.

```cpp
#define MAX_STR_LENGTH 300+1    // BITS limit for user name and password

CREDUI_INFO cuiinfo;
WCHAR szUserName[MAX_STR_LENGTH];
WCHAR szPassword[MAX_STR_LENGTH];
DWORD rc;
IBackgroundCopyJob* pJob;
IBackgroundCopyJob2* pJob2 = NULL;
BG_AUTH_CREDENTIALS ac;

cuiinfo.cbSize = sizeof(CREDUI_INFO);
cuiinfo.hbmBanner = NULL;
cuiinfo.hwndParent = NULL; //Desktop is parent
cuiinfo.pszCaptionText = L"Server Authentication";
cuiinfo.pszMessageText = L"Enter user credentials for Basic authentication.";

//Initialize the UserName and Password fields. This example sets
//UserName to blank, but you could also set UserName to the owner
//of the job or the current user. For an example that retrieves the owner's
//name, see the example code for the IBackgroundCopyJob::GetOwner method.
szUserName[0] = L'\0';
szPassword[0] = L'\0';
rc = CredUIPromptForCredentials(&cuiinfo, NULL, NULL, 0,
    szUserName, MAX_STR_LENGTH,
    szPassword, MAX_STR_LENGTH,
    NULL, CREDUI_FLAGS_DO_NOT_PERSIST | CREDUI_FLAGS_GENERIC_CREDENTIALS);

if (NO_ERROR == rc)
{
    pJob->QueryInterface(__uuidof(IBackgroundCopyJob2), (void**)&pJob2);
    ac.Target = BG_AUTH_TARGET_SERVER;
    ac.Scheme = BG_AUTH_SCHEME_BASIC;
    ac.Credentials.Basic.UserName = szUserName;
    ac.Credentials.Basic.Password = szPassword;
    hr = pJob2->SetCredentials(&ac);
    if (FAILED(hr))
    {
      //Handle error
    }
    SecureZeroMemory(szUserName, sizeof(szUserName));
    SecureZeroMemory(szPassword, sizeof(szPassword));
}
```

## See also

[Authentication](https://learn.microsoft.com/windows/desktop/Bits/authentication)

[BG_AUTH_CREDENTIALS](https://learn.microsoft.com/windows/desktop/api/bits1_5/ns-bits1_5-bg_auth_credentials)

[IBackgroundCopyJob2::RemoveCredentials](https://learn.microsoft.com/windows/desktop/api/bits1_5/nf-bits1_5-ibackgroundcopyjob2-removecredentials)