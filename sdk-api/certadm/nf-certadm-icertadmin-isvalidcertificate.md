# ICertAdmin::IsValidCertificate

## Description

The **IsValidCertificate** method verifies the [certificate](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) against the [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) key and checks that the certificate has not been revoked. This method was first defined in the [ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin) interface.

## Parameters

### `strConfig` [in]

Represents a valid configuration string for the CA in the form COMPUTERNAME\CANAME, where COMPUTERNAME is the network name of the Certificate Services server and CANAME is the common name of the certification authority, as entered during Certificate Services setup. For information about the configuration string name, see
[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig).

**Important** **IsValidCertificate** does not clear the internal cache when the configuration string is changed. When you change the configuration string for the CA, you must instantiate a new [ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2) object and call this method again with the new configuration string.

### `strSerialNumber` [in]

Specifies a serial number that identifies the certificate to be reviewed. The string must specify the serial number as an even number of hexadecimal digits. If necessary, a zero can be prefixed to the number to produce an even number of digits. No more than one leading zero may be used.

### `pDisposition` [out, retval]

A pointer to a **LONG** that receives the disposition value.

## Return value

### C++

If the method succeeds and the *pDisposition* parameter is set to one of the following values, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The return value specifies the disposition of the certificate. This value is one of the following values. (These values are defined in Certadm.h.)

| Return code | Description |
| --- | --- |
| **CA_DISP_INCOMPLETE** | The call was not completed. |
| **CA_DISP_ERROR** | The call failed. |
| **CA_DISP_REVOKED** | The certificate has been revoked. |
| **CA_DISP_VALID** | The certificate is still valid. |
| **CA_DISP_INVALID** | The certificate was never issued. |
| **CA_DISP_UNDER_SUBMISSION** | The certificate is pending. |

## Remarks

This method determines only whether a certificate has been issued and is not currently revoked; it does not check that the current time and date are within the period for which the certificate is valid (the NotBefore and NotAfter certificate properties). An application that uses this method is also responsible for checking the certificate expiration.

Administration tasks use DCOM. Code that calls this interface method as defined in an earlier version of Certadm.h will run on Windows-based servers as long as the client and the server are both running the same Windows operating system.

#### Examples

```cpp
    BSTR       bstrCA = NULL;      // Machine\CAName
    BSTR       bstrSerial = NULL;  // Contains the certificate
                             // serial number
    long       nDisp;              // Contains the certificate
                             // disposition
    HRESULT    hr;

    bstrCA = SysAllocString(L"<COMPUTERNAMEHERE>\\<CANAMEHERE>");
    bstrSerial = SysAllocString(L"<SERIALNUMBERHERE>");

    if (NULL == bstrCA || NULL == bstrSerial)
    {
        printf("Memory allocation failed\n");
        goto error;
    }

    //  Determine whether the certificate is valid.
    //  pCertAdmin is a previously instantiated ICertAdmin
    //  object pointer.
    hr = pCertAdmin->IsValidCertificate(bstrCA, bstrSerial, &nDisp);
    if (FAILED(hr))
    {
        printf("Failed IsValidCertificate [%x]\n", hr);
        goto error;
    }
    //  Use nDisp as needed.

    //  Done processing.

error:

    //  Free BSTR values.
    if (NULL != bstrCA)
        SysFreeString(bstrCA);

    if (NULL != bstrSerial)
        SysFreeString(bstrSerial);
```

## See also

[CCertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2)

[ICertAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin)

[ICertAdmin2](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-icertadmin2)

[ICertConfig](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertconfig)