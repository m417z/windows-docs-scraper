# IPrintReadStream::Seek

## Description

The `Seek` method changes the seek pointer to a new location in the stream.

## Parameters

### `dlibMove` [in]

The displacement that is added to the location that *dwOrigin* specifies.

### `dwOrigin` [in]

The origin for the displacement that *dlibMove* specifies. The origin can be the beginning of the file (STREAM_SEEK_SET), the current seek pointer (STREAM_SEEK_CUR), or the end of the file (STREAM_SEEK_END).

### `plibNewPosition` [out]

A pointer to the location where `Seek` writes the value of the new seek pointer from the beginning of the stream.

## Return value

`Seek` returns an **HRESULT** value.

## Remarks

The `Seek` method might block, for example, if seeking to the end of the stream.

This method is similar to the **IStream::Seek** and **SetFilePointerEx** methods. For more information about these methods, see the Microsoft Windows SDK documentation.