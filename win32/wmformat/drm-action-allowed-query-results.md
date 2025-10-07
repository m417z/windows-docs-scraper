# DRM\_ACTION\_ALLOWED\_QUERY\_RESULTS enumeration

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **DRM\_ACTION\_ALLOWED\_QUERY\_RESULTS** enumeration type is used by the [**IWMDRMLicenseQuery::QueryActionAllowed**](https://learn.microsoft.com/windows/win32/wmformat/iwmdrmlicensequery-queryactionallowed) interface to specify the reason an action is not allowed.

## Constants

**DRM\_ACTION\_ALLOWED\_QUERY\_NOT\_ENABLED**

Specifies that the queries action is not allowed. For actions that are not allowed, the returned value is this value combined by using a bitwise OR with one or more of the other values in this enumeration.

**DRM\_ACTION\_ALLOWED\_QUERY\_NOT\_ENABLED\_NO\_LICENSE**

Specifies that a license does not exist for the requested content.

**DRM\_ACTION\_ALLOWED\_QUERY\_NOT\_ENABLED\_NO\_RIGHT**

Specifies that a license exists for the content, but that the queried right is not allowed.

**DRM\_ACTION\_ALLOWED\_QUERY\_NOT\_ENABLED\_EXHAUSTED**

Specifies that the queried right is restricted by a count, and that no more uses remain.

**DRM\_ACTION\_ALLOWED\_QUERY\_NOT\_ENABLED\_EXPIRED**

Specifies that the queried right is restricted with an expiration date that is earlier than the current date.

**DRM\_ACTION\_ALLOWED\_QUERY\_NOT\_ENABLED\_NOT\_STARTED**

Specifies that the queried right is restricted with a start date that is later than the current date.

**DRM\_ACTION\_ALLOWED\_QUERY\_NOT\_ENABLED\_APPSEC\_TOO\_LOW**

Specifies that a license exists for the content and that the license allows the queried right, but that the security level of the calling application is not high enough.

**DRM\_ACTION\_ALLOWED\_QUERY\_NOT\_ENABLED\_REQ\_INDIV**

Specifies that a license exists for the content and that the license allows the queried right, but that the DRM subsystem must be individualized.

**DRM\_ACTION\_ALLOWED\_QUERY\_NOT\_ENABLED\_COPY\_OPL\_TOO\_LOW**

Specifies that the output protection level of the client is too low.

**DRM\_ACTION\_ALLOWED\_QUERY\_NOT\_ENABLED\_COPY\_OPL\_EXCLUDED**

Specifies that the output protection level of the client is on the exclusion list.

**DRM\_ACTION\_ALLOWED\_QUERY\_NOT\_ENABLED\_NO\_CLOCK\_SUPPORT**

Specifies that the license requires secure clock support and that the client does not provide it.

**DRM\_ACTION\_ALLOWED\_QUERY\_NOT\_ENABLED\_NO\_METERING\_SUPPORT**

Specifies that the queried action is allowed by a license, but that metering is required and the client does not support metering.

**DRM\_ACTION\_ALLOWED\_QUERY\_NOT\_ENABLED\_CHAIN\_DEPTH\_TOO\_HIGH**

Specifies that the rights for the queried action cannot be determined because the content is covered by a chained license and the leaf license is missing.

## Remarks

The values of this enumeration type indicate that an action is not allowed. A value of zero indicates that the action is allowed.

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------------|
| Header<br> | Wmdrmsdk.h |

## See also

[**Enumeration Types**](https://learn.microsoft.com/windows/win32/wmformat/drm-enumeration-types)

