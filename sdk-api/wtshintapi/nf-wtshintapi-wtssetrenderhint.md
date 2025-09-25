# WTSSetRenderHint function

## Description

Used by an application that is displaying content that can be optimized for displaying in a remote
session to identify the region of a window that is the actual content.

In the remote session, this content will be encoded, sent to the client, then decoded and displayed.

## Parameters

### `pRenderHintID` [in, out]

The address of a value that identifies the rendering hint affected by this call. If a new hint is being
created, this value must contain zero. This function will return a unique rendering hint identifier which is
used for subsequent calls, such as clearing the hint.

### `hwndOwner` [in]

The handle of window linked to lifetime of the rendering hint. This window is used in situations where a
hint target is removed without the hint being explicitly cleared.

### `renderHintType` [in]

Specifies the type of hint represented by this call.

#### RENDER_HINT_CLEAR (0)

The previous hint is cleared.

*pHintData* must be **NULL**.

#### RENDER_HINT_VIDEO (1)

Indicates the presence of moving video.

*pHintData* contains a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure
which specifies the coordinates and size of the rendering area. These per-monitor DPI-aware coordinates are
relative to the client coordinates of the window represented by the *hwndOwner*
parameter.

**Windows 8 and Windows Server 2012:** The coordinates are not DPI-aware before Windows 8.1 and
Windows Server 2012 R2.

#### RENDER_HINT_MAPPEDWINDOW (2)

Indicates the presence of a window mapping.

*pHintData* contains a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure
which specifies the coordinates and size of the rendering area. These per-monitor DPI-aware coordinates are
relative to the client coordinates of the window represented by the *hwndOwner*
parameter.

**Windows 8 and Windows Server 2012:** The coordinates are not DPI-aware before Windows 8.1 and
Windows Server 2012 R2.

### `cbHintDataLength` [in]

The size, in **BYTE**s, of the *pHintData* buffer.

### `pHintData` [in]

Additional data for the hint.

The format of this data is dependent upon the value passed in the *renderHintType*
parameter.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.