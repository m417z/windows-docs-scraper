# OLEINPLACEFRAMEINFO structure

## Description

Contains information about the accelerators supported by a container during an in-place session. The structure is used in the [IOleInPlaceSite::GetWindowContext](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplacesite-getwindowcontext) method and the [OleTranslateAccelerator](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oletranslateaccelerator) function.

## Members

### `cb`

The size of this structure, in bytes. The object server must specify sizeof(**OLEINPLACEFRAMEINFO**) in the structure it passes to [IOleInPlaceSite::GetWindowContext](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplacesite-getwindowcontext). The container can then use this size to determine the structure's version.

### `fMDIApp`

Indicates whether the container is an MDI application.

### `hwndFrame`

A handle to the container's top-level frame window.

### `haccel`

A handle to the accelerator table that the container wants to use during an in-place editing session.

### `cAccelEntries`

The number of accelerators in **haccel**.

## Remarks

When an object is being in-place activated, its server calls the container's [IOleInPlaceSite::GetWindowContext](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplacesite-getwindowcontext) method, which fills in an **OLEINPLACEFRAMEINFO** structure. During an in-place session, the message loop of an EXE server passes a pointer to the **OLEINPLACEFRAMEINFO** structure to [OleTranslateAccelerator](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oletranslateaccelerator). OLE uses the information in this structure to determine whether a message maps to one of the container's accelerators.

## See also

[IOleInPlaceSite::GetWindowContext](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplacesite-getwindowcontext)

[OleTranslateAccelerator](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oletranslateaccelerator)