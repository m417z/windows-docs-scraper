# LINEPROXYREQUESTLIST structure

## Description

The
**LINEPROXYREQUESTLIST** structure describes a list of proxy requests. The
[lineGetProxyStatus](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetproxystatus) function returns the
**LINEPROXYREQUESTLIST** structure.

## Members

### `dwTotalSize`

Total size allocated to this structure, in bytes.

### `dwNeededSize`

Size needed to hold all the information requested, in bytes.

### `dwUsedSize`

Size of the portion of this structure that contains useful information, in bytes.

### `dwNumEntries`

Number of **DWORD** elements that appear in the list array.

### `dwListSize`

Size of the proxy request type list, in bytes.

### `dwListOffset`

Offset from the beginning of the structure to an array of **DWORD** elements indicating the currently supported proxy request types. Each element is one of the
[LINEPROXYREQUEST_ constants](https://learn.microsoft.com/windows/desktop/Tapi/lineproxyrequest--constants). The **dwListOffset** member is **dwNumEntries** times SIZEOF(DWORD). The size of the field is specified by **dwListSize**.

## See also

[About Call Center Controls](https://learn.microsoft.com/windows/desktop/Tapi/about-call-center-controls)

[LINEPROXYREQUEST_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/lineproxyrequest--constants)

[lineGetProxyStatus](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetproxystatus)