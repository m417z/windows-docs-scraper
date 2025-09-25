# ICertAdmin::RevokeCertificate

## Description

The **RevokeCertificate** method revokes a [certificate](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) either on a specified date or immediately. This method was first defined in the [ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin) interface.

 A revoked certificate will appear in a subsequent [certificate revocation lists](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRLs), provided the revocation date is effective at the time the CRL was published.

## Parameters

### `strConfig` [in]

Represents a valid configuration string for the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) server in the form COMPUTERNAME\CANAME, where COMPUTERNAME is the network name of the Certificate Services server and CANAME is the common name of the certification authority, as entered during Certificate Services setup. For information about the configuration string name, see [ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig).

**Important** **RevokeCertificate** does not clear the internal cache when the configuration string is changed. When you change the configuration string for the CA, you must instantiate a new [ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2) object and call this method again with the new configuration string.

### `strSerialNumber` [in]

 Specifies a serial number that identifies the certificate to be revoked. The string must specify the serial number as an even number of hexadecimal digits. If necessary, a zero can be prefixed to the number to produce an even number of digits. However, no more than one leading zero may be used.

### `Reason` [in]

Specifies the reason for the revocation.
The following values (defined in Wincrypt.h) are
supported reason codes.

#### CRL_REASON_UNSPECIFIED (0)

#### CRL_REASON_KEY_COMPROMISE (1)

#### CRL_REASON_CA_COMPROMISE (2)

#### CRL_REASON_AFFILIATION_CHANGED (3)

#### CRL_REASON_SUPERSEDED (4)

#### CRL_REASON_CESSATION_OF_OPERATION (5)

#### CRL_REASON_CERTIFICATE_HOLD (6)

You can reinstate a certificate revoked with the CRL_REASON_CERTIFICATE_HOLD revocation reason code by calling **RevokeCertificate** with MAXDWORD as the *Reason* value. Note that if a certificate has been revoked with any reason code other than CRL_REASON_CERTIFICATE_HOLD, it cannot be reinstated.

### `Date` [in]

Specifies the date, in Coordinated Universal Time (Greenwich Mean Time), on which the revocation will become effective. The value zero indicates the current Coordinated Universal Time, causing a certificate to be revoked immediately. The value of *Date* appears in the **Effective Revocation Date** column of the revoked certificate (in the Certification Authority MMC snap-in).

## Return value

### VB

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

This method can be called more than once on the same certificate, which allows you to change the effective revocation date and revocation reason.

If a currently revoked certificate has CRL_REASON_CERTIFICATE_HOLD as its reason code, you can reinstate the certificate by calling **RevokeCertificate** with MAXDWORD (defined in Winnt.h) as the value for its reason code (the *Reason* parameter). After it is reinstated, the certificate will not appear in future CRLs.

Administration tasks use DCOM. Code that calls this interface method as defined in an earlier version of Certadm.h will run on Windows-based servers as long as the client and the server are both running the same Windows operating system.

#### Examples

```cpp
    BSTR bstrCA = NULL;
    BSTR bstrSerial = NULL;  // certificate serial number
    long nReason;
    DATE RevokeDate;         // revocation date
    SYSTEMTIME st;

    bstrSerial = SysAllocString(L"<SERIALNUMBERHERE>");
    bstrCA = SysAllocString(L"<COMPUTERNAMEHERE>\\<CANAMEHERE>");
    if (NULL == bstrCA || NULL == bstrSerial)
    {
        printf("Memory allocation failed\n");
        goto error;
    }

    nReason = CRL_REASON_AFFILIATION_CHANGED;  // Defined
	                                      // in Wincrypt.h

    //  Specify when the cert should be revoked.
    //  Note: To revoke immediately, set RevokeDate to zero.
    //  This example sets the revoke date to noon on 1/1/2001.
    //  Zero out values first (avoids setting minutes, seconds,
    //  and so on).
    memset(&st, 0, sizeof(SYSTEMTIME));
    st.wYear = 2001;
    st.wMonth = 1;     // Jan
    st.wDay = 1;       // 1st day of month
    st.wHour = 12;     // Noon

    //  Place the date in the required format.
    if (!SystemTimeToVariantTime(&st, &RevokeDate))
    {
        printf("Unable to convert time.\n");
        goto error;
    }

    //  Revoke the certificate.
    //  pCertAdmin is a previously instantiated ICertAdmin object.
    hr = pCertAdmin->RevokeCertificate( bstrCA,
                                        bstrSerial,
                                        nReason,
                                        RevokeDate );
    if (FAILED(hr))
    {
        printf("Failed RevokeCertificate. [%x]\n", hr);
        goto error;
    }
    else
        printf("Certificate %ws revoked.\n", bstrSerial );

    //  Done processing.

error:

    //  Free resources.
    if (bstrSerial)
        SysFreeString( bstrSerial );
    if (bstrCA)
        SysFreeString( bstrCA );
```

## See also

[CCertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2)

[ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin)

[ICertAdmin2](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2)

[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig)