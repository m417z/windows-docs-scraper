# _KSPROCESSPIN structure

## Description

The KSPROCESSPIN structure describes the process state of a specific pin.

## Members

### `Pin`

A pointer to a [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure that the KSPROCESSPIN structure is describing. Everything in the structure refers to this KSPIN.

### `StreamPointer`

A pointer to a [KSSTREAM_POINTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksstream_pointer) structure that points into the input stream at the current input location or into the output stream at the current output location. This can be used, for example, by output pins to stamp information onto the associated [KSSTREAM_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksstream_header) (ProcessPin->StreamPointer->StreamHeader->Flags=...).

### `InPlaceCounterpart`

A pointer to a KSPROCESSPIN structure. If this KSPROCESSPIN is not part of an [inplace](https://learn.microsoft.com/windows-hardware/drivers/) transform, AVStream sets **InPlaceCounterpart** to **NULL**. If this KSPROCESSPIN is the input to an inplace transform, **InPlaceCounterpart** points to the output process pin for the transform. If this KSPROCESSPIN is the output of an inplace transform, **InPlaceCounterpart** points to the input process pin for the transform.

### `DelegateBranch`

A pointer to a KSPROCESSPIN structure. If frames coming out of this KSPROCESSPIN are being split and sent to multiple sink pins, and the split does not cause a data copy (that is, the split sends the frames in a read-only manner and all of the split pin instances are in the same pipe), **DelegateBranch** points to the first instance of the process pin. The splitter automatically handles any process pin that has a non-**NULL****DelegateBranch**.

### `CopySource`

A pointer to a KSPROCESSPIN structure. If frames coming out of this process pin are being split and sent to multiple sink pins in a manner that causes a data copy (that is, one of the downstream filters is modifying the data frame by using an in-place transform), **CopySource** points to the process pin from which the frame was copied. The splitter automatically handles any process pin that has a non-**NULL****CopySource**.

### `Data`

A pointer to a buffer. If the pin described by this process entry is an input pin, **Data** points to the next available byte of data to be input. If the pin described by this process entry is an output pin, **Data** points to an output buffer in which processed data is placed.

### `BytesAvailable`

This member specifies how many bytes of data are available in **Data**.

### `BytesUsed`

This member specifies how many bytes of this data frame have been used by the process function. AVStream drivers should set this member to update how much they have read or written.

### `Flags`

This member contains a copy of the flags from the relevant [KSSTREAM_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksstream_header) structure, if this KSPROCESSPIN is an input pin.

### `Terminate`

This member indicates whether the current data frame should be sent downstream after the process dispatch finishes. If **TRUE**, the frame is sent downstream even if all data has not been consumed. If **FALSE**, the frame is not released until all data is consumed.

## Remarks

The KSPROCESSPIN structure is used in the [filter-centric processing](https://learn.microsoft.com/windows-hardware/drivers/stream/filter-centric-processing) model. You can use this structure to access data on a specific input pin or to write out processed data to an output pin.

Only filter-centric clients use process pins. Further, process pins that have a non-**NULL****DelegateBranch** or a non-**NULL****CopySource** typically are not of concern to the client. The splitter automatically handles process pins with these pointers.

Most clients are concerned with the members **Pin**, **Data**, **BytesAvailable**, **BytesUsed**, **Flags**, and **Terminate**. Data can be read from the stream or written into the stream through the **Data** member; **BytesAvailable** tells the client how many bytes of data are available in the current data frame (buffer) that **Data** points to. As the client minidriver reads from or writes to the stream, **BytesUsed** should be updated to reflect how many bytes of data have been consumed. The **Terminate** flag can be set if the minidriver is done with the current frame despite the fact that **BytesUsed** is not equal to **BytesAvailable**. After the minidriver exits the processing dispatch, pointers are advanced, and frames are completed as appropriate.

## See also

[KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin)

[KSPROCESSPIN_INDEXENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksprocesspin_indexentry)

[KSSTREAM_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksstream_header)

[KSSTREAM_POINTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksstream_pointer)