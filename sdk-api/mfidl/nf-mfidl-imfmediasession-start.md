# IMFMediaSession::Start

## Description

Starts the Media Session.

## Parameters

### `pguidTimeFormat` [in]

Pointer to a GUID that specifies the time format for the *pvarStartPosition* parameter. This parameter can be **NULL**. The value **NULL** is equivalent to passing in **GUID_NULL**.

The following time format GUIDs are defined:

| Value | Meaning |
| --- | --- |
| **GUID_NULL** | Presentation time. The *pvarStartPosition* parameter must have one of the following **PROPVARIANT** types.<br><br>* **VT_I8**: The *pvarStartPosition* parameter contains the starting position in 100-nanosecond units, relative to the start of the presentation.<br>* **VT_EMPTY**: Playback starts from the current position.<br><br>All media sources support this time format. |
| **MF_TIME_FORMAT_SEGMENT_OFFSET** | Segment offset. This time format is supported by the [Sequencer Source](https://learn.microsoft.com/windows/desktop/medfound/sequencer-source). The starting time is an offset within a segment.<br><br>Call the [MFCreateSequencerSegmentOffset](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-mfcreatesequencersegmentoffset) function to create the **PROPVARIANT** value for the *pvarStartPosition* parameter. |
| **MF_TIME_FORMAT_ENTRY_RELATIVE** | **Note** Requires Windows 7 or later.<br><br>Skip to a playlist entry. The *pvarStartPosition* parameter specifies the index of the playlist entry, relative to the current entry. For example, the value 2 skips forward two entries. To skip backward, pass a negative value. The **PROPVARIANT** type is **VT_I4**.<br><br>If a media source supports this time format, the [IMFMediaSource::GetCharacteristics](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasource-getcharacteristics) method returns one or both of the following flags:<br><br>* **MFMEDIASOURCE_CAN_SKIPFORWARD**<br>* **MFMEDIASOURCE_CAN_SKIPBACKWARD** |

### `pvarStartPosition` [in]

Pointer to a **PROPVARIANT** that specifies the starting position for playback. The meaning and data type of this parameter are indicated by the *pguidTimeFormat* parameter.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_INVALIDREQUEST** | The operation cannot be performed in the Media Session's current state. |
| **MF_E_SHUTDOWN** | The Media Session has been shut down. |

## Remarks

When this method is called, the Media Session starts the presentation clock and begins to process media samples.

This method is asynchronous. When the method completes, the Media Session sends an [MESessionStarted](https://learn.microsoft.com/windows/desktop/medfound/mesessionstarted) event.

## See also

[IMFMediaSession](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasession)