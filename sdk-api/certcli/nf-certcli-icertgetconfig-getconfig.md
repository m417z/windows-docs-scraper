# ICertGetConfig::GetConfig

## Description

The **GetConfig** method retrieves the configuration string for a [Certificate Services](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) server.

The configuration string is the server name and [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) name separated by a backslash (\\); for example: *ServerName*\*CAName*. This configuration string can be used to refer unambiguously to a specific Certificate Services server. For more information, see Remarks.

## Parameters

### `Flags` [in]

Value that specifies the CA to use. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CC_DEFAULTCONFIG**<br><br>0x00000000 | Retrieves the default CA. |
| **CC_FIRSTCONFIG**<br><br>0x00000002 | Returns the first CA. |
| **CC_LOCALACTIVECONFIG**<br><br>0x00000004 | Retrieves the local CA if it is running. |
| **CC_LOCALCONFIG**<br><br>0x00000003 | Retrieves the local CA. |
| **CC_UIPICKCONFIG**<br><br>0x00000001 | Displays a user interface (UI) that allows the user to select a CA. |
| **CC_UIPICKCONFIGSKIPLOCALCA**<br><br>0x00000005 | Displays a UI that allows the user to select a CA. The UI excludes any local CA. This exclusion is useful during subordinate CA certificate renewal when the subordinate CA certificate request is submitted to a CA other than the current CA. |

### `pstrOut` [out]

A pointer to a **BSTR** that contains the configuration. When you have finished using the configuration, call the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function to free *pbstrOut*.

## Return value

If the function is successful, the return value is S_OK.

If the method fails, the return value is an **HRESULT** that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

The [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) name portion of the configuration string that this function returns is the exact text entered during the Certificate Services setup process. Note that this text may be different from the form of the CA name found in file names (such as for the [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly)) or in registry keys. This is because file names and registry keys use a [sanitized](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) version of the CA name.

The process of sanitizing the CA name is necessary to remove characters that are illegal for file names, registry key names, or distinguished name values, or illegal for reasons specific to Certificate Services. In the sanitizing process, any illegal character in the common name is converted to a five-character representation in the format **!***xxxx*, where the exclamation point (**!**) is used as an escape character and *xxxx* represents four hexadecimal digits that uniquely identify the character to be converted.

For example, the number sign (#) is not allowed in distinguished names in the Active Directory directory service. If the CA name entered during setup is **#***YourName*, the sanitized CA name will be **!0023***YourName*.

The following characters, if entered for the common name of the CA during setup, are converted to the **!***xxxx* format during the sanitizing process. This list is subject to change.

| Character | Value in !xxxx format |
| --- | --- |
| < | !003c |
| > | !003e |
| " | !0022 |
| / | !002f |
| \ | !005c |
| : | !003a |
| | | !007c |
| ? | !003f |
| * | !002a |
| # | !0023 |
| , | !002c |
| + | !002b |
| ; | !003b |
| ! | !0021 |

Any nonprinting character and all [Unicode](https://learn.microsoft.com/windows/desktop/SecGloss/u-gly) characters that are not seven bits are also converted to the **!***xxxx* format.

A sanitized short name is generated when the [sanitized name](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) is too long for a 64-character directory services [relative distinguished name](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) (RDN). The sanitized short name consists of the sanitized name truncated and appended with a [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) of the full sanitized name. The sanitized short name reserves some of the 64 characters to contain [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL) suffixes, such as (123).

The CA name portion of the configuration string returned by this method is the original text entered during setup. Note that Certificate Services methods that require a CA name as a parameter accept the originally entered CA name. For example, for the CA name **#***YourName*, the
[ICertView2::OpenConnection](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-icertview-openconnection) method accepts **#***YourName* as the parameter's CA portion.

## See also

[ICertConfig2::GetConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertconfig-getconfig)

[ICertGetConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertgetconfig)

[ICertView2::OpenConnection](https://learn.microsoft.com/windows/desktop/api/certview/nf-certview-icertview-openconnection)