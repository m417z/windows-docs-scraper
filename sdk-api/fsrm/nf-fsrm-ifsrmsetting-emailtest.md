# IFsrmSetting::EmailTest

## Description

Send an email message to the specified email address.

## Parameters

### `mailTo` [in]

The email address. The string is limited to 255 characters.

## Return value

The method returns the following return codes:

## Remarks

Use this method to test the SMTP server specified in the
[SmtpServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmsetting-get_smtpserver) property. The sender is specified in
the [MailFrom](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmsetting-get_mailfrom) property (cannot be set to
"[Admin Email]").

The subject and message body are predefined, localized text.

#### Examples

The following example shows how to call this method.

```cpp
#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>
#include <stdio.h>
#include <comutil.h>
#include <fsrm.h>       // FSRM base objects and collections
#include <fsrmtlb_i.c>  // contains CLSIDs

//
// Call the IFsrmSetting::EmailTest method to test the SMTP email server.
//
void wmain(void)
{
  HRESULT hr = 0;
  IFsrmSetting* pSettings = NULL;

  hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
  if (FAILED(hr))
  {
    wprintf(L"CoInitializeEx() failed, 0x%x.\n", hr);
    exit(1);
  }

  hr = CoCreateInstance(CLSID_FsrmSetting,
                        NULL,
                        CLSCTX_LOCAL_SERVER,
                        __uuidof(IFsrmSetting),
                        reinterpret_cast<void**> (&pSettings));

  if (FAILED(hr))
  {
    wprintf(L"CoCreateInstance(FsrmSetting) failed, 0x%x.\n", hr);
    if (E_ACCESSDENIED == hr)
      wprintf(L"Access denied. You must run the client with an elevated token.\n");

    goto cleanup;
  }

  wprintf(L"Successfully created Setting object.\n");

  // Specify the SMTP server to use for sending email.
  hr = pSettings->put_SmtpServer(_bstr_t(L"<FQDNOFSMTPSERVER>"));
  if (FAILED(hr))
  {
    wprintf(L"pSettings->put_SmtpServer failed, 0x%x.\n", hr);
    goto cleanup;
  }

  // Test the specified SMTP server. If the test succeeds, you will find a
  // predefined email message in C:\Inetpub\mailroot\Drop. You can use
  // Outlook Express to read the message.

  hr = pSettings->EmailTest(_bstr_t(L"admin@<FQDNOFSMTPSERVER>"));
  if (FAILED(hr))
  {
    wprintf(L"pSettings->EmailTest failed, 0x%x.\n", hr);
    goto cleanup;
  }

  wprintf(L"Successfully sent mail.\n");

cleanup:

  if (pSettings)
    pSettings->Release();

  CoUninitialize();
}

```

## See also

[FsrmSetting](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmsetting)

[IFsrmSetting](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmsetting)