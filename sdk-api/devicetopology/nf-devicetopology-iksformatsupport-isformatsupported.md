# IKsFormatSupport::IsFormatSupported

## Description

The **IsFormatSupported** method indicates whether the audio endpoint device supports the specified audio stream format.

## Parameters

### `pKsFormat` [in]

Pointer to an audio-stream format specifier. This parameter points to a caller-allocated buffer that contains a format specifier. The specifier begins with a [KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ks/ns-ks-ksdataformat) structure that might be followed by additional format information. For more information about **KSDATAFORMAT** and format specifiers, see the Windows DDK documentation.

### `cbFormat` [in]

The size in bytes of the buffer that contains the format specifier.

### `pbSupported` [out]

Pointer to a **BOOL** variable into which the method writes a value to indicate whether the format is supported. The method writes **TRUE** if the device supports the format and **FALSE** if the device does not support the format.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer *pKsFormat* or *pbSupported* is **NULL**. |
| **E_INVALIDARG** | The format specifier is not valid. |

## See also

[IKsFormatSupport Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iksformatsupport)