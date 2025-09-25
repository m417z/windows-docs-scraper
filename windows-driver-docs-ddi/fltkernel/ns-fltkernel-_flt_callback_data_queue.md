# FLT_CALLBACK_DATA_QUEUE structure

## Description

**FLT_CALLBACK_DATA_QUEUE** is an opaque structure that is used to specify the callback routines for a minifilter's callback data queue. Do not set the members of this structure directly. Use [**FltCbdqInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqinitialize) to initialize this structure.

## Members

### `Csq`

Do not set directly.

### `Flags`

Do not set directly.

### `Instance`

Do not set directly.

### `InsertIo`

Do not set directly.

### `RemoveIo`

Do not set directly.

### `PeekNextIo`

Do not set directly.

### `Acquire`

Do not set directly.

### `Release`

Do not set directly.

### `CompleteCanceledIo`

Do not set directly.

## See also

[**FltCbdqDisable**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqdisable)

[**FltCbdqEnable**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqenable)

[**FltCbdqInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqinitialize)

[**FltCbdqInsertIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqinsertio)

[**FltCbdqRemoveIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqremoveio)

[**FltCbdqRemoveNextIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqremovenextio)