# IBackgroundCopyJobHttpOptions::RemoveClientCertificate

## Description

Removes the client certificate from the job.

## Return value

The following table lists some of the possible return values.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Successfully removed the certificate. |
| ****S_FALSE**** | The job does not specify a certificate. |
| **BG_E_INVALID_STATE** | The state of the job cannot be BG_JOB_STATE_CANCELLED or BG_JOB_STATE_ACKNOWLEDGED. |

## Remarks

You use the [IBackgroundCopyJobHttpOptions::SetClientCertificateByID](https://learn.microsoft.com/windows/desktop/api/bits2_5/nf-bits2_5-ibackgroundcopyjobhttpoptions-setclientcertificatebyid) or [IBackgroundCopyJobHttpOptions::SetClientCertificateByName](https://learn.microsoft.com/windows/desktop/api/bits2_5/nf-bits2_5-ibackgroundcopyjobhttpoptions-setclientcertificatebyname) method to specify the certificate.

## See also

[IBackgroundCopyJobHttpOptions](https://learn.microsoft.com/windows/desktop/api/bits2_5/nn-bits2_5-ibackgroundcopyjobhttpoptions)

[IBackgroundCopyJobHttpOptions::GetClientCertificate](https://learn.microsoft.com/windows/desktop/api/bits2_5/nf-bits2_5-ibackgroundcopyjobhttpoptions-getclientcertificate)

[IBackgroundCopyJobHttpOptions::SetClientCertificateByID](https://learn.microsoft.com/windows/desktop/api/bits2_5/nf-bits2_5-ibackgroundcopyjobhttpoptions-setclientcertificatebyid)

[IBackgroundCopyJobHttpOptions::SetClientCertificateByName](https://learn.microsoft.com/windows/desktop/api/bits2_5/nf-bits2_5-ibackgroundcopyjobhttpoptions-setclientcertificatebyname)