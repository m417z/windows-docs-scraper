# IAMDevMemoryControl::WriteSync

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** The **IAMDevMemoryControl** interface is deprecated.

Used to synchronize with the completed write. This method returns when any data being written to the particular allocator region is fully written into the memory.

## Return value

Returns an **HRESULT** value. Possible values include the following:

| Return code | Description |
| --- | --- |
| **E_FAIL** | A time-out has occurred without this method confirming that data was written. |
| **S_OK** | The data was successfully written into memory. |
| **VFW_E_NOT_COMMITTED** | The allocator hasn't called the [IMemAllocator::Commit](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imemallocator-commit) method. |

## Remarks

This method guarantees that all prior write operations to allocated memory have succeeded. Subsequent memory write operations require another call to `WriteSync`.

This method is implementation dependent, and is used (when necessary) to synchronize memory write operations to the memory. The driver of the on-board memory provides the implementation.

The [IAMDevMemoryControl](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamdevmemorycontrol) interface is typically found on memory that is accessed through a Peripheral Component Interconnect (PCI) bridge. (A PCI is a local bus for personal computers that provides a high-speed data path between the processor and peripheral devices.) Memory behind a PCI bridge must be synchronized after a memory write operation completes, if another device will access that memory from behind the PCI bridge. This is because the host access to the memory is buffered through the PCI bridge FIFO (first in first out), and the host will assume the write is completed before the bridge actually writes the data. A subsequent action by a device behind the bridge, such as a SCSI controller, might read the memory before the write is completed, if the **IAMDevMemoryControl::WriteSync** method is not called.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMDevMemoryControl Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamdevmemorycontrol)