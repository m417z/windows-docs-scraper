# GetDialogSize function

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetDialogSize** function retrieves the size of a resource dialog box.

## Parameters

*iResourceID*

Dialog box resource identifier.

*pDlgProc*

Pointer to the dialog box procedure.

*lParam*

Value passed in the WM\_INITDIALOG message sent to the temporary dialog box just after it is created.

*pResult*

Pointer to a **SIZE** structure that receives the dimensions of the dialog box, in screen pixels.

## Return value

Returns **TRUE** if the dialog box resource was found, or **FALSE** otherwise.

## Remarks

Property pages can use this function to return the actual display size they require. Most property pages are dialog boxes and, as such, have dialog box templates stored in resource files. Templates use dialog box units that do not map directly onto screen pixels. However, a property page's [**GetPageInfo**](https://learn.microsoft.com/windows/win32/directshow/cbasepropertypage-getpageinfo) function must return the actual display size in pixels. The property page can call `GetDialogSize` to calculate the display size.

This function creates a temporary instance of the dialog box. To avoid having the dialog box appear on the screen, the dialog box template in the resource file should not have a WS\_VISIBLE property.

## Requirements

| Requirement | Value |
|--------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Header<br> | Wxutil.h (include Streams.h) |
| Library<br> | Strmbase.lib (retail builds); <br>Strmbasd.lib (debug builds) |

## See also

[Property Page Helper Functions](https://learn.microsoft.com/windows/win32/directshow/property-page-helper-functions)

