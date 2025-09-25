# ICertAdmin::SetRequestAttributes

## Description

The **SetRequestAttributes** method sets attributes in the specified pending [certificate request](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). This method was first defined in the [ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin) interface.

For this method to succeed, the certificate request must be pending.

## Parameters

### `strConfig` [in]

Represents a valid configuration string for the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) server in the form COMPUTERNAME\CANAME, where COMPUTERNAME is the network name of the Certificate Services server and CANAME is the common name of the certification authority, as entered during Certificate Services setup. For information about the configuration string name, see
[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig).

**Important** **SetRequestAttributes** does not clear the internal cache when the configuration string is changed. When you change the configuration string for the CA, you must instantiate a new [ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2) object and call this method again with the new configuration string.

### `RequestId` [in]

Specifies the ID of the request receiving the [attributes](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly).

### `strAttributes` [in]

Specifies the attribute data. Each attribute is a name-value string pair. The colon character separates the name and value, and a newline character separates multiple name-value pairs, for example:

|  |  |
| --- | --- |
| **C++** | *AttributeName1***:***AttributeValue1***\***nAttributeName2***:***AttributeValue2* |
| **VB** | *AttributeName1***:***AttributeValue1* **&** *vbNewLine* **&** *AttributeName2***:***AttributeValue2* |

There is no set limit to the number of request attributes that may be added to a request.

When Certificate Services parses attribute names, it ignores spaces, hyphens (minus signs), and case. For example, *AttributeName1*, *Attribute Name1*, and *Attribute-name1* are all equivalent. For attribute values, Certificate Services ignores leading and trailing white space.

**Note** The maximum length for an attribute name is 127 non-**NULL** characters. The maximum length for an attribute value is 4,096 non-**NULL** characters.

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

[Attributes](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) added or updated by calling **SetRequestAttributes** do not alter the initial, unparsed attribute string associated with the [certificate request](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). The certificate request's unparsed attribute string is unalterable after the certificate is requested (the
[ICertRequest::Submit](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertrequest-submit) method allows attributes to be specified at the time the certificate is requested).

You can use the Certification Authority MMC snap-in to display the initial unparsed request attribute string.

When you view the parsed attributes, you will also see any changes due to calls to **SetRequestAttributes**.

**To view the parsed attributes**

1. Open the Certification Authority MMC snap-in.
2. Open the **Pending Requests** folder.
3. Right-click a request, point to **All Tasks**, and then click **View Attributes/Extensions**.

To enumerate or view all of the parsed attributes, including those added by means of **SetRequestAttributes**, you may also use the
[IEnumCERTVIEWATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewattribute) interface.

Administration tasks use DCOM. Code that calls this interface method as defined in an earlier version of Certadm.h will run on Windows-based servers as long as the client and the server are both running the same Windows operating system.

#### Examples

```cpp
    BSTR bstrAttribs = NULL;
    BSTR bstrCA = NULL;
    long nReqID;  // request ID

    //  Specify the attributes.
    //  For example, "AttName1:AttValue1\nAttName2:AttValue2".
    bstrAttribs = SysAllocString(L"<ATTRIBUTESHERE>");
    if (NULL == bstrAttribs)
    {
        printf("Memory allocation failed for bstrAttribs.\n");
        goto error;
    }

    bstrCA = SysAllocString(L"<COMPUTERNAMEHERE>\\<CANAMEHERE>");
    if (NULL == bstrCA)
    {
        printf("Memory allocation failed for bstrCA.\n");
        goto error;
    }

    //  Request ID to receive the attributes.
    nReqID = <REQUESTIDHERE>;

    //  Add these attributes to the certificate.
    //  pCertAdmin is a previously instantiated
    //  ICertAdmin object pointer.
    hr = pCertAdmin->SetRequestAttributes( bstrCA,
                                           nReqID,
                                           bstrAttribs );
    if (FAILED(hr))
        printf("Failed SetRequestAttributes [%x]\n", hr);
    else
        printf("SetRequestAttributes succeeded\n");

    //  Done processing.

error:

    if (bstrAttribs)
        SysFreeString(bstrAttribs);
    if (bstrCA)
        SysFreeString(bstrCA);
    //  Free other resources.
```

## See also

[CCertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2)

[ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin)

[ICertAdmin2](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2)

[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig)

[IEnumCERTVIEWATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/certview/nn-certview-ienumcertviewattribute)