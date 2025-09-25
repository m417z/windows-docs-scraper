# IAudioSystemEffectsCustomFormats::GetFormatRepresentation

## Description

The `GetFormatRepresentation` method retrieves a string representation of the custom format so that it can be displayed on a user-interface.

## Parameters

### `nFormat` [in]

Specifies the index of a supported format. This parameter can be any value in the range from zero to one less than the return value of [GetFormatCount](https://learn.microsoft.com/windows/desktop/api/audioenginebaseapo/nf-audioenginebaseapo-iaudiosystemeffectscustomformats-getformatcount). In other words, any value in the range from zero to GetFormatCount( ) - 1.

### `ppwstrFormatRep` [out, optional]

Specifies the address of the buffer that receives a NULL-terminated Unicode string that describes the custom format.

## Return value

The `GetFormatRepresentation` method returns S_OK when the call is successful. Otherwise, it returns one of the error codes shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Invalid pointer passed to function |
| **E_OUTOFMEMORY** | Return buffer cannot be allocated |
| **E_INVALIDARG** | nFormat is out of range |

## Remarks

The sAPO uses [CoTaskMemAlloc](https://learn.microsoft.com/previous-versions/windows/embedded/ms886939(v=msdn.10)) to allocate the returned string. The caller must use [CoTaskMemFree](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemfree) to delete the buffer that is pointed to by the *ppwstrFormatRep* parameter.

## See also

[CoTaskMemAlloc](https://learn.microsoft.com/previous-versions/windows/embedded/ms886939(v=msdn.10))

[CoTaskMemFree](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemfree)

[GetFormatCount](https://learn.microsoft.com/windows/desktop/api/audioenginebaseapo/nf-audioenginebaseapo-iaudiosystemeffectscustomformats-getformatcount)