# VSS_PROVIDER_PROP structure

## Description

The **VSS_PROVIDER_PROP** structure specifies
shadow copy provider properties.

## Members

### `m_ProviderId`

Identifies the provider who supports shadow copies of this class.

### `m_pwszProviderName`

Null-terminated wide character string containing the provider name.

### `m_eProviderType`

Provider type. See [VSS_PROVIDER_TYPE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_provider_type) for more
information.

### `m_pwszProviderVersion`

Null-terminated wide character string containing the provider version in readable format.

### `m_ProviderVersionId`

A [VSS_ID](https://learn.microsoft.com/windows/desktop/VSS/volume-shadow-copy-api-data-types) (GUID) uniquely
identifying the version of a provider.

### `m_ClassId`

Class identifier of the component registered in the local machine's COM catalog.

## See also

[VSS_ID](https://learn.microsoft.com/windows/desktop/VSS/volume-shadow-copy-api-data-types)

[VSS_PROVIDER_TYPE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_provider_type)