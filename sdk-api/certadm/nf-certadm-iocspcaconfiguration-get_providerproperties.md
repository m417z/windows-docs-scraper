# IOCSPCAConfiguration::get_ProviderProperties

## Description

The **ProviderProperties** property gets or sets information that provides certificate status responses. The revocation information provider configured in the [ProviderCLSID](https://learn.microsoft.com/windows/desktop/api/certadm/nf-certadm-iocspcaconfiguration-get_providerclsid) property uses [certificate revocation lists](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRLs) specified in this property to provide responses.

This property is read/write.

## Parameters

## Remarks

The **VARIANT** returned in *pVal* is a pointer to a safe array that contains the properties as name-value pairs.

This array is a two-dimensional array of elements, each of type VARIANT. The array contains one row for each named property in the collection. Each row contains two columns: the property name and the property value.

The following table lists the possible named property values and their data types for the default revocation provider:

| Name | Data type |
| --- | --- |
| BaseCrl | REG_BINARY |
| BaseCrlUrls | REG_MULTI_SZ |
| CrlUrlTimeout | DWORD |
| DeltaCrl | REG_BINARY |
| DeltaCrlUrls | REG_MULTI_SZ |
| RefreshTimeOut | DWORD |
| RevocationErrorCode | DWORD |
| IssuedSerialNumbersDirectories | REG_MULTI_SZ |

Note: IssuedSerialNumberDirectories is not supported on Windows Server 2008.

## See also

[IOCSPCAConfiguration](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocspcaconfiguration)