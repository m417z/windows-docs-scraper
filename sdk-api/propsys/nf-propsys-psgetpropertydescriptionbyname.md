# PSGetPropertyDescriptionByName function

## Description

Gets an instance of a property description interface for a specified property name.

## Parameters

### `pszCanonicalName` [in]

Type: **LPCWSTR**

A pointer to a null-terminated, Unicode string that identifies the property.

### `riid` [in]

Type: **REFIID**

Reference to the interface ID of the requested property.

### `ppv` [out]

Type: **void****

When this function returns, contains the interface pointer requested in *riid*. This is typically [IPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescription), [IPropertyDescriptionAliasInfo](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescriptionaliasinfo), or [IPropertyDescriptionSearchInfo](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertydescriptionsearchinfo).

## Return value

Type: **PSSTDAPI**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The interface was obtained. |
| **E_INVALIDARG** | The *pszCanonicalName* parameter is **NULL**. |
| **TYPE_E_ELEMENTNOTFOUND** | The canonical name does not exist in the schema subsystem cache. |

## Remarks

 It is recommended that you use the IID_PPV_ARGS macro, defined in objbase.h, to package the *riid* and *ppv* parameters. This macro provides the correct IID based on the interface pointed to by the value in *ppv*, eliminating the possibility of a coding error.

We recommend that *pszCanonicalName* point to the canonical name of a property, for example, `L"System.Keywords"`. The canonical name is case sensitive.

In addition to the new canonical names, callers can pass a legacy name for a property. The following table contains the complete list of supported legacy names and the canonical names they correspond to.

| Property name | Maps to property |
| --- | --- |
| Access | System.DateAccessed |
| Album | System.Music.AlbumTitle |
| AllocSize | System.FileAllocationSize |
| Aperture | System.Photo.Aperture |
| Artist | System.Music.Artist |
| Attrib | System.FileAttributes |
| Attributes | System.FileAttributes |
| AttributesDescription | System.FileAttributesDisplay |
| Audio Format | System.Audio.Format |
| Audio Sample Size | System.Audio.SampleSize |
| BitDepth | System.Image.BitDepth |
| Bitrate | System.Audio.EncodingBitrate |
| CameraModel | System.Photo.CameraModel |
| Capacity | System.Capacity |
| Channels | System.Audio.ChannelCount |
| ColorSpace | System.Image.ColorSpace |
| Company | System.Company |
| Compression | System.Video.Compression |
| Compression | System.Video.Compression |
| Copyright | System.Copyright |
| Copyright | System.Copyright |
| Copyright | System.Image.Copyright |
| Create | System.DateCreated |
| CSCStatus | System.OfflineStatus |
| Data Rate | System.Video.EncodingBitrate |
| DateDeleted | System.Recycle.DateDeleted |
| DeletedFrom | System.Recycle.DeletedFrom |
| Dimensions | System.Image.Dimensions |
| Directory | System.ItemFolderNameDisplay |
| Distance | System.Photo.SubjectDistance |
| DocAppName | System.ApplicationName |
| DocAuthor | System.Author |
| DocByteCount | System.Document.ByteCount |
| DocCategory | System.Category |
| DocCharCount | System.Document.CharacterCount |
| DocComments | System.Comment |
| DocCompany | System.Company |
| DocCreatedTm | System.Document.DateCreated |
| DocEditTime | System.Document.TotalEditingTime |
| DocHiddenCount | System.Document.HiddenSlideCount |
| DocKeywords | System.Keywords |
| DocLastAuthor | System.Document.LastAuthor |
| DocLastPrinted | System.Document.DatePrinted |
| DocLastSavedTm | System.Document.DateSaved |
| DocLineCount | System.Document.LineCount |
| DocManager | System.Document.Manager |
| DocNoteCount | System.Document.NoteCount |
| DocPageCount | System.Document.PageCount |
| DocParaCount | System.Document.ParagraphCount |
| DocPresentationTarget | System.Document.PresentationFormat |
| DocRevNumber | System.Document.RevisionNumber |
| DocSlideCount | System.Document.SlideCount |
| DocSubject | System.Subject |
| DocTemplate | System.Document.Template |
| DocTitle | System.Title |
| DocWordCount | System.Document.WordCount |
| DRM Description | System.DRM.Description |
| Duration | System.Media.Duration |
| EquipMake | System.Photo.CameraManufacturer |
| ExposureBias | System.Photo.ExposureBias |
| ExposureProg | System.Photo.ExposureProgram |
| ExposureTime | System.Photo.ExposureTime |
| FaxCallerID | System.Fax.CallerID |
| FaxCSID | System.Fax.CSID |
| FaxRecipientName | System.Fax.RecipientName |
| FaxRecipientNumber | System.Fax.RecipientNumber |
| FaxRouting | System.Fax.Routing |
| FaxSenderName | System.Fax.SenderName |
| FaxTime | System.Fax.Time |
| FaxTSID | System.Fax.TSID |
| FileDescription | System.FileDescription |
| FileSystem | System.Volume.FileSystem |
| FileType | System.Image.FileType |
| FileVersion | System.FileVersion |
| Flash | System.Photo.Flash |
| FlashEnergy | System.Photo.FlashEnergy |
| FNumber | System.Photo.FNumber |
| FocalLength | System.Photo.FocalLength |
| Frame Rate | System.Video.FrameRate |
| FrameCount | System.Media.FrameCount |
| FreeSpace | System.FreeSpace |
| Genre | System.Music.Genre |
| ImageX | System.Image.HorizontalSize |
| ImageY | System.Image.VerticalSize |
| ISOSpeed | System.Photo.ISOSpeed |
| LightSource | System.Photo.LightSource |
| LinksUpToDate | System.Document.LinksDirty |
| LinkTarget | System.Link.TargetParsingPath |
| Lyrics | System.Music.Lyrics |
| Manager | System.Document.Manager |
| MeteringMode | System.Photo.MeteringMode |
| MMClipCount | System.Document.MultimediaClipCount |
| Name | System.ItemNameDisplay |
| Owner | System.FileOwner |
| Play Count | System.DRM.PlayCount |
| Play Expires | System.DRM.DatePlayExpires |
| Play Starts | System.DRM.DatePlayStarts |
| PresentationTarget | System.Document.PresentationFormat |
| ProductName | System.Software.ProductName |
| ProductVersion | System.Software.ProductVersion |
| Project | System.Media.Project |
| Protected | System.DRM.IsProtected |
| Rank | System.Search.Rank |
| Rating | System.Rating |
| ResolutionX | System.Image.HorizontalResolution |
| ResolutionY | System.Image.VerticalResolution |
| Sample Rate | System.Audio.SampleRate |
| Scale | System.Document.Scale |
| ShutterSpeed | System.Photo.ShutterSpeed |
| Size | System.Size |
| Software | System.SoftwareUsed |
| Status | System.Media.Status |
| Status | System.Status |
| Stream Name | System.Video.StreamName |
| SyncCopyIn | System.Sync.CopyIn |
| Track | System.Music.TrackNumber |
| Type | System.ItemTypeText |
| Video Sample Size | System.Video.SampleSize |
| WhenTaken | System.Photo.DateTaken |
| Write | System.DateModified |
| Year | System.Media.Year |

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PSGetPropertyDescriptionByName](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psgetpropertydescriptionbyname) to retrieve the description for the ratings property.

```cpp
IPropertyDescription *pPropDesc;

HRESULT hr = PSGetPropertyDescriptionByName(L"System.Rating", IID_PPV_ARGS(&pPropDesc))

if (SUCCEEDED(hr))
{
    // pPropDesc is now valid.

    pPropDesc->Release();
}
```

## See also

[IPropertySystem](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertysystem)

[PSGetPropertyDescription](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psgetpropertydescription)