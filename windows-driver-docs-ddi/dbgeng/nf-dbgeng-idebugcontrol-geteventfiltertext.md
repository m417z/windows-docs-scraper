# IDebugControl::GetEventFilterText

## Description

The **GetEventFilterText** method returns a short description of an event for a specific filter.

## Parameters

### `Index` [in]

Specifies the index of the event filter whose description will be returned. Only the specific filters have a description attached to them; *Index* must refer to a specific filter.

### `Buffer` [out, optional]

Receives the description of the specific filter.

### `BufferSize` [in]

Specifies the size, in characters, of the buffer that *Buffer* specifies. This size includes the space for the '\0' terminating character.

### `TextSize` [out, optional]

Receives the size of the event description. This size includes the space for the '\0' terminating character. If *TextSize* is **NULL**, this information is not returned.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_NOINTERFACE** | *Index* did not refer to a specific filter. This can occur if *Index* refers to an arbitrary exception filter. |

## Remarks

For more information about [event filters](https://learn.microsoft.com/windows-hardware/drivers/debugger/event-filters), see [Event Filters](https://learn.microsoft.com/windows-hardware/drivers/debugger/event-filters).

## See also

[GetSpecificFilterParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getspecificfilterparameters)

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)

[sx, sxd, sxe, sxi, sxn (Set Exceptions)](https://learn.microsoft.com/windows-hardware/drivers/debugger/sx--sxd--sxe--sxi--sxn--sxr--sx---set-exceptions-)