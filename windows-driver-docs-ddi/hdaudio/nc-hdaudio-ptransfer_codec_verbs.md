# PTRANSFER_CODEC_VERBS callback function

## Description

The *TransferCodecVerbs* routine transfers one or more commands to a codec or codecs and retrieves the responses to those commands.

The function pointer type for a *TransferCodecVerbs* routine is defined as follows.

## Parameters

### `_context` [in]

Specifies the context value from the **Context** member of the [HDAUDIO_BUS_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface), [HDAUDIO_BUS_INTERFACE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_v2), or [HDAUDIO_BUS_INTERFACE_BDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_bdl) structure.

### `Count` [in]

Specifies the number of elements in the *codecTransfer* array.

### `CodecTransfer` [in, out]

Pointer to an array of [HDAUDIO_CODEC_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_codec_transfer) structures. Each array element is a structure that contains storage for both an output command from the caller and the corresponding input response from the codec.

### `Callback` [in]

Function pointer to a callback routine. This parameter is a function pointer of type HDAUDIO_TRANSFER_COMPLETE_CALLBACK. The parameter can be specified as **NULL**. For more information, see the following Remarks section.

### `Context` [in]

A context value for the callback routine. The caller casts the context value to type PVOID. After completing the commands asynchronously, the HD Audio bus driver passes the context value to the callback routine as a call parameter.

## Return value

*TransferCodecVerbs* returns STATUS_SUCCESS if the call succeeds. Otherwise, the routine returns an appropriate error code. The following table shows a possible return status code.

| Return code | Description |
| --- | --- |
| **STATUS_NO_MEMORY** | Indicates that the request could not be added to the command queue due to a shortage of nonpaged memory. |

## Remarks

This routine submits one or more codec commands to the HD Audio bus driver. The bus driver issues the commands to the codecs, retrieves the codecs' responses to the commands, and outputs the responses to the caller.

The caller specifies the commands in an array of HDAUDIO_CODEC_TRANSFER structures. Each structure contains storage for both a command and the codec's response to that command. Before calling *TransferCodecVerbs*, the caller fills in the commands in each of the structures in the array. As each command completes, the HD Audio bus driver retrieves the codec's response and writes it into the structure. After the last command completes, the caller can read the responses from the array.

The routine can operate either synchronously or asynchronously:

* If the caller specifies **NULL** for the value of input parameter *callback*, the HD Audio bus driver completes the commands in the *codecTransfer* array synchronously. (In other words, the routine returns only after the codecs have processed all the commands and the responses to those commands are available.)
* If the caller specifies a non-**NULL** value for the *callback* parameter, the routine operates asynchronously. (In other words, the routine returns immediately after adding the commands to its internal queue without waiting for the codecs to process all the commands.) After the codecs process the commands, the HD Audio bus driver calls the callback routine. In the asynchronous case, the caller should not attempt to read the responses to the commands before the bus driver calls the callback routine.

The function pointer type for the callback parameter is defined as:

```cpp
typedef VOID
  (*PHDAUDIO_TRANSFER_COMPLETE_CALLBACK)
    (HDAUDIO_CODEC_TRANSFER *, PVOID);
```

The first call parameter is a pointer to the *codecTransfer* array element that contains the codec command and the response that triggered the callback. The second call parameter is the same context value that was specified previously in the *TransferCodecVerbs* routine's *callbackContext* parameter.

If successful, *TransferCodecVerbs* returns STATUS_SUCCESS. The meaning of this status code depends on whether the routine operates synchronously or asynchronously:

* In the synchronous case (*callback* is **NULL**), STATUS_SUCCESS means that the bus driver has all the commands in the codecTransfer array to the codecs and that the routine has written all the responses to those commands into the array. However, the caller must check the individual responses to determine whether they are valid. Individual responses might be invalid due to codec timeouts or FIFO overrun.
* In the asynchronous case (*callback* is non-**NULL**), STATUS_SUCCESS means only that the routine has successfully added the commands to the HD Audio bus driver's internal queue. The caller must not attempt to read the responses to those commands until the bus driver calls the callback routine.

If a response is invalid due to a FIFO overrun, the likely cause is that the codec responded to the command but the response was lost due to an insufficiently sized response input ring buffer (RIRB). If a FIFO overrun is not the cause of the invalid response, the failure probably occurred because the codec did not respond in time (timed out). In this case, the caller can assume that the command did not reach the codec.

If the *callback* parameter is **NULL**, the caller must be running at IRQL PASSIVE_LEVEL. If *callback* is non-**NULL**, the caller can call *TransferCodecVerbs* at IRQL <= DISPATCH_LEVEL, in which case the call returns immediately without waiting for the codecs to process all the commands; after the commands complete, the HD Audio bus driver calls the callback routine at IRQL DISPATCH_LEVEL.

The caller must allocate the *codecTransfer* array from the nonpaged pool.

## See also

[HDAUDIO_BUS_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface)

[HDAUDIO_BUS_INTERFACE_BDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_bdl)

[HDAUDIO_BUS_INTERFACE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_v2)

[HDAUDIO_CODEC_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_codec_transfer)