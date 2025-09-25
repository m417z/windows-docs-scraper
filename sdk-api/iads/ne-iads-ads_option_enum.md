# ADS_OPTION_ENUM enumeration

## Description

The **ADS_OPTION_ENUM** enumeration type
contains values that indicate the options that can be retrieved or set with the
[IADsObjectOptions.GetOption](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsobjectoptions-getoption) and
[IADsObjectOptions.SetOption](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsobjectoptions-setoption)
methods.

## Constants

### `ADS_OPTION_SERVERNAME:0`

Gets a **VT_BSTR** that contains the host name of the server for the current binding
to this object. This option is not supported by the
[IADsObjectOptions.SetOption](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsobjectoptions-setoption) method.

### `ADS_OPTION_REFERRALS`

Gets or sets a **VT_I4** value that indicates how referral chasing is performed in a
query. This option can contain one of the
values defined by the [ADS_CHASE_REFERRALS_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_chase_referrals_enum)
enumeration.

### `ADS_OPTION_PAGE_SIZE`

Gets or sets a **VT_I4** value that indicates the page size in a paged search.

### `ADS_OPTION_SECURITY_MASK`

Gets or sets a **VT_I4** value that controls the security descriptor data that can be
read on the object. This option can contain any combination of the values defined in the
[ADS_SECURITY_INFO_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_security_info_enum) enumeration.

### `ADS_OPTION_MUTUAL_AUTH_STATUS`

Gets a **VT_I4** value that determines if mutual authentication is performed by the
SSPI layer. If the returned option value contains the **ISC_RET_MUTUAL_AUTH** flag,
defined in Sspi.h, then mutual authentication has been performed. If the returned option value does not contain
the **ISC_RET_MUTUAL_AUTH** flag, then mutual authentication has not been performed. For
more information about mutual authentication, see [SSPI](https://learn.microsoft.com/windows/desktop/SecAuthN/sspi). This
option is not supported by the
[IADsObjectOptions.SetOption](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsobjectoptions-setoption) method.

### `ADS_OPTION_QUOTA`

Enables the effective quota and used quota of a security principal to be read. This option takes a
**VT_BSTR** value that contains the security principal that the quotas can be read for.
If the security principal string is zero length or the value is a **VT_EMPTY** value,
the security principal is the currently logged on user. This option is only supported by the
[IADsObjectOptions.SetOption](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsobjectoptions-setoption) method.

### `ADS_OPTION_PASSWORD_PORTNUMBER`

Retrieves or sets a **VT_I4** value that contains the port number that ADSI uses to
establish a connection when the password is set or changed. By default, ADSI uses port 636 to establish a
connection to set or change the password.

### `ADS_OPTION_PASSWORD_METHOD`

Retrieves or sets a **VT_I4** value that specifies the password encoding method.
This option can contain one of the values defined in the
[ADS_PASSWORD_ENCODING_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_password_encoding_enum)
enumeration.

### `ADS_OPTION_ACCUMULATIVE_MODIFICATION`

Contains a **VT_BOOL** value that specifies if attribute value change operations
should be accumulated. By default, when an attribute value is modified more than one time, the previous value
change operation is overwritten by the more recent operation. If this option is set to
**VARIANT_TRUE**, each attribute value change operation is accumulated in the cache.
When the attribute value updates are committed to the server with the
[IADs.SetInfo](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-setinfo) method, each individual accumulated
operation is sent to the server.

When this option has been set to **VARIANT_TRUE**, it cannot be reset to
**VARIANT_FALSE** for the lifetime of the ADSI object. To reset this option, all
references to the ADSI object must be released and the object must be bound to again. When the object is bound
to again, this option will be set to **VARIANT_FALSE** by default.

This option only affects attribute values modified with the
[IADs.PutEx](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-putex) and
[IADsPropertyList.PutPropertyItem](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadspropertylist-putpropertyitem)
methods. This option is ignored by the [IADs.Put](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-put) method.

### `ADS_OPTION_SKIP_SID_LOOKUP`

If this option is set on the object, no lookups will be performed (either during the retrieval or during
modification). This option affects the [IADs](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iads) and
[IADsPropertyList](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadspropertylist) interfaces. It is also applicable
when retrieving the effective quota usage of a particular user.

## See also

[ADSI Enumerations](https://learn.microsoft.com/windows/desktop/ADSI/adsi-enumerations)

[ADS_PASSWORD_ENCODING_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_password_encoding_enum)

[ADS_SECURITY_INFO_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_security_info_enum)

[IADs.Put](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-put)

[IADs.PutEx](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-putex)

[IADs.SetInfo](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iads-setinfo)

[IADsObjectOptions](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsobjectoptions)

[IADsObjectOptions.GetOption](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsobjectoptions-getoption)

[IADsObjectOptions.SetOption](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsobjectoptions-setoption)

[IADsPropertyList.PutPropertyItem](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadspropertylist-putpropertyitem)