# IAppxBlockMapReader::GetHashMethod

## Description

Retrieves the URI for the hash algorithm used to create block hashes in the block map.

## Parameters

### `hashMethod` [out, retval]

Type: **[IUri](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775038(v=vs.85))****

The hash algorithm used in this block map.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The *hashMethod* value corresponds to the **HashMethod** attribute of the [BlockMap](https://learn.microsoft.com/uwp/schemas/blockmapschema/element-blockmap) root element.

**GetHashMethod** returns supported URIs for [DigestMethod](https://learn.microsoft.com/uwp/schemas/mobilebroadbandschema/carriercontrolsignatureschema/element-digestmethod)s.

## See also

[IAppxBlockMapReader](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxblockmapreader)