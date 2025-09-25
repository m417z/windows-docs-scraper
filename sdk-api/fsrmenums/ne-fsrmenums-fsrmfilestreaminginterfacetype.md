# FsrmFileStreamingInterfaceType enumeration

## Description

Defines the possible streaming interface types.

## Constants

### `FsrmFileStreamingInterfaceType_Unknown:0`

The streaming interface type is unknown; do not use this value.

### `FsrmFileStreamingInterfaceType_ILockBytes:0x1`

Use an [ILockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ilockbytes) interface to stream the file.

### `FsrmFileStreamingInterfaceType_IStream:0x2`

Use an [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface to stream the file.

## See also

[FsrmFileStreamingMode](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmfilestreamingmode)

[IFsrmPropertyBag::GetFileStreamInterface](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmpropertybag-getfilestreaminterface)