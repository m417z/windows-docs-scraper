# IMFSpatialAudioObjectBuffer::GetID

## Description

Returns the unique, unsigned 32-bit ID of the spatial audio object represented by the buffer.
If [SetID](https://learn.microsoft.com/windows/desktop/api/mfspatialaudio/nf-mfspatialaudio-imfspatialaudioobjectbuffer-setid) method was not previously called, this method returns the invalid object ID, -1
(0xffffffff). The invalid ID indicates that the object buffer is unused and
contains invalid data.

## Parameters

### `pu32ID` [out]

Pointer to a 32-bit variable where the object ID will be stored.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The supplied pointer is invalid. |

## See also

[IMFSpatialAudioObjectBuffer](https://learn.microsoft.com/windows/desktop/api/mfspatialaudio/nn-mfspatialaudio-imfspatialaudioobjectbuffer)