# ICEnroll3::put_LimitExchangeKeyToEncipherment

## Description

[This property is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **LimitExchangeKeyToEncipherment** property sets or retrieves a Boolean value that determines whether an AT_KEYEXCHANGE request contains [digital signature](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) and nonrepudiation key usages.

This property was first introduced in the [ICEnroll3](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll3) interface.

This property is read/write.

## Parameters

## Remarks

This property is a Boolean value and affects only AT_KEYEXCHANGE requests. It has no impact on AT_SIGNATURE requests.

If the value for this property is false, an AT_KEYEXCHANGE request will contain the following key usages:

* CERT_DATA_ENCIPHERMENT_KEY_USAGE
* CERT_KEY_ENCIPHERMENT_KEY_USAGE
* CERT_DIGITAL_SIGNATURE_KEY_USAGE
* CERT_NON_REPUDIATION_KEY_USAGE

If the value for this property is true, an AT_KEYEXCHANGE request will contain the following key usages:

* CERT_DATA_ENCIPHERMENT_KEY_USAGE
* CERT_KEY_ENCIPHERMENT_KEY_USAGE

#### Examples

```cpp
// Get the LimitExchangeKeyToEncipherment value.
BOOL       bLimitKey;
HRESULT    hr;
// pEnroll is previously instantiated ICEnroll interface pointer.
hr = pEnroll->get_LimitExchangeKeyToEncipherment(&bLimitKey);
if (FAILED(hr))
    printf("Failed get_LimitExchangeKeyToEncipherment - %x\n", hr );
else
    printf("LimitExchangeKeyToEncipherment: %s\n",
          ( bLimitKey ? "TRUE" : "FALSE"));

// Set the LimitExchangeKeyToEncipherment value.
hr = pEnroll->put_LimitExchangeKeyToEncipherment( TRUE );
if ( FAILED ( hr ) )
    printf("Failed put_LimitExchangeKeyToEncipherment - %x\n", hr );
else
    printf( "LimitExchangeKeyToEncipherment was set to TRUE\n" );
```

## See also

[CEnroll](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376007(v=vs.85))

[ICEnroll3](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll3)

[ICEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll4)

[KeySpec](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-get_keyspec)