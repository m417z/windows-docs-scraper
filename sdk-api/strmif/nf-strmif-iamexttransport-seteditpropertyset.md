# IAMExtTransport::SetEditPropertySet

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetEditPropertySet` method registers an edit property set that describes a group of edit properties.

This method is not implemented.

## Parameters

### `pEditID` [in, out]

Pointer to a **long** integer that specifies or receives an identifier for the edit property set.

### `State` [in]

Specifies the state of the edit property set.

| Value | Description |
| --- | --- |
| ED_ACTIVE | Activates the edit property set. |
| ED_DELETE | Deletes the edit property set. |
| ED_INACTIVE | Inactivates edit property set. |
| ED_REGISTER | Registers the edit property set. |

If the value is ED_REGISTER, the *pEditID* parameter receives an identifier for the edit property set. For the other flags, use the *pEditID* parameter to specify the identifier.

## Return value

When this method succeeds, it returns S_OK. Otherwise it returns an **HRESULT** error code.

## Remarks

An *edit event* is a set of parameters that define a recording sequence. For example, the parameters can specify editing modes, inpoints and outpoints, or seek positions. Each edit event consists of one or more parameters, called *edit properties*. The collection of properties is called an *edit property set*. Each edit property set is identified by a **long** integer, assigned by the device filter.

To create and execute an edit event, the application must do the following:

* Register an edit property set. Call the `SetEditPropertySet` method with the value ED_REGISTER in the *State* parameter. When the method returns, the *pEditID* parameter contains the identifier for the edit property set. Use this number to identify the edit property set in subsequent method calls.
* Specify the edit properties using the [IAMExtTransport::SetEditProperty](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamexttransport-seteditproperty) method.
* Activate the edit event by calling `SetEditPropertySet` with the value ED_ACTIVE.
* Cue the transport by calling `SetEditProperty` with the value ED_EDIT_SEEK.
* Run the filter graph.

For example, the following code configures an insert edit on all tracks:

| C++ |
| --- |
| ``` // Register an edit property set ID. (Causes memory to be allocated.) long EditId; SetEditPropertySet(&EditId, ED_REGISTER);  <br><br>// Set the edit mode. SetEditProperty(EditId, ED_EDIT_MODE, ED_EDIT_MODE_INSERT); // Set the particulars about the event. SetEditProperty(EditId, ED_EDIT_TRACK, ED_VIDEO \| ED_AUDIO_ALL); SetEditProperty(EditId, ED_REHEARSE_MODE, ED_EDIT_PERFORM);<br><br>// Set the source and record times.  SetEditProperty(EditId, ED_EDIT_SRC_INPOINT, 200) SetEditProperty(EditId, ED_EDIT_SRC_OUTPOINT, 500) SetEditProperty(EditId, ED_EDIT_REC_INPOINT, 100) SetEditProperty(EditId, ED_EDIT_REC_OUTPOINT, 400)<br><br>// Activate the edit event. SetEditPropertySet(&EditId, ED_ACTIVE);  // Cue up the machine. SetEditProperty(EditId, ED_EDIT_SEEK, OATRUE); <br><br>// Run the graph. (Not shown.) ``` |

### DV Implementation

[MSDV](https://learn.microsoft.com/windows/desktop/DirectShow/msdv-driver) does not support this method. It returns E_NOTIMPL.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMExtTransport Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamexttransport)

[IAMExtTransport::GetEditPropertySet](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamexttransport-geteditpropertyset)