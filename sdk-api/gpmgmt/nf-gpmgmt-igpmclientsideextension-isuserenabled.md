# IGPMClientSideExtension::IsUserEnabled

## Description

Checks whether the client-side extension can be called during the processing of user policy.

## Parameters

### `pvbEnabled` [out]

Value that indicates whether the client-side extension can be called during the processing of user policy. If **VARIANT_TRUE**, the client-side extension is called during the processing of user policy, provided that there are policy settings for the client-side extension in the user portion of one or more of the applied GPOs.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Value that indicates whether the client-side extension can be configured in the user portion of the GPO. If **VARIANT_TRUE**, the client-side extension can be configured.

### VB

Value that indicates whether the client-side extension can be configured in the user portion of the GPO. If **VARIANT_TRUE**, the client-side extension can be configured.

## See also

[IGPMClientSideExtension](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmclientsideextension)