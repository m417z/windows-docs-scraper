# ILockBytes::SetSize

## Description

The **SetSize** method changes the size of the byte array.

## Parameters

### `cb` [in]

Specifies the new size of the byte array as a number of bytes.

## Return value

This method can return one of these values.

| Return code | Description |
|----------------|---------------|
|S_OK | The size of the byte array was successfully changed.|
|STG_E_ACCESSDENIED | The caller does not have permission to access the byte array.|
|STG_E_MEDIUMFULL | The byte array size is not changed because there is no space left on the storage device.|

## Remarks

**ILockBytes::SetSize** changes the size of the byte array. If the *cb* parameter is larger than the current byte array, the byte array is extended to the indicated size by filling the intervening space with bytes of undefined value, as does
[ILockBytes::WriteAt](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilockbytes-writeat), if the seek pointer is past the current end-of-stream.

If the *cb* parameter is smaller than the current byte array, the byte array is truncated to the indicated size.

### Notes to Callers

Callers cannot rely on STG_E_MEDIUMFULL being returned at the appropriate time because of cache buffering in the operating system or network. However, callers must be able to deal with this return code because some
[ILockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ilockbytes) implementations might support it.

## See also

[ILockBytes - File-Based Implementation](https://learn.microsoft.com/windows/desktop/Stg/ilockbytes-file-based-implementation)

[ILockBytes - Global Memory Implementation](https://learn.microsoft.com/windows/desktop/Stg/ilockbytes-global-memory-implementation)

[ILockBytes::ReadAt](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilockbytes-readat)

[ILockBytes::WriteAt](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilockbytes-writeat)