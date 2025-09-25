# IWMPContentPartner::GetCatalogURL

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **GetCatalogURL** method retrieves the URL from which to retrieve an update to the online store's current catalog.

## Parameters

### `dwCatalogVersion` [in]

**DWORD** containing the current catalog version.

### `dwCatalogSchemaVersion` [in]

**DWORD** containing the current catalog schema version.

### `catalogLCID` [in]

The locale ID (LCID) for the catalog.

### `pdwNewCatalogVersion` [out]

Address of a **DWORD** that receives the new catalog version.

### `pbstrCatalogURL` [out]

Address of a **BSTR** that receives the URL.

### `pExpirationDate` [out]

Address of a **VARIANT** (**VT_DATE**) that receives the expiration date of the catalog update.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

We recommend that the catalog URL specify the version as part of the path. For example, `http://www.contoso.com/Catalogs/210/catalog.wmdb`.

## See also

[Catalog Compiler for Type 1 Online Stores](https://learn.microsoft.com/windows/desktop/WMP/catalog-compiler-for-type-1-online-stores)

[IWMPContentPartner Interface](https://learn.microsoft.com/windows/desktop/api/contentpartner/nn-contentpartner-iwmpcontentpartner)

[Music Catalog](https://learn.microsoft.com/windows/desktop/WMP/music-catalog)