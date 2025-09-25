# CF_HYDRATION_POLICY_PRIMARY enumeration

## Description

Allows a sync provider to control how placeholder files should be hydrated by the platform. This is the primary policy.

> [!WARNING]
> **CF_HYDRATION_POLICY_PARTIAL** policy is not currently supported.

## Constants

### `CF_HYDRATION_POLICY_PARTIAL:0`

The same behavior as **CF_HYDRATION_POLICY_PROGRESSIVE**, except that **CF_HYDRATION_POLICY_PARTIAL** does not have continuous hydration in the background.

### `CF_HYDRATION_POLICY_PROGRESSIVE:1`

When **CF_HYDRATION_POLICY_PROGRESSIVE** is selected, the platform will allow a placeholder to be dehydrated. When the platform detects access to a dehydrated placeholder, it will complete the user IO request as soon as it determines that sufficient data is received from the sync provider. However, the platform will continue requesting the remaining content in the placeholder from the sync provider in the background until either the full content of the placeholder is available locally, or the last user handle on the placeholder is closed. \
\
**NOTE**\
Sync providers who opt in for **CF_HYDRATION_POLICY_PROGRESSIVE** may not assume that hydration callbacks arrive sequentially from offset 0. In other words, sync providers with **CF_HYDRATION_POLICY_PROGRESSIVE** policy are expected to handle random seeks on the placeholder.

### `CF_HYDRATION_POLICY_FULL:2`

When **CF_HYDRATION_POLICY_FULL** is selected, the platform will allow a placeholder to be dehydrated. When the platform detects access to a dehydrated placeholder, it will ensure that the full content of the placeholder is available locally before completing the user IO request, even if the request is only asking for 1 byte.

### `CF_HYDRATION_POLICY_ALWAYS_FULL:3`

When **CF_HYDRATION_POLICY_ALWAYS_FULL** is selected, the platform will block any placeholder operation that could result in a not fully hydrated placeholder, which includes [CfCreatePlaceholders](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfcreateplaceholders), [CfUpdatePlaceholder](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfupdateplaceholder) with the dehydrate option, and [CfConvertToPlaceholder](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfconverttoplaceholder) with the dehydrate option.

## See also

[CfCreatePlaceholders](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfcreateplaceholders)

[CfUpdatePlaceholder](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfupdateplaceholder)

[CfConvertToPlaceholder](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfconverttoplaceholder)