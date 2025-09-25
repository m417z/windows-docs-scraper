# IESOpenMmiEvent::GetDialogData

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the data associated with an **OpenMMI** event, in byte stream format. This data can be the contents of the dialog that is opened or the Uniform Resource Locator (URL) that contains the dialog.

## Parameters

### `pbData` [out, retval]

Pointer to a SAFEARRAY object containing the event data.
The caller is responsible for freeing this memory.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IESOpenMmiEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iesopenmmievent)