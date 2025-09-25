# ICertConfig::GetField

## Description

The **GetField** method gets a specific field from the current record of the configuration database. This method was first defined in the [ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig) interface.

## Parameters

### `strFieldName` [in]

Specifies the name of the field to return. This parameter can be one of the following valid strings for field names (note that some certification authorities may not provide data for each field).

| Value | Meaning |
| --- | --- |
| **Authority** | Reference certification authority (CA) name. |
| **CommonName** | Common name of the server. |
| **Config** | Reference computer\CA name. |
| **Country** | Country/region. |
| **Description** | Descriptive comment about the server (replaces obsolete "Comment"). |
| **ExchangeCertificate** | Name of the file that contains the exchange certificate (applies to Certificate Services 1.0 only). |
| **Flags** | String that represents the location where the CA information was found. For more information, see Remarks. |
| **Locality** | City or town. |
| **Organization** | Organization. |
| **OrgUnit** | Organizational unit. |
| **SanitizedName** | CA name that is [sanitized](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) according to the rules described in [GetConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertconfig-getconfig). |
| **SanitizedShortName** | CA name that is sanitized and shortened according to the rules described in [GetConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertconfig-getconfig). |
| **Server** | Reference computer name. |
| **ShortName** | SanitizedShortName, but with the '!xxx' sequences, as described in [GetConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertconfig-getconfig), translated back into the original text. |
| **SignatureCertificate** | Name of the file that contains the CA certificate (also known as the CA [signature certificate](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly)); this may or may not be a [root certificate](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly). |
| **State** | State or province. |
| **WebEnrollmentServers** | An array of certificate enrollment Web service URLs for a specific CA configuration in the Active Directory.<br><br>**Windows Vista and Windows Storage Server 2003:** This field is not supported. |

### `pstrOut` [out, retval]

A pointer to a **BSTR** that receives the data from the field. When you have finished using the **BSTR**, free *pbstrOut* by calling the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value is a string that represents the data for the field.

## Remarks

This method returns the field data for the specified field.

When you specify "Flags" in the *strFieldName* parameter, the retrieved data for the flags field is a string that can be converted to an integer by means of the C-library function **_wtoi**. The resulting integer represents a bitfield that can be examined to determine whether the flags CAIF_DSENTRY and CAIF_SHAREDFOLDERENTRY are set. If CAIF_DSENTRY (0x00000001) is set, the information for the CA was contained in Directory Services. If CAIF_SHAREDFOLDERENTRY (0x00000002) is set, the information for the CA was contained in the shared folder. Note that one or both of these flags may be set.

#### Examples

```cpp
    BSTR  bstrFieldName = NULL;
    BSTR  bstrFieldValue = NULL;
    HRESULT    hr;

    // Specify the field to retrieve, for example, "CommonName".
    bstrFieldName = SysAllocString(L"<FIELDNAMEHERE>");
    if (NULL == bstrFieldName)
    {
        printf("Memory allocation failed for bstrFieldName.\n");
        goto error;
    }

    // pConfig is a previously instantiated ICertConfig object.
    hr = pConfig->GetField(bstrFieldName, &bstrFieldValue);
    if (FAILED(hr))
    {
        printf("Failed GetField - [%x]\n", hr);
        goto error;
    }
    else
        printf("GetField value for %ws is: %ws\n",
            bstrFieldName, bstrFieldValue );

error:

    if (bstrFieldName)
        SysFreeString(bstrFieldName);

    if (bstrFieldValue)
        SysFreeString(bstrFieldValue);
```

## See also

[CCertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig2)

[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig)