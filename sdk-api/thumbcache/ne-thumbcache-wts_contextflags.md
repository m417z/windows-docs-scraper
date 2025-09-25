# WTS_CONTEXTFLAGS enumeration

## Description

Specifies the context of a thumbnail extraction. Used by [IThumbnailSettings::SetContext](https://learn.microsoft.com/windows/desktop/api/thumbcache/nf-thumbcache-ithumbnailsettings-setcontext).

Your thumbnail provider will set this flag based on the [WTS_FLAGS](https://learn.microsoft.com/windows/desktop/api/thumbcache/ne-thumbcache-wts_flags) values that it received through the [IThumbnailProvider::GetThumbnail](https://learn.microsoft.com/windows/desktop/api/thumbcache/nf-thumbcache-ithumbnailprovider-getthumbnail) request.

## Constants

### `WTSCF_DEFAULT:0`

None of the following options are set. Set in response to [WTS_NONE](https://learn.microsoft.com/windows/desktop/api/thumbcache/ne-thumbcache-wts_flags).

### `WTSCF_APPSTYLE:0x1`

Provide a thumbnail suitable to the Windows Store app UX guidelines. Set in response to [WTS_APPSTYLE](https://learn.microsoft.com/windows/desktop/api/thumbcache/ne-thumbcache-wts_flags).

### `WTSCF_SQUARE:0x2`

If necessary, crop the bitmap's dimensions so that is square. The length of the shortest side becomes the length of all sides. Set in response to [WTS_CROPTOSQUARE](https://learn.microsoft.com/windows/desktop/api/thumbcache/ne-thumbcache-wts_flags).

### `WTSCF_WIDE:0x4`

Stretch and crop the bitmap so that its height is 0.7 times its width. Set in response to [WTS_WIDETHUMBNAILS](https://learn.microsoft.com/windows/desktop/api/thumbcache/ne-thumbcache-wts_flags).

### `WTSCF_FAST:0x8`

If not cached, only extract the thumbnail if it is embedded in EXIF format, typically 96x96. Set in response to [WTS_FASTEXTRACT](https://learn.microsoft.com/windows/desktop/api/thumbcache/ne-thumbcache-wts_flags).