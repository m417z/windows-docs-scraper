# IFilterMapper2::EnumMatchingFilters

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `EnumMatchingFilters` method enumerates registered filters that meet specified requirements.

## Parameters

### `ppEnum` [out]

Receives a pointer to the [IEnumMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienummoniker) interface. Use this interface pointer to retrieve filter monikers from the enumeration. The caller must release the interface.

### `dwFlags` [in]

Reserved, must be zero.

### `bExactMatch` [in]

Boolean value indicating whether an exact match is required. See Remarks for more information.

### `dwMerit` [in]

Minimum merit value. The enumeration excludes filters with a lesser merit value. For a list of merit values, see [Merit](https://learn.microsoft.com/windows/desktop/DirectShow/merit). If *dwMerit* is higher than MERIT_DO_NOT_USE, the enumeration also excludes filters whose category has a merit less than or equal to MERIT_DO_NOT_USE. (See [Filter Categories](https://learn.microsoft.com/windows/desktop/DirectShow/filter-categories).)

### `bInputNeeded` [in]

Boolean value indicating whether the filter must have an input pin. If the value is **TRUE**, the filter must have at least one input pin.

### `cInputTypes` [in]

Number of input media types specified in *pInputTypes*.

### `pInputTypes` [in]

Pointer to an array of GUID pairs that specify major types and subtypes, for the input pins to match. The size of the array is 2 * *cInputTypes*. The array can be **NULL**. Individual array members can be GUID_NULL, which matches any type. (See [Media Types](https://learn.microsoft.com/windows/desktop/DirectShow/media-types).)

### `pMedIn` [in]

Pointer to a [REGPINMEDIUM](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-regpinmedium) structure specifying the medium for the input pins. Set to **NULL** if not needed.

### `pPinCategoryIn` [in]

Pointer to a GUID that specifies the input pin category. (See [Pin Property Set](https://learn.microsoft.com/windows/desktop/DirectShow/pin-property-set).) Set to **NULL** if not needed.

### `bRender` [in]

Boolean value that specifies whether the filter must render its input. If **TRUE**, the specified filter must render its input. (This value corresponds to the **bRendered** field in the [REGFILTERPINS](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-regfilterpins) structure, which is used to register information about the filter's pins.)

### `bOutputNeeded` [in]

Boolean value specifying whether the filter must have an output pin. If **TRUE**, the filter must have at least one output pin.

### `cOutputTypes` [in]

Number of input media types specified in *pOutputTypes*.

### `pOutputTypes` [in]

Pointer to an array of GUID pairs that specify major types and subtypes, for the output pins to match. The size of the array is 2 * *cOutputTypes*. The array can be **NULL**. Individual array members can be GUID_NULL, which matches any type.

### `pMedOut` [in]

Pointer to a [REGPINMEDIUM](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-regpinmedium) structure specifying the medium for the output pins. Set to **NULL** if not needed.

### `pPinCategoryOut` [in]

Pointer to a GUID that specifies the output pin category. (See [Pin Property Set](https://learn.microsoft.com/windows/desktop/DirectShow/pin-property-set).) Set to **NULL** if not needed.

## Return value

Returns an **HRESULT** value. Possible values include those shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Success |
| **E_FAIL** | Failure |
| **E_OUTOFMEMORY** | Insufficient memory |
| **E_POINTER** | **NULL** pointer argument |

## Remarks

To find filters whose input pins match a given set of media types, declare an array with major-type GUIDs and subtype GUIDs ordered in pairs. Pass the array address in the *pInputTypes* parameter, and set the *cInputTypes* parameter equal to the number of pairs (that is, half the array size):

| C++ |
| --- |
| ``` GUID arrayInTypes[2]; arrayInTypes[0] = MEDIATYPE_Video; arrayInTypes[1] = GUID_NULL;<br><br>DWORD cInTypes = 1; ``` |

For output pins, pass a similar array in the *pOutputTypes* parameter, and specify the number of GUID pairs in the *cOutputTypes* parameter.

If the value of the *bExactMatch* parameter is **TRUE**, this method looks for filters that exactly match the values you specify for media type, pin category, and pin medium. If the value is **FALSE**, filters that register a value of **NULL** for any of these items are considered a match. (In effect, a **NULL** value in the registry acts as a wildcard.)

If you specify **NULL** for media type, pin category, or pin medium, any filter is considered a match for that parameter.

If a pin did not register any media types, this method will not consider it a match for the media type.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IFilterMapper2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ifiltermapper2)