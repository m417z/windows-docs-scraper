# IEnroll2::put_LimitExchangeKeyToEncipherment

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **LimitExchangeKeyToEncipherment** property sets or retrieves a Boolean value that determines whether an AT_KEYEXCHANGE request contains [digital signature](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) and nonrepudiation key usages.

This property was first introduced in the [IEnroll2](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll2) interface.

This property is read/write.

## Parameters

## Remarks

This property is a Boolean value and affects only AT_KEYEXCHANGE requests. It has no impact on AT_SIGNATURE requests.

If the value for this property is **FALSE**, an AT_KEYEXCHANGE request will contain the following key usages:

* CERT_DATA_ENCIPHERMENT_KEY_USAGE
* CERT_KEY_ENCIPHERMENT_KEY_USAGE
* CERT_DIGITAL_SIGNATURE_KEY_USAGE
* CERT_NON_REPUDIATION_KEY_USAGE

If the value for this property is **TRUE**, an AT_KEYEXCHANGE request will contain the following key usages:

* CERT_DATA_ENCIPHERMENT_KEY_USAGE
* CERT_KEY_ENCIPHERMENT_KEY_USAGE

## See also

[IEnroll2](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll2)

[IEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)