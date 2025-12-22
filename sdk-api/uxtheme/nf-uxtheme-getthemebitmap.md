# GetThemeBitmap function

## Description

Retrieves the bitmap associated with a particular theme, part, state, and property.

## Parameters

### `hTheme` [in]

Type: **HTHEME**

A handle to theme data.

### `iPartId` [in]

Type: **int**

The part that contains the bitmap. See [Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states).

### `iStateId` [in]

Type: **int**

The state of the part.

### `iPropId` [in]

Type: **int**

The property to retrieve. Pass zero to automatically select the first available bitmap for this part and state,
or use one of the following values.

| Value | Meaning |
| --- | --- |
| **TMT_DIBDATA** | The background image. |
| **TMT_GLYPHDIBDATA** | The glyph image drawn on top of the background, if present. |
| **TMT_HBITMAP** | Not currently supported. |

### `dwFlags` [in]

Type: **[ULONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The flags that specify how the bitmap is to be retrieved. Can be one of the following values.

| Value | Meaning |
| --- | --- |
| **GBF_DIRECT** | Retrieves a handle to the existing bitmap. |
| **GBF_COPY** | Retrieves a copy of the bitmap. |
| **GBF_VALIDBITS** | **GBF_DIRECT** \| **GBF_COPY** |

### `phBitmap` [out]

Type: **[HBITMAP](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A pointer that receives a handle to the requested bitmap.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If *dwFlags* is set to **GBF_COPY**, release the bitmap stored in *phBitmap* when no longer needed by calling [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject).