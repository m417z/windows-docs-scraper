# IPersistStreamInit::Save

## Description

Saves an object to the specified stream.

## Parameters

### `pStm` [in]

An [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) pointer to the stream into which the object should be saved.

### `fClearDirty` [in]

Indicates whether to clear the dirty flag after the save is complete. If **TRUE**, the flag should be cleared. If **FALSE**, the flag should be left unchanged.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **STG_E_CANTSAVE** | The object could not save itself to the stream. This error could indicate, for example, that the object contains another object that is not serializable to a stream or that an [ISequentialStream::Write](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-write) call returned STG_E_CANTSAVE. |
| **STG_E_MEDIUMFULL** | The object could not be saved because there is no space left on the storage device. |

## Remarks

**IPersistStreamInit::Save** saves an object into the specified stream and indicates whether the object should reset its dirty flag.

The seek pointer is positioned at the location in the stream at which the object should begin writing its data. The object calls the [ISequentialStream::Write](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-write) method to write its data.

On exit, the seek pointer must be positioned immediately past the object data. The position of the seek pointer is undefined if an error returns.

### Notes to Implementers

The **IPersistStreamInit::Save** method does not write the CLSID to the stream. The caller is responsible for writing the CLSID.

The **IPersistStreamInit::Save** method can read from, write to, and seek in the stream; but it must not seek to a location in the stream before that of the seek pointer on entry.

## See also

[IPersistStreamInit](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipersiststreaminit)