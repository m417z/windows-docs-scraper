# IOCSPCAConfiguration::put_ProviderProperties

## Description

The **ProviderProperties** property gets or sets information that provides certificate status responses. The revocation information provider configured in the [ProviderCLSID](https://learn.microsoft.com/windows/desktop/api/certadm/nf-certadm-iocspcaconfiguration-get_providerclsid) property uses [certificate revocation lists](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRLs) specified in this property to provide responses.

This property is read/write.

## Parameters

## Remarks

The **VARIANT** returned in *pVal* is an [IOCSPPropertyCollection](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocsppropertycollection) interface.

To work with revocation-information provider properties:

1. Create an [IOCSPPropertyCollection](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocsppropertycollection) object.
2. Call [InitializeFromProperties](https://learn.microsoft.com/windows/desktop/api/certadm/nf-certadm-iocsppropertycollection-initializefromproperties) and pass in the **VARIANT**, *pVal*, returned by the **ProviderProperties** property.
3. Use the [Methods](https://learn.microsoft.com/windows/desktop/SecCrypto/methods-of-iocsppropertycollection) and [Properties](https://learn.microsoft.com/windows/desktop/SecCrypto/properties-of-iocsppropertycollection) of the [IOCSPPropertyCollection](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocsppropertycollection) interface.

The following table lists the possible [IOCSPProperty](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocspproperty) [Name](https://learn.microsoft.com/windows/desktop/api/certadm/nf-certadm-iocspproperty-get_name) values and their data types for the default revocation-information provider.

| Name | Data type |
| --- | --- |
| BaseCrl | Depends on BaseCrlUrl |
| BaseCrlUrl | REG_MULTI_SZ |
| CrlUrlTimeout | DWORD |
| DeltaCrl | Depends on BaseCrlUrl or DeltaCrlUrl |
| DeltaCrlUrl | REG_MULTI_SZ |
| RefreshTimeOut | DWORD |
| RevocationErrorCode | DWORD |

## See also

[IOCSPCAConfiguration](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocspcaconfiguration)