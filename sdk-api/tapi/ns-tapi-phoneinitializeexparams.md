# PHONEINITIALIZEEXPARAMS structure

## Description

The
**PHONEINITIALIZEEXPARAMS** structure contains parameters used to establish the association between an application and TAPI; for example, the application's selected event notification mechanism. The
[phoneInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phoneinitializeexa) function uses this structure.

## Members

### `dwTotalSize`

Total size allocated to this data structure, in bytes.

### `dwNeededSize`

Size for this data structure that is needed to hold all the returned information, in bytes.

### `dwUsedSize`

Size of the portion of this data structure that contains useful information, in bytes.

### `dwOptions`

One of the
[PHONEINITIALIZEEXOPTION_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phoneinitializeexoption--constants). Specifies the event notification mechanism the application desires to use.

### `Handles`

### `Handles.hEvent`

If **dwOptions** specifies PHONEINITIALIZEEXOPTION_USEEVENT, TAPI returns the event handle in this member.

### `Handles.hCompletionPort`

If **dwOptions** specifies PHONEINITIALIZEEXOPTION_USECOMPLETIONPORT, the application must specify in this member the handle of an existing completion port opened using
[CreateIoCompletionPort](https://learn.microsoft.com/windows/desktop/FileIO/createiocompletionport).

### `dwCompletionKey`

If **dwOptions** specifies PHONEINITIALIZEEXOPTION_USECOMPLETIONPORT, the application must specify in this field a value that is returned through the *lpCompletionKey* parameter of
[GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus) to identify the completion message as a telephony message.

## Remarks

See
[phoneInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phoneinitializeexa) for further information on these options.

## See also

[phoneInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phoneinitializeexa)