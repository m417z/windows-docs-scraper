# ICertAdmin2::PublishCRLs

## Description

The **PublishCRLs** method publishes [certificate revocation lists](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRLs) for a [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA). This method was first defined in the [ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin) interface.

The **PublishCRLs** method publishes a CRL based on the CA's current certificate, as well as CRLs based on any CA certificates that have been renewed and are not yet expired.

## Parameters

### `strConfig` [in]

Represents a valid configuration string for the CA in the form COMPUTERNAME\CANAME, where COMPUTERNAME is the Certificate Services server's network name, and CANAME is the common name of the certification authority, as entered during Certificate Services setup. For information about the configuration string name, see [ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig).

**Important** **PublishCRLs** does not clear the internal cache when the configuration string is changed. When you change the configuration string for the CA, you must instantiate a new [ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2) object and call this method again with the new configuration string.

### `Date` [in]

Specifies the next update value of the CRL in GMT time.
If *Date* is nonzero, the next update value for the CRL is *Date*, subject to rounding or ceiling limits enforced by [Certificate Services](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). If *Date* is zero, the next update value of the CRL is calculated from the default CRL publication period.

### `CRLFlags` [in]

Value that specifies the CRL publishing options. This value can be a bitwise combination of the following flags.

| Value | Meaning |
| --- | --- |
| **CA_CRL_BASE** | A base CRL is published, or the most recent base CRL is republished if CA_CRL_REPUBLISH is set. |
| **CA_CRL_DELTA** | A delta CRL is published, or the most recent delta CRL is republished if CA_CRL_REPUBLISH is set. Note that if the CA has not enabled delta CRL publishing, use of this flag will result in an error. |
| **CA_CRL_REPUBLISH** | The most recent base or delta CRL, as specified by CA_CRL_BASE or CA_CRL_DELTA, is republished. The CA will not republish a CRL to a CRL distribution point if the CRL at the distribution point is already the most recent CRL. |

## Remarks

To determine whether a CA has successfully published base and delta CRLs, call [ICertAdmin2::GetCAProperty](https://learn.microsoft.com/windows/desktop/api/certadm/nf-certadm-icertadmin2-getcaproperty) with the CR_PROP_BASECRLPUBLISHSTATUS and CR_PROP_DELTACRLPUBLISHSTATUS property identifiers, respectively.

#### Examples

The following example shows publishing CRLs.

```cpp
    DATE ExpDate;  // CRL expiration date.
    SYSTEMTIME st;
    BSTR bstrCA = NULL;

    //  Set the CRL expiration date to noon, July 1, 2001.
    //  Zero out values first (avoids setting minutes,
    //  seconds, and so on).
    memset(&st, 0, sizeof(SYSTEMTIME));
    st.wYear = 2001;
    st.wMonth = 7;     // July
    st.wDay = 1;       // first day of month
    st.wHour = 12;     // noon

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
    hr = pCertAdmin2->PublishCRLs(bstrCA,
                              ExpDate,
                              CA_CRL_BASE);
    if (FAILED(hr))
    {
        printf("Failed PublishCRLs [%x]\n", hr);
        goto error;
    }
    else
        printf("PublishCRLs succeeded\n");
    //  Done.

error:

    //  Free resources.
    if (bstrCA)
        SysFreeString(bstrCA);
```