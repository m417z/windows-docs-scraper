# IExtractImage::GetLocation

## Description

Gets a path to the image that is to be extracted.

## Parameters

### `pszPathBuffer` [out]

Type: **LPWSTR**

The buffer used to return the path description. This value identifies the image so you can avoid loading the same one more than once.

### `cch` [in]

Type: **DWORD**

The size of *pszPathBuffer* in characters.

### `pdwPriority` [out]

Type: **DWORD***

Not used.

**Microsoft Windows XP and earlier:** The pointer used to return the priority of the item when the **IEIFLAG_ASYNC** flag is set in *pdwFlags*. This parameter must not be **NULL**. The function fails if this parameter is **NULL**, whether **IEIFLAG_ASYNC** flag is set or not.

This parameter is typically used to indicate the amount of time needed to extract the image. If you want more control over the order in which thumbnails are extracted, you can define multiple priority levels, up to 32 bits. As long as the integer values assigned to the different priority levels increase from low to high priority, the actual numbers you use aren't important. They are only used to determine the order in which the images will be extracted. There are three standard priority levels:

#### IEI_PRIORITY_MAX

Maximum priority.

#### IEI_PRIORITY_MIN

Minimum priority.

#### IEIT_PRIORITY_NORMAL

Normal priority.

**Microsoft Windows XP.** Not used.

### `prgSize` [in]

Type: **const [SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size)***

A pointer to a [SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size) structure with the desired width and height of the image. Must not be **NULL**.

### `dwRecClrDepth` [in]

Type: **DWORD**

The recommended color depth in units of bits per pixel. Must not be **NULL**.

### `pdwFlags` [in, out]

Type: **DWORD***

Flags that specify how the image is to be handled. Value must be one or more of the following:

#### IEIFLAG_ASPECT

Used to ask the object to use the supplied aspect ratio. If this flag is set, a rectangle with the desired aspect ratio will be passed in *prgSize*. This flag cannot be used with **IEIFLAG_SCREEN**.

#### IEIFLAG_ASYNC

Not used. The thumbnail is always extracted on a background thread.

**Microsoft Windows XP and earlier.** Used to ask if this instance supports asynchronous (free-threaded) extraction. If this flag is set by the calling applications, **IExtractImage::GetLocation** may return **E_PENDING**, indicating to the calling application to extract the image on another thread. If **E_PENDING** is returned, the priority of the item is returned in *pdwPriority*.

#### IEIFLAG_CACHE

Not supported.

**Windows XP and earlier:** Set by the object to indicate that it will not cache the image. If this flag is returned, the Shell will cache a copy of the image.

#### IEIFLAG_GLEAM

Not supported.

#### IEIFLAG_NOBORDER (0x0100)

Not supported.

#### IEIFLAG_NOSTAMP (0x0080)

Not supported.

#### IEIFLAG_OFFLINE

Used to tell the object to use only local content for rendering.

#### IEIFLAG_ORIGSIZE

[Version 5.0](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776779(v=vs.85)). Used to tell the object to render the image to the approximate size passed in *prgSize*, but crop it if necessary.

#### IEIFLAG_QUALITY (0x0200)

Passed to the [IExtractImage::Extract](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iextractimage-extract) method to indicate that a higher quality image is requested.

If this flag is not set, [IExtractImage](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iextractimage) retrieves an embedded thumbnail if the file has one, no matter what size the user requests. For example, if the file is 2000x2000 pixels but the embedded thumbnail is only 100x100 pixels and the user does not set this flag, yet requests a 1000x1000 pixel thumbnail, **IExtractImage** always returns the 100x100 pixel thumbnail. This is by design, since **IExtractImage** does not scale up. If a larger thumbnail is desired (usually embedded thumbnails are 160x160), this flag must be set.

#### IEIFLAG_REFRESH (0x0400)

Returned by the object to indicate that **Refresh Thumbnail** should be displayed on the item's shortcut menu.

#### IEIFLAG_SCREEN

Used to tell the object to render as if for the screen. This flag cannot be used with **IEIFLAG_ASPECT**.

## Return value

Type: **HRESULT**

This method may return a COM-defined error code or one of the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Success |
| **E_PENDING** | **Windows XP and earlier:** If the **IEIFLAG_ASYNC** flag is set, this return value is used to indicate to the Shell that the object is free-threaded. |

## Remarks

**Microsoft Windows XP and earlier:** This method returns the path to an image and specifies how the image should be rendered. **IExtractImage::GetLocation** is free-threaded—that is, supports the Multithreaded Apartment Model (MTA)— therefore it can be placed in a background thread. The object must also expose an [IRunnableTask](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-irunnabletask) interface, so the calling application can start and stop the extraction process as needed.

You should return images that fit within the boundaries defined by *prgSize*. With Windows 2000 and later systems, you can set **IEIFLAG_ORIGSIZE** to use objects that do not have a standard aspect ratio, and they will be displayed properly. You do not need to fill in the unused part of the rectangle. If you try to use a nonstandard aspect ratio image with earlier versions of the Shell, it will be stretched to fit the *prgSize* rectangle. Depending on how much the aspect ratio differs from what is specified, the image may be badly distorted.