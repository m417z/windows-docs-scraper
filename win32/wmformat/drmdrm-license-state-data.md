# DRM_LICENSE_STATE_DATA structure (Wmdrmsdk.h)

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **DRM\_LICENSE\_STATE\_DATA** structure contains information about the license restrictions for a DRM right.

## Members

**dwStreamId**

Stream number to which the license applies. Must be 0, which indicates that the license applies to all streams in the file.

**dwCategory**

Category of string to be displayed. See [**DRM\_LICENSE\_STATE\_CATEGORY**](https://learn.microsoft.com/windows/win32/wmformat/drmdrm-license-state-category) for possible values and their meaning.

**dwNumCounts**

Number of items supplied in **dwCount**. This value is typically 0 or 1.

**dwCount\[4\]**

An array of 0 or 1 or more **DWORD** values that represent the number of times the action specified in **dwCategory** may be performed. See Remarks.

**dwNumDates**

Number of items supplied in **datetime**. Typically no more than two dates are used, for example, with a license that is valid from one date until another date.

**datetime\[4\]**

An array of one or more **FILETIME** structures representing one or more dates in the license. The meaning of a particular date depends on the value of **dwCategory**.

**dwVague**

Zero or more of the following flags combined with a bitwise **OR**:

| Flag | Description |
|-----------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| DRM\_LICENSE\_STATE\_DATA\_VAGUE | If set, there may be more licenses that apply to the content. The only way to be certain about the individual licenses that apply to a given key ID is to enumerate the licenses. To do this, call [**IWMDRMLicenseManagement::CreateLicenseEnumeration**](https://learn.microsoft.com/windows/win32/wmformat/iwmdrmlicensemanagement-createlicenseenumeration), passing the key ID as the bstrKID parameter. Then use the retrieved IWMDRMLicense interface to examine the licenses. |
| DRM\_LICENSE\_STATE\_DATA\_OPL\_PRESENT | If set, the license includes output protection levels (OPLs) that must be retrieved and checked against the destination of your application's output. |
| DRM\_LICENSE\_STATE\_DATA\_SAP\_PRESENT | If set, the content must be delivered using secure audio path (SAP). |

## Remarks

This structure is retrieved by calling **IWMDRMLicenseQuery::QueryLicenseState**.

If **dwCategory** is **WM\_DRM\_LICENSE\_STATE\_COUNT\_FROM\_UNTIL**, then the **datetime** array will typically contain two dates: a "from" date and an "until" date. Two date pairs may also be specified to create more complex licenses.

The elements of the **dwCount** array correspond to the dates or date ranges specified in the **datetime** array. If **dwCategory** is **WM\_DRM\_LICENSE\_STATE\_COUNT\_FROM\_UNTIL** and **datetime** contains one pair of dates, then **dwCount** will contain one element. If **datetime** contains two date pairs (four elements), then **dwCount** should contain two elements, one for each date pair.

In some cases, users may have been issued more than one license for a file. For example, they might have acquired a license that allowed five plays until the end of the month, and later acquired a second license for unlimited rights. In such a case, the DRM\_LICENSE\_STATE\_DATA\_VAGUE flag is set in **dwVague** (`dwVague & DRM_LICENSE_STATE_DATA_VAGUE != 0`) and the DRM component will use an algorithm to determine the most likely set of rights that have been applied. When one license expires, the DRM component will examine the remaining licenses, and so on until all licenses have expired.

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------------|
| Header<br> | Wmdrmsdk.h |

## See also

[**Structures**](https://learn.microsoft.com/windows/win32/wmformat/drm-structures)

