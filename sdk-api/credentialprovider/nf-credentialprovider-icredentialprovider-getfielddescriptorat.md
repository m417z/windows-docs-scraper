# ICredentialProvider::GetFieldDescriptorAt

## Description

Gets metadata that describes a specified field.

## Parameters

### `dwIndex` [in]

Type: **DWORD**

The zero-based index of the field for which the information should be retrieved.

### `ppcpfd` [out]

Type: **[CREDENTIAL_PROVIDER_FIELD_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/credentialprovider/ns-credentialprovider-credential_provider_field_descriptor)****

The address of a pointer to a [CREDENTIAL_PROVIDER_FIELD_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/credentialprovider/ns-credentialprovider-credential_provider_field_descriptor) structure which receives the information about the field.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is required.