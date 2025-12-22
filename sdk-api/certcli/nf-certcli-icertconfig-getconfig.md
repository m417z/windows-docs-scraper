# ICertConfig::GetConfig

## Description

The **GetConfig** method retrieves the configuration string for a [Certificate Services](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) server. This method was first defined in the [ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig) interface.

The configuration string is the server name and [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) name separated by a backslash (\\); for example: *ServerName***\\***CAName*. This configuration string can be used to refer unambiguously to a specific Certificate Services server. For more information, see Remarks.

## Parameters

### `Flags` [in]

Value that specifies the certification authority to use. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CC_DEFAULTCONFIG**<br><br>0x00000000 | Retrieves the default certification authority. |
| **CC_FIRSTCONFIG**<br><br>0x00000002 | Returns the first certification authority. |
| **CC_LOCALACTIVECONFIG**<br><br>0x00000004 | Retrieves the local certification authority if it is running. |
| **CC_LOCALCONFIG**<br><br>0x00000003 | Retrieves the local certification authority. |
| **CC_UIPICKCONFIG**<br><br>0x00000001 | Displays a user interface that allows the user to select a certification authority. |
| **CC_UIPICKCONFIGSKIPLOCALCA**<br><br>0x00000005 | Displays a user interface that allows the user to select a certification authority. The UI excludes any local certification authority. This exclusion is useful during subordinate certification authority certificate renewal when the subordinate certification authority certificate request is submitted to a certification authority other than the current certification authority. |

### `pstrOut` [out]

A pointer to a **BSTR** that contains the configuration. When you have finished using the configuration, call the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function to free *pbstrOut*.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is a string that contains the configuration.

## Remarks

The [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) name portion of the configuration string that this function returns is the exact text entered during the Certificate Services setup process. Note that this text may be different from the form of the CA name found in file names (such as for the [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly)) or in registry keys. This is because file names and registry keys use a [sanitized](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) version of the CA name.

The process of sanitizing the CA name is necessary to remove characters that are illegal for file names, registry key names, or distinguished name values, or illegal for reasons specific to Certificate Services. In the sanitizing process, any illegal character in the common name is converted to a five-character representation in the format **!***xxxx*, where **!** is used as an escape character and *xxxx* represents four hexadecimal digits that uniquely identify the character to be converted.

For example, the number sign (#) is not allowed in distinguished names in Active Directory. If the CA name entered during setup is **#***YourName*, the sanitized CA name will be **!0023***YourName*.

The following characters, if entered for the common name of the CA during setup, are converted to the **!***xxxx* format during the sanitizing process. This list is subject to change.

| Name | Character | Value in !xxxx format |
| --- | --- | --- |
| Ampersand | & | !0026 |
| Apostrophe | ' | !0027 |
| Asterisk | * | !002a |
| Backslash | \ | !005c |
| Left brace | { | !007b |
| Right brace | } | !007d |
| Left bracket | [ | !005b |
| Right bracket | ] | !005d |
| Caret | ^ | !005e |
| Colon | : | !003a |
| Comma | , | !002c |
| Equal sign | = | !003d |
| Exclamation point | ! | !0021 |
| Grave accent | ` | !0060 |
| Greater than sign | > | !003e |
| Less than sign | < | !003c |
| Number sign | # | !0023 |
| Opening parenthesis | ( | !0028 |
| Closing parenthesis | ) | !0029 |
| Percent | % | !0025 |
| Pipe | \| | !007c |
| Plus sign | + | !002b |
| Question mark | ? | !003f |
| Quotation mark | " | !0022 |
| Semicolon | ; | !003b |
| Slash mark | / | !002f |

Any nonprinting character and all [Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) characters that are not seven bits are also converted to the **!***xxxx* format.

A sanitized short name is generated when the [sanitized name](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) is too long for a 64-character directory services [relative distinguished name](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) (RDN). The sanitized short name consists of the sanitized name truncated and appended with a [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) of the full sanitized name. The sanitized short name reserves some of the 64 characters to contain [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) suffixes, such as (123).

The certification authority name portion of the configuration string returned by this method is the original text entered during setup. Note that Certificate Services methods that require a certification authority name as a parameter accept the originally entered certification authority name. For example, for the certification authority name **#***YourName*, the
[ICertView2::OpenConnection](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-icertview-openconnection) method accepts **#***YourName* as the parameter's certification authority portion.

#### Examples

The following example shows how to use this method to retrieve the default certification authority configuration string.

```cpp

    ICertConfig2 * pConfig = NULL;
    BSTR  bstrConfig = NULL; //Contains CA configuration name
    HRESULT    hr;

    hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
    if (FAILED(hr))
    {
        printf("Failed CoInitializeEx - [%x]\n", hr);
        goto error;
    }

    // Create an instance of the CertConfig object.
    hr = CoCreateInstance( CLSID_CCertConfig,
                           NULL,
                           CLSCTX_INPROC_SERVER,
                           IID_ICertConfig2,
                           (void **)&pConfig);
    if (FAILED(hr))
    {
        printf("Failed CoCreateInstance - pConfig [%x]\n", hr);
        goto error;
    }

    // Retrieve the default CA configuration string.
    hr = pConfig->GetConfig(CC_DEFAULTCONFIG, &bstrConfig);
    if (FAILED(hr))
    {
        printf("Failed GetConfig - [%x]\n", hr);
        goto error;
    }
    else
        printf("GetConfig returned: %ws\n", bstrConfig );

error:

    // Done processing.
    if (pConfig)
        pConfig->Release();

    if (bstrConfig)
        SysFreeString(bstrConfig);

    CoUninitialize();

```

## See also

[CCertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig2)

[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig)

[ICertView2::OpenConnection](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-icertview-openconnection)