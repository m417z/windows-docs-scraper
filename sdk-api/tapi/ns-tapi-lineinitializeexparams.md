# LINEINITIALIZEEXPARAMS structure

## Description

The **LINEINITIZALIZEEXPARAMS** structure describes parameters supplied when making calls using
[LINEINITIALIZEEX](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitializeexa).

## Members

### `dwTotalSize`

Total size, in bytes, allocated to this data structure.

### `dwNeededSize`

Size for this data structure that is needed to hold all the returned information, in bytes.

### `dwUsedSize`

Size of the portion of this data structure that contains useful information, in bytes.

### `dwOptions`

One of the
[LINEINITIALIZEEXOPTION_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/lineinitializeexoption--constants). Specifies the event notification mechanism the application desires to use.

### `Handles`

### `Handles.hEvent`

If **dwOptions** specifies LINEINITIALIZEEXOPTION_USEEVENT, TAPI returns the event handle in this field.

### `Handles.hCompletionPort`

If **dwOptions** specifies LINEINITIALIZEEXOPTION_USECOMPLETIONPORT, the application must specify in this field the handle of an existing completion port opened using
[CreateIoCompletionPort](https://learn.microsoft.com/windows/desktop/FileIO/createiocompletionport).

### `dwCompletionKey`

If **dwOptions** specifies LINEINITIALIZEEXOPTION_USECOMPLETIONPORT, the application must specify in this field a value that is returned through the *lpCompletionKey* parameter of
[GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus) to identify the completion message as a telephony message.

## Remarks

See
[lineInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitializeexa) for further information on these options.

## See also

[lineInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitializeexa)