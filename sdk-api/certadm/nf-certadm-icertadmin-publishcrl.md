# ICertAdmin::PublishCRL

## Description

The **PublishCRL** method sends a request to the Certificate Services [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) to publish a new [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRL). This method was first introduced in the [ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin) interface.

## Parameters

### `strConfig` [in]

Represents a valid configuration string for the CA in the form COMPUTERNAME\CANAME, where COMPUTERNAME is the Certificate Services server's network name, and CANAME is the common name of the certification authority, as entered during Certificate Services setup. For information about the configuration string name, see [ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig).

**Important** **PublishCRL** does not clear the internal cache when the configuration string is changed. When you change the configuration string for the CA, you must instantiate a new [ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2) object and call this method again with the new configuration string.

### `Date` [in]

Specifies the next update value of the CRL in Coordinated Universal Time (Greenwich Mean Time).
If *Date* is nonzero, the next update value for the CRL is *Date*, subject to rounding or ceiling limits enforced by Certificate Services. If *Date* is zero, the next update value of the CRL is calculated from the default CRL publication period.

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

Administration tasks use DCOM. Code that calls this interface method as defined in an earlier version of Certadm.h will run on Windows-based servers as long as the client and the server are both running the same Windows operating system.

#### Examples

The following example shows publishing a CRL.

```cpp
    DATE ExpDate;  // CRL expiration date
    SYSTEMTIME st;
    BSTR bstrCA = NULL;

    //  Set the CRL Expiration Date to Noon on Jan. 1, 2005 GMT.
    //  Zero out values first
	//  (avoids setting minutes, seconds, and so on).
    memset(&st, 0, sizeof(SYSTEMTIME));
    st.wYear = 2005;
    st.wMonth = 1;     // Jan
    st.wDay = 1;       // 1st day of month
    st.wHour = 12;     // Noon

    //  Place the date in required format.
    if (!SystemTimeToVariantTime(&st, &ExpDate))
    {
        printf("Unable to convert time\n");
        goto error;
    }

    bstrCA = SysAllocString(L"<COMPUTERNAMEHERE>\\<CANAMEHERE>");
    if (NULL == bstrCA)
    {
        printf("Memory allocation failed\n");
        goto error;
    }

    //  Publish the CRL.
    //  pCertAdmin is a previously instantiated ICertAdmin object.
    hr = pCertAdmin->PublishCRL(bstrCA, ExpDate);
    if (FAILED(hr))
    {
        printf("Failed PublishCRL [%x]\n", hr);
        goto error;
    }
    else
        printf("PublishCRL succeeded\n");
```

## See also

[CCertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2)

[ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin)

[ICertAdmin2](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2)

[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig)