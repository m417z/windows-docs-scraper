# IESOpenMmiEvent::GetDialogType

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetDialogType** method gets the GUID representing the experience type of the dialog that is being opened.

## Parameters

### `guidDialogType` [out, retval]

Gets the GUID identifying the experience type of the dialog. If the application does not recognize the experience type, it should set the event as complete by returning an ERROR_ INVALID_TYPE result.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IESOpenMmiEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iesopenmmievent)