# ICredentialProvider::GetFieldDescriptorCount

## Description

Retrieves the count of fields in the needed to display this provider's credentials.

## Parameters

### `pdwCount` [out]

Type: **DWORD***

Pointer to the field count.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is required.

The count provided by this method must be valid for the entire usage scenario. This means that you need to include all fields, even those that are hidden or only shown under special circumstances. This value cannot be changed during a usage scenario and can only be changed when a new [SetUsageScenario](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovider-setusagescenario) call is made to the provider or the [ICredentialProviderEvents](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nn-credentialprovider-icredentialproviderevents) instance forces another enumeration.