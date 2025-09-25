# IRDPSRAPIClipboardUseEvents::OnPasteFromClipboard

## Description

This callback is issued when an attempt to copy data from the sharer computer is made.

## Parameters

### `clipboardFormat` [in]

A clipboard format identifier. For more information about clipboard formats, see [Clipboard Formats](https://learn.microsoft.com/windows/desktop/dataxchg/clipboard-formats). For a list of clipboard format identifiers, see [Standard Clipboard Formats](https://learn.microsoft.com/windows/desktop/dataxchg/standard-clipboard-formats).

### `pAttendee` [in]

A pointer to the [IRDPSRAPIAttendee](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapiattendee) instance for the attendee who attempted the clipboard copy.

### `pRetVal` [out, retval]

The return value for this attempt.

| Value | Meaning |
| --- | --- |
| VARIANT_TRUE | The clipboard copy attempt should be allowed. |
| VARIANT_FALSE | The clipboard copy attempt should not be allowed. |

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IRDPSRAPIClipboardUseEvents](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapiclipboarduseevents)

[Property](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nf-rdpencomapi-irdpsrapisessionproperties-get_property)