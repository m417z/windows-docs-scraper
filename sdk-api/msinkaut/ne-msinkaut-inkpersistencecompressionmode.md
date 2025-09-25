# InkPersistenceCompressionMode enumeration

## Description

Defines values for the compression modes that are used to save the [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object to a serialized format.

## Constants

### `IPCM_Default:0`

The default. Provides the best tradeoff between save-time and storage for the typical application.

### `IPCM_MaximumCompression:1`

Maximum compression. This is the default value.

### `IPCM_NoCompression:2`

No compression. Used when save-time is more important than the amount of storage space used and when compatibility between versions is important.

## See also

[InkDisp Class](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class)

[Save Method [InkDisp Class]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-save)